#include "Chapter5_1.h"
#include "Chapter5_2.h"
#include "Chapter5.h"

USING_NS_CC;

Scene* Chapter5_1::createScene()
{
    // some upfront items that we need
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // create a scene
    auto scene = Scene::create();

    // add title
    auto thisSceneLabel = Label::createWithTTF("This Is A New Scene", "Marker Felt.ttf", 32);
    thisSceneLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));

    // add the menu item for Make a New Scene Using a Transition Fade
    auto menuItem = MenuItemFont::create("Make a New Scene Using a Transition Fade");
    menuItem->setFontNameObj("Marker Felt.ttf");
    menuItem->setFontSizeObj(32);
    menuItem->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - 80));
    menuItem->setCallback([&] (cocos2d::Ref* sender) {
        Director::getInstance()->replaceScene(TransitionFade::create(0.5, Chapter5_2::createScene(), Color3B(0, 255, 255)));
    });

    // add menu
    auto menu = Menu::create(menuItem, NULL);
    menu->setPosition(Vec2::ZERO);

    // add node to hold menu
    auto menuNode = Node::create();

    // add child nodes to containers
    menuNode->addChild(menu, 1);
    scene->addChild(thisSceneLabel, -1);
    scene->addChild(menuNode, 2);

    return scene;
}
