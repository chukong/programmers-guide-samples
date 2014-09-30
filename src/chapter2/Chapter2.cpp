#include "Chapter2.h"

#include "Chapter2Level1.h"

USING_NS_CC;

Scene* Chapter2::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Chapter2::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Chapter2::init()
{
    //////////////////////////////
    // 1. super init first
    //if ( !LayerColor::initWithColor(Color4B(176, 224, 230, 176)))
    if (!Node::init())
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size playingSize; // actual playing size to work with
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    //auto closeItem = MenuItemImage::create(
    //                                       "CloseNormal.png",
    //                                       "CloseSelected.png",
    //                                       CC_CALLBACK_1(Chapter2::menuCloseCallback, this));
    
	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
    //                            origin.y + closeItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    //auto menu = Menu::create(closeItem, NULL);
    //menu->setPosition(Vec2::ZERO);
    //this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // layout the bottom where the character will walk
    createWalkingPath(visibleSize, playingSize);
    
    // add the main character to the screen
    createSpriteCharacter(visibleSize, playingSize);
    
    // add some block to the screen
    createBlocks(visibleSize, playingSize);
    
    // add a title block
    createTitle(visibleSize, playingSize);
    
    // add the player 1 and 2 labels
    createPlayerLabels(visibleSize, playingSize);
    
    // add the menu
    createMenu(visibleSize, playingSize);
    
    return true;
}

void Chapter2::createMenu(const Size& _visibleSize, const Size& _playingSize)
{
    auto menuItem1 = MenuItemFont::create("Start Game", CC_CALLBACK_1(Chapter2::menuPlayCallback, this));
    menuItem1->setFontNameObj("Marker Felt.ttf");
    menuItem1->setFontSizeObj(64);
    
    auto menu = Menu::create(menuItem1, NULL);
    
    this->addChild(menu, 3);
}

void Chapter2::menuPlayCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(Chapter2Level1::createScene());
}

void Chapter2::createPlayerLabels(const Size& _visibleSize, const Size& _playingSize)
{
    int paddingX = 20;
    int paddingY = 20;
    
    auto player1 = Label::createWithTTF("Player 1", "Marker Felt.ttf", 32);
    auto player2 = Label::createWithTTF("Player 2", "Marker Felt.ttf", 32);
    
    auto player1Score = Label::createWithTTF("00000", "Marker Felt.ttf", 32);
    auto player2Score = Label::createWithTTF("00000", "Marker Felt.ttf", 32);
    
    this->addChild(player1, 2);
    this->addChild(player2, 2);
    this->addChild(player1Score, 2);
    this->addChild(player2Score, 2);
    
    player1->setPosition(Vec2(0 + player1->getContentSize().width / 2 + paddingX,
                              _visibleSize.height - player1->getContentSize().height / 2 - paddingY));
    
    player1Score->setPosition(Vec2(0 + player1->getPositionX() + player1->getContentSize().width + paddingX,
                                   _visibleSize.height - player1->getContentSize().height / 2 - paddingY));
    
    player2Score->setPosition(Vec2(_visibleSize.width - player2Score->getContentSize().width / 2 - paddingX,
                                   _visibleSize.height - player2Score->getContentSize().height / 2 - paddingY));
    
    player2->setPosition(Vec2(player2Score->getPositionX() - player2Score->getContentSize().width - paddingX,
                              _visibleSize.height - player2Score->getContentSize().height / 2 - paddingY));
}

void Chapter2::createTitle(const Size& _visibleSize, const Size& _playingSize)
{
    auto white = Color4F(1.0f, 0.5f, 0.3f, 1);
    
    int verts = 4;
    
    cocos2d::Point stripe1[] = {
        cocos2d::Point(0,0),
        cocos2d::Point(0,200),
        cocos2d::Point(600,200),
        cocos2d::Point(600,0)
    };
    
    cocos2d::DrawNode* dotNode1 = cocos2d::DrawNode::create();
    dotNode1->setContentSize(Size(600, 200));
    dotNode1->drawPolygon(stripe1, verts, white, 0, white);
    dotNode1->setPosition(Vec2(_visibleSize.width/2 - (dotNode1->getContentSize().width / 2),
                               _playingSize.height - dotNode1->getContentSize().height));
    this->addChild(dotNode1, 1);
    
    
    auto label = Label::createWithTTF("Super Cocos Aliens", "Marker Felt.ttf", 64);
    dotNode1->addChild(label, 2);
    label->setPosition(Vec2(dotNode1->getContentSize().width/2, dotNode1->getContentSize().height/2));
}

void Chapter2::createBlocks(const Size& _visibleSize, const Size& _playingSize)
{
    auto testSprite = Sprite::create("ZigzagGrass_Mud_Round.png");
    
    int sX = _visibleSize.width/2 - testSprite->getContentSize().width;
    int sY = _playingSize.height/2 - testSprite->getContentSize().height * 2;
    
    for (int i=0; i < 5; i++)
    {
        auto sprite = Sprite::create("ZigzagGrass_Mud_Round.png");
        sprite->setAnchorPoint(Vec2(0,0));
        sprite->setPosition(sX,sY);
        
        sX += sprite->getContentSize().width;
        
        this->addChild(sprite,1);
    }
    
    testSprite = NULL;
}

void Chapter2::createSpriteCharacter(const Size& _visibleSize, const Size& _playingSize)
{
    auto sprite1 = Sprite::create("Blue_Front1.png");
    sprite1->setAnchorPoint(Vec2(0,0));
    sprite1->setPosition(100, (_visibleSize.height - _playingSize.height));
    this->addChild(sprite1, 1);
    
    auto sprite2 = Sprite::create("LightBlue_Front1.png");
    sprite2->setAnchorPoint(Vec2(0,0));
    sprite2->setPosition(500, (_visibleSize.height - _playingSize.height));
    this->addChild(sprite2, 1);
    
    auto sprite3 = Sprite::create("White_Front1.png");
    sprite3->setAnchorPoint(Vec2(0,0));
    sprite3->setPosition(800, (_visibleSize.height - _playingSize.height));
    this->addChild(sprite3, 1);
}

void Chapter2::createWalkingPath(const Size& _visibleSize, Size& _playingSize)
{
    // depending upon how large the screen is we need to decide how many blocks to lay down.
    
    auto testSprite = Sprite::create("ZigzagForest_Square.png");
    
    int howMany = std::ceil(_visibleSize.width / testSprite->getContentSize().width);
    
    int sX = 0;
    int sY = 0;
    
    _playingSize = Size(_visibleSize.width, _visibleSize.height - testSprite->getContentSize().height);
    
    for (int i=0; i < howMany; i++)
    {
        auto sprite = Sprite::create("ZigzagForest_Square.png");
        sprite->setAnchorPoint(Vec2(0,0));
        sprite->setPosition(sX,sY);
        
        sX += sprite->getContentSize().width;
        
        this->addChild(sprite,1);
    }
    
    testSprite = NULL;
}

void Chapter2::onMenuCloseCallback(Ref* pSender)
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
