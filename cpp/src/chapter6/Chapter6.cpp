#include "Chapter6.h"
#include "Chapter6_1.h"
#include "Chapter6_2.h"
#include "Chapter6_3.h"
#include "Chapter6_4.h"
#include "Chapter6_5.h"
#include "Chapter6_6.h"
#include "Chapter6_7.h"

USING_NS_CC;

Scene* Chapter6::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Chapter6::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Chapter6::init()
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
                                           CC_CALLBACK_1(Chapter6::onMenuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto closemenu = Menu::create(closeItem, NULL);
    closemenu->setPosition(Vec2::ZERO);
    this->addChild(closemenu, 1);
    
    // Create a Label to identify the sample
    auto label = LabelTTF::create("Chapter 6", "Marker Felt.ttf", 32);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    /////////////////////////////
    // 3. add main menu
    auto mainmenu = Menu::create();
    int index = 2;
    
    // Label
    auto itemlabel = LabelTTF::create("Label", "Marker Felt.ttf", 32);
    auto menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter6_1::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);
    
    // Menu and Menu Items
    itemlabel = LabelTTF::create("Menu and Menu Items", "Marker Felt.ttf", 32);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter6_2::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);
    
    // Button
    itemlabel = LabelTTF::create("Button", "Marker Felt.ttf", 32);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter6_3::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);
    
    
    // Checkbox
    itemlabel = LabelTTF::create("CheckBox", "Marker Felt.ttf", 32);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter6_4::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);
    
    // LoadingBar
    itemlabel = LabelTTF::create("LoadingBar", "Marker Felt.ttf", 32);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter6_5::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);
    
    // Slider
    itemlabel = LabelTTF::create("Slider", "Marker Felt.ttf", 32);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter6_6::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    mainmenu->setPosition(Vec2::ZERO);
    
    // TextField
    itemlabel = LabelTTF::create("TextField", "Marker Felt.ttf", 32);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter6_7::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    
    // add main menu
    mainmenu->setPosition(Vec2::ZERO);
    this->addChild(mainmenu, 1);

    
    
    return true;
}

void Chapter6::onMenuCloseCallback(Ref* sender)
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
