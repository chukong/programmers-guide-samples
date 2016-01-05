#include "Chapter9_7.h"
#include "Chapter9.h"
#include "DrawNode3D.h"

USING_NS_CC;

Scene* Chapter9_7::createScene()
{
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    
    auto layer = OBBTest::create();
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

OBBTest::OBBTest():
_drawAABB(nullptr),
_pick(false),
_camera(nullptr)
{
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(OBBTest::onTouchesBegan, this);
    listener->onTouchesEnded = CC_CALLBACK_2(OBBTest::onTouchesEnded, this);
    listener->onTouchesMoved = CC_CALLBACK_2(OBBTest::onTouchesMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto s = Director::getInstance()->getWinSize();
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();
    
    // add title
    auto label = LabelTTF::create("OBB", "Arial", 24);
    label->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                       Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - 30);
    
    this->addChild(label, -1);
    
    //add the menu item for back to main menu
    label = LabelTTF::create("MainMenu", "Arial", 24);
    auto menuItem = MenuItemLabel::create(label);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9::createScene());
    });
    auto menu = Menu::create(menuItem, nullptr);
    menu->setPosition( Vec2::ZERO );
    menuItem->setPosition( Vec2(origin.x+visibleSize.width - 80, origin.y + 25) );
    this->addChild(menu, 1);
    
    auto layer3D=Layer::create();
    addChild(layer3D);
    
    // add camera
    _camera=Camera::createPerspective(60, (GLfloat)winSize.width/winSize.height, 1, 1000);
    _camera->setCameraFlag(CameraFlag::USER1);// set camera flag
    _camera->setPosition3D(Vec3(0, 50, 230));
    _camera->lookAt(Vec3(0,0,0), Vec3(0,1,0));
    layer3D->addChild(_camera);
    
    _drawAABB = DrawNode3D::create();
    
    Vec3 extents = Vec3(60, 30, 100);
    AABB aabb = AABB(-extents, extents);
    _obb = OBB(aabb);
    layer3D->addChild(_drawAABB);
    
    layer3D->setCameraMask(2);
    
    scheduleUpdate();
}

void OBBTest::update(float dt)
{
    if (_pick)
        return;
    
    _drawAABB->clear();
    
    Mat4 mat = Mat4::IDENTITY;
    mat.rotate(Vec3::UNIT_Y, 0.01f);
    
    _obb.transform(mat);
    Vec3 corners[8] = {};
    _obb.getCorners(corners);
    
    _drawAABB->setPosition3D(_obb._center);
    _drawAABB->drawCube(corners, Color4F(0,0,1,1));
}

void OBBTest::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
{
    for (auto touch: touches)
    {
        auto location = touch->getLocationInView();
        Vec3 nearP(location.x, location.y, -1.0f), farP(location.x, location.y, 1.0f);
        auto size = Director::getInstance()->getWinSize();
        _camera->unproject(size, &nearP, &nearP);
        _camera->unproject(size, &farP, &farP);
        
        Vec3 dir(farP - nearP);
        dir.normalize();
        Ray ray(_camera->getPosition3D(), dir);
        
        if(ray.intersects(_obb))
        {
            _pick = true;
            return;
        }
    }
    _pick = false;
}

void OBBTest::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
{
    _pick = false;
}

void OBBTest::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
{
    
}