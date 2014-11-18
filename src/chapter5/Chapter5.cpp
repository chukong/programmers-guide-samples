#include "Chapter5.h"

USING_NS_CC;

Chapter5::Chapter5()
{
    initialize();
}

Chapter5::~Chapter5() { }

void Chapter5::initialize()
{
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // some upfront items that we need
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();
    Vec2 origin = dirs->getVisibleOrigin();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    scene1 = Scene::create();
    
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
    
    auto thisSceneLabel = Label::createWithTTF("This Is A Scene", "Marker Felt.ttf", 32);
    thisSceneLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    scene1->addChild(thisSceneLabel, 1);
    
    auto menuItem1 = MenuItemFont::create("Make A New Scene");
    menuItem1->setFontNameObj("Marker Felt.ttf");
    menuItem1->setFontSizeObj(32);
    menuItem1->setName("menuItem1");
    menuItem1->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem1->setCallback([&](cocos2d::Ref *sender) {
        
        Director::getInstance()->replaceScene(createScene2());
    });
    
    auto menu = Menu::create(menuItem1, NULL);
    menu->setName("menu");
    menuNode->addChild(menu, 1);
    menu->setPosition(Vec2::ZERO);
    
    scene1->addChild(menuNode, 2);
}

Scene* Chapter5::createScene2()
{
    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();
    Vec2 origin = dirs->getVisibleOrigin();
    
    scene2 = Scene::create();
    scene2->retain();
    
    auto nodeItems = Node::create();
    nodeItems->setName("nodeItems");
    
    auto menuNode = Node::create();
    menuNode->setName("menuNode");
    int index = 2;
    
    auto thisSceneLabel = Label::createWithTTF("This Is A New Scene", "Marker Felt.ttf", 32);
    thisSceneLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    scene2->addChild(thisSceneLabel, 1);
    
    auto menuItem1 = MenuItemFont::create("Make a New Scene Using a Transition Fade");
    menuItem1->setFontNameObj("Marker Felt.ttf");
    menuItem1->setFontSizeObj(32);
    menuItem1->setName("menuItem1");
    menuItem1->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem1->setCallback([&](cocos2d::Ref *sender) {
        
        Director::getInstance()->replaceScene(TransitionFade::create(0.5, createScene3(), Color3B(0,255,255)));
    });
    
    auto menu = Menu::create(menuItem1, NULL);
    menu->setName("menu");
    menuNode->addChild(menu, 1);
    menu->setPosition(Vec2::ZERO);
    
    scene2->addChild(menuNode, 2);
    
    return scene2;
}

Scene* Chapter5::createScene3()
{
    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();
    Vec2 origin = dirs->getVisibleOrigin();
    
    scene3 = Scene::create();
    scene3->retain();
    
    auto nodeItems = Node::create();
    nodeItems->setName("nodeItems");
    
    auto menuNode = Node::create();
    menuNode->setName("menuNode");
    int index = 2;
    
    auto thisSceneLabel = Label::createWithTTF("This Scene used a Transition!", "Marker Felt.ttf", 32);
    thisSceneLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    scene3->addChild(thisSceneLabel, 1);
    
    auto menuItem1 = MenuItemFont::create("Make a New Scene Using a Flip");
    menuItem1->setFontNameObj("Marker Felt.ttf");
    menuItem1->setFontSizeObj(32);
    menuItem1->setName("menuItem1");
    menuItem1->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                           (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (index) * 40));
    menuItem1->setCallback([&](cocos2d::Ref *sender) {
        
        Director::getInstance()->replaceScene(TransitionFlipX::create(2, createScene4()));
    });
    
    auto menu = Menu::create(menuItem1, NULL);
    menu->setName("menu");
    menuNode->addChild(menu, 1);
    menu->setPosition(Vec2::ZERO);
    
    scene3->addChild(menuNode, 2);

    return scene3;
}

Scene* Chapter5::createScene4()
{
    auto dirs = Director::getInstance();
    Size visibleSize = dirs->getVisibleSize();
    Vec2 origin = dirs->getVisibleOrigin();
    
    scene4 = Scene::create();
    scene4->retain();
    
    auto nodeItems = Node::create();
    nodeItems->setName("nodeItems");
    
    auto menuNode = Node::create();
    menuNode->setName("menuNode");
    
    auto thisSceneLabel = Label::createWithTTF("This Scene used a Flip!", "Marker Felt.ttf", 32);
    thisSceneLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    scene4->addChild(thisSceneLabel, 1);
    
    return scene4;
}
