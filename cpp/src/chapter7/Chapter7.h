#ifndef __CHAPTER7_H__
#define __CHAPTER7_H__

#include "cocos2d.h"

class Chapter7 : public cocos2d::Node
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void onMenuCloseCallback(cocos2d::Ref* sender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Chapter7);
};

#endif // __CHAPTER6_H__
