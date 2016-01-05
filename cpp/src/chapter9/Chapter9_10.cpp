#include "Chapter9_10.h"
#include "Chapter9.h"


USING_NS_CC;

static int TerrainTag = 100;
static int PlayerTag = 101;

Scene* Chapter9_10::createScene()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();

    // add title
    auto label = LabelTTF::create("Terrain", "Arial", 24);
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
    menuItem->setPosition( Vec2(origin.x+visibleSize.width - 80, origin.y + 25) );
    scene->addChild(menu, 1);

    auto layer = Layer::create();
    scene->addChild(layer);
    
    Terrain::DetailMap r("chapter9/dirt.jpg"),g("chapter9/Grass2.jpg"),b("chapter9/road.jpg"),a("chapter9/GreenSkin.jpg");
    Terrain::TerrainData data("chapter9/heightmap16.jpg","chapter9/alphamap.png",r,g,b,a);
    auto terrain = Terrain::create(data,Terrain::CrackFixedType::SKIRT);

    layer->addChild(terrain, TerrainTag);
    
    auto player = Sprite3D::create("chapter9/orc.c3b");
    player->setScale(0.06f);
    player->setPositionY(terrain->getHeight(player->getPositionX(),player->getPositionZ()));
    auto animation = Animation3D::create("chapter9/orc.c3b");
    if (animation)
    {
        auto animate = Animate3D::create(animation);
        player->runAction(RepeatForever::create(animate));
    }
    layer->addChild(player);

    auto camera = Camera::createPerspective(60, (GLfloat)winSize.width / winSize.height, 1.0f, 1000.0f);
    camera->setCameraFlag(CameraFlag::USER1);
    camera->setPosition3D(Vec3(0.0, 10, 10));
    camera->lookAt(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
    layer->addChild(camera);
    layer->setCameraMask((unsigned short)CameraFlag::USER1);

    // return the scene
    return scene;
}