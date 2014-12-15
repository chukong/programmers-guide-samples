#include "Chapter9_9.h"
#include "Chapter9.h"


USING_NS_CC;

Scene* Chapter9_9::createScene()
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
    auto label = LabelTTF::create("Light", "Arial", 24);
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

    //add sprite3d
    {
        std::string fileName = "orc.c3b";
        auto sprite = Sprite3D::create(fileName);
        sprite->setRotation3D(Vec3(0.0, 180.0, 0.0));
        sprite->setPosition(Vec2(-30.0, 0.0));
        sprite->setScale(2.0);
        auto sp = Sprite3D::create("axe.c3b");
        sprite->getAttachNode("Bip001 R Hand")->addChild(sp);
        auto animation = Animation3D::create(fileName);
        if (animation)
        {
            auto animate = Animate3D::create(animation);
            sprite->runAction(RepeatForever::create(animate));
        }
        layer->addChild(sprite);
    }

    {
        std::string fileName = "sphere.c3b";
        auto sprite = Sprite3D::create(fileName);
        sprite->setScale(2.0f);
        sprite->setPosition(Vec2(30.0, 0.0));
        layer->addChild(sprite);
    }

    {
        std::string fileName = "plane.obj";
        auto sprite = Sprite3D::create(fileName);
        sprite->setTexture("planetex.png");
        sprite->setScale(20.0f);
        sprite->setPosition(Vec2(0.0, -10.0f));
        layer->addChild(sprite);
    }
    
    //end add sprite3d

    //add lights
    auto s = Director::getInstance()->getWinSize();
    auto ambientLight = AmbientLight::create(Color3B(200, 200, 200));
    ambientLight->setEnabled(true);
    layer->addChild(ambientLight);

    auto directionalLight = DirectionLight::create(Vec3(0.0f, -1.0f, 0.0f), Color3B(200, 200, 200));
    directionalLight->setEnabled(false);
    layer->addChild(directionalLight);

    auto pointLight = PointLight::create(Vec3(-200.0f, 200.0f, 0.0f), Color3B(200, 200, 200), 10000.0f);
    pointLight->setEnabled(false);
    layer->addChild(pointLight);

    auto spotLight = SpotLight::create(Vec3(0.0f, -1.0f, 0.0f), Vec3(-200.0f, 200.0f, 0.0f), Color3B(200, 200, 200), 0.0f, 0.5f, 10000.0f);
    spotLight->setEnabled(false);
    layer->addChild(spotLight);

    {
        auto tintto1 = TintTo::create(1, 0, 0, 255);
        auto tintto2 = TintTo::create(1, 0, 255, 0);
        auto tintto3 = TintTo::create(1, 255, 0, 0);
        auto tintto4 = TintTo::create(1, 255, 255, 255);
        auto moveby = MoveBy::create(2.0, Vec2(400.0f, 0.0f));
        auto seq = Sequence::create(tintto1, moveby, tintto2, moveby->reverse(), tintto3, moveby, tintto4, moveby->reverse(), nullptr);
        ambientLight->runAction(RepeatForever::create(seq));
    }

    {
        auto tintto1 = TintTo::create(1, 255, 0, 0);
        auto tintto2 = TintTo::create(1, 0, 255, 0);
        auto tintto3 = TintTo::create(1, 0, 0, 255);
        auto tintto4 = TintTo::create(1, 255, 255, 255);
        auto moveby = MoveBy::create(2.0, Vec2(400.0f, 0.0f));
        auto seq = Sequence::create(tintto1, moveby, tintto2, moveby->reverse(), tintto3, moveby, tintto4, moveby->reverse(), nullptr);
        directionalLight->runAction(RepeatForever::create(seq));
    }

    {
        auto tintto1 = TintTo::create(1, 255, 0, 0);
        auto tintto2 = TintTo::create(1, 0, 255, 0);
        auto tintto3 = TintTo::create(1, 0, 0, 255);
        auto tintto4 = TintTo::create(1, 255, 255, 255);
        auto moveby = MoveBy::create(2.0, Vec2(400.0f, 0.0f));
        auto seq = Sequence::create(tintto1, moveby, tintto2, moveby->reverse(), tintto3, moveby, tintto4, moveby->reverse(), nullptr);
        pointLight->runAction(RepeatForever::create(seq));
    }

    {
        auto tintto1 = TintTo::create(1, 255, 0, 0);
        auto tintto2 = TintTo::create(1, 0, 255, 0);
        auto tintto3 = TintTo::create(1, 0, 0, 255);
        auto tintto4 = TintTo::create(1, 255, 255, 255);
        auto moveby = MoveBy::create(2.0, Vec2(400.0f, 0.0f));
        auto seq = Sequence::create(tintto1, moveby, tintto2, moveby->reverse(), tintto3, moveby, tintto4, moveby->reverse(), nullptr);
        spotLight->runAction(RepeatForever::create(seq));
    }
    //end add lights

    {
        auto size = Director::getInstance()->getWinSize();
        auto ambientLightLabel = LabelTTF::create("Ambient Light ON", "Arial", 24);
        auto menuItem0 = MenuItemLabel::create(ambientLightLabel);
        menuItem0->setCallback([=](cocos2d::Ref *sender) {
            char str[32];
            bool isON = !ambientLight->isEnabled();
            sprintf(str, "Ambient Light %s", isON == true? "ON":"OFF");
            ambientLight->setEnabled(isON);
            ambientLightLabel->setString(str);
        });

        auto directionalLightLabel = LabelTTF::create("Directional Light OFF", "Arial", 24);
        auto menuItem1 = MenuItemLabel::create(directionalLightLabel);
        menuItem1->setCallback([=](cocos2d::Ref *sender) {
            char str[32];
            bool isON = !directionalLight->isEnabled();
            sprintf(str, "Directional Light %s", isON == true? "ON":"OFF");
            directionalLight->setEnabled(isON);
            directionalLightLabel->setString(str);
        });

        auto pointLightLabel = LabelTTF::create("Point Light OFF", "Arial", 24);
        auto menuItem2 = MenuItemLabel::create(pointLightLabel);
        menuItem2->setCallback([=](cocos2d::Ref *sender) {
            char str[32];
            bool isON = !pointLight->isEnabled();
            sprintf(str, "Point Light %s", isON == true? "ON":"OFF");
            pointLight->setEnabled(isON);
            pointLightLabel->setString(str);
        });

        auto spotLightLabel = LabelTTF::create("Spot Light OFF", "Arial", 24);
        auto menuItem3 = MenuItemLabel::create(spotLightLabel);
        menuItem3->setCallback([=](cocos2d::Ref *sender) {
            char str[32];
            bool isON = !spotLight->isEnabled();
            sprintf(str, "Spot Light %s", isON == true? "ON":"OFF");
            spotLight->setEnabled(isON);
            spotLightLabel->setString(str);
        });

        auto menu = Menu::create(menuItem0, menuItem1, menuItem2, menuItem3, nullptr);
        menu->setPosition(Vec2::ZERO);
        menuItem0->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
        menuItem0->setPosition( Vec2(origin.x, origin.y + visibleSize.height - 50) );
        menuItem1->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
        menuItem1->setPosition( Vec2(origin.x, origin.y + visibleSize.height - 100) );
        menuItem2->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
        menuItem2->setPosition( Vec2(origin.x, origin.y + visibleSize.height - 150));
        menuItem3->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
        menuItem3->setPosition( Vec2(origin.x, origin.y + visibleSize.height - 200));
        scene->addChild(menu);
    }

    auto camera = Camera::createPerspective(60, (GLfloat)winSize.width / winSize.height, 1.0f, 1000.0f);
    camera->setCameraFlag(CameraFlag::USER1);
    camera->setPosition3D(Vec3(0.0, 100, 100));
    camera->lookAt(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
    layer->addChild(camera);
    layer->setCameraMask((unsigned short)CameraFlag::USER1);

    // return the scene
    return scene;
}