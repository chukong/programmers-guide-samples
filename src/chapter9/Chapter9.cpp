#include "Chapter9.h"
#include "Chapter9_1.h"
#include "Chapter9_2.h"
#include "Chapter9_3.h"
#include "Chapter9_4.h"
#include "Chapter9_5.h"
#include "Chapter9_6.h"
#include "Chapter9_7.h"
#include "Chapter9_8.h"
#include "Chapter9_9.h"
#include "Chapter9_10.h"

USING_NS_CC;

Scene* Chapter9::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Chapter9::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Chapter9::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Node::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(Chapter9::onMenuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto closemenu = Menu::create(closeItem, NULL);
    closemenu->setPosition(Vec2::ZERO);
    this->addChild(closemenu, 1);
    
    /////////////////////////////
    // 3. add main menu
    auto mainmenu = Menu::create();
    int index = 2;
    
    // add "Static sprite3D model"
    auto itemlabel = LabelTTF::create("3D static model", "Arial", 24);
    auto menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9_1::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);

    // add "Sprite3D skeleton animation"
    itemlabel = LabelTTF::create("3D skeleton animation", "Arial", 24);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9_2::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);

    
    // add "Attach weapon"
    itemlabel = LabelTTF::create("Attach weapon", "Arial", 24);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9_3::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);
    
    // add "Test reskin"
    itemlabel = LabelTTF::create("Reskin", "Arial", 24);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9_4::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);

    // add "Test camera"
    itemlabel = LabelTTF::create("Camera", "Arial", 24);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9_5::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);

    // add "Test AABB"
    itemlabel = LabelTTF::create("AABB", "Arial", 24);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9_6::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);
    
    // add "Test OBB"
    itemlabel = LabelTTF::create("OBB", "Arial", 24);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9_7::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);

    // add "Test BillBoard"
    itemlabel = LabelTTF::create("BillBoard", "Arial", 24);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9_8::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);

    // add "Test BillBoard"
    itemlabel = LabelTTF::create("Light", "Arial", 24);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9_9::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);
    
    // add "Frustum Clipping"
    itemlabel = LabelTTF::create("Frustum Clipping", "Arial", 24);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9_10::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);
    
    // add main menu
    this->addChild(mainmenu, 1);
    

    /////////////////////////////
    // 3. add your codes below...

    auto label = LabelTTF::create("Chapter 9", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    return true;
}


void Chapter9::onMenuCloseCallback(Ref* sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
