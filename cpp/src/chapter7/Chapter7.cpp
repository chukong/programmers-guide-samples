#include "Chapter7.h"
#include "Chapter7_1.h"
#include "Chapter7_2.h"
#include "Chapter7_3.h"

USING_NS_CC;

Scene* Chapter7::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Chapter7::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Chapter7::init()
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
                                           CC_CALLBACK_1(Chapter7::onMenuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    auto closemenu = Menu::create(closeItem, NULL);
    closemenu->setPosition(Vec2::ZERO);
    this->addChild(closemenu, 1);
    
    // Create a Label to identify the sample
    auto label = LabelTTF::create("Chapter 7", "Marker Felt.ttf", 32);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);

    /////////////////////////////
    // 3. add main menu
    auto mainmenu = Menu::create();
    int index = 2;
    
    // TileMap
    auto itemlabel = LabelTTF::create("TileMap", "Marker Felt.ttf", 32);
    auto menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter7_1::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    
    // Particle
    itemlabel = LabelTTF::create("Particle", "Marker Felt.ttf", 32);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter7_2::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);
    
    // Parallax
    itemlabel = LabelTTF::create("Parallax", "Marker Felt.ttf", 32);
    menuItem = MenuItemLabel::create(itemlabel);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter7_3::createScene());
    });
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    mainmenu->addChild(menuItem,2);

    // add main menu
    mainmenu->setPosition(Vec2::ZERO);
    this->addChild(mainmenu, 1);

    return true;
}


void Chapter7::onMenuCloseCallback(Ref* sender)
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
