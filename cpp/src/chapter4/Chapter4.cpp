#include "Chapter4.h"

USING_NS_CC;

Scene* Chapter4::createScene()
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
    menuItem1->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("point2"); // old one
        dirs->removeChildByName("point3"); // old one
        
        auto newSprite = Sprite::create("Blue_Front1.png");
        newSprite->setPosition(100, 56);
        newSprite->setName("sprite1");
        newSprite->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite,1);
        
        auto point1 = Sprite::create("dot.png");
        point1->setName("point1");
        point1->setPosition(newSprite->getPosition());
        dirs->addChild(point1,2);

        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 56);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite2,1);
        
        auto anode = dirs->getChildByName("menuNode");
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
        cnode = bnode->getChildByName("menuItem10");
        cnode->setVisible(true);
        cnode = bnode->getChildByName("menuItem11");
        cnode->setVisible(true);
    });
    
    auto menuItem2 = MenuItemFont::create("MoveTo/MoveBy");
    menuItem2->setFontNameObj("Marker Felt.ttf");
    menuItem2->setFontSizeObj(32);
    menuItem2->setName("menuItem2");
    menuItem2->setVisible(false);
    menuItem2->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem2->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite2"); // the old one
        dirs->removeChildByName("sprite3"); // the old one
        dirs->removeChildByName("point2"); // the old one
        dirs->removeChildByName("point3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 56);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite2,1);
        
        auto moveBy = MoveBy::create(2, Point(500, 0));
        
        auto moveTo = MoveTo::create(2, Point(300, 56));
        
        auto delay = DelayTime::create(2.0f);
        
        auto sequence = Sequence::create(moveBy, delay, NULL);
        auto sequence2 = Sequence::create(delay, moveTo, NULL);
        
        newSprite2->runAction(sequence);
        
        auto newSprite3 = Sprite::create("Blue_Front1.png");
        newSprite3->setPosition(600, 56);
        newSprite3->setName("sprite3");
        newSprite3->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite3,1);
        
        newSprite3->runAction(sequence2);
    });
    
    auto menuItem3 = MenuItemFont::create("FadeIn/FadeOut");
    menuItem3->setFontNameObj("Marker Felt.ttf");
    menuItem3->setFontSizeObj(32);
    menuItem3->setName("menuItem3");
    menuItem3->setVisible(false);
    menuItem3->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem3->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite2"); // the old one
        dirs->removeChildByName("sprite3"); // the old one
        dirs->removeChildByName("point2"); // the old one
        dirs->removeChildByName("point3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(300, 56);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite2,1);

        auto fadeIn = FadeIn::create(1.0f);
        newSprite2->runAction(fadeIn);

        auto newSprite3 = Sprite::create("Blue_Front1.png");
        newSprite3->setPosition(500, 56);
        newSprite3->setName("sprite3");
        newSprite3->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite3,1);
        
        auto fadeOut = FadeOut::create(2.0f);
        newSprite3->runAction(fadeOut);
    });
    
    auto menuItem11 = MenuItemFont::create("Animate");
    menuItem11->setFontNameObj("Marker Felt.ttf");
    menuItem11->setFontSizeObj(32);
    menuItem11->setName("menuItem11");
    menuItem11->setVisible(false);
    menuItem11->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem11->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite2"); // the old one
        dirs->removeChildByName("sprite3"); // the old one
        dirs->removeChildByName("point2"); // the old one
        dirs->removeChildByName("point3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(300, 56);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite2,1);
        
        auto moveBy = MoveBy::create(2.0f, Vec2(500, 0));
        
        newSprite2->runAction(moveBy);
        
        // now lets animate the sprite we moved
        Vector<SpriteFrame*> animFrames;
        animFrames.reserve(12);
        animFrames.pushBack(SpriteFrame::create("Blue_Front1.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Front2.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Front3.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Left1.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Left2.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Left3.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Back1.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Back2.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Back3.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Right1.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Right2.png", Rect(0,0,65,81)));
        animFrames.pushBack(SpriteFrame::create("Blue_Right3.png", Rect(0,0,65,81)));
        
        // create the animation out of the frames
        Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
        Animate* animate = Animate::create(animation);
        
        // run it and repeat it forever
        newSprite2->runAction(RepeatForever::create(animate));
    });
    
    auto menuItem4 = MenuItemFont::create("RotateTo/RotateBy");
    menuItem4->setFontNameObj("Marker Felt.ttf");
    menuItem4->setFontSizeObj(32);
    menuItem4->setName("menuItem4");
    menuItem4->setVisible(false);
    menuItem4->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem4->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite2"); // the old one
        dirs->removeChildByName("sprite3"); // the old one
        dirs->removeChildByName("point2"); // the old one
        dirs->removeChildByName("point3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(300, 56);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite2,1);
        
        auto point2 = Sprite::create("dot.png");
        point2->setName("point2");
        point2->setPosition(newSprite2->getPosition());
        dirs->addChild(point2,2);

        auto newSprite3 = Sprite::create("Blue_Front1.png");
        newSprite3->setPosition(500, 56);
        newSprite3->setName("sprite3");
        newSprite3->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite3,1);
        
        auto point3 = Sprite::create("dot.png");
        point3->setName("point3");
        point3->setPosition(newSprite3->getPosition());
        dirs->addChild(point3,2);
        
        auto rotateTo = RotateTo::create(2.0f, 40.0f);
        newSprite2->runAction(rotateTo);
        
        auto rotateBy = RotateBy::create(2.0f, -20.0f);
        newSprite3->runAction(rotateBy);
    });
    
    auto menuItem5 = MenuItemFont::create("ScaleTo/ScaleBy");
    menuItem5->setFontNameObj("Marker Felt.ttf");
    menuItem5->setFontSizeObj(32);
    menuItem5->setName("menuItem5");
    menuItem5->setVisible(false);
    menuItem5->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem5->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite2"); // the old one
        dirs->removeChildByName("sprite3"); // the old one
        dirs->removeChildByName("point2"); // the old one
        dirs->removeChildByName("point3"); // the old one
        
        dirs->getChildByName("sprite1")->setPosition(100, 100);
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(300, 100);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite2,1);
        
        auto point2 = Sprite::create("dot.png");
        point2->setName("point2");
        point2->setPosition(newSprite2->getPosition());
        dirs->addChild(point2,2);

        auto scaleTo = ScaleTo::create(2.0f, 2.0f);
        newSprite2->runAction(scaleTo);
        
        auto newSprite3 = Sprite::create("Blue_Front1.png");
        newSprite3->setPosition(500, 56);
        newSprite3->setName("sprite3");
        newSprite3->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite3,1);
        
        auto point3 = Sprite::create("dot.png");
        point3->setName("point3");
        point3->setPosition(newSprite3->getPosition());
        dirs->addChild(point3,2);
        
        auto scaleBy = ScaleBy::create(2.0f, 0.5f);
        newSprite3->runAction(scaleBy);
        
        dirs->getChildByName("sprite1")->setPosition(100, 56);
    });
    
    auto menuItem6 = MenuItemFont::create("TintTo/TintBy");
    menuItem6->setFontNameObj("Marker Felt.ttf");
    menuItem6->setFontSizeObj(32);
    menuItem6->setName("menuItem6");
    menuItem6->setVisible(false);
    menuItem6->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem6->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite2"); // the old one
        dirs->removeChildByName("sprite3"); // the old one
        dirs->getChildByName("point1")->setVisible(false); // the old one
        dirs->removeChildByName("point2"); // the old one
        dirs->removeChildByName("point3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(300, 56);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite2,1);
        
        auto tintTo = TintTo::create(2.0f, 120.0f, 232.0f, 254.0f);
        newSprite2->runAction(tintTo);
        
        auto newSprite3 = Sprite::create("Blue_Front1.png");
        newSprite3->setPosition(500, 56);
        newSprite3->setName("sprite3");
        newSprite3->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite3,1);
        
        auto tintBy = TintBy::create(2.0f, 30.0f, 0, 0);
        newSprite3->runAction(tintBy);
    });
    
    auto menuItem7 = MenuItemFont::create("Ease");
    menuItem7->setFontNameObj("Marker Felt.ttf");
    menuItem7->setFontSizeObj(32);
    menuItem7->setName("menuItem7");
    menuItem7->setVisible(false);
    menuItem7->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem7->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance();
        dirs->getRunningScene()->getChildByName("point1")->setVisible(true);
        dirs->getRunningScene()->removeChildByName("sprite2"); // the old one
        dirs->getRunningScene()->removeChildByName("sprite3"); // the old one
        dirs->getRunningScene()->removeChildByName("point2"); // the old one
        dirs->getRunningScene()->removeChildByName("point3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 56);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->getRunningScene()->addChild(newSprite2,1);
        
//        auto newSprite3 = Sprite::create("White_Front1.png");
//        newSprite3->setPosition(100, 56);
//        newSprite3->setName("sprite3");
//        newSprite3->setAnchorPoint(Vec2(0.5,0.5));
//        dirs->addChild(newSprite3,1);
//        
        auto move = MoveBy::create(2, Point(200, dirs->getVisibleSize().height - newSprite2->getContentSize().height));
        auto move_back = move->reverse();
        
        auto move_ease_in = EaseBounceIn::create(move->clone() );
        auto move_ease_in_back = move_ease_in->reverse();
        
        auto move_ease_out = EaseBounceOut::create(move->clone() );
        auto move_ease_out_back = move_ease_out->reverse();

        auto delay = DelayTime::create(0.25f);
        
        auto seq1 = Sequence::create(move_ease_in, delay, move_ease_in_back, delay->clone(), nullptr);
        
        newSprite2->runAction(RepeatForever::create(seq1));
    });
    
    auto menuItem8 = MenuItemFont::create("Sequence");
    menuItem8->setFontNameObj("Marker Felt.ttf");
    menuItem8->setFontSizeObj(32);
    menuItem8->setName("menuItem8");
    menuItem8->setVisible(false);
    menuItem8->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem8->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite2"); // the old one
        dirs->removeChildByName("sprite3"); // the old one
        dirs->removeChildByName("point2"); // the old one
        dirs->removeChildByName("point3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 56);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite2,1);
        
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
    menuItem9->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite2"); // the old one
        dirs->removeChildByName("sprite3"); // the old one
        dirs->removeChildByName("point2"); // the old one
        dirs->removeChildByName("point3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 56);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite2,1);
        
        // create a few actions
        auto moveBy = MoveBy::create(10, Point(400,100));
        auto fadeTo = FadeTo::create(2.0f, 120.0f);
        
        // running the above Actions with Spawn.
        auto mySpawn = Spawn::createWithTwoActions(moveBy, fadeTo);
        newSprite2->runAction(mySpawn);
    });
    
    auto menuItem10 = MenuItemFont::create("Reverse");
    menuItem10->setFontNameObj("Marker Felt.ttf");
    menuItem10->setFontSizeObj(32);
    menuItem10->setName("menuItem10");
    menuItem10->setVisible(false);
    menuItem10->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    menuItem10->setCallback([&](Ref *sender) {
        auto dirs = Director::getInstance()->getRunningScene();
        dirs->removeChildByName("sprite2"); // the old one
        dirs->removeChildByName("sprite3"); // the old one
        dirs->removeChildByName("point2"); // the old one
        dirs->removeChildByName("point3"); // the old one
        
        auto newSprite2 = Sprite::create("Blue_Front1.png");
        newSprite2->setPosition(100, 56);
        newSprite2->setName("sprite2");
        newSprite2->setAnchorPoint(Vec2(0.5,0.5));
        dirs->addChild(newSprite2,1);
        
        // create a few Actions
        auto moveBy = MoveBy::create(2.0f, Point(500,0));
        auto scaleBy = ScaleBy::create(2.0f, 2.0f);
        auto delay = DelayTime::create(1.0f);
        
        // create a sequence
        auto delaySequence = Sequence::create(delay, delay->clone(), delay->clone(), delay->clone(), nullptr);
        
        auto sequence = Sequence::create(moveBy, delay, scaleBy, delaySequence, nullptr);
        
        newSprite2->runAction(sequence);
        
        newSprite2->runAction(sequence->reverse());
    });
    
    auto menu = Menu::create(menuItem1, menuItem2, menuItem3, menuItem4, menuItem5,
                             menuItem6, menuItem7, menuItem8, menuItem9, menuItem10,
                             menuItem11, NULL);
    menu->setName("menu");
    menuNode->addChild(menu, 1);
    menu->setPosition(Vec2::ZERO);
    
    scene->addChild(menuNode, 2);
    
    // return the scene
    return scene;
}
