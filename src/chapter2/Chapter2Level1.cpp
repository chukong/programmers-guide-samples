#include "Chapter2Level1.h"

USING_NS_CC;

Scene* Chapter2Level1::createScene()
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
    // create a node to hold all of the labels
    // create the player and score labels
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int paddingX = 20;
    int paddingY = 20;
    
    auto labelNode = Node::create();
    
    auto player1 = Label::createWithTTF("Player 1", "Marker Felt.ttf", 32);
    auto player2 = Label::createWithTTF("Player 2", "Marker Felt.ttf", 32);
    
    auto player1Score = Label::createWithTTF("00000", "Marker Felt.ttf", 32);
    auto player2Score = Label::createWithTTF("00000", "Marker Felt.ttf", 32);
    
    labelNode->addChild(player1, -2);
    labelNode->addChild(player1Score, -1);
    labelNode->addChild(player2, 1);
    labelNode->addChild(player2Score, 2);
    
    player1->setPosition(Vec2(0 + player1->getContentSize().width / 2 + paddingX,
                              visibleSize.height - player1->getContentSize().height / 2 - paddingY));
    
    player1Score->setPosition(Vec2(0 + player1->getPositionX() + player1->getContentSize().width + paddingX,
                                   visibleSize.height - player1->getContentSize().height / 2 - paddingY));
    
    player2Score->setPosition(Vec2(visibleSize.width - player2Score->getContentSize().width / 2 - paddingX,
                                   visibleSize.height - player2Score->getContentSize().height / 2 - paddingY));
    
    player2->setPosition(Vec2(player2Score->getPositionX() - player2Score->getContentSize().width - paddingX,
                              visibleSize.height - player2Score->getContentSize().height / 2 - paddingY));
    
    scene->addChild(labelNode, 0);
    
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
    
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a few blocks as obstables
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    testSprite = Sprite::create("ZigzagGrass_Mud_Round.png");
    
    // left side blocks
    sX = visibleSize.width/4 - testSprite->getContentSize().width;
    sY = playingSize.height/2 - testSprite->getContentSize().height * 2;
    
    for (int i=0; i < 3; i++)
    {
        auto sprite = Sprite::create("ZigzagGrass_Mud_Round.png");
        sprite->setAnchorPoint(Vec2(0,0));
        sprite->setPosition(sX,sY);
        
        sX += sprite->getContentSize().width;
        
        if (i == 1)
        {
            sprite->setName("middleBlock1");
        }
        
        nodeItems->addChild(sprite, 1);
    }
    
    // right side blocks
    sX = (visibleSize.width/2 + visibleSize.width/4) - testSprite->getContentSize().width;
    sY = playingSize.height/2 - testSprite->getContentSize().height * 2;
    
    for (int i=0; i < 3; i++)
    {
        auto sprite = Sprite::create("ZigzagGrass_Mud_Round.png");
        sprite->setAnchorPoint(Vec2(0,0));
        sprite->setPosition(sX,sY);
        
        sX += sprite->getContentSize().width;
        
        if (i == 1)
        {
            sprite->setName("middleBlock2");
        }
        
        scene->addChild(sprite, 1);
    }
    
    // center blocks
    sX = visibleSize.width/2 - testSprite->getContentSize().width;
    sY = (playingSize.height/2 + playingSize.height/4) - testSprite->getContentSize().height * 2;
    
    for (int i=0; i < 3; i++)
    {
        auto sprite = Sprite::create("ZigzagGrass_Mud_Round.png");
        sprite->setAnchorPoint(Vec2(0,0));
        sprite->setPosition(sX,sY);
        
        sX += sprite->getContentSize().width;
        
        nodeItems->addChild(sprite, 1);
    }
    
    testSprite = NULL;
    
    scene->addChild(nodeItems, 1);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a node to hold sprites
    // create a sprite
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto spriteNode = Node::create();
    spriteNode->setName("spriteNode");
    
    auto sprite1 = Sprite::create("Blue_Front1.png");
    sprite1->setAnchorPoint(Vec2(0,0));
    sprite1->setPosition(100, (visibleSize.height - playingSize.height));
    sprite1->setName("mainSprite");
    
    spriteNode->addChild(sprite1, 1);
    
    scene->addChild(spriteNode, 1);
    
    //sprite1->scheduleOnce([&](float dt) {
    //    // the local variable "sprite1" will go out of scope, so I have to get it from "this"
    //    auto anode = Director::getInstance()->getRunningScene()->getChildByName("spriteNode");
    //    auto bnode = anode->getChildByName("mainSprite");
    //
    //    //auto moveBy = MoveBy::create(2, Point(400,0));
    //
    //    //bnode->runAction(moveBy);
    //}, 5, "udpate_key");
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a node to hold menu
    // create a menu
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto menuNode = Node::create();
    menuNode->setName("menuNode");
    
    auto menuItem1 = MenuItemFont::create("Demo Parent/Child");
    menuItem1->setFontNameObj("Marker Felt.ttf");
    menuItem1->setFontSizeObj(32);
    
    menuItem1->setCallback([&](cocos2d::Ref *sender) {
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("spriteNode");
        auto bnode = anode->getChildByName("mainSprite");
        
        auto cnode = Director::getInstance()->getRunningScene()->getChildByName("nodeItems");
        auto dnode = cnode->getChildByName("middleBlock1");
        
        // add a few more sprites
        auto sprite1 = Sprite::create("LightBlue_Front1.png");
        sprite1->setAnchorPoint(Vec2(0,0));
        sprite1->setName("childSprite1");
        
        bnode->addChild(sprite1, 1);

        sprite1->setPosition(dnode->getPositionX(), dnode->getPositionY());
        
        auto sprite2 = Sprite::create("White_Front1.png");
        sprite2->setAnchorPoint(Vec2(0,0));
        sprite2->setName("childSprite2");
        
        bnode->addChild(sprite2, 1);
        
        sprite2->setPosition(dnode->getPositionX() - dnode->getContentSize().width * 3, dnode->getPositionY());
        
        // hide the menu option
        auto ynode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto znode = ynode->getChildByName("menu");
        znode->removeFromParentAndCleanup(true);
        
        // schedule an action after 3 seconds
        bnode->scheduleOnce([&](float dt) {
            auto anode = Director::getInstance()->getRunningScene()->getChildByName("spriteNode");
            auto bnode = anode->getChildByName("mainSprite");
            
            bnode->setRotation(40.0f);
            
            auto delay = DelayTime::create(4.0f);
            bnode->runAction(delay);
            
            bnode->setScale(2.0f);
            
            // You could also use an Action and Sequence combination to do this.
            //auto rotateBy = RotateBy::create(2, 40.0f);
            //auto scaleBy = ScaleTo::create(2, 2.0f);
        
            //auto seq = Sequence::create(rotateBy, scaleBy, NULL);
            
            //bnode->runAction(seq);
            
        }, 3, "udpate_key");
    });

    auto menu = Menu::create(menuItem1, NULL);
    menu->setName("menu");
    menuNode->addChild(menu, 1);
    menu->setPosition(visibleSize.width / 2, visibleSize.height - menuItem1->getContentSize().height * 2);
    
    scene->addChild(menuNode, 2);
    
    // return the scene
    return scene;
}
