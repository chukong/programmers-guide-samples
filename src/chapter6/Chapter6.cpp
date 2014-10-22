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
        CL(UIDemoLabelEffect),
        CL(UIDemoLabelTypesetting),
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
        //create a BMFont label
        auto bmFntLabel = Label::createWithBMFont("bitmapFontTest.fnt", "This is BMFont Label");
        bmFntLabel->setPosition(s_centre + Vec2(-50,100));
        this->addChild(bmFntLabel);
        
        //create a TTF label
        auto ttfLabel = Label::createWithTTF("This is TTF Label", "arial.ttf", 40);
        ttfLabel->setPosition(s_centre);
        this->addChild(ttfLabel);
        
        //create a TTF label from TTFConfig
        TTFConfig labelConfig;
        labelConfig.fontFilePath = "arial.ttf";
        labelConfig.fontSize = 20;
        labelConfig.glyphs = GlyphCollection::DYNAMIC;
        labelConfig.outlineSize = 0;
        labelConfig.customGlyphs = nullptr;
        labelConfig.distanceFieldEnabled = false;
        auto ttfLabelFromTTFConfig = Label::createWithTTF(labelConfig, "This is TTF Label created from TTFConfig");
        ttfLabelFromTTFConfig->setPosition(s_centre + Vec2(50, -30));
        this->addChild(ttfLabelFromTTFConfig);
        
        //create a label use SystemFont
        auto systemFontLabel = Label::createWithSystemFont("This is a Label created form System Font", "Helvetical", 36);
        systemFontLabel->setPosition(s_centre + Vec2(100,-100));
        this->addChild(systemFontLabel);
        
        //create a label use atlas file
        auto atlasLabel = Label::createWithCharMap("labelatlasimg.png",24,32,'0');
        atlasLabel->setString("12345");
        atlasLabel->setPosition(s_centre + Vec2(0,150));
        this->addChild(atlasLabel);

        
        return true;
    }
    
    return true;
}

//=====================================================================================
// MARK: - UIDemoLabelEffect
std::string UIDemoLabelEffect::subtitle() const
{
    return "Label Effect Sample Code";
}

bool UIDemoLabelEffect::init()
{
    if (UIDemo::init()) {
        
        //create a white ttf label with red shadow
        auto ttfLabelWithShadow = Label::createWithTTF("Label With Shadow", "arial.ttf", 40);
        ttfLabelWithShadow->setPosition(s_centre + Vec2(0,100));
        ttfLabelWithShadow->enableShadow(Color4B::RED, Size(2,2));
        this->addChild(ttfLabelWithShadow);
        
        //create a white ttf label with yellow outline
        auto ttfLabelWithOutline = Label::createWithTTF("Label with outline", "arial.ttf", 60);
        ttfLabelWithOutline->setPosition(s_centre);
        ttfLabelWithOutline->enableOutline(Color4B::YELLOW, 4);
        this->addChild(ttfLabelWithOutline);
        
        //create a white ttf label with green glow effect
        auto ttfLabelWithGlow = Label::createWithTTF("Label with Glow", "arial.ttf", 40);
        ttfLabelWithGlow->setPosition(s_centre + Vec2(0,-100));
        ttfLabelWithGlow->enableGlow(Color4B::GREEN);
        this->addChild(ttfLabelWithGlow);
        
        return true;
    }
    
    return true;
}

//=====================================================================================
// MARK: - UIDemoLabelTypesetting
std::string UIDemoLabelTypesetting::subtitle() const
{
    return "Label Typesetting Sample Code";
}

bool UIDemoLabelTypesetting::init()
{
    if (UIDemo::init()) {
        auto s = Director::getInstance()->getWinSize();
        TTFConfig config("arial.ttf",30);
        
        //create a label with left text alignment
        auto ttf0 = Label::createWithTTF(config,"Alignment 0\nnew line",TextHAlignment::LEFT);
        ttf0->setPosition(s_centre + Vec2(-100, 100));
        this->addChild(ttf0);
        
        //create a long sentence with line wrap
        TTFConfig config1("arial.ttf",14);
        auto ttf1 = Label::createWithTTF(config1,"This is a very long sentence!This is a very long sentence!This is a very long sentence!This is a very long sentence!",
                                         TextHAlignment::LEFT,
                                         200);
//        ttf1->setLineBreakWithoutSpace(true);     //uncomment this line to see the affects
        ttf1->setPosition(s_centre);
        this->addChild(ttf1);
        
        
        //create a label with kerning
        TTFConfig config2("arial.ttf",24);
        auto ttf2 = Label::createWithTTF(config1,"Label with Kerning!");
        ttf2->setPosition(s_centre + Vec2(0,-100));
        ttf2->setTextColor(Color4B::RED);
        ttf2->setAdditionalKerning(8.0);
        this->addChild(ttf2);
        
        
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
        //create a menu with Sprites, one menuItem which don't use lambda
        auto menuItemSprite = MenuItemSprite::create(Sprite::create("menuItemSpriteNormal.png"),
                                                     Sprite::create("menuItemSpriteSelected.png"),
                                                     CC_CALLBACK_1(UIDemoMenu::spriteMenuItemCallback, this));
        menuItemSprite->setPosition(s_centre + Vec2(0,100));
        
        auto menuSprite = Menu::createWithItem(menuItemSprite);
        //we must call menu->setPosition() here
        menuSprite->setPosition(Vec2::ZERO);
        this->addChild(menuSprite);
        
        //create a menu with Labels, three menu items which use lambda
        Vector<MenuItem*> labelItems;
        for (int i = 0; i < 3; ++i) {
            std::string str = StringUtils::format("Label MenuItem %d", i+1);
            auto label = Label::createWithSystemFont(str, "Arial", 20);
            MenuItemLabel *labelItem = MenuItemLabel::create(label,[=](Ref* sender){
                auto labelItem = (MenuItemLabel*)sender;
                CCLOG("label item %d is clicked", labelItem->getTag());
                
            });
            labelItem->setTag(i+1);
            labelItem->setPosition(s_centre + Vec2((i+1) * (labelItem->getContentSize().width + 20) - 400, 0));
            labelItems.pushBack(labelItem);
        }
        auto menuLabel = Menu::createWithArray(labelItems);
        menuLabel->setPosition(Vec2::ZERO);
        this->addChild(menuLabel);
        
        //create a menu with Toggle MenuItems and alignment
        auto menuItemImage = MenuItemImage::create("menuItemSpriteNormal.png", "menuItemSpriteSelected.png",[=](Ref*){
            CCLOG("menu item image be clicked!");
        });
        
        auto menuItemOn = MenuItemFont::create("On", nullptr);
        auto menuItemOff = MenuItemFont::create("Off", nullptr);
        auto menuItemToggle = MenuItemToggle::createWithCallback([=](Ref* sender){
            auto toggleItem = (MenuItemToggle*)sender;
            //pay attention to the log
            if (toggleItem->getSelectedItem() == menuItemOn) {
                CCLOG("off menu clicked!");
            }else{
                CCLOG("on menu clicked!");
            }
        }, menuItemOn, menuItemOff,nullptr);
        auto menuMixed = Menu::create(menuItemImage, menuItemToggle,nullptr);
        menuMixed->alignItemsVertically();
        menuMixed->setPosition(s_centre + Vec2(50,-100));
        this->addChild(menuMixed);
        
        return true;
    }
    
    return true;
}

void UIDemoMenu::spriteMenuItemCallback(cocos2d::Ref *ref)
{
    CCLOG("sprite menu item clicked!");
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
