#include "Chapter9_13.h"
#include "Chapter9.h"
#include "navmesh/CCNavMesh.h"
#include "physics3d/CCPhysics3D.h"
#include "3d/CCBundle3D.h"

USING_NS_CC;

Scene* Chapter9_13::createScene()
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
    if (!scene->initWithPhysics()) return nullptr;

    auto navMesh = NavMesh::create("NavMesh/all_tiles_tilecache.bin", "NavMesh/geomset.txt");
    scene->setNavMesh(navMesh);

    // add title
    auto label = LabelTTF::create("NavMesh Test", "Arial", 24);
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
    camera->setPosition3D(Vec3(0.0, 50.0f, 80.0f));
    camera->lookAt(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
    scene->addChild(camera);

    //create mesh
    std::vector<Vec3> trianglesList = Bundle3D::getTrianglesList("NavMesh/scene.obj");

    Physics3DRigidBodyDes rbDes;
    rbDes.mass = 0.0f;
    rbDes.shape = Physics3DShape::createMesh(&trianglesList[0], (int)trianglesList.size() / 3);
    auto rigidBody = Physics3DRigidBody::create(&rbDes);
    auto component = Physics3DComponent::create(rigidBody);
    auto sprite = Sprite3D::create("NavMesh/scene.obj");
    sprite->addComponent(component);
    sprite->setCameraMask((unsigned short)CameraFlag::USER1);
    scene->addChild(sprite);


    std::string filePath = "girl.c3b";
    NavMeshAgentParam param;
    param.radius = 2.0f;
    param.height = 8.0f;
    param.maxSpeed = 8.0f;
    auto agent = NavMeshAgent::create(param);
    auto agentNode = Sprite3D::create(filePath);
    agent->setOrientationRefAxes(Vec3(-1.0f, 0.0f, 1.0f));
    agentNode->setPosition3D(Vec3(0.0f, 2.34667206f, 0.0f));
    agentNode->setScale(0.05f);
    agentNode->addComponent(agent);
    agentNode->setCameraMask((unsigned short)CameraFlag::USER1);
    scene->addChild(agentNode);

    agentNode->runAction(RepeatForever::create(Sequence::create(CallFunc::create([=](){
        float x = cocos2d::random(-50.0f, 50.0f);
        float z = cocos2d::random(-50.0f, 50.0f);
        Physics3DWorld::HitResult result;
        scene->getPhysics3DWorld()->rayCast(Vec3(x, 50.0f, z), Vec3(x, -50.0f, z), &result);
        agent->move(result.hitPosition);
    }), DelayTime::create(5.0f), nullptr)));

    auto animation = Animation3D::create(filePath);
    auto animate = Animate3D::create(animation);
    if (animate){
        agentNode->runAction(RepeatForever::create(animate));
        //animate->setSpeed(0);
    }

    navMesh->setDebugDrawEnable(true);
    scene->setNavMeshDebugCamera(camera);

    // return the scene
    return scene;
}