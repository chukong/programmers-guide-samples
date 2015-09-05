#include "Chapter9_11.h"
#include "Chapter9.h"
#include "extensions/Particle3D/PU/CCPUParticleSystem3D.h"

USING_NS_CC;

Scene* Chapter9_11::createScene()
{
    //cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    FileUtils::getInstance()->addSearchPath("Particle3D/scripts");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();

    // add title
    auto label = LabelTTF::create("Particle3D Test", "Arial", 24);
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


    auto camera = Camera::createPerspective(60, (GLfloat)winSize.width / winSize.height, 1.0f, 1000.0f);
    camera->setCameraFlag(CameraFlag::USER1);
    camera->setPosition3D(Vec3(0.0, 0.0, 60));
    camera->lookAt(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
    scene->addChild(camera);


    auto sprite3d = Sprite3D::create("orc.c3b");
    sprite3d->setPosition3D(Vec3(-30.0f, 0.0f, 0.0f));
    sprite3d->setRotation3D(Vec3(0.0f, 180.0f, 0.0f));
    scene->addChild(sprite3d);
    auto animation = Animation3D::create("orc.c3b");
    if (animation)
    {
        auto animate = Animate3D::create(animation);
        sprite3d->runAction(RepeatForever::create(animate));
    }
    auto handlerps = PUParticleSystem3D::create("lightningBolt.pu");
    //handlerps->setScale(10.0f);
    handlerps->startParticleSystem();
    sprite3d->getAttachNode("Bip001 L Hand")->addChild(handlerps);
    sprite3d->setCameraMask((unsigned short)CameraFlag::USER1);


    auto ps1 = PUParticleSystem3D::create("lineStreak.pu");
    ps1->setPosition3D(Vec3(30.0f, 0.0f, 0.0f));
    ps1->setScale(2.0f);
    ps1->setCameraMask((unsigned short)CameraFlag::USER1);
    ps1->startParticleSystem();
    scene->addChild(ps1);

    auto ps2 = PUParticleSystem3D::create("blackHole.pu");
    ps2->setPosition(-20.0f, 0.0f);
    auto moveby = MoveBy::create(2.0f, Vec2(40.0f, 0.0f));
    auto moveby1 = MoveBy::create(2.0f, Vec2(-40.0f, 0.0f));
    ps2->runAction(RepeatForever::create(Sequence::create(moveby, moveby1, nullptr)));
    ps2->setCameraMask((unsigned short)CameraFlag::USER1);
    ps2->startParticleSystem();
    scene->addChild(ps2);

    // return the scene
    return scene;
}