#ifndef __SAMPLES_CHAPTER_12_H__
#define __SAMPLES_CHAPTER_12_H__

#include "cocos2d.h"

USING_NS_CC;

class Chapter12
{
public:
    static cocos2d::Scene* createScene();
};

class PhysicsDemo : public cocos2d::Layer
{
public:
    virtual std::string subtitle() const { return "";}
    
	void restartCallback(Ref* sender);
	void nextCallback(Ref* sender);
	void backCallback(Ref* sender);
    
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);

protected:
    virtual bool init();

    Sprite* addSpriteAtPosition(const Vec2& pos,int spriteIndex = 0, float scale = 1.0f);

    std::unordered_map<int, Node*> _mouses;
};

class PhysicsDemoCorrelationToSprite : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoCorrelationToSprite);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class PhysicsDemoCollisionFiltering : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoCollisionFiltering);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class PhysicsDemoCollisionProcessing : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoCollisionProcessing);
    
    virtual std::string subtitle() const override;
    
    bool onContactBegin(PhysicsContact& contact);

    void tick(float dt);

protected:
    virtual bool init();
};

class PhysicsDemoJointsDistance : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoJointsDistance);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class PhysicsDemoRayTest : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoRayTest);
    
    virtual std::string subtitle() const override;
    
    void tick(float dt);
protected:
    virtual bool init();

    DrawNode* _drawNode;
    float _angle;
};

#endif // __SAMPLES_CHAPTER_12_H__
