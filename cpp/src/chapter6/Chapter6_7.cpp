#include "Chapter6_7.h"
#include "Chapter6.h"

#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene* Chapter6_7::createScene()
{
    cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    int index=2;
    
    // create a scene
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("TextField", "Marker Felt.ttf", 32);
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

    // textfield
    auto textField = TextField::create("TextField - Edit Me", "Marker Felt.ttf", 30);
    textField->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - (++index) * 40));
    
    textField->setMaxLength(10); // max number of chars user can enter
    
    textField->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        std::cout << "editing a TextField" << std::endl;
    });

    scene->addChild(textField);
    
    // return the scene
    return scene;
}