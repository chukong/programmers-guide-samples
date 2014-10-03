#ifndef __CHAPTER2LEVEL1_H__
#define __CHAPTER2LEVEL1_H__

#include "cocos2d.h"

#include <iostream>

USING_NS_CC;

class Chapter2Level1 : public Ref
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    //virtual bool init();
    
    // a selector callback
    //void onMenuCloseCallback(Ref* sender);
    
    // implement the "static create()" method manually
    //CREATE_FUNC(Chapter2Level1);
    
    //void createWalkingPath(const Size& _visibleSize, Size& _playingSize);
    //void createSpriteCharacter(const Size& _visibleSize, const Size& _playingSize);
    //void createBlocks(const Size& _visibleSize, const Size& _playingSize);
    //void createPlayerLabels(const Size& _visibleSize, const Size& _playingSize);
    
    void createSprites();
    void moveSprite(float dt);

private:
    //cocos2d::Sprite* sprite1;
};

#endif // __CHAPTER2LEVEL1_H__
