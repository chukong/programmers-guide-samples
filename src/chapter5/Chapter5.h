#ifndef __CHAPTER5_H__
#define __CHAPTER5_H__

#include "cocos2d.h"

USING_NS_CC;

class Chapter5 : public Ref
{
    public:
        Chapter5();
        ~Chapter5();
    
        void initialize();
        Scene* createScene2();
        Scene* createScene3();
        Scene* createScene4();
    
        inline Scene* getScene1(){ return scene1; };
    
    protected:
        Scene* scene1;
        Scene* scene2;
        Scene* scene3;
        Scene* scene4;
    
};

#endif // __CHAPTER5_H__
