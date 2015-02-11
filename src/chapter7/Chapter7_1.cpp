#include "Chapter7_1.h"
#include "Chapter7.h"

USING_NS_CC;

Scene* Chapter7_1::createScene()
{
    cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // create a scene
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("TileMap", "Marker Felt.ttf", 32);
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
    
    // TileMap
    auto map = TMXTiledMap::create("isometric_grass_and_water.tmx");
    map->setPosition(Vec2(visibleSize.width/2 - map->getContentSize().width/2, 0));
    
    auto listener1 = EventListenerTouchOneByOne::create();
    
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        return true; // if you are consuming it
    };
    
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        auto layer = map->getLayer("layer0");
        Size viewSize = Director::getInstance()->getWinSize();
        
        Vec2 mapCordinate = map->convertToNodeSpace(Director::getInstance()->convertToGL(touch->getLocationInView()));
        int tileX = mapCordinate.x / map->getTileSize().width;
        int tileY = (viewSize.height - mapCordinate.y) / map->getTileSize().height;
        
        int id = layer->getTileGIDAt(Vec2(tileX, tileY));
        Sprite* tileSprite = layer->getTileAt(Vec2(tileX, tileY));
        
        std::cout << "Tile GID: " << id << std::endl;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, map);
    
    scene->addChild(map, 0, 99); // with a tag of '99'
    
    return scene;
}
