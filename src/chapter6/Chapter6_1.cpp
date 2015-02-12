#include "Chapter6_1.h"
#include "Chapter6.h"

USING_NS_CC;

Scene* Chapter6_1::createScene()
{
    cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    int index=2;
    
    // create a scene
    auto scene = Scene::create();
    
    auto layer = LayerColor::create(Color4B::GRAY);
    scene->addChild(layer);
    
    // add title
    auto label = LabelTTF::create("Label", "Marker Felt.ttf", 32);
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
    
    // this is for Labels section of the Programmers Guide
    
    // 1. BMFont
    auto myLabel = Label::createWithBMFont("bitmapRed.fnt", "LabelBMFont");
    myLabel->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                         (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    scene->addChild(myLabel, 1);
    
    // 2. LabelTTF
    auto myLabel2 = Label::createWithTTF("LabelTTF", "Marker Felt.ttf", 32);
    myLabel2->setColor(Color3B::RED);
    myLabel2->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                 (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    scene->addChild(myLabel2, 1);
    
    // 3. LabelTTF with TTFConfig
    
    // create a TTFConfig files for labels to share
    TTFConfig labelConfig;
    labelConfig.fontFilePath = "Marker Felt.ttf";
    labelConfig.fontSize = 32;
    
    auto myLabel3 = Label::createWithTTF(labelConfig, "LabelTTF from TTFConfig");
    myLabel3->setColor(Color3B::RED);
    myLabel3->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    scene->addChild(myLabel3, 1);
    
    // 4. Label using SystemFont
    auto myLabel4 = Label::createWithSystemFont("Label using SystemFont", "Arial", 32);
    myLabel4->setColor(Color3B::RED);
    myLabel4->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    scene->addChild(myLabel4, 1);
    
    // 5. LabelTTF with shadow, outline and glow
    auto myLabel5 = Label::createWithTTF("LabelTTF with Shadow", "Marker Felt.ttf", 32);
    myLabel5->enableShadow();
    myLabel5->setColor(Color3B::RED);
    myLabel5->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    scene->addChild(myLabel5, 1);

    auto myLabel6 = Label::createWithTTF("LabelTTF with Outline", "Marker Felt.ttf", 32);
    myLabel6->setTextColor(Color4B::RED);
    //setColor will change the color of the whole label with effects as if 3.4
//    myLabel6->setColor(Color3B::RED);
    myLabel6->enableOutline(Color4B::WHITE, 1);
    myLabel6->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    scene->addChild(myLabel6, 1);
    
    auto myLabel7 = Label::createWithTTF("LabelTTF with Glow", "Marker Felt.ttf", 32);
    myLabel7->enableGlow(Color4B::YELLOW);
    myLabel7->setTextColor(Color4B::RED);
    myLabel7->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                          (Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - (++index) * 40));
    
    scene->addChild(myLabel7, 1);
    
    // return the scene
    return scene;
}
