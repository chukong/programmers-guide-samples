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
    // create the player and score labels
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int paddingX = 20;
    int paddingY = 20;
    
    auto player1 = Label::createWithTTF("Player 1", "Marker Felt.ttf", 32);
    auto player2 = Label::createWithTTF("Player 2", "Marker Felt.ttf", 32);
    
    auto player1Score = Label::createWithTTF("00000", "Marker Felt.ttf", 32);
    auto player2Score = Label::createWithTTF("00000", "Marker Felt.ttf", 32);
    
    scene->addChild(player1, -1);
    scene->addChild(player2, -1);
    scene->addChild(player1Score, -1);
    scene->addChild(player2Score, -1);
    
    player1->setPosition(Vec2(0 + player1->getContentSize().width / 2 + paddingX,
                              visibleSize.height - player1->getContentSize().height / 2 - paddingY));
    
    player1Score->setPosition(Vec2(0 + player1->getPositionX() + player1->getContentSize().width + paddingX,
                                   visibleSize.height - player1->getContentSize().height / 2 - paddingY));
    
    player2Score->setPosition(Vec2(visibleSize.width - player2Score->getContentSize().width / 2 - paddingX,
                                   visibleSize.height - player2Score->getContentSize().height / 2 - paddingY));
    
    player2->setPosition(Vec2(player2Score->getPositionX() - player2Score->getContentSize().width - paddingX,
                              visibleSize.height - player2Score->getContentSize().height / 2 - paddingY));
    
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
        
        scene->addChild(sprite, 1);
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
        
        scene->addChild(sprite,1);
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
        
        scene->addChild(sprite,1);
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
        
        scene->addChild(sprite,1);
    }
    
    testSprite = NULL;
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a sprite
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto sprite1 = Sprite::create("Blue_Front1.png");
    sprite1->setAnchorPoint(Vec2(0,0));
    sprite1->setPosition(100, (visibleSize.height - playingSize.height));
    sprite1->setName("mainSprite");
    
    // schedule doesn't support lambda's, file a bug
    
    sprite1->scheduleOnce(schedule_selector(Chapter2Level1::moveSprite()), 5);
    
    scene->addChild(sprite1, 1);

    // return the scene
    return scene;
}

void Chapter2Level1::moveSprite(float dt)
{
    // Move a sprite 400 pixels to the right, over 2 seconds.
    auto moveBy = MoveBy::create(2, Point(400,0));
    
    sprite1->runAction(moveBy);

    //this->setRotation(40);

    //this->setScale(2.0);
}

// on "init" you need to initialize your instance
//bool Chapter2Level1::init()
//{
    //////////////////////////////
    // 1. super init first
    //if ( !LayerColor::initWithColor(Color4B(176, 224, 230, 176)))
    //if (!Node::init())
    //{
    //    return false;
    //}
    
    //Size visibleSize = Director::getInstance()->getVisibleSize();
    //Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //Size playingSize; // actual playing size to work with
    
    
    // layout the bottom where the character will walk
    //createWalkingPath(visibleSize, playingSize);
    
    // add the main character to the screen
    //createSpriteCharacter(visibleSize, playingSize);
    
    // add some block to the screen
    //createBlocks(visibleSize, playingSize);
    
    // add the player 1 and 2 labels
    //createPlayerLabels(visibleSize, playingSize);
    
    //return true;
//}

//void Chapter2Level1::createPlayerLabels(const Size& _visibleSize, const Size& _playingSize)
//{
//    int paddingX = 20;
//    int paddingY = 20;
//    
//    auto player1 = Label::createWithTTF("Player 1", "Marker Felt.ttf", 32);
//    auto player2 = Label::createWithTTF("Player 2", "Marker Felt.ttf", 32);
//    
//    auto player1Score = Label::createWithTTF("00000", "Marker Felt.ttf", 32);
//    auto player2Score = Label::createWithTTF("00000", "Marker Felt.ttf", 32);
//    
//    this->addChild(player1, 2);
//    this->addChild(player2, 2);
//    this->addChild(player1Score, 2);
//    this->addChild(player2Score, 2);
//    
//    player1->setPosition(Vec2(0 + player1->getContentSize().width / 2 + paddingX,
//                              _visibleSize.height - player1->getContentSize().height / 2 - paddingY));
//    
//    player1Score->setPosition(Vec2(0 + player1->getPositionX() + player1->getContentSize().width + paddingX,
//                                   _visibleSize.height - player1->getContentSize().height / 2 - paddingY));
//    
//    player2Score->setPosition(Vec2(_visibleSize.width - player2Score->getContentSize().width / 2 - paddingX,
//                                   _visibleSize.height - player2Score->getContentSize().height / 2 - paddingY));
//    
//    player2->setPosition(Vec2(player2Score->getPositionX() - player2Score->getContentSize().width - paddingX,
//                              _visibleSize.height - player2Score->getContentSize().height / 2 - paddingY));
//}

//void Chapter2Level1::createBlocks(const Size& _visibleSize, const Size& _playingSize)
//{
//    auto testSprite = Sprite::create("ZigzagGrass_Mud_Round.png");
//    
//    
//    // left side blocks
//    int sX = _visibleSize.width/4 - testSprite->getContentSize().width;
//    int sY = _playingSize.height/2 - testSprite->getContentSize().height * 2;
//    
//    for (int i=0; i < 3; i++)
//    {
//        auto sprite = Sprite::create("ZigzagGrass_Mud_Round.png");
//        sprite->setAnchorPoint(Vec2(0,0));
//        sprite->setPosition(sX,sY);
//        
//        sX += sprite->getContentSize().width;
//        
//        this->addChild(sprite,1);
//    }
//    
//    // right side blocks
//    sX = (_visibleSize.width/2 + _visibleSize.width/4) - testSprite->getContentSize().width;
//    sY = _playingSize.height/2 - testSprite->getContentSize().height * 2;
//    
//    for (int i=0; i < 3; i++)
//    {
//        auto sprite = Sprite::create("ZigzagGrass_Mud_Round.png");
//        sprite->setAnchorPoint(Vec2(0,0));
//        sprite->setPosition(sX,sY);
//        
//        sX += sprite->getContentSize().width;
//        
//        this->addChild(sprite,1);
//    }
//    
//    // center blocks
//    sX = _visibleSize.width/2 - testSprite->getContentSize().width;
//    sY = (_playingSize.height/2 + _playingSize.height/4) - testSprite->getContentSize().height * 2;
//    
//    for (int i=0; i < 3; i++)
//    {
//        auto sprite = Sprite::create("ZigzagGrass_Mud_Round.png");
//        sprite->setAnchorPoint(Vec2(0,0));
//        sprite->setPosition(sX,sY);
//        
//        sX += sprite->getContentSize().width;
//        
//        this->addChild(sprite,1);
//    }
//    
//    testSprite = NULL;
//}

//void Chapter2Level1::createSpriteCharacter(const Size& _visibleSize, const Size& _playingSize)
//{
//    sprite1 = Sprite::create("Blue_Front1.png");
//    sprite1->setAnchorPoint(Vec2(0,0));
//    sprite1->setPosition(100, (_visibleSize.height - _playingSize.height));
//    
//    sprite1->scheduleOnce(schedule_selector(Chapter2Level1::moveSprite), 5);
//    
//    this->addChild(sprite1, 1);
//}



//void Chapter2Level1::createWalkingPath(const Size& _visibleSize, Size& _playingSize)
//{
//    // depending upon how large the screen is we need to decide how many blocks to lay down.
//    
//    auto testSprite = Sprite::create("ZigzagForest_Square.png");
//    
//    int howMany = std::ceil(_visibleSize.width / testSprite->getContentSize().width);
//    
//    int sX = 0;
//    int sY = 0;
//    
//    _playingSize = Size(_visibleSize.width, _visibleSize.height - testSprite->getContentSize().height);
//    
//    for (int i=0; i < howMany; i++)
//    {
//        auto sprite = Sprite::create("ZigzagForest_Square.png");
//        sprite->setAnchorPoint(Vec2(0,0));
//        sprite->setPosition(sX,sY);
//        
//        sX += sprite->getContentSize().width;
//        
//        this->addChild(sprite,1);
//    }
//    
//    testSprite = NULL;
//}
//
//void Chapter2Level1::onMenuCloseCallback(Ref* pSender)
//{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//    return;
//#endif
//    
//    Director::getInstance()->end();
//    
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}
