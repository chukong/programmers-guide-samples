#include "Chapter4.h"

USING_NS_CC;

Scene* Chapter4::createScene()
{
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // some upfront items that we need
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
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
    // create a path/walkway
    // depending upon how large the screen is we need to decide how many blocks to lay down.
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto testSprite = Sprite::create("ZigzagForest_Square.png");
    
    int howMany = std::ceil(visibleSize.width / testSprite->getContentSize().width);
    
    int sX = 0; // act as a counter for setPosition x coordinate.
    int sY = 0; // act as a counter for setPosition y coordinate.
    
    playingSize = Size(visibleSize.width, visibleSize.height - testSprite->getContentSize().height);
    
    for (int i=0; i < howMany; i++)
    {
        auto sprite = Sprite::create("ZigzagForest_Square.png");
        sprite->setAnchorPoint(Vec2(0,0));
        sprite->setPosition(sX,sY);
        
        sX += sprite->getContentSize().width;
        
        nodeItems->addChild(sprite, -1);
    }
    
    testSprite = NULL;
    
    scene->addChild(nodeItems, 1);
        
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a node to hold menu
    // create a menu
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto menuNode = Node::create();
    menuNode->setName("menuNode");
    int index = 2;
    
    auto menuItem1 = MenuItemFont::create("First: Create a Sprite");
    menuItem1->setFontNameObj("Marker Felt.ttf");
    menuItem1->setFontSizeObj(32);
    menuItem1->setName("menuItem1");
    menuItem1->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem1->setCallback([&](cocos2d::Ref *sender) {
        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 64);
        newSprite->setName("sprite1");
        newSprite->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite,1);
        
        //auto newSprite2 = Sprite::create("Blue_Front1.png");
        //newSprite2->setPosition(100, 64);
        //newSprite2->setName("sprite2");
        //newSprite2->setAnchorPoint(Vec2(0,0));
        //Director::getInstance()->getRunningScene()->addChild(newSprite2,1);
        
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem1");
        cnode->setVisible(false);
        auto dnode = bnode->getChildByName("menuItem2");
        dnode->setVisible(true);
    });
    
    auto menuItem2 = MenuItemFont::create("Next: Move the Sprite over 2 seconds");
    menuItem2->setFontNameObj("Marker Felt.ttf");
    menuItem2->setFontSizeObj(32);
    menuItem2->setName("menuItem2");
    menuItem2->setVisible(false);
    menuItem2->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem2->setCallback([&](cocos2d::Ref *sender) {
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("sprite1");
        auto moveTo = MoveTo::create(2, Point(300, 64));
        
        anode->runAction(moveTo);
       
        auto wnode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto xnode = wnode->getChildByName("menu");
        auto ynode = xnode->getChildByName("menuItem2");
        ynode->setVisible(false);
        //auto znode = bnode->getChildByName("menuItem3");
        //znode->setVisible(true);
    });
    
    
    auto menu = Menu::create(menuItem1, menuItem2, NULL);
    menu->setName("menu");
    menuNode->addChild(menu, 1);
    menu->setPosition(Vec2::ZERO);
    
    scene->addChild(menuNode, 2);
    
    // return the scene
    return scene;
}
