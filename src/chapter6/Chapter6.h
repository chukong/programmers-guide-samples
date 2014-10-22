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
    
    void selectedEvent(Ref* sender, CheckBox::EventType type);
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoLoadingBar : public UIDemo
{
public:
    CREATE_FUNC(UIDemoLoadingBar);
    
    void updateLoadingBar(float dt);
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoSlider : public UIDemo
{
public:
    CREATE_FUNC(UIDemoSlider);
    
    void sliderEvent(Ref* sender, Slider::EventType type);
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoImageView : public UIDemo
{
public:
    CREATE_FUNC(UIDemoImageView);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoText : public UIDemo
{
public:
    CREATE_FUNC(UIDemoText);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};


class UIDemoTextBMFont : public UIDemo
{
public:
    CREATE_FUNC(UIDemoTextBMFont);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoTextAtlas : public UIDemo
{
public:
    CREATE_FUNC(UIDemoTextAtlas);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoRichText : public UIDemo
{
public:
    CREATE_FUNC(UIDemoRichText);
    
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};

class UIDemoTextField : public UIDemo
{
public:
    CREATE_FUNC(UIDemoTextField);
    void textFieldEvent(Ref* sender, TextField::EventType type);
    virtual std::string subtitle() const override;
    
protected:
    virtual bool init();
};
#endif // __Scane_Chapter6__
