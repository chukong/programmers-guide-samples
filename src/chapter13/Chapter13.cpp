#include "Chapter13.h"

#include <SimpleAudioEngine.h>

USING_NS_CC;

Scene* Chapter13::createScene()
{
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // some upfront items that we need
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();
    Vec2 origin = dirs->getVisibleOrigin();
    
    Size playingSize = Size(visibleSize.width, visibleSize.height - (visibleSize.height/8)); // actual playing size to work with

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a node to hold non-sprites.
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto nodeItems = Node::create();
    nodeItems->setName("nodeItems");
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a node to hold menu
    // create a menu
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto menuNode = Node::create();
    menuNode->setName("menuNode");
    int index = 2;
    
    auto menuItem1 = MenuItemFont::create("Play Music");
    menuItem1->setFontNameObj("Marker Felt.ttf");
    menuItem1->setFontSizeObj(32);
    menuItem1->setName("menuItem1");
    menuItem1->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem1->setCallback([&](cocos2d::Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
        
        audio->playBackgroundMusic("music.mp3");
        
        auto anode = dirs->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem1");
        cnode->setVisible(false);
        cnode = bnode->getChildByName("menuItem2");
        cnode->setVisible(true);
    });
    
    auto menuItem2 = MenuItemFont::create("Stop Music");
    menuItem2->setFontNameObj("Marker Felt.ttf");
    menuItem2->setFontSizeObj(32);
    menuItem2->setName("menuItem2");
    menuItem2->setVisible(false);
    menuItem2->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem2->setCallback([&](cocos2d::Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
        
        audio->stopBackgroundMusic("music.mp3");
        
        auto anode = dirs->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem2");
        cnode->setVisible(false);
        cnode = bnode->getChildByName("menuItem1");
        cnode->setVisible(true);
    });
    
    auto menuItem3 = MenuItemFont::create("Play Effect");
    menuItem3->setFontNameObj("Marker Felt.ttf");
    menuItem3->setFontSizeObj(32);
    menuItem3->setName("menuItem3");
    menuItem3->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem3->setCallback([&](cocos2d::Ref *sender) {
        auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
        
        audio->playEffect("alert.mp3");
    });
    
    auto menu = Menu::create(menuItem1, menuItem2, menuItem3, NULL);
    menu->setName("menu");
    menuNode->addChild(menu, 1);
    menu->setPosition(Vec2::ZERO);
    
    scene->addChild(menuNode, 2);
    
    // return the scene
    return scene;
}
