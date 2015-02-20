#include "Chapter9_10.h"
#include "Chapter9.h"
#include "DrawNode3D.h"

USING_NS_CC;

Scene* Chapter9_10::createScene()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // show draw call
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Director::getInstance()->setDisplayStats(true);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // add title
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto label = LabelTTF::create("Frustum Clipping", "Arial", 24);
    label->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                       Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - 30);
    scene->addChild(label, 0);
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // add zoom in button
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    label = LabelTTF::create("zoom in", "Arial", 24);
    label->setPosition(winSize.width - 50, origin.y - 100);
    scene->addChild(label, 0);
    
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // add 3d layer
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto layer3D = Layer::create();
    scene->addChild(layer3D,2);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // add camera
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    static Camera* camera = nullptr;
    if (camera == nullptr) {
        camera = Camera::createPerspective(60, (GLfloat)winSize.width/winSize.height, 1, 500);
        camera->setCameraFlag(CameraFlag::USER1);// set camera flag
        camera->setPosition3D(Vec3(0, 100, 200));
        camera->lookAt(Vec3(0, 0, 0), Vec3(0, 1, 0));
        layer3D->addChild(camera);
    }
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // open frustum clipping
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    camera->enableFrustumCulling(true, true);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // add the menu item for back to main menu
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    label = LabelTTF::create("MainMenu", "Arial", 24);
    auto menuItemMain = MenuItemLabel::create(label);
    menuItemMain->setPosition( Vec2(origin.x + visibleSize.width - 80, origin.y + 25) );
    menuItemMain->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9::createScene());
        Director::getInstance()->setDisplayStats(false);
        camera = nullptr;
    });
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // add zoom out button
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    label = LabelTTF::create("Zoom Out", "Arial", 34);
    auto menuItemZoomOut = MenuItemLabel::create(label);
    menuItemZoomOut->setPosition( winSize.width - 80, origin.y + visibleSize.height - 100 );
    menuItemZoomOut->setCallback([&](cocos2d::Ref *sender) {
        Vec3 dir = camera->getPosition3D() - Vec3::ZERO;
        Vec3 cameraPos = camera->getPosition3D();
        if(dir.length() <= 300)
        {
            dir.normalize();
            cameraPos += dir * 5;
            camera->setPosition3D(cameraPos);
        }
    });
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // add zoom in button
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    label = LabelTTF::create("Zoom In", "Arial", 34);
    auto menuItemZoomIn = MenuItemLabel::create(label);
    menuItemZoomIn->setPosition( winSize.width - 80, origin.y + visibleSize.height - 140 );
    menuItemZoomIn->setCallback([&](cocos2d::Ref *sender) {
        Vec3 dir = camera->getPosition3D() - Vec3::ZERO;
        Vec3 cameraPos = camera->getPosition3D();
        if(cameraPos.length() >= 50)
        {
            dir.normalize();
            cameraPos -= dir * 5;
            camera->setPosition3D(cameraPos);
        }
    });
    
    auto menuMain = Menu::create(menuItemMain, menuItemZoomOut, menuItemZoomIn, nullptr);
    menuMain->setPosition( Vec2::ZERO );
    scene->addChild(menuMain, 1);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // add sprite3D
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    const int NUM(5);
    for (int x = -NUM; x < NUM; x++)
    {
        for (int z = -NUM; z < NUM; z++)
        {
            auto sprite = Sprite3D::create("orc.c3b");
            sprite->setPosition3D(Vec3(x * 30, 0, z * 30));
            sprite->setRotation3D(Vec3(0, 180, 0));
            layer3D->addChild(sprite);
        }
    }
    
    layer3D->setCameraMask((unsigned short)CameraFlag::USER1);
    
    // return the scene
    return scene;
}