#ifndef __CHAPTER_9_6_H__
#define __CHAPTER_9_6_H__

#include "cocos2d.h"
#include "DrawNode3D.h"

USING_NS_CC;

class Chapter9_6 : public Ref
{
    public:
        static cocos2d::Scene* createScene();
};

class ABBTest : public Layer
{
public:
    CREATE_FUNC(ABBTest);
    ABBTest();
    virtual void update(float dt) override;
    void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);
    void onTouchesMoved(const std::vector<Touch*>& touches, Event* event);
protected:
    DrawNode3D* _drawAABB;
    AABB _aabb;
    Camera* _camera;
    bool _pick;
};

#endif // __CHAPTER_9_6_H__
