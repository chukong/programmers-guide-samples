#ifndef __CHAPTER_9_7_H__
#define __CHAPTER_9_7_H__

#include "cocos2d.h"
#include "DrawNode3D.h"

USING_NS_CC;

class Chapter9_7 : public Ref
{
    public:
        static cocos2d::Scene* createScene();
};

class OBBTest : public Layer
{
public:
    CREATE_FUNC(OBBTest);
    OBBTest();
    virtual void update(float dt) override;
    void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);
    void onTouchesMoved(const std::vector<Touch*>& touches, Event* event);
protected:
    DrawNode3D* _drawAABB;
    OBB _obb;
    Sprite3D* _sprite;
    Camera* _camera;
    bool _pick;
};

#endif // __CHAPTER_10_6_H__
