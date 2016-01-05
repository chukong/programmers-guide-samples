#include "Chapter6_2.h"
#include "Chapter6.h"

USING_NS_CC;

Scene* Chapter6_2::createScene()
{
    cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    int index=2;
    
    // create a scene
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("Menu and MenuItem", "Marker Felt.ttf", 32);
    label->setPosition(Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height/2).x,
                       Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height).y - 30);
    
    scene->addChild(label, -1);
    
    //add the menu item for back to main menu
    label = LabelTTF::create("MainMenu", "Marker Felt.ttf", 32);
    auto menuItem = MenuItemLabel::create(label);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter6::createScene());
    });
    
    auto menu = Menu::create(menuItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    menuItem->setPosition(Vec2(visibleRect.origin.x+visibleRect.size.width - 80, visibleRect.origin.y + 25));
    scene->addChild(menu, 1);
    
    // this is for Menu section of the Programmers Guide
    // creating a Menu from a Vector of items
    Vector<MenuItem*> MenuItems;
    
    // first item
    auto label1 = LabelTTF::create("Item 1", "Marker Felt.ttf", 32);
    auto item1 = MenuItemLabel::create(label1);
    item1->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                       (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    item1->setCallback([&](cocos2d::Ref *sender) {
        std::cout << "Item 1 was pushed..." << std::endl;
    });
    MenuItems.pushBack(item1);
    
    // second item
    auto label2 = LabelTTF::create("Item 2", "Marker Felt.ttf", 32);
    auto item2 = MenuItemLabel::create(label2);
    item2->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                       (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    item2->setCallback([&](cocos2d::Ref *sender) {
        std::cout << "Item 2 was pushed..." << std::endl;
    });
    MenuItems.pushBack(item2);
    
    // third item
    auto label3 = LabelTTF::create("Item 3", "Marker Felt.ttf", 32);
    auto item3 = MenuItemLabel::create(label3);
    item3->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                       (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    item3->setCallback([&](cocos2d::Ref *sender) {
        std::cout << "Item 3 was pushed..." << std::endl;
    });
    MenuItems.pushBack(item3);
    
    // now create the menu from the vector of MenuItems
    auto menuExample = Menu::createWithArray(MenuItems);
    menuExample->setPosition(Vec2::ZERO);
    scene->addChild(menuExample, 1);
    
    // return the scene
    return scene;
}
