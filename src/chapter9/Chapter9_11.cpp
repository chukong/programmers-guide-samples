#include "Chapter9_11.h"
#include "Chapter9.h"
#include "extensions/Particle3D/PU/CCPUParticleSystem3D.h"

USING_NS_CC;

Scene* Chapter9_11::createScene()
{
    FileUtils::getInstance()->addSearchPath("chapter9/Particle3D/scripts");
    FileUtils::getInstance()->addSearchPath("chapter9/Particle3D/materials");
    FileUtils::getInstance()->addSearchPath("chapter9/Particle3D/textures");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();

    // add title
    auto label = LabelTTF::create("Particle3D", "Arial", 24);
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
    
//    //the basic example
//    auto ps = PUParticleSystem3D::create("explosionSystem.pu");
//    ps->startParticleSystem();
//    layer->addChild(ps);
    
//    // the following is a particle with action
//    auto ps = PUParticleSystem3D::create("blackHole.pu", "pu_mediapack_01.material");
//    ps->setScale(0.2f);
//    ps->setPosition(-20.0f, 0.0f);
//    auto moveby = MoveBy::create(2.0f, Vec2(40.0f, 0.0f));
//    auto moveby1 = MoveBy::create(2.0f, Vec2(-40.0f, 0.0f));
//    ps->runAction(RepeatForever::create(Sequence::create(moveby, moveby1, nullptr)));
//    ps->startParticleSystem();
//    layer->addChild(ps);
    
    // the following is an example that attach a particle to a Sprite3D
    auto sprite3d = Sprite3D::create("chapter9/orc.c3b");
    sprite3d->setPosition3D(Vec3(0.0f, 0.0f, 0.0f));
    sprite3d->setRotation3D(Vec3(0.0f, 180.0f, 0.0f));
    sprite3d->setScale(0.3f);
    auto animation = Animation3D::create("orc.c3b");
    if (animation)
    {
        auto animate = Animate3D::create(animation);
        sprite3d->runAction(RepeatForever::create(animate));
    }
    auto handlerps = PUParticleSystem3D::create("lightningBolt.pu");
    handlerps->startParticleSystem();
    sprite3d->getAttachNode("Bip001 L Hand")->addChild(handlerps);
    layer->addChild(sprite3d);

    auto camera = Camera::createPerspective(60, (GLfloat)winSize.width / winSize.height, 1.0f, 1000.0f);
    camera->setCameraFlag(CameraFlag::USER1);
    camera->setPosition3D(Vec3(0.0, 3, 20));
    camera->lookAt(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
    layer->addChild(camera);
    layer->setCameraMask((unsigned short)CameraFlag::USER1);

    // return the scene
    return scene;
}