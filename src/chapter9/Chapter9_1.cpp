#include "Chapter9_1.h"
#include "Chapter9.h"

USING_NS_CC;

Scene* Chapter9_1::createScene()
{
    cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("3D static model", "Arial", 24);
    label->setPosition(Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height/2).x,
                       Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height).y - 30);
    
    scene->addChild(label, -1);
    
    //add the menu item for back to main menu
    label = LabelTTF::create("MainMenu", "Arial", 24);
    auto menuItem = MenuItemLabel::create(label);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9::createScene());
    });
    auto menu = Menu::create(menuItem, nullptr);
    menu->setPosition( Vec2::ZERO );
    menuItem->setPosition( Vec2( visibleRect.origin.x+visibleRect.size.width - 80, visibleRect.origin.y + 25) );
    scene->addChild(menu, 1);
    
    // create 3D sprite
    auto sprite = Sprite3D::create("boss.c3b");
    sprite->setScale(5.f);
    sprite->setPosition( Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height/2));
    
    ActionInterval* action;
    action = ScaleBy::create(3, 2);
    auto action_back = action->reverse();
    auto seq = Sequence::create( action, action_back, nullptr );
    
    // Run Action
    sprite->runAction( RepeatForever::create(seq) );
    
    //add to scene
    scene->addChild(sprite);
    
    // return the scene
    return scene;
}
