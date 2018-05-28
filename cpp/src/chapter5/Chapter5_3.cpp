#include "Chapter5_3.h"
#include "Chapter5.h"

USING_NS_CC;

Scene* Chapter5_3::createScene()
{
    // some upfront items that we need
    cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Size visibleSize = Director::getInstance()->getVisibleSize();

    // create a scene
    auto scene = Scene::create();

    // add title
    auto sceneLabel = Label::createWithTTF("This Scene used a Flip!", "Marker Felt.ttf", 32);
    sceneLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));

    //add the menu item for back to main menu
    auto itemLabel = Label::createWithTTF("MainMenu", "Marker Felt.ttf", 32);
    auto menuItem = MenuItemLabel::create(itemLabel);
    menuItem->setPosition(Vec2(visibleRect.origin.x + visibleRect.size.width - 80, visibleRect.origin.y + 25));
    menuItem->setCallback([&](cocos2d::Ref* sender) {
        Director::getInstance()->replaceScene(Chapter5::createScene());
    });

    // add menu
    auto menu = Menu::create(menuItem, NULL);
    menu->setPosition(Vec2::ZERO);

    // add node to hold menu
    auto menuNode = Node::create();

    // add child nodes to containers
    menuNode->addChild(menu, 1);
    scene->addChild(sceneLabel, -1);
    scene->addChild(menuNode, 2);

    return scene;
}
