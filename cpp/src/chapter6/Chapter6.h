#ifndef __CHAPTER6_H__
#define __CHAPTER6_H__

#include "cocos2d.h"

USING_NS_CC;

class Chapter6 : public Node
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void onMenuCloseCallback(Ref* sender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Chapter6);
};

#endif // __CHAPTER6_H__
