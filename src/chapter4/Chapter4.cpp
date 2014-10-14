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
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 64);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite2,1);
        
        auto anode = Director::getInstance()->getRunningScene()->getChildByName("menuNode");
        auto bnode = anode->getChildByName("menu");
        auto cnode = bnode->getChildByName("menuItem1");
        cnode->setVisible(false);
        cnode = bnode->getChildByName("menuItem2");
        cnode->setVisible(true);
        cnode = bnode->getChildByName("menuItem3");
        cnode->setVisible(true);
        cnode = bnode->getChildByName("menuItem4");
        cnode->setVisible(true);
        cnode = bnode->getChildByName("menuItem5");
        cnode->setVisible(true);
        cnode = bnode->getChildByName("menuItem6");
        cnode->setVisible(true);
        cnode = bnode->getChildByName("menuItem7");
        cnode->setVisible(true);
        cnode = bnode->getChildByName("menuItem8");
        cnode->setVisible(true);
        cnode = bnode->getChildByName("menuItem9");
        cnode->setVisible(true);
    });
    
    auto menuItem2 = MenuItemFont::create("MoveTo");
    menuItem2->setFontNameObj("Marker Felt.ttf");
    menuItem2->setFontSizeObj(32);
    menuItem2->setName("menuItem2");
    menuItem2->setVisible(false);
    menuItem2->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem2->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->getRunningScene()->removeChildByName("sprite2"); // the old one
        Director::getInstance()->getRunningScene()->removeChildByName("sprite3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 64);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite2,1);
        
        auto moveTo = MoveTo::create(2, Point(300, 64));
        newSprite2->runAction(moveTo);
    });
    
    auto menuItem3 = MenuItemFont::create("FadeTo");
    menuItem3->setFontNameObj("Marker Felt.ttf");
    menuItem3->setFontSizeObj(32);
    menuItem3->setName("menuItem3");
    menuItem3->setVisible(false);
    menuItem3->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem3->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->getRunningScene()->removeChildByName("sprite2"); // the old one
        Director::getInstance()->getRunningScene()->removeChildByName("sprite3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 64);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite2,1);
        
        auto moveTo = MoveTo::create(2, Point(300, 64));
        newSprite2->runAction(moveTo);
        
        //auto fadeIn = FadeIn::create(200.0f);
        //anode->runAction(fadeIn);
        
        auto fadeTo = FadeTo::create(2.0f, 120.0f);
        newSprite2->runAction(fadeTo);
    });
    
    auto menuItem4 = MenuItemFont::create("RotateTo");
    menuItem4->setFontNameObj("Marker Felt.ttf");
    menuItem4->setFontSizeObj(32);
    menuItem4->setName("menuItem4");
    menuItem4->setVisible(false);
    menuItem4->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem4->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->getRunningScene()->removeChildByName("sprite2"); // the old one
        Director::getInstance()->getRunningScene()->removeChildByName("sprite3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 64);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite2,1);
        
        auto moveTo = MoveTo::create(2, Point(300, 64));
        newSprite2->runAction(moveTo);
    
        auto rotateTo = RotateTo::create(2.0f, 40.0f);
        newSprite2->runAction(rotateTo);
    });
    
    auto menuItem5 = MenuItemFont::create("ScaleTo");
    menuItem5->setFontNameObj("Marker Felt.ttf");
    menuItem5->setFontSizeObj(32);
    menuItem5->setName("menuItem5");
    menuItem5->setVisible(false);
    menuItem5->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem5->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->getRunningScene()->removeChildByName("sprite2"); // the old one
        Director::getInstance()->getRunningScene()->removeChildByName("sprite3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 64);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite2,1);
        
        auto moveTo = MoveTo::create(2, Point(300, 64));
        newSprite2->runAction(moveTo);
        
        auto scaleTo = ScaleTo::create(2.0f, 3.0f);
        newSprite2->runAction(scaleTo);
    });
    
    auto menuItem6 = MenuItemFont::create("TintTo");
    menuItem6->setFontNameObj("Marker Felt.ttf");
    menuItem6->setFontSizeObj(32);
    menuItem6->setName("menuItem6");
    menuItem6->setVisible(false);
    menuItem6->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem6->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->getRunningScene()->removeChildByName("sprite2"); // the old one
        Director::getInstance()->getRunningScene()->removeChildByName("sprite3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 64);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite2,1);
        
        auto moveTo = MoveTo::create(2, Point(300, 64));
        newSprite2->runAction(moveTo);
        
        auto tintTo = TintTo::create(2.0f, 120.0f, 232.0f, 254.0f);
        newSprite2->runAction(tintTo);
    });
    
    auto menuItem7 = MenuItemFont::create("Ease");
    menuItem7->setFontNameObj("Marker Felt.ttf");
    menuItem7->setFontSizeObj(32);
    menuItem7->setName("menuItem7");
    menuItem7->setVisible(false);
    menuItem7->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem7->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->getRunningScene()->removeChildByName("sprite2"); // the old one
        Director::getInstance()->getRunningScene()->removeChildByName("sprite3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 64);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite2,1);
        
        auto newSprite3 = Sprite::create("White_Front1.png");
        newSprite3->setPosition(100, 64);
        newSprite3->setName("sprite3");
        newSprite3->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite3,1);
        
        auto move = MoveBy::create(2, Point(700, 64));
        auto move_back = move->reverse();
        
        auto move_ease_in = EaseBounceIn::create(move->clone() );
        auto move_ease_in_back = move_ease_in->reverse();
        
        auto move_ease_out = EaseBounceOut::create(move->clone() );
        auto move_ease_out_back = move_ease_out->reverse();
        
        auto delay = DelayTime::create(0.25f);
        
        auto seq1 = Sequence::create(move, delay, move_back, delay->clone(), nullptr);
        auto seq2 = Sequence::create(move_ease_in, delay->clone(), move_ease_in_back, delay->clone(), nullptr);
        
        newSprite2->runAction(RepeatForever::create(seq1));
        newSprite3->runAction(RepeatForever::create(seq2));
    });
    
    auto menuItem8 = MenuItemFont::create("Sequence");
    menuItem8->setFontNameObj("Marker Felt.ttf");
    menuItem8->setFontSizeObj(32);
    menuItem8->setName("menuItem8");
    menuItem8->setVisible(false);
    menuItem8->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem8->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->getRunningScene()->removeChildByName("sprite2"); // the old one
        Director::getInstance()->getRunningScene()->removeChildByName("sprite3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 64);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite2,1);
        
        // create a few actions.
        auto jump = JumpBy::create(0.5, Point(0, 0), 100, 1);
        
        auto rotate = RotateTo::create(2.0f, 10);
        
        // create a few callbacks
        auto callbackJump = CallFunc::create([](){
            log("Jumped!");
        });
        
        auto callbackRotate = CallFunc::create([](){
            log("Rotated!");
        });
        
        // create a sequence with the actions and callbacks
        auto seq = Sequence::create(jump, callbackJump, rotate, callbackRotate, nullptr);
        
        newSprite2->runAction(RepeatForever::create(seq));
    });
    
    auto menuItem9 = MenuItemFont::create("Spawn");
    menuItem9->setFontNameObj("Marker Felt.ttf");
    menuItem9->setFontSizeObj(32);
    menuItem9->setName("menuItem9");
    menuItem9->setVisible(false);
    menuItem9->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem9->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->getRunningScene()->removeChildByName("sprite2"); // the old one
        Director::getInstance()->getRunningScene()->removeChildByName("sprite3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 64);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0,0));
        Director::getInstance()->getRunningScene()->addChild(newSprite2,1);
        
    });
    
    auto menu = Menu::create(menuItem1, menuItem2, menuItem3, menuItem4, menuItem5,
                             menuItem6, menuItem7, menuItem8, menuItem9, NULL);
    menu->setName("menu");
    menuNode->addChild(menu, 1);
    menu->setPosition(Vec2::ZERO);
    
    scene->addChild(menuNode, 2);
    
    // return the scene
    return scene;
}
