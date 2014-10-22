#include "Chapter9_3.h"
#include "Chapter9.h"

USING_NS_CC;

Scene* Chapter9_3::createScene()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create sprite
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    std::string fileName = "orc.c3b";
    static Sprite3D* sprite = nullptr;
    if(sprite == nullptr)
        sprite = Sprite3D::create(fileName);
    sprite->setScale(8.f);
    sprite->setRotation3D(Vec3(0,180,0));
    sprite->setPosition( Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                        Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).y );
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // play animation
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto animation = Animation3D::create(fileName);
    if (animation)
    {
        auto animate = Animate3D::create(animation);
        animate->setSpeed(1);
        sprite->runAction(RepeatForever::create(animate));
    }
    
    // add title
    auto label = LabelTTF::create("Attach weapon", "Arial", 24);
    label->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                       Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - 30);
    
    scene->addChild(label, -1);
    
    static bool isAttach = false;
    auto label1 = LabelTTF::create("Attach", "Arial", 24);
    static MenuItemLabel* item1 = nullptr;
    if (item1 == nullptr)
    {
        item1 = MenuItemLabel::create(label1);
    }
    
    item1->setCallback([&](cocos2d::Ref *sender) {
        if(!isAttach)
        {
            auto sp = Sprite3D::create("axe.c3b");
            sprite->getAttachNode("Bip001 R Hand")->addChild(sp);
            item1->setString("Detach");
        }
        else
        {
            sprite->removeAllAttachNode();
            item1->setString("Attach");
        }
        isAttach = !isAttach;
    });
    auto itemSize = item1->getContentSize();
    item1->setPosition( Vec2(origin.x + 50, origin.y+visibleSize.height - itemSize.height * 2));
    
    auto menuSelect = CCMenu::create(item1, NULL);
    menuSelect->setPosition(Vec2(0,0));
    scene->addChild(menuSelect, 1);
    
    //add the menu item for back to main menu
    label = LabelTTF::create("MainMenu", "Arial", 24);
    auto menuItem = MenuItemLabel::create(label);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        item1 = nullptr;
        sprite = nullptr;
        Director::getInstance()->replaceScene(Chapter9::createScene());
    });
    auto menu = Menu::create(menuItem, nullptr);
    menu->setPosition( Vec2::ZERO );
    menuItem->setPosition( Vec2(origin.x+visibleSize.width - 80, origin.y + 25) );
    scene->addChild(menu, 1);
    
    //add to scene
    scene->addChild(sprite);
    
    // return the scene
    return scene;
}
