#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"+
#include "Constants.h"
#include "LevelEasyScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* LevelEasyScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelEasyScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelEasyScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto backGround = Sprite::create(level1);
	backGround->setPosition(Point(visibleSize.width * 0.5 + origin.x, visibleSize.height * 0.5 + origin.y));
	this->addChild(backGround);

	// Back Button
	auto backButtonMenuItem = MenuItemImage::create(backButton, "Back Button clicked",
		CC_CALLBACK_1(LevelEasyScene::goToMainMenuScene, this));
	backButtonMenuItem->setPosition(Point(visibleSize.width * 0.1 + origin.x, visibleSize.height * 0.15 + origin.y));
	
	auto menu = Menu::create(backButtonMenuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	return true;
}

void LevelEasyScene::goToMainMenuScene(cocos2d::Ref * sender)
{
	auto scene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(transitionDuration, scene));
}