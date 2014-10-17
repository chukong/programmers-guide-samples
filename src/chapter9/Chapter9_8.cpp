#include "Chapter9_8.h"
#include "Chapter9.h"
#include "DrawNode3D.h"

USING_NS_CC;

Scene* Chapter9_8::createScene()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("BillBoard", "Arial", 24);
    label->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                       Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - 30);
    
    scene->addChild(label, -1);
    
    //add the menu item for back to main menu
    label = LabelTTF::create("MainMenu", "Arial", 24);
    auto menuItem = MenuItemLabel::create(label);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9::createScene());
    });
    auto menu = Menu::create(menuItem, nullptr);
    menu->setPosition( Vec2::ZERO );
    menuItem->setPosition( Vec2(origin.x+visibleSize.width - 80, origin.y + 25) );
    scene->addChild(menu, 1);
    
    
    auto layer3D=Layer::create();
    scene->addChild(layer3D,2);
    
    static std::vector<BillBoard*> _billboards;
    for (int i = -4; i < 4; ++i)
    {
        auto billboard = BillBoard::create("Blue_Front1.png");
        billboard->setScale(0.5f);
        billboard->setPosition3D(Vec3(i * 50, 0.0f, 0));
        billboard->setBlendFunc(cocos2d::BlendFunc::ALPHA_NON_PREMULTIPLIED);
        _billboards.push_back(billboard);
        layer3D->addChild(billboard);
    }
    
    for (int i = -4; i < 4; ++i)
    {
        auto billboard = BillBoard::create("Blue_Front1.png");
        billboard->setScale(0.5f);
        billboard->setPosition3D(Vec3(i * 50, 0.0f, -50));
        billboard->setBlendFunc(cocos2d::BlendFunc::ALPHA_NON_PREMULTIPLIED);
        _billboards.push_back(billboard);
        layer3D->addChild(billboard);
    }
    
    // add camera
    auto camera=Camera::createPerspective(60, (GLfloat)winSize.width/winSize.height, 1, 1000);
    camera->setCameraFlag(CameraFlag::USER1);// set camera flag
    camera->setPosition3D(Vec3(0, 150, 230));
    camera->lookAt(Vec3(0, 0, 0), Vec3(0,1,0));
    
    // create camera action
    auto action = MoveBy::create(3, Vec2(100, 0));
    auto actionrev = action->reverse();
    auto actionback = MoveBy::create(3, Vec2(-100, 0));
    auto actionbackrev = actionback->reverse();
    auto seq = Sequence::create( action, actionrev, actionback, actionbackrev, nullptr );
    
    // run camera action
    camera->runAction( RepeatForever::create(seq) );
    
    layer3D->addChild(camera);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // set camera mask
    // when node's camera-mask & camer-flag result is true, the node is visible for this camera.
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    layer3D->setCameraMask(0x2);
    
    // add select menue
    auto label1 = LabelTTF::create("Point Oriented", "Arial", 24);
    auto item1 = MenuItemLabel::create(label1);
    item1->setCallback([&](cocos2d::Ref *sender) {
        for (auto& billboard : _billboards) {
            billboard->setMode(BillBoard::Mode::VIEW_POINT_ORIENTED);
        }
    });
    auto label2 = LabelTTF::create("Plane Oriented", "Arial", 24);
    auto item2 = MenuItemLabel::create(label2);
    item2->setCallback([&](cocos2d::Ref *sender) {
        for (auto& billboard : _billboards) {
            billboard->setMode(BillBoard::Mode::VIEW_PLANE_ORIENTED);
        }
    });
    auto itemSize = item1->getContentSize();
    item1->setPosition( Vec2(origin.x + 100, origin.y+visibleSize.height - itemSize.height * 2));
    item2->setPosition( Vec2(origin.x + 100, origin.y+visibleSize.height - itemSize.height * 3));
    
    auto menuSelect = CCMenu::create(item1, item2, NULL);
    menuSelect->setPosition(Vec2(0,0));
    scene->addChild(menuSelect, 1);
    
    // return the scene
    return scene;
}