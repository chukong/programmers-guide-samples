#include "Chapter3.h"

USING_NS_CC;

Scene* Chapter3::createScene()
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
    
    auto menuItem1 = MenuItemFont::create("First: Create a Sprite");
    menuItem1->setFontNameObj("Marker Felt.ttf");
    menuItem1->setFontSizeObj(32);
    menuItem1->setName("menuItem1");
    menuItem1->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem1->setCallback([&](cocos2d::Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 256);
        newSprite->setName("sprite1");
        newSprite->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite,1);
        
        auto anode = dirs->getChildByName("menuNode");
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
        auto dirs = Director::getInstance()->getRunningScene();
        auto newSprite = Sprite::create("Blue_Front1.png", Rect(0,0,50,50));
        newSprite->setPosition(250, 256);
        newSprite->setName("sprite2");
        newSprite->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite,1);
        
        auto anode = dirs->getChildByName("menuNode");
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
        auto dirs = Director::getInstance()->getRunningScene();
        auto spritecache = SpriteFrameCache::getInstance();
        spritecache->addSpriteFramesWithFile("sprites.plist");

        auto newSprite = Sprite::createWithSpriteFrameName("Blue_Front1.png");
        newSprite->setPosition(400, 256);
        newSprite->setName("sprite3");
        newSprite->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite,1);

        auto anode = dirs->getChildByName("menuNode");
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
        auto dirs = Director::getInstance()->getRunningScene();
        auto spritecache = SpriteFrameCache::getInstance();
        spritecache->addSpriteFramesWithFile("sprites.plist");
        
        auto newspriteFrame = SpriteFrame::create("Blue_Front1.png", Rect(0,0,50,50));
        
        auto newSprite = Sprite::createWithSpriteFrame(newspriteFrame);
        newSprite->setPosition(550, 256);
        newSprite->setName("sprite4");
        newSprite->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite,1);
        
        auto anode = dirs->getChildByName("menuNode");
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
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite1");
        dirs->removeChildByName("sprite2");
        dirs->removeChildByName("sprite3");
        dirs->removeChildByName("sprite4");

        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 256);
        newSprite->setName("sprite5");
        newSprite->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite,1);
        
        auto point00 = Sprite::create("dot.png");
        point00->setName("point00");
        point00->setPosition(newSprite->getPosition());
        dirs->addChild(point00,2);
        
        auto newSpriteScaleXY = Sprite::create("Blue_Front1.png");
        newSpriteScaleXY->setPosition(300,256);
        newSpriteScaleXY->setName("sprite6");
        newSpriteScaleXY->setAnchorPoint(Vec2(0.5,0.5));
        newSpriteScaleXY->setScale(2.0f);
        dirs->addChild(newSpriteScaleXY,1);
        
        auto pointXY = Sprite::create("dot.png");
        pointXY->setName("pointXY");
        pointXY->setPosition(newSpriteScaleXY->getPosition());
        dirs->addChild(pointXY,2);
        
        auto newSpriteScaleX = Sprite::create("Blue_Front1.png");
        newSpriteScaleX->setPosition(500,256);
        newSpriteScaleX->setName("sprite7");
        newSpriteScaleX->setAnchorPoint(Vec2(0.5,0.5));
        newSpriteScaleX->setScaleX(2.0f);
        dirs->addChild(newSpriteScaleX,1);
        
        auto pointX = Sprite::create("dot.png");
        pointX->setName("pointX");
        pointX->setPosition(newSpriteScaleX->getPosition());
        dirs->addChild(pointX,2);
        
        auto newSpriteScaleY = Sprite::create("Blue_Front1.png");
        newSpriteScaleY->setPosition(800, 256);
        newSpriteScaleY->setName("sprite8");
        newSpriteScaleY->setAnchorPoint(Vec2(0.5,0.5));
        newSpriteScaleY->setScaleY(2.0f);
        dirs->addChild(newSpriteScaleY,1);
        
        auto pointY = Sprite::create("dot.png");
        pointY->setName("pointY");
        pointY->setPosition(newSpriteScaleY->getPosition());
        dirs->addChild(pointY,2);
        
        auto anode = dirs->getChildByName("menuNode");
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
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite5");
        dirs->removeChildByName("sprite6");
        dirs->removeChildByName("sprite7");
        dirs->removeChildByName("sprite8");
        dirs->removeChildByName("point00");
        dirs->removeChildByName("pointXY");
        dirs->removeChildByName("pointX");
        dirs->removeChildByName("pointY");

        
        auto newSprite00 = Sprite::create("Blue_Front1.png");
        newSprite00->setPosition(100, 256);
        newSprite00->setName("sprite9");
        newSprite00->setAnchorPoint(Vec2(0,0));
        dirs->addChild(newSprite00,1);
        
        auto point00 = Sprite::create("dot.png");
        point00->setName("point00");
        point00->setPosition(newSprite00->getPosition());
        dirs->addChild(point00,2);
        
        auto newSprite01 = Sprite::create("Blue_Front1.png");
        newSprite01->setPosition(250, 256);
        newSprite01->setName("sprite10");
        newSprite01->setAnchorPoint(Vec2(0,1));
        dirs->addChild(newSprite01,1);
        
        auto point01 = Sprite::create("dot.png");
        point01->setName("point01");
        point01->setPosition(newSprite01->getPosition());
        dirs->addChild(point01,2);
        
        auto newSprite10 = Sprite::create("Blue_Front1.png");
        newSprite10->setPosition(400, 256);
        newSprite10->setName("sprite11");
        newSprite10->setAnchorPoint(Vec2(1,0));
        dirs->addChild(newSprite10,1);
        
        auto point10 = Sprite::create("dot.png");
        point10->setName("point10");
        point10->setPosition(newSprite10->getPosition());
        dirs->addChild(point10,2);
        
        auto newSprite11 = Sprite::create("Blue_Front1.png");
        newSprite11->setPosition(550, 256);
        newSprite11->setName("sprite12");
        newSprite11->setAnchorPoint(Vec2(1,1));
        dirs->addChild(newSprite11,1);
        
        auto point11 = Sprite::create("dot.png");
        point11->setName("point11");
        point11->setPosition(newSprite11->getPosition());
        dirs->addChild(point11,2);
        
        auto newSprite22 = Sprite::create("Blue_Front1.png");
        newSprite22->setPosition(700, 256);
        newSprite22->setName("sprite13");
        newSprite22->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite22,1);
        
        auto point22 = Sprite::create("dot.png");
        point22->setName("point22");
        point22->setPosition(newSprite22->getPosition());
        dirs->addChild(point22,2);
        
        auto anode = dirs->getChildByName("menuNode");
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
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite9");
        dirs->removeChildByName("sprite10");
        dirs->removeChildByName("sprite11");
        dirs->removeChildByName("sprite12");
        dirs->removeChildByName("sprite13");
        dirs->removeChildByName("point00");
        dirs->removeChildByName("point01");
        dirs->removeChildByName("point10");
        dirs->removeChildByName("point11");
        dirs->removeChildByName("point22");
        
        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 256);
        newSprite->setName("sprite14");
        newSprite->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite,1);
        
        auto pointN = Sprite::create("dot.png");
        pointN->setName("pointN");
        pointN->setPosition(newSprite->getPosition());
        dirs->addChild(pointN,2);
        
        auto newSpriteSkewX = Sprite::create("Blue_Front1.png");
        newSpriteSkewX->setPosition(250, 256);
        newSpriteSkewX->setName("sprite15");
        newSpriteSkewX->setAnchorPoint(Vec2(0.5,0.5));
        newSpriteSkewX->setSkewX(20.0f);
        dirs->addChild(newSpriteSkewX,1);
        
        auto pointX = Sprite::create("dot.png");
        pointX->setName("pointX");
        pointX->setPosition(newSpriteSkewX->getPosition());
        dirs->addChild(pointX,2);
        
        auto newSpriteSkewY = Sprite::create("Blue_Front1.png");
        newSpriteSkewY->setPosition(400, 256);
        newSpriteSkewY->setName("sprite16");
        newSpriteSkewY->setAnchorPoint(Vec2(0.5,0.5));
        newSpriteSkewY->setSkewY(20.0f);
        dirs->addChild(newSpriteSkewY,1);
        
        auto pointY = Sprite::create("dot.png");
        pointY->setName("pointY");
        pointY->setPosition(newSpriteSkewY->getPosition());
        dirs->addChild(pointY,2);
        
        auto anode = dirs->getChildByName("menuNode");
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
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite14");
        dirs->removeChildByName("sprite15");
        dirs->removeChildByName("sprite16");
        dirs->removeChildByName("pointN");
        dirs->removeChildByName("pointX");
        dirs->removeChildByName("pointY");
        
        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 256);
        newSprite->setName("sprite17");
        newSprite->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite,1);
        
        auto point00 = Sprite::create("dot.png");
        point00->setName("point00");
        point00->setPosition(newSprite->getPosition());
        dirs->addChild(point00,2);
        
        auto newSpriteRotateP20 = Sprite::create("Blue_Front1.png");
        newSpriteRotateP20->setPosition(250, 256);
        newSpriteRotateP20->setName("sprite18");
        newSpriteRotateP20->setAnchorPoint(Vec2(0.5,0.5));
        newSpriteRotateP20->setRotation(20.0f);
        dirs->addChild(newSpriteRotateP20,1);
        
        auto pointP20 = Sprite::create("dot.png");
        pointP20->setName("pointP20");
        pointP20->setPosition(newSpriteRotateP20->getPosition());
        dirs->addChild(pointP20,2);
        
        auto newSpriteRotateN20 = Sprite::create("Blue_Front1.png");
        newSpriteRotateN20->setPosition(400, 256);
        newSpriteRotateN20->setName("sprite19");
        newSpriteRotateN20->setAnchorPoint(Vec2(0.5,0.5));
        newSpriteRotateN20->setRotation(-20.0f);
        dirs->addChild(newSpriteRotateN20,1);
        
        auto pointN20 = Sprite::create("dot.png");
        pointN20->setName("pointN20");
        pointN20->setPosition(newSpriteRotateN20->getPosition());
        dirs->addChild(pointN20,2);
        
        auto newSpriteRotateP60 = Sprite::create("Blue_Front1.png");
        newSpriteRotateP60->setPosition(550, 256);
        newSpriteRotateP60->setName("sprite20");
        newSpriteRotateP60->setAnchorPoint(Vec2(0.5,0.5));
        newSpriteRotateP60->setRotation(60.0f);
        dirs->addChild(newSpriteRotateP60,1);
        
        auto pointP60 = Sprite::create("dot.png");
        pointP60->setName("pointP60");
        pointP60->setPosition(newSpriteRotateP60->getPosition());
        dirs->addChild(pointP60,2);
        
        auto newSpriteRotateN60 = Sprite::create("Blue_Front1.png");
        newSpriteRotateN60->setPosition(700, 256);
        newSpriteRotateN60->setName("sprite21");
        newSpriteRotateN60->setAnchorPoint(Vec2(0.5,0.5));
        newSpriteRotateN60->setRotation(-60.0f);
        dirs->addChild(newSpriteRotateN60,1);
        
        auto pointN60 = Sprite::create("dot.png");
        pointN60->setName("pointN60");
        pointN60->setPosition(newSpriteRotateN60->getPosition());
        dirs->addChild(pointN60,2);
        
        auto anode = dirs->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem8");
        cnode->setVisible(false);
        auto dnode = bnode->getChildByName("menuItem9");
        dnode->setVisible(true);
    });
    
    auto menuItem9 = MenuItemFont::create("Next: Change the Color of a Sprite");
    menuItem9->setFontNameObj("Marker Felt.ttf");
    menuItem9->setFontSizeObj(32);
    menuItem9->setName("menuItem9");
    menuItem9->setVisible(false);
    menuItem9->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem9->setCallback([&](cocos2d::Ref *sender) {
        // hide everything else on the screen
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite18");
        dirs->removeChildByName("sprite19");
        dirs->removeChildByName("sprite20");
        dirs->removeChildByName("sprite21");
        dirs->removeChildByName("point00");
        dirs->removeChildByName("pointP20");
        dirs->removeChildByName("pointN20");
        dirs->removeChildByName("pointP60");
        dirs->removeChildByName("pointN60");
        
        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 256);
        newSprite->setName("sprite30");
        newSprite->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite,1);
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(200, 256);
        newSprite2->setName("sprite31");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        newSprite2->setColor(Color3B(155, 200, 50));
        dirs->addChild(newSprite2,1);
        
        auto newSprite3 = Sprite::create("Blue_Front1.png");
        newSprite3->setPosition(300, 256);
        newSprite3->setName("sprite32");
        newSprite3->setAnchorPoint(Vec2(0.5,0.5));
        newSprite3->setColor(Color3B(10, 230, 100));
        dirs->addChild(newSprite3,1);
        
        auto newSprite4 = Sprite::create("Blue_Front1.png");
        newSprite4->setPosition(400, 256);
        newSprite4->setName("sprite33");
        newSprite4->setAnchorPoint(Vec2(0.5,0.5));
        newSprite4->setColor(Color3B(100, 101, 230));
        dirs->addChild(newSprite4,1);
        
        auto anode = dirs->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem9");
        cnode->setVisible(false);
        auto dnode = bnode->getChildByName("menuItem10");
        dnode->setVisible(true);
    });
    
    auto menuItem10 = MenuItemFont::create("Next: Change the Color of a Sprite");
    menuItem10->setFontNameObj("Marker Felt.ttf");
    menuItem10->setFontSizeObj(32);
    menuItem10->setName("menuItem10");
    menuItem10->setVisible(false);
    menuItem10->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem10->setCallback([&](cocos2d::Ref *sender) {
        // hide everything else on the screen
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite30");
        dirs->removeChildByName("sprite31");
        dirs->removeChildByName("sprite32");
        dirs->removeChildByName("sprite33");
        
        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 256);
        newSprite->setName("sprite34");
        newSprite->setAnchorPoint(Vec2(0.5,0.5));
        newSprite->setOpacity(0.0f);
        dirs->addChild(newSprite,1);
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(200, 256);
        newSprite2->setName("sprite35");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        newSprite2->setOpacity(99);
        dirs->addChild(newSprite2,1);
        
        auto newSprite3 = Sprite::create("Blue_Front1.png");
        newSprite3->setPosition(300, 256);
        newSprite3->setName("sprite36");
        newSprite3->setAnchorPoint(Vec2(0.5,0.5));
        newSprite3->setOpacity(89);
        dirs->addChild(newSprite3,1);
        
        auto newSprite4 = Sprite::create("Blue_Front1.png");
        newSprite4->setPosition(400, 256);
        newSprite4->setName("sprite37");
        
        newSprite4->setAnchorPoint(Vec2(0.5,0.5));
        newSprite4->setOpacity(79);
        dirs->addChild(newSprite4,1);
        
        auto anode = dirs->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem10");
        cnode->setVisible(false);
        //auto dnode = bnode->getChildByName("menuItem10");
        //dnode->setVisible(true);
    });

    auto menu = Menu::create(menuItem1, menuItem2, menuItem3, menuItem4, menuItem5, menuItem6,
                             menuItem7, menuItem8, menuItem9, menuItem10, NULL);
    menu->setName("menu");
    menuNode->addChild(menu, 1);
    menu->setPosition(Vec2::ZERO);
    
    scene->addChild(menuNode, 2);
    
    // return the scene
    return scene;
}
