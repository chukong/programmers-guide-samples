#include "Chapter9_11.h"
#include "Chapter9.h"

#include "3d/CCSprite3D.h"
#include "3d/CCTextureCube.h"
#include "3d/CCSkybox.h"


USING_NS_CC;

static int TeapotTag = 100;
static int PlayerTag = 101;

Scene* Chapter9_11::createScene()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto scene = Scene::create();
    
    // add title
    auto label = LabelTTF::create("Skybox and CubeMap", "Arial", 24);
    label->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2).x,
                       Vec2(origin.x+visibleSize.width/2, origin.y+visibleSize.height).y - 30);
    
    scene->addChild(label, -1);
    
    //add the menu item for back to main menu
    label = LabelTTF::create("MainMenu", "Arial", 24);
    auto menuItem = MenuItemLabel::create(label);
    menuItem->setCallback([&](cocos2d::Ref *sender) {
        Director::getInstance()->replaceScene(Chapter9::createScene());
    });
    auto menu = Menu::create(menuItem, nullptr);
    menu->setPosition( Vec2::ZERO );
    menuItem->setPosition( Vec2(origin.x+visibleSize.width - 80, origin.y + 25) );
    scene->addChild(menu, 1);
    
    auto layer = Layer::create();
    scene->addChild(layer);
    
    auto _camera = Camera::createPerspective(60, visibleSize.width / visibleSize.height, 10, 1000);
    _camera->setPosition3D(Vec3(0.f, 0.f, 50.f));
    _camera->setCameraFlag(CameraFlag::USER1);
    
    //create and set our custom shader
    auto shader = GLProgram::createWithFilenames("chapter9/cube_map.vert", "chapter9/cube_map.frag");
    auto state = GLProgramState::create(shader);
    
    // create the second texture for cylinder
    auto _textureCube = TextureCube::create("chapter9/skybox/left.jpg", "chapter9/skybox/right.jpg",
                                            "chapter9/skybox/top.jpg", "chapter9/skybox/bottom.jpg",
                                            "chapter9/skybox/front.jpg", "chapter9/skybox/back.jpg");
    
    //set texture parameters
    Texture2D::TexParams tRepeatParams;
    tRepeatParams.magFilter = GL_LINEAR;
    tRepeatParams.minFilter = GL_LINEAR;
    tRepeatParams.wrapS = GL_MIRRORED_REPEAT;
    tRepeatParams.wrapT = GL_MIRRORED_REPEAT;
    _textureCube->setTexParameters(tRepeatParams);
    
    // pass the texture sampler to our custom shader
    state->setUniformTexture("u_cubeTex", _textureCube);
    
    // create a teapot
    auto _teapot = Sprite3D::create("chapter9/teapot.c3b");
    _teapot->setGLProgramState(state);
    _teapot->setPosition3D(Vec3(0, -5, 0));
    _teapot->setRotation3D(Vec3(-90, 180, 0));
    
    auto rotate_action = RotateBy::create(1.5, Vec3(0, 30, 0));
    _teapot->runAction(RepeatForever::create(rotate_action));
    
    //pass mesh's attribute to shader
    long offset = 0;
    auto attributeCount = _teapot->getMesh()->getMeshVertexAttribCount();
    for (auto i = 0; i < attributeCount; i++)
    {
        auto meshattribute = _teapot->getMesh()->getMeshVertexAttribute(i);
        state->setVertexAttribPointer(s_attributeNames[meshattribute.vertexAttrib],
                                      meshattribute.size,
                                      meshattribute.type,
                                      GL_FALSE,
                                      _teapot->getMesh()->getVertexSizeInBytes(),
                                      (GLvoid*)offset);
        
        offset += meshattribute.attribSizeBytes;
    }
    
    layer->addChild(_teapot, 0, TeapotTag);
    
    {
        // config skybox
        auto _skyBox = Skybox::create();
        
        _skyBox->setTexture(_textureCube);
        _skyBox->setScale(700.f);
        
        layer->addChild(_skyBox);
    }
    
    layer->addChild(_camera);
    layer->setCameraMask(2);
    
    // return the scene
    return scene;
}
