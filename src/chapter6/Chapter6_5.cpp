#include "Chapter6_5.h"
#include "Chapter6.h"

#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene* Chapter6_5::createScene()
{
    cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    int index=2;
    
    // create a scene
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("LoadingBar", "Marker Felt.ttf", 32);
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

    // loadingbar
    auto loadingBar = LoadingBar::create("LoadingBarFile.png");
    loadingBar->loadTexture("LoadingBarFile.png");
    loadingBar->setPercent(20.0);
    loadingBar->setDirection(LoadingBar::Direction::LEFT);
    loadingBar->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - (++index) * 40));
    
    scene->addChild(loadingBar, 1);
    
    loadingBar->schedule([loadingBar](float f){
        if (loadingBar->getPercent() < 100.0)
        {
            loadingBar->setPercent(loadingBar->getPercent() + 10.00f);
            std::cout << "LoadingBar percent: " << loadingBar->getPercent() << std::endl;
        }
        else
        {
            loadingBar->unschedule("update_loading_bar");
            std::cout << "Loading complete!" << std::endl;
        }
    }, 0.5f, "update_loading_bar");
    
    // return the scene
    return scene;
}
