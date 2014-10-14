#include "Chapter12.h"

USING_NS_CC;

static Size s_visibleSize;
static Vec2 s_origin;
static Vec2 s_centre;
static Scene* s_currScene;
static const int DRAG_BODYS_TAG = 0x80;

//=====================================================================================
bool PhysicsDemoCorrelationToSprite::init()
{
    if (PhysicsDemo::init()) {
        //create a static PhysicsBody
        auto physicsBody = PhysicsBody::createBox(Size(65.0f , 81.0f ),PhysicsMaterial(0.1f, 1.0f, 0.0f));
        physicsBody->setDynamic(false);

        //create a sprite
        auto sprite = Sprite::create("whiteSprite.png");
        sprite->setPosition(s_centre);
        addChild(sprite);

        //make physicsBody associated with sprite
        sprite->setPhysicsBody(physicsBody);

        //add five dynamic body
        for (int i = 0; i < 5; ++i)
        {
            physicsBody = PhysicsBody::createBox(Size(65.0f , 81.0f ),PhysicsMaterial(0.1f, 1.0f, 0.0f));
            //set the body isn't affected by the physics world's gravitational force
            physicsBody->setGravityEnable(false);
            //set initial velocity of physicsBody
            physicsBody->setVelocity(Vec2(cocos2d::random(-500,500),cocos2d::random(-500,500)));
            physicsBody->setTag(DRAG_BODYS_TAG);

            sprite = Sprite::create("blueSprite.png");
            sprite->setPosition(Vec2(s_centre.x + cocos2d::random(-300 ,300 ),s_centre.y + cocos2d::random(-300 ,300 )));
            sprite->setPhysicsBody(physicsBody);
            addChild(sprite);
        }
        
        return true;
    }
    
    return false;
}

std::string PhysicsDemoCorrelationToSprite::subtitle() const
{
    return "Make body correlation to sprite.Please drag the sprites.";
}

//=====================================================================================
bool PhysicsDemoCollisionFiltering::init()
{
    if (PhysicsDemo::init()) {
        auto sprite1 = addSpriteAtPosition(Vec2(s_centre.x - 150 ,s_centre.y));
        sprite1->getPhysicsBody()->setCategoryBitmask(0x02);    // 0010
        sprite1->getPhysicsBody()->setCollisionBitmask(0x01);   // 0001

        sprite1 = addSpriteAtPosition(Vec2(s_centre.x - 150 ,s_centre.y + 100 ));
        sprite1->getPhysicsBody()->setCategoryBitmask(0x02);    // 0010
        sprite1->getPhysicsBody()->setCollisionBitmask(0x01);   // 0001

        auto sprite2 = addSpriteAtPosition(Vec2(s_centre.x + 150 ,s_centre.y),1);
        sprite2->getPhysicsBody()->setCategoryBitmask(0x01);    // 0001
        sprite2->getPhysicsBody()->setCollisionBitmask(0x02);   // 0010

        auto sprite3 = addSpriteAtPosition(Vec2(s_centre.x + 150 ,s_centre.y + 100 ),2);
        sprite3->getPhysicsBody()->setCategoryBitmask(0x03);    // 0011
        sprite3->getPhysicsBody()->setCollisionBitmask(0x03);   // 0011

        return true;
    }
    
    return false;
}

std::string PhysicsDemoCollisionFiltering::subtitle() const
{
    return "Collision Filtering.Please drag the sprites";
}

//=====================================================================================
#define STATIC_SPRITE_TAG 10
bool PhysicsDemoCollisionProcessing::init()
{
    if (PhysicsDemo::init()) {

        auto sprite = addSpriteAtPosition(s_centre,1);
        sprite->setTag(STATIC_SPRITE_TAG);
        sprite->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
        sprite->getPhysicsBody()->setDynamic(false);

        //add contact event listener
        auto contactListener = EventListenerPhysicsContact::create();
        contactListener->onContactBegin = CC_CALLBACK_1(PhysicsDemoCollisionProcessing::onContactBegin, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

        schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoCollisionProcessing::tick), 0.3f);
        return true;
    }
    
    return true;
}

void PhysicsDemoCollisionProcessing::tick(float dt)
{
    auto sprite = addSpriteAtPosition(Vec2(s_centre.x + cocos2d::random(-300 ,300 ),s_centre.y + cocos2d::random(-300 ,300 )));
    auto physicsBody = sprite->getPhysicsBody();
    physicsBody->setVelocity(Vec2(cocos2d::random(-500 ,500 ),cocos2d::random(-500 ,500 )));
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
}

bool PhysicsDemoCollisionProcessing::onContactBegin(PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    if (nodeA && nodeB)
    {
        if (nodeA->getTag() == STATIC_SPRITE_TAG)
        {
            nodeB->removeFromParentAndCleanup(true);
        }
        else if (nodeB->getTag() == STATIC_SPRITE_TAG)
        {
            nodeA->removeFromParentAndCleanup(true);
        }
    }
    
    return true;
}

std::string PhysicsDemoCollisionProcessing::subtitle() const
{
    return "Collision Processing";
}

//=====================================================================================
bool PhysicsDemoRayTest::init()
{
    if (PhysicsDemo::init()) {
        _angle = 0.0f;
        _drawNode = nullptr;

        auto touchListener = EventListenerTouchAllAtOnce::create();
        touchListener->onTouchesEnded = [=](const std::vector<Touch*>& touches, Event* event){
            for( auto &touch: touches)
            {
                auto sprite = addSpriteAtPosition(touch->getLocation());
                sprite->getPhysicsBody()->setGravityEnable(false);
            }
        };
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

        schedule(CC_SCHEDULE_SELECTOR(PhysicsDemoRayTest::tick), 0.03f);
        return true;
    }
    
    return false;
}

void PhysicsDemoRayTest::tick(float dt)
{
    Vec2 d(300  * cosf(_angle), 300  * sinf(_angle));
    Vec2 point2 = s_centre + d;
    if (_drawNode)
    {
        removeChild(_drawNode);
    }
    _drawNode = DrawNode::create();

#define MAX_MULTI_RAYCAST_NUM 5

    Vec2 points[MAX_MULTI_RAYCAST_NUM];
    int num = 0;
    PhysicsRayCastCallbackFunc func = [&points, &num](PhysicsWorld& world, const PhysicsRayCastInfo& info, void* data)->bool
    {
        if (num < MAX_MULTI_RAYCAST_NUM)
        {
            points[num++] = info.contact;
        }
        return true;
    };

    s_currScene->getPhysicsWorld()->rayCast(func, s_centre, point2, nullptr);

    _drawNode->drawSegment(s_centre, point2, 1, Color4F::RED);
    for (int i = 0; i < num; ++i)
    {
        _drawNode->drawDot(points[i], 3, Color4F(1.0f, 1.0f, 1.0f, 1.0f));
    }
    addChild(_drawNode);

    _angle += 1.5f * (float)M_PI / 180.0f;
}

std::string PhysicsDemoRayTest::subtitle() const
{
    return "Ray Test.Touch screen to add sprite.";
}

//=====================================================================================
bool PhysicsDemoJointsDistance::init()
{
    if (PhysicsDemo::init()) {
        auto sprite1 = addSpriteAtPosition(Vec2(s_centre.x - 100,s_centre.y));
        auto sprite2 = addSpriteAtPosition(Vec2(s_centre.x + 100,s_centre.y),1);

        PhysicsJointDistance* joint = PhysicsJointDistance::construct(sprite1->getPhysicsBody(), sprite2->getPhysicsBody(), Point::ZERO, Point::ZERO);
        s_currScene->getPhysicsWorld()->addJoint(joint);
        return true;
    }

    return false;
}

std::string PhysicsDemoJointsDistance::subtitle() const
{
    return "Joints Test:Distance";
}

//==========================================================================
#define CL(__className__) [](){ return __className__::create();}

namespace
{
    static std::function<Layer*()> createFunctions[] = {
        CL(PhysicsDemoCorrelationToSprite),
        CL(PhysicsDemoCollisionFiltering),
        CL(PhysicsDemoCollisionProcessing),
        CL(PhysicsDemoRayTest),
        CL(PhysicsDemoJointsDistance),
    };

    static int sceneIdx = -1;

#define MAX_LAYER (sizeof(createFunctions) / sizeof(createFunctions[0]))

    static Layer* next()
    {
        sceneIdx++;
        sceneIdx = sceneIdx % MAX_LAYER;

        auto layer = (createFunctions[sceneIdx])();
        return layer;
    }

    static Layer* back()
    {
        sceneIdx--;
        int total = MAX_LAYER;
        if( sceneIdx < 0 )
            sceneIdx += total;

        auto layer = (createFunctions[sceneIdx])();
        return layer;
    }

    static Layer* restart()
    {
        auto layer = (createFunctions[sceneIdx])();
        return layer;
    }
}

bool PhysicsDemo::init()
{
    if (Layer::init())
    {
        s_currScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

        //create title
        TTFConfig ttfConfig("fonts/arial.ttf", 32);
        auto titleLabel = Label::createWithTTF(ttfConfig,"Physics Chapter Samples");
        addChild(titleLabel, 9999);
        titleLabel->setPosition(Vec2(s_origin.x + s_visibleSize.width/2, s_origin.y + s_visibleSize.height - 30));

        //create subtitle
        std::string strSubtitle = subtitle();
        if( ! strSubtitle.empty() )
        {
            ttfConfig.fontSize = 20;
            auto subTitleLabel = Label::createWithTTF(ttfConfig, strSubtitle.c_str());
            addChild(subTitleLabel, 9999);
            subTitleLabel->setPosition(Vec2(s_origin.x + s_visibleSize.width/2, s_origin.y + s_visibleSize.height - 70));
        }

        //create menu
        auto backItem = MenuItemImage::create("leftNormal.png", "leftSelected.png", CC_CALLBACK_1(PhysicsDemo::backCallback, this) );
        auto restartItem = MenuItemImage::create("restartNormal.png", "restartSelected.png", CC_CALLBACK_1(PhysicsDemo::restartCallback, this) );
        auto nextItem = MenuItemImage::create("rightNormal.png", "rightSelected.png", CC_CALLBACK_1(PhysicsDemo::nextCallback, this) );

        auto menu = Menu::create(backItem, restartItem, nextItem, nullptr);
        menu->setPosition(Vec2::ZERO);
        addChild(menu, 9999);

        auto restartItemSize = restartItem->getContentSize();
        backItem->setPosition(s_centre.x - restartItemSize.width * 2, s_origin.y + restartItemSize.height / 2);
        restartItem->setPosition(s_centre.x, s_origin.y + restartItemSize.height / 2);
        nextItem->setPosition(s_centre.x + restartItemSize.width * 2, s_origin.y + restartItemSize.height/2);

        //create border
        auto node = Node::create();
        auto physicsBody = PhysicsBody::createEdgeBox(s_visibleSize,PhysicsMaterial(0.1f, 1, 0.0f));
        node->setPhysicsBody(physicsBody);
        node->setPosition(s_centre);
        this->addChild(node);

        //add touch event listener
        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->onTouchBegan = CC_CALLBACK_2(PhysicsDemo::onTouchBegan, this);
        touchListener->onTouchMoved = CC_CALLBACK_2(PhysicsDemo::onTouchMoved, this);
        touchListener->onTouchEnded = CC_CALLBACK_2(PhysicsDemo::onTouchEnded, this);
        touchListener->onTouchCancelled = CC_CALLBACK_2(PhysicsDemo::onTouchEnded, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
        return true;
    }

    return false;
}

void PhysicsDemo::restartCallback(Ref* sender)
{
    s_currScene = Scene::createWithPhysics();
    s_currScene->addChild( restart() );
    Director::getInstance()->replaceScene(s_currScene);
}

void PhysicsDemo::nextCallback(Ref* sender)
{
    s_currScene = Scene::createWithPhysics();
    s_currScene->addChild( next() );
    Director::getInstance()->replaceScene(s_currScene);
}

void PhysicsDemo::backCallback(Ref* sender)
{
    s_currScene = Scene::createWithPhysics();
    s_currScene->addChild( back() );
    Director::getInstance()->replaceScene(s_currScene);
}

bool PhysicsDemo::onTouchBegan(Touch* touch, Event* event)
{
    auto location = touch->getLocation();
    auto arr = s_currScene->getPhysicsWorld()->getShapes(location);

    PhysicsBody* body = nullptr;
    for (auto& obj : arr)
    {
        if ((obj->getBody()->getTag() & DRAG_BODYS_TAG) != 0)
        {
            body = obj->getBody();
            break;
        }
    }

    if (body != nullptr)
    {
        Node* mouse = Node::create();
        mouse->setPhysicsBody(PhysicsBody::create(PHYSICS_INFINITY, PHYSICS_INFINITY));
        mouse->getPhysicsBody()->setDynamic(false);
        mouse->setPosition(location);
        this->addChild(mouse);
        PhysicsJointPin* joint = PhysicsJointPin::construct(mouse->getPhysicsBody(), body, location);
        joint->setMaxForce(5000.0f * body->getMass());
        s_currScene->getPhysicsWorld()->addJoint(joint);
        _mouses.insert(std::make_pair(touch->getID(), mouse));

        return true;
    }

    return false;
}

void PhysicsDemo::onTouchMoved(Touch* touch, Event* event)
{
    auto it = _mouses.find(touch->getID());

    if (it != _mouses.end())
    {
        it->second->setPosition(touch->getLocation());
    }
}

void PhysicsDemo::onTouchEnded(Touch* touch, Event* event)
{
    auto it = _mouses.find(touch->getID());

    if (it != _mouses.end())
    {
        this->removeChild(it->second);
        _mouses.erase(it);
    }
}

Sprite* PhysicsDemo::addSpriteAtPosition(const Vec2& pos, int spriteIndex /* = 0 */, float scale /* = 1.0f */)
{
    static std::string sprites[] = {"blueSprite.png","whiteSprite.png","LightBlueSprite.png"};

    auto sprite = Sprite::create(sprites[spriteIndex]);
    auto physicsBody = PhysicsBody::createBox(Size(65.0f * scale, 81.0f * scale),PhysicsMaterial(0.1f, 1.0f, 0.0f));
    physicsBody->setTag(DRAG_BODYS_TAG);
    sprite->setScale(scale);
    sprite->setPosition(pos);
    //make `PhysicsBody` associated with sprite
    sprite->setPhysicsBody(physicsBody);
    addChild(sprite);

    return sprite;
}

Scene* Chapter12::createScene()
{
    sceneIdx = -1;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // some upfront items that we need
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    s_visibleSize = Director::getInstance()->getVisibleSize();
    s_origin = Director::getInstance()->getVisibleOrigin();
    s_centre = s_origin + s_visibleSize / 2;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene with physics world for our game to hold everything
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    s_currScene = Scene::createWithPhysics();

    s_currScene->addChild(next());

    // return the scene
    return s_currScene;
}