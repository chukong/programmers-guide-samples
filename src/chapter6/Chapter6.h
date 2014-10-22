#ifndef __Scane_Chapter6__
#define __Scane_Chapter6__

#include "cocos2d.h"

#include <iostream>

USING_NS_CC;

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

class UIDemoTextField : public UIDemo
{
public:
    CREATE_FUNC(UIDemoTextField);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoControlExtensions : public UIDemo
{
public:
    CREATE_FUNC(UIDemoControlExtensions);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoEditBox : public UIDemo
{
public:
    CREATE_FUNC(UIDemoEditBox);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoScrollView : public UIDemo
{
public:
    CREATE_FUNC(UIDemoScrollView);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoTableView : public UIDemo
{
public:
    CREATE_FUNC(UIDemoTableView);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};


#endif // __Scane_Chapter6__
