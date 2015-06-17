#include "Chapter9_12.h"
#include "Chapter9.h"
#include "physics3d/CCPhysics3D.h"
#include "3d/CCBundle3D.h"

USING_NS_CC;

#define START_POS_X -15.0
#define START_POS_Y 10.0
#define START_POS_Z -0.5

#define ARRAY_SIZE_X 4
#define ARRAY_SIZE_Y 3
#define ARRAY_SIZE_Z 4

Scene* Chapter9_12::createScene()
{
    //cocos2d::Rect visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    if (!scene->initWithPhysics()) return nullptr;

    // add title
    auto label = LabelTTF::create("Physics3D Test", "Arial", 24);
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
    camera->setPosition3D(Vec3(0.0, 0.0f, 60.0f));
    camera->lookAt(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
    scene->addChild(camera);

    //PhysicsSprite3D = Sprite3D + Physics3DComponent
    Physics3DRigidBodyDes rbDes;
    rbDes.disableSleep = true;
    auto sprite = Sprite3D::create("orc.c3b");
    rbDes.mass = 10.f;
    rbDes.shape = Physics3DShape::createBox(Vec3(5.0f, 5.0f, 5.0f));
    auto rigidBody = Physics3DRigidBody::create(&rbDes);
    Quaternion quat;
    Quaternion::createFromAxisAngle(Vec3(0.f, 1.f, 0.f), CC_DEGREES_TO_RADIANS(180), &quat);
    auto component = Physics3DComponent::create(rigidBody, Vec3(0.f, -3.f, 0.f), quat);
    sprite->addComponent(component);
    scene->addChild(sprite);
    sprite->setCameraMask((unsigned short)CameraFlag::USER1);
    sprite->setScale(0.4f);
    sprite->setPosition3D(Vec3(10.f, 0.f, 0.f));
    //sync node position to physics
    component->syncNodeToPhysics();
    //physics controlled, we will not set position for it, so we can skip sync node position to physics
    component->setSyncFlag(Physics3DComponent::PhysicsSyncFlag::PHYSICS_TO_NODE);
    //create point to point constraint
    Physics3DConstraint* constraint = Physics3DPointToPointConstraint::create(rigidBody, Vec3(2.5f, 2.5f, 2.5f));
    scene->getPhysics3DWorld()->addPhysics3DConstraint(constraint);


    //create kinematic
    rbDes.mass = 0.f; //kinematic objects. zero mass so that it can not be affected by other dynamic objects
    rbDes.shape = Physics3DShape::createBox(Vec3(100.0f, 2.0f, 100.0f));
    auto phySprite = PhysicsSprite3D::create("box.c3t", &rbDes);
    phySprite->setTexture("HelloWorld.png");
    phySprite->setCameraMask((unsigned short)CameraFlag::USER1);
    rigidBody = static_cast<Physics3DRigidBody*>(phySprite->getPhysicsObj());
    rigidBody->setKinematic(true);
    scene->addChild(phySprite);
    phySprite->setScale(100.0f);
    phySprite->setScaleY(2.0f);
    phySprite->setPosition3D(Vec3(0.0f, -20.0f, 0.0f));
    phySprite->setRotation3D(Vec3(0.0f, 180.0f, 0.0f));
    //create mesh
    std::vector<Vec3> trianglesList = Bundle3D::getTrianglesList("boss.c3b");

    rbDes.mass = 0.0f;
    rbDes.shape = Physics3DShape::createMesh(&trianglesList[0], (int)trianglesList.size() / 3);
    rigidBody = Physics3DRigidBody::create(&rbDes);
    component = Physics3DComponent::create(rigidBody);
    sprite = Sprite3D::create("boss.c3b");
    sprite->addComponent(component);
    sprite->setRotation3D(Vec3(-90.0f, 0.0f, 0.0f));
    sprite->setPosition3D(Vec3(-10.0f, 0.0f, 0.0f));
    sprite->setCameraMask((unsigned short)CameraFlag::USER1);
    scene->addChild(sprite);

    //create several boxes using PhysicsSprite3D
    rbDes.mass = 1.f;
    rbDes.shape = Physics3DShape::createBox(Vec3(2.0f, 2.0f, 2.0f));
    float start_x = START_POS_X - ARRAY_SIZE_X / 2;
    float start_y = START_POS_Y;
    float start_z = START_POS_Z - ARRAY_SIZE_Z / 2;
    for (int k = 0; k < ARRAY_SIZE_Y; k++)
    {
        for (int i = 0; i < ARRAY_SIZE_X; i++)
        {
            for (int j = 0; j < ARRAY_SIZE_Z; j++)
            {
                float x = 10.0*i + start_x;
                float y = 5.0 + 1.0*k + start_y;
                float z = 10.0*j + start_z;

                auto sprite = PhysicsSprite3D::create("box.c3t", &rbDes);
                sprite->setTexture("HelloWorld.png");
                sprite->setPosition3D(Vec3(x, y, z));
                sprite->syncNodeToPhysics();
                sprite->setSyncFlag(Physics3DComponent::PhysicsSyncFlag::PHYSICS_TO_NODE);
                sprite->setCameraMask((unsigned short)CameraFlag::USER1);
                sprite->setScale(2.0f);
                scene->addChild(sprite);
            }
        }
    }

    //scene->getPhysics3DWorld()->setDebugDrawEnable(true);
    scene->setPhysics3DDebugCamera(camera);

    // return the scene
    return scene;
}