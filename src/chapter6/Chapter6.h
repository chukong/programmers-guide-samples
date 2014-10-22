#ifndef __Scane_Chapter6__
#define __Scane_Chapter6__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include <iostream>

USING_NS_CC;
using namespace cocos2d::ui;

class Chapter6
{
    public:
        static cocos2d::Scene* createScene();
};

class UIDemo : public cocos2d::Layer
{
public:
    virtual std::string subtitle() const { return "";}
    
    void restartCallback(Ref* sender);
    void nextCallback(Ref* sender);
    void backCallback(Ref* sender);
    
protected:
    virtual bool init();
};

class UIDemoLabel : public UIDemo
{
public:
    CREATE_FUNC(UIDemoLabel);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoLabelEffect : public UIDemo
{
public:
    CREATE_FUNC(UIDemoLabelEffect);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoLabelTypesetting : public UIDemo
{
public:
    CREATE_FUNC(UIDemoLabelTypesetting);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};


class UIDemoMenu : public UIDemo
{
public:
    CREATE_FUNC(UIDemoMenu);
    
    virtual std::string subtitle() const override;
    void spriteMenuItemCallback(Ref* ref);
    
protected:
    virtual bool init();
};

class UIDemoButton : public UIDemo
{
public:
    CREATE_FUNC(UIDemoButton);
   
    void touchEvent(Ref* sender, Widget::TouchEventType type);
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoCheckBox : public UIDemo
{
public:
    CREATE_FUNC(UIDemoCheckBox);
    
    void selectedEvent(Ref* sender, Widget::TouchEventType type);
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};



#endif // __Scane_Chapter6__
