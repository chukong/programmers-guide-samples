#include "Chapter6_3.h"
#include "Chapter6.h"

#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene* Chapter6_3::createScene()
{
    cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    int index=2;
    
    // create a scene
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("Button", "Marker Felt.ttf", 32);
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

    // button
    auto button = Button::create("Button_Normal.png", "Button_Press.png", "Button_Disable.png");
    button->setTitleText("Button 1");
    button->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - (++index) * 40));
    
    button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                std::cout << "Button 1 clicked" << std::endl;
                break;
            default:
                break;
        }
    });
    
    scene->addChild(button);
    
    // return the scene
    return scene;
}

//void Chapter6_3::buttonOneCallback(Ref* sender)
//{
//    std::cout << "Button One clicked" << std::endl;
//}
