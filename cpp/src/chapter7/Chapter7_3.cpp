#include "Chapter7_3.h"
#include "Chapter7.h"

USING_NS_CC;

Scene* Chapter7_3::createScene()
{
    cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create a scene
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("Parallax", "Marker Felt.ttf", 32);
    label->setPosition(Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height/2).x,
                       Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height).y - 30);
    
    scene->addChild(label, -1);
    
    //add the menu item for back to main menu
    label = LabelTTF::create("MainMenu", "Marker Felt.ttf", 32);
    auto menuItem = MenuItemLabel::create(label);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter7::createScene());
    });
    
    auto menu = Menu::create(menuItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    menuItem->setPosition(Vec2(visibleRect.origin.x+visibleRect.size.width - 80, visibleRect.origin.y + 25));
    scene->addChild(menu, 1);
    
    // Parallax
    auto parallax = ParallaxNode::create();
    
    // create a few "layers"
    int verts = 4;

    auto color1 = Color4F(1.0f, 0.5f, 0.3f, 1);
    auto color2 = Color4F(1.0f, 0.6f, 0.4f, 1);
    auto color3 = Color4F(1.0f, 0.7f, 0.5f, 1);
    
    Vec2 box1[] = {Vec2::ZERO, Vec2(0,200), Vec2(600,200), Vec2(600,0)};
    Vec2 box2[] = {Vec2::ZERO, Vec2(0,300), Vec2(800,300), Vec2(800,0)};
    Vec2 box3[] = {Vec2::ZERO, Vec2(0,500), Vec2(1000,500), Vec2(1000,0)};
    
    DrawNode* layer1 = DrawNode::create();
    layer1->setContentSize(Size(600, 200));
    layer1->drawPolygon(box1, verts, color1, 0, color1);
    layer1->setPosition(Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height/2).x,
                        Vec2(visibleRect.origin.x+visibleRect.size.width/2, visibleRect.origin.y+visibleRect.size.height).y - 60);
    
    DrawNode* layer2 = DrawNode::create();
    layer2->setContentSize(Size(800, 300));
    layer2->drawPolygon(box2, verts, color2, 0, color2);
    layer2->setPosition(Vec2(visibleRect.origin.x+visibleRect.size.width/3, visibleRect.origin.y+visibleRect.size.height/3).x,
                          Vec2(visibleRect.origin.x+visibleRect.size.width/3, visibleRect.origin.y+visibleRect.size.height).y - 80);
    
    DrawNode* layer3 = DrawNode::create();
    layer3->setContentSize(Size(1000, 500));
    layer3->drawPolygon(box3, verts, color3, 0, color3);
    layer3->setPosition(Vec2(visibleRect.origin.x+visibleRect.size.width/3, visibleRect.origin.y+visibleRect.size.height/3).x,
                        Vec2(visibleRect.origin.x+visibleRect.size.width/3, visibleRect.origin.y+visibleRect.size.height).y - 80);
    

    // now add all 3 layers to the parallax node
    // background image is moved at a ratio of 0.4x, 0.5y
    parallax->addChild(layer1, -1, Vec2(0.4f,0.5f), Vec2::ZERO);
    
    // tiles are moved at a ratio of 2.2x, 1.0y
    parallax->addChild(layer2, 1, Vec2(2.2f,1.0f), Vec2(0,-200) );
    
    // top image is moved at a ratio of 3.0x, 2.5y
    parallax->addChild(layer3, 2, Vec2(3.0f,2.5f), Vec2(200,800) );
    
    // now create some actions that will move the 'parallax' node
    // and the children of the 'parallax' node will move at different speed
    auto goUp = MoveBy::create(4, Vec2(0,-250) );
    auto goDown = goUp->reverse();
    auto go = MoveBy::create(8, Vec2(-500,0) );
    auto goBack = go->reverse();
    auto seq = Sequence::create(goUp, go, goDown, goBack, nullptr);
    parallax->runAction( (RepeatForever::create(seq) ));
    
    scene->addChild(parallax, 1);
    
    return scene;
}
