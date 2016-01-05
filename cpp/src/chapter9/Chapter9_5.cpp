#include "Chapter9_5.h"
#include "Chapter9.h"

USING_NS_CC;

Scene* Chapter9_5::createScene()
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
    auto label = LabelTTF::create("Camera", "Arial", 24);
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
    
    std::string fileName = "orc.c3b";
    
    auto sprite = Sprite3D::create(fileName);
    sprite->setScale(5.f);
    sprite->setRotation3D(Vec3(0,180,0));
    sprite->setPosition( Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                        Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).y );
    
    // play animation
    auto animation = Animation3D::create(fileName);
    if (animation)
    {
        auto animate = Animate3D::create(animation);
        animate->setSpeed(1);
        sprite->runAction(RepeatForever::create(animate));
    }
    
    //add to scene
    layer3D->addChild(sprite);
    
    // add camera
    auto camera=Camera::createPerspective(60, (GLfloat)winSize.width/winSize.height, 1, 1000);
    camera->setCameraFlag(CameraFlag::USER1);// set camera flag
    camera->setPosition3D(Vec3(0, 0, 230) + sprite->getPosition3D());
    camera->lookAt(sprite->getPosition3D(), Vec3(0,1,0));
    
    // create camera action
    auto action = MoveBy::create(3, Vec2(100, 0));
    auto action_back = action->reverse();
    auto action1 = MoveBy::create(3, Vec2(0, 100));
    auto action_back1 = action1->reverse();
    auto seq = Sequence::create( action, action_back, action1, action_back1, nullptr );
    
    // run camera action
    camera->runAction( RepeatForever::create(seq) );
    
    layer3D->addChild(camera);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // set camera mask
    // when node's camera-mask & camer-flag result is true, the node is visible for this camera.
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    layer3D->setCameraMask(0x2);
    
    // return the scene
    return scene;
}
