#include "Chapter6.h"


USING_NS_CC;

//==========================================================================
#define CL(__className__) [](){ return __className__::create();}
static Size s_visibleSize;
static Vec2 s_origin;
static Vec2 s_centre;
static Scene* s_currScene;


namespace
{
    static std::function<Layer*()> createFunctions[] = {
        CL(UIDemoLabel),
        CL(UIDemoMenu),
        CL(UIDemoTextField),
        CL(UIDemoControlExtensions),
        CL(UIDemoEditBox),
        CL(UIDemoScrollView),
        CL(UIDemoTableView),
    };
    
    static int sceneIdx = -1;
    
#define MAX_LAYER (sizeof(createFunctions) / sizeof(createFunctions[0]))
    
    static Layer* next()
    {
        sceneIdx++;
        sceneIdx = sceneIdx % MAX_LAYER;
        
        auto layer = (createFunctions[sceneIdx])();
        return layer;
    }
    
    static Layer* back()
    {
        sceneIdx--;
        int total = MAX_LAYER;
        if( sceneIdx < 0 )
            sceneIdx += total;
        
        auto layer = (createFunctions[sceneIdx])();
        return layer;
    }
    
    static Layer* restart()
    {
        auto layer = (createFunctions[sceneIdx])();
        return layer;
    }
}

Scene* Chapter6::createScene()
{
    sceneIdx = -1;
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // some upfront items that we need
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    s_visibleSize = Director::getInstance()->getVisibleSize();
    s_origin = Director::getInstance()->getVisibleOrigin();
    s_centre = s_origin + s_visibleSize / 2;
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene with physics world for our game to hold everything
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    s_currScene = Scene::create();
    
    s_currScene->addChild(next());
    
    // return the scene
    return s_currScene;
}

bool UIDemo::init()
{
    if (Layer::init())
    {
        //create title
        TTFConfig ttfConfig("arial.ttf", 32);
        auto titleLabel = Label::createWithTTF(ttfConfig,"UI Chapter Samples");
        addChild(titleLabel, 9999);
        titleLabel->setPosition(Vec2(s_origin.x + s_visibleSize.width/2, s_origin.y + s_visibleSize.height - 30));
        
        //create subtitle
        std::string strSubtitle = subtitle();
        if( ! strSubtitle.empty() )
        {
            ttfConfig.fontSize = 20;
            auto subTitleLabel = Label::createWithTTF(ttfConfig, strSubtitle.c_str());
            addChild(subTitleLabel, 9999);
            subTitleLabel->setPosition(Vec2(s_origin.x + s_visibleSize.width/2, s_origin.y + s_visibleSize.height - 70));
        }
        
        //create menu
        auto backItem = MenuItemImage::create("leftNormal.png", "leftSelected.png", CC_CALLBACK_1(UIDemo::backCallback, this) );
        auto restartItem = MenuItemImage::create("restartNormal.png", "restartSelected.png", CC_CALLBACK_1(UIDemo::restartCallback, this) );
        auto nextItem = MenuItemImage::create("rightNormal.png", "rightSelected.png", CC_CALLBACK_1(UIDemo::nextCallback, this) );
        
        auto menu = Menu::create(backItem, restartItem, nextItem, nullptr);
        menu->setPosition(Vec2::ZERO);
        addChild(menu, 9999);
        
        auto restartItemSize = restartItem->getContentSize();
        backItem->setPosition(s_centre.x - restartItemSize.width * 2, s_origin.y + restartItemSize.height / 2);
        restartItem->setPosition(s_centre.x, s_origin.y + restartItemSize.height / 2);
        nextItem->setPosition(s_centre.x + restartItemSize.width * 2, s_origin.y + restartItemSize.height/2);
        
        
        return true;
    }
    
    return false;
}

void UIDemo::restartCallback(Ref* sender)
{
    s_currScene = Scene::create();
    s_currScene->addChild( restart() );
    Director::getInstance()->replaceScene(s_currScene);
}

void UIDemo::nextCallback(Ref* sender)
{
    s_currScene = Scene::create();
    s_currScene->addChild( next() );
    Director::getInstance()->replaceScene(s_currScene);
}

void UIDemo::backCallback(Ref* sender)
{
    s_currScene = Scene::create();
    s_currScene->addChild( back() );
    Director::getInstance()->replaceScene(s_currScene);
}

//=====================================================================================
// MARK: - UIDemoLabel
std::string UIDemoLabel::subtitle() const
{
    return "Label Sample Code";
}

bool UIDemoLabel::init()
{
    if (UIDemo::init()) {
        
      
        return true;
    }
    
    return true;
}

//=====================================================================================
// MARK: - UIDemoMenu
std::string UIDemoMenu::subtitle() const
{
    return "Menu Sample Code";
}

bool UIDemoMenu::init()
{
    if (UIDemo::init()) {
        
        
        return true;
    }
    
    return true;
}

//=====================================================================================
// MARK: - UIDemoTextField
std::string UIDemoTextField::subtitle() const
{
    return "TextField Sample Code";
}

bool UIDemoTextField::init()
{
    if (UIDemo::init()) {
        
        
        return true;
    }
    
    return true;
}

//=====================================================================================
// MARK: - UIDemoControlExtensions
std::string UIDemoControlExtensions::subtitle() const
{
    return "ControlExtensions Sample Code";
}

bool UIDemoControlExtensions::init()
{
    if (UIDemo::init()) {
        
        
        return true;
    }
    
    return true;
}

//=====================================================================================
// MARK: - UIDemoEditBox
std::string UIDemoEditBox::subtitle() const
{
    return "EditBox Sample Code";
}

bool UIDemoEditBox::init()
{
    if (UIDemo::init()) {
        
        
        return true;
    }
    
    return true;
}

//=====================================================================================
// MARK: - UIDemoScrollView
std::string UIDemoScrollView::subtitle() const
{
    return "ScrollView Sample Code";
}

bool UIDemoScrollView::init()
{
    if (UIDemo::init()) {
        
        
        return true;
    }
    
    return true;
}

//=====================================================================================
// MARK: - UIDemoTableView
std::string UIDemoTableView::subtitle() const
{
    return "TableView Sample Code";
}

bool UIDemoTableView::init()
{
    if (UIDemo::init()) {
        
        
        return true;
    }
    
    return true;
}
