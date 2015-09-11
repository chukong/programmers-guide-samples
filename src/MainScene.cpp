#include "MainScene.h"

#include "Chapter2.h"
#include "Chapter3.h"
#include "Chapter4.h"
#include "Chapter5.h"
#include "Chapter6.h"
#include "Chapter7.h"
#include "Chapter9.h"
#include "Chapter12.h"
#include "Chapter13.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
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
    auto closeItem = MenuItemImage::create("CloseNormal.png",
                                "CloseSelected.png",
                    CC_CALLBACK_1(MainScene::onMenuCloseCallback, this));
    
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
    
    std::vector<std::string> vChapters = {"Chapter 2", "Chapter 3", "Chapter 4", "Chapter 5", "Chapter 6", "Chapter 7", "Chapter 9", "Chapter 12", "Chapter 13"};
    
    std::vector<MenuItemLabel*> vMenuItems;
    
    // create the menu items for each chaper
    for (int i=0; i < vChapters.size(); i++)
    {
        auto itemLabel = LabelTTF::create(vChapters.at(i), "Arial", 32);
        auto menuItemLabel = MenuItemLabel::create(itemLabel);
        
        menuItemLabel->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
            (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));

        vMenuItems.push_back(menuItemLabel);
    }
    
    // create the callbacks for each menu item
    vMenuItems.at(0)->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter2::createScene());
    });
    vMenuItems.at(1)->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter3::createScene());
    });
    vMenuItems.at(2)->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter4::createScene());
    });
    vMenuItems.at(3)->setCallback([&](cocos2d::Ref *sender) {
        auto chapter5 = Chapter5();
        Director::getInstance()->replaceScene(chapter5.getScene1());
    });
    vMenuItems.at(4)->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter6::createScene());
    });
    vMenuItems.at(5)->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter7::createScene());
    });
    vMenuItems.at(6)->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9::createScene());
    });
    vMenuItems.at(7)->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter12::createScene());
    });
    vMenuItems.at(8)->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter13::createScene());
    });
    
    // now add all the menu items to the menu
    for (int i=0; i < vMenuItems.size(); i++)
    {
        mainmenu->addChild(vMenuItems.at(i),2);
    }
    
    mainmenu->setPosition(Vec2::ZERO);
    
    // add main menu
    this->addChild(mainmenu, 1);
    

    /////////////////////////////
    // 3. add your codes below...

    auto label = LabelTTF::create("Programmers Guide Samples", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
        origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    return true;
}


void MainScene::onMenuCloseCallback(Ref* sender)
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
