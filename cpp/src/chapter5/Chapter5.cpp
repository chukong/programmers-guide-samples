#include "Chapter5.h"
#include "Chapter5_1.h"
#include "Chapter5_2.h"
#include "Chapter5_3.h"

USING_NS_CC;

Scene* Chapter5::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = Chapter5::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Chapter5::init()
{
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // super init first
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if (!Node::init())
    {
        return false;
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // some upfront items that we need
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a label
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto thisSceneLabel = Label::createWithTTF("This Is A Scene", "Marker Felt.ttf", 32);
    thisSceneLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a menu item
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto menuItem = MenuItemFont::create("Make A New Scene");
    menuItem->setFontNameObj("Marker Felt.ttf");
    menuItem->setFontSizeObj(32);
    menuItem->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2).x,
                          (Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height).y - 80));
    menuItem->setCallback([&] (cocos2d::Ref* sender) {
        Director::getInstance()->replaceScene(Chapter5_1::createScene());
    });

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a menu
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto menu = Menu::create(menuItem, NULL);
    menu->setPosition(Vec2::ZERO);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a node to hold menu
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto menuNode = Node::create();

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // add child nodes to containers
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    menuNode->addChild(menu, 1);
    this->addChild(thisSceneLabel, 1);
    this->addChild(menuNode, 2);

    return true;
}
