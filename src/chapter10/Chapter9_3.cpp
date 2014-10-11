#include "Chapter9_3.h"
#include "Chapter9.h"

USING_NS_CC;

Scene* Chapter9_3::createScene()
{
    //cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("3D model aniamtion", "Arial", 24);
    label->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                       Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - 30);
    
    scene->addChild(label, -1);
    
    //add the menu item for back to main menu
    label = LabelTTF::create("MainMenu", "Arial", 24);
    
    auto menuItem = MenuItemLabel::create(label);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9::createScene());
    });
    auto menu = Menu::create(menuItem, nullptr);
    
    menu->setPosition( Vec2::ZERO );
    menuItem->setPosition( Vec2( Vec2(origin.x+visibleSize.width, origin.y+visibleSize.height/2).x - 80, Vec2(origin.x+visibleSize.width/2, origin.y).y + 25) );
    
    scene->addChild(menu, 1);
    
    std::string fileName = "orc.c3b";
    
    auto sprite = Sprite3D::create(fileName);
    sprite->setScale(5.f);
    sprite->setRotation3D(Vec3(0,180,0));
    sprite->setPosition( Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                        Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).y );
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // attach weapon
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto sp = Sprite3D::create("axe.c3b");
    sprite->getAttachNode("Bip001 R Hand")->addChild(sp);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // play animation
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto animation = Animation3D::create(fileName);
    if (animation)
    {
        auto animate = Animate3D::create(animation);
        animate->setSpeed(1);
        sprite->runAction(RepeatForever::create(animate));
    }
    
    //add to scene
    scene->addChild(sprite);
    
    // return the scene
    return scene;
}
