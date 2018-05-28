#ifndef __CHAPTER5_H__
#define __CHAPTER5_H__

#include "cocos2d.h"

class Chapter5 : public cocos2d::Node
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(Chapter5);
};

#endif // __CHAPTER5_H__
