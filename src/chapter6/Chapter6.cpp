#include "Chapter6.h"


USING_NS_CC;

Scene* Chapter6::createScene()
{
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // some upfront items that we need
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size playingSize = Size(visibleSize.width, visibleSize.height - (visibleSize.height/8)); // actual playing size to work with
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene for our game to hold everything
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create the title dialog
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto color = Color4F(1.0f, 0.5f, 0.3f, 1);
    
    int verts = 4;
    
    cocos2d::Point stripe1[] = {
        cocos2d::Point(0,0),
        cocos2d::Point(0,200),
        cocos2d::Point(600,200),
        cocos2d::Point(600,0)
    };
    
    cocos2d::DrawNode* dotNode1 = cocos2d::DrawNode::create();
    dotNode1->setContentSize(Size(600, 200));
    dotNode1->drawPolygon(stripe1, verts, color, 0, color);
    
    dotNode1->setPosition(Vec2(visibleSize.width/2 - (dotNode1->getContentSize().width / 2),
                               playingSize.height - dotNode1->getContentSize().height));
    
    auto label = Label::createWithTTF("Super Cocos Aliens", "Marker Felt.ttf", 64);
    dotNode1->addChild(label, 1);
    label->setPosition(Vec2(dotNode1->getContentSize().width/2, dotNode1->getContentSize().height/2));

    scene->addChild(dotNode1, -1);

   
    
    
    
    
    // return the scene
    return scene;
}
