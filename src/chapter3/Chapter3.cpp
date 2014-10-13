#include "Chapter3.h"

USING_NS_CC;

Scene* Chapter3::createScene()
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
        
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem1");
        cnode->setVisible(false);
        auto dnode = bnode->getChildByName("menuItem2");
        dnode->setVisible(true);
    });
    
    auto menuItem2 = MenuItemFont::create("Next: Create a Sprite from a Rect");
    menuItem2->setFontNameObj("Marker Felt.ttf");
    menuItem2->setFontSizeObj(32);
    menuItem2->setName("menuItem2");
    menuItem2->setVisible(false);
    menuItem2->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem2->setCallback([&](cocos2d::Ref *sender) {
        auto newSprite = Sprite::create("Blue_Front1.png", Rect(0,0,50,50));
        newSprite->setPosition(250, 64);
        newSprite->setName("sprite2");
        newSprite->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite,1);
        
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem2");
        cnode->setVisible(false);
        auto dnode = bnode->getChildByName("menuItem3");
        dnode->setVisible(true);
    });
    
    auto menuItem3 = MenuItemFont::create("Next: Create a Sprite from SpriteFrameCache");
    menuItem3->setFontNameObj("Marker Felt.ttf");
    menuItem3->setFontSizeObj(32);
    menuItem3->setName("menuItem3");
    menuItem3->setVisible(false);
    menuItem3->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem3->setCallback([&](cocos2d::Ref *sender) {
        auto spritecache = SpriteFrameCache::getInstance();
        spritecache->addSpriteFramesWithFile("sprites.plist");

        auto newSprite = Sprite::createWithSpriteFrameName("Blue_Front1.png");
        newSprite->setPosition(400, 64);
        newSprite->setName("sprite3");
        newSprite->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite,1);

        auto anode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem3");
        cnode->setVisible(false);
        auto dnode = bnode->getChildByName("menuItem4");
        dnode->setVisible(true);
    });
    
    auto menuItem4 = MenuItemFont::create("Next: Create a Sprite from SpriteFrame");
    menuItem4->setFontNameObj("Marker Felt.ttf");
    menuItem4->setFontSizeObj(32);
    menuItem4->setName("menuItem4");
    menuItem4->setVisible(false);
    menuItem4->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem4->setCallback([&](cocos2d::Ref *sender) {
        auto spritecache = SpriteFrameCache::getInstance();
        spritecache->addSpriteFramesWithFile("sprites.plist");
        
        auto newspriteFrame = SpriteFrame::create("Blue_Front1.png", Rect(0,0,50,50));
        
        auto newSprite = Sprite::createWithSpriteFrame(newspriteFrame);
        newSprite->setPosition(550, 64);
        newSprite->setName("sprite4");
        newSprite->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite,1);
        
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem4");
        cnode->setVisible(false);
        auto dnode = bnode->getChildByName("menuItem5");
        dnode->setVisible(true);
    });
    
    auto menuItem5 = MenuItemFont::create("Next: Scale a Sprite");
    menuItem5->setFontNameObj("Marker Felt.ttf");
    menuItem5->setFontSizeObj(32);
    menuItem5->setName("menuItem5");
    menuItem5->setVisible(false);
    menuItem5->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem5->setCallback([&](cocos2d::Ref *sender) {
        // hide everything else on the screen
        Director::getInstance()->getRunningScene()->removeChildByName("sprite1");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite2");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite3");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite4");

        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 64);
        newSprite->setName("sprite5");
        newSprite->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite,1);
        
        auto newSpriteScaleXY = Sprite::create("Blue_Front1.png");
        newSpriteScaleXY->setPosition(200, 64);
        newSpriteScaleXY->setName("sprite6");
        newSpriteScaleXY->setAnchorPoint(Vec2(0,0));
        newSpriteScaleXY->setScale(4.0f);
        Director::getInstance()->getRunningScene()->addChild(newSpriteScaleXY,1);
        
        auto newSpriteScaleX = Sprite::create("Blue_Front1.png");
        newSpriteScaleX->setPosition(500, 64);
        newSpriteScaleX->setName("sprite7");
        newSpriteScaleX->setAnchorPoint(Vec2(0,0));
        newSpriteScaleX->setScaleX(4.0f);
        Director::getInstance()->getRunningScene()->addChild(newSpriteScaleX,1);
        
        auto newSpriteScaleY = Sprite::create("Blue_Front1.png");
        newSpriteScaleY->setPosition(800, 64);
        newSpriteScaleY->setName("sprite8");
        newSpriteScaleY->setAnchorPoint(Vec2(0,0));
        newSpriteScaleY->setScaleY(4.0f);
        Director::getInstance()->getRunningScene()->addChild(newSpriteScaleY,1);
        
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem5");
        cnode->setVisible(false);
        auto dnode = bnode->getChildByName("menuItem6");
        dnode->setVisible(true);
    });
    
    auto menuItem6 = MenuItemFont::create("Next: Anchor Point and Sprite");
    menuItem6->setFontNameObj("Marker Felt.ttf");
    menuItem6->setFontSizeObj(32);
    menuItem6->setName("menuItem6");
    menuItem6->setVisible(false);
    menuItem6->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem6->setCallback([&](cocos2d::Ref *sender) {
        // hide everything else on the screen
        Director::getInstance()->getRunningScene()->removeChildByName("sprite5");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite6");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite7");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite8");
        
        auto newSprite00 = Sprite::create("Blue_Front1.png");
        newSprite00->setPosition(100, 64);
        newSprite00->setName("sprite9");
        newSprite00->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite00,1);
        
        auto newSprite01 = Sprite::create("Blue_Front1.png");
        newSprite01->setPosition(250, 64);
        newSprite01->setName("sprite10");
        newSprite01->setAnchorPoint(Vec2(0,1));
        Director::getInstance()->getRunningScene()->addChild(newSprite01,1);
        
        auto newSprite10 = Sprite::create("Blue_Front1.png");
        newSprite10->setPosition(400, 64);
        newSprite10->setName("sprite11");
        newSprite10->setAnchorPoint(Vec2(1,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite10,1);
        
        auto newSprite11 = Sprite::create("Blue_Front1.png");
        newSprite11->setPosition(550, 64);
        newSprite11->setName("sprite12");
        newSprite11->setAnchorPoint(Vec2(1,1));
        Director::getInstance()->getRunningScene()->addChild(newSprite11,1);
        
        auto newSprite22 = Sprite::create("Blue_Front1.png");
        newSprite22->setPosition(700, 64);
        newSprite22->setName("sprite13");
        newSprite22->setAnchorPoint(Vec2(0.5,0.5));
        Director::getInstance()->getRunningScene()->addChild(newSprite22,1);
        
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem6");
        cnode->setVisible(false);
        auto dnode = bnode->getChildByName("menuItem7");
        dnode->setVisible(true);
    });

    auto menuItem7 = MenuItemFont::create("Next: Skew a Sprite");
    menuItem7->setFontNameObj("Marker Felt.ttf");
    menuItem7->setFontSizeObj(32);
    menuItem7->setName("menuItem7");
    menuItem7->setVisible(false);
    menuItem7->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem7->setCallback([&](cocos2d::Ref *sender) {
        // hide everything else on the screen
        Director::getInstance()->getRunningScene()->removeChildByName("sprite9");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite10");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite11");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite12");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite13");
        
        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 64);
        newSprite->setName("sprite14");
        newSprite->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite,1);
        
        auto newSpriteSkewX = Sprite::create("Blue_Front1.png");
        newSpriteSkewX->setPosition(250, 64);
        newSpriteSkewX->setName("sprite15");
        newSpriteSkewX->setAnchorPoint(Vec2(0,0));
        newSpriteSkewX->setSkewX(20.0f);
        Director::getInstance()->getRunningScene()->addChild(newSpriteSkewX,1);
        
        auto newSpriteSkewY = Sprite::create("Blue_Front1.png");
        newSpriteSkewY->setPosition(400, 64);
        newSpriteSkewY->setName("sprite16");
        newSpriteSkewY->setAnchorPoint(Vec2(0,0));
        newSpriteSkewY->setSkewY(20.0f);
        Director::getInstance()->getRunningScene()->addChild(newSpriteSkewY,1);
        
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem7");
        cnode->setVisible(false);
        auto dnode = bnode->getChildByName("menuItem8");
        dnode->setVisible(true);
    });

    auto menuItem8 = MenuItemFont::create("Next: Rotate a Sprite");
    menuItem8->setFontNameObj("Marker Felt.ttf");
    menuItem8->setFontSizeObj(32);
    menuItem8->setName("menuItem8");
    menuItem8->setVisible(false);
    menuItem8->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem8->setCallback([&](cocos2d::Ref *sender) {
        // hide everything else on the screen
        Director::getInstance()->getRunningScene()->removeChildByName("sprite14");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite15");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite16");
        Director::getInstance()->getRunningScene()->removeChildByName("sprite17");
        
        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 64);
        newSprite->setName("sprite18");
        newSprite->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite,1);
        
        auto newSpriteRotateP20 = Sprite::create("Blue_Front1.png");
        newSpriteRotateP20->setPosition(250, 64);
        newSpriteRotateP20->setName("sprite19");
        newSpriteRotateP20->setAnchorPoint(Vec2(0,0));
        newSpriteRotateP20->setRotation(20.0f);
        Director::getInstance()->getRunningScene()->addChild(newSpriteRotateP20,1);
        
        auto newSpriteSkewN20 = Sprite::create("Blue_Front1.png");
        newSpriteSkewN20->setPosition(400, 64);
        newSpriteSkewN20->setName("sprite20");
        newSpriteSkewN20->setAnchorPoint(Vec2(0,0));
        newSpriteSkewN20->setRotation(-20.0f);
        Director::getInstance()->getRunningScene()->addChild(newSpriteSkewN20,1);
        
        auto newSpriteRotateP60 = Sprite::create("Blue_Front1.png");
        newSpriteRotateP60->setPosition(550, 64);
        newSpriteRotateP60->setName("sprite21");
        newSpriteRotateP60->setAnchorPoint(Vec2(0,0));
        newSpriteRotateP60->setRotation(60.0f);
        Director::getInstance()->getRunningScene()->addChild(newSpriteRotateP60,1);
        
        auto newSpriteRotateN60 = Sprite::create("Blue_Front1.png");
        newSpriteRotateN60->setPosition(700, 64);
        newSpriteRotateN60->setName("sprite22");
        newSpriteRotateN60->setAnchorPoint(Vec2(0,0));
        newSpriteRotateN60->setRotation(-60.0f);
        Director::getInstance()->getRunningScene()->addChild(newSpriteRotateN60,1);
        
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem8");
        cnode->setVisible(false);
        //auto dnode = bnode->getChildByName("menuItem9");
        //dnode->setVisible(true);
    });
    
    auto menu = Menu::create(menuItem1, menuItem2, menuItem3, menuItem4, menuItem5, menuItem6,
                             menuItem7, menuItem8, NULL);
    menu->setName("menu");
    menuNode->addChild(menu, 1);
    menu->setPosition(Vec2::ZERO);
    
    scene->addChild(menuNode, 2);
    
    // return the scene
    return scene;
}
