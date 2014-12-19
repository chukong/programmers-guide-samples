#include "Chapter9_4.h"
#include "Chapter9.h"

USING_NS_CC;

Scene* Chapter9_4::createScene()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    static std::string  girlPants[] = {"Girl_LowerBody01", "Girl_LowerBody02"};
    static int usePantsId = 0;
    static std::string  girlUpperBody[] = {"Girl_UpperBody01", "Girl_UpperBody02"};
    static int useUpBodyId = 0;
    static std::string  girlShoes[] = {"Girl_Shoes01", "Girl_Shoes02"};
    static int useShoesId = 0;
    static std::string  girlHair[] = {"Girl_Hair01", "Girl_Hair02"};
    static int useHairId = 0;
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("3D model animation", "Arial", 24);
    label->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                       Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - 30);
    
    scene->addChild(label, -1);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create sprite3D
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    std::string fileName = "ReskinGirl.c3b";
    static Sprite3D* sprite = nullptr;
    if(sprite == nullptr)
        sprite = Sprite3D::create(fileName);
    sprite->setScale(6.f);
    sprite->setPosition( Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                         Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).y );
    auto animation = Animation3D::create(fileName);
    if (animation)
    {
        auto animate = Animate3D::create(animation);
        sprite->runAction(RepeatForever::create(animate));
    }
    scene->addChild(sprite);

    auto girlPants_ = sprite->getMeshByName(girlPants[1]);
    if(girlPants)
    {
        girlPants_->setVisible(false);
    }
    auto girlShoes_ = sprite->getMeshByName(girlShoes[1]);
    if(girlShoes)
    {
        girlShoes_->setVisible(false);
    }
    auto girlHair_ = sprite->getMeshByName(girlHair[1]);
    if(girlHair)
    {
        girlHair_->setVisible(false);
    }
    auto girlUpBody_ = sprite->getMeshByName( girlUpperBody[1]);
    if(girlUpBody_)
    {
        girlUpBody_->setVisible(false);
    }
    
    // add the menu for reskin
    auto label1 = LabelTTF::create("Hair", "Arial", 24);
    auto item1 = MenuItemLabel::create(label1);
    item1->setCallback([&](cocos2d::Ref *sender) {
        useHairId++;
        if(useHairId > 1 )
        {
            useHairId = 0;
        }
        if(useHairId >= 0  && sprite)
        {
            for(int i = 0; i < 2; i++ )
            {
                auto subMesh = sprite->getMeshByName(girlHair[i]);
                if(subMesh)
                {
                    if(i == useHairId )
                    {
                        subMesh->setVisible(true);
                    }
                    else
                    {
                        subMesh->setVisible(false);
                    }
                }
            }
        }
    });
    
    auto label2 = LabelTTF::create("Glasses", "Arial", 24);
    auto item2 = MenuItemLabel::create(label2);
    item2->setCallback([&](cocos2d::Ref *sender) {
        auto subMesh = sprite->getMeshByName("Girl_Glasses01");
        if(subMesh)
        {
            if(subMesh->isVisible())
            {
                subMesh->setVisible(false);
            }
            else
            {
                subMesh->setVisible(true);
            }
        }
    });
    
    auto label3 = LabelTTF::create("Coat", "Arial", 24);
    auto item3 = MenuItemLabel::create(label3);
    item3->setCallback([&](cocos2d::Ref *sender) {
        useUpBodyId++;
        if(useUpBodyId > 1 )
        {
            useUpBodyId = 0;
        }
        if(useUpBodyId >= 0  && sprite)
        {
            for(int i = 0; i < 2; i++ )
            {
                auto subMesh = sprite->getMeshByName(girlUpperBody[i]);
                if(subMesh)
                {
                    if(i == useUpBodyId )
                    {
                        subMesh->setVisible(true);
                    }
                    else
                    {
                        subMesh->setVisible(false);
                    }
                }
            }
        }
    });
    
    auto label4 = LabelTTF::create("Pants", "Arial", 24);
    auto item4 = MenuItemLabel::create(label4);
    item4->setCallback([&](cocos2d::Ref *sender) {
        usePantsId++;
        if(usePantsId > 1 )
        {
            usePantsId = 0;
        }
        if(usePantsId >= 0  && sprite)
        {
            for(int i = 0; i < 2; i++ )
            {
                auto subMesh = sprite->getMeshByName(girlPants[i]);
                if(subMesh)
                {
                    if(i == usePantsId )
                    {
                        subMesh->setVisible(true);
                    }
                    else
                    {
                        subMesh->setVisible(false);
                    }
                }
            }
        }
    });
    
    auto label5 = LabelTTF::create("Shoes", "Arial", 24);
    auto item5 = MenuItemLabel::create(label5);
    item5->setCallback([&](cocos2d::Ref *sender) {
        useShoesId++;
        if(useShoesId > 1 )
        {
            useShoesId = 0;
        }
        if(useShoesId >= 0  && sprite)
        {
            for(int i = 0; i < 2; i++ )
            {
                auto subMesh = sprite->getMeshByName(girlShoes[i]);
                if(subMesh)
                {
                    if(i == useShoesId )
                    {
                        subMesh->setVisible(true);
                    }
                    else
                    {
                        subMesh->setVisible(false);
                    }
                }
            }
        }
    });
    
    auto itemSize = item1->getContentSize();
    item1->setPosition( Vec2(origin.x + 50, origin.y+visibleSize.height - itemSize.height * 2));
    item2->setPosition( Vec2(origin.x + 50, origin.y+visibleSize.height - itemSize.height * 3));
    item3->setPosition( Vec2(origin.x + 50, origin.y+visibleSize.height - itemSize.height * 4));
    item4->setPosition( Vec2(origin.x + 50, origin.y+visibleSize.height - itemSize.height * 5));
    item5->setPosition( Vec2(origin.x + 50, origin.y+visibleSize.height - itemSize.height * 6));
    auto pMenu1 = CCMenu::create(item1,item2,item3,item4,item5,NULL);
    pMenu1->setPosition(Vec2(0,0));
    scene->addChild(pMenu1, 10);
    
    //add the menu item for back to main menu
    label = LabelTTF::create("MainMenu", "Arial", 24);
    auto menuItem = MenuItemLabel::create(label);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        sprite = nullptr;
        Director::getInstance()->replaceScene(Chapter9::createScene());
    });
    auto menu = Menu::create(menuItem, nullptr);
    menu->setPosition( Vec2::ZERO );
    menuItem->setPosition( Vec2(origin.x+visibleSize.width - 80, origin.y + 25) );
    scene->addChild(menu, 1);
    
    // return the scene
    return scene;
}
