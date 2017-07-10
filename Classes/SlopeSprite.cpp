#include "SlopeSprite.h"
#include "GlobalValues.h"
#include "MyBodyParser.h"

SlopeSprite::SlopeSprite(bool isHelper)
{
	this->isHelper = isHelper;
}

SlopeSprite::~SlopeSprite()
{
}

SlopeSprite * SlopeSprite::createSlopeSprite(bool isHelper)
{
	auto spritePNG = spriteHelperSlope;
	if (!isHelper)
	{
		spritePNG = spriteObstacleSlope;
	}
	
	auto slope = new SlopeSprite(isHelper);

	if (slope && slope->initWithFile(spritePNG)) {
		slope->autorelease();
		
		bool b = MyBodyParser::getInstance()->parseJsonFile(jsonRamp);
		if (b) {
			CCLOG(">>> TRUE");
		}
		auto sloepBody = MyBodyParser::getInstance()->bodyFormJson(slope, jsonNameRamp, PHYSICSBODY_MATERIAL_DEFAULT);
		CCLOG(">>> SLOPE");
		if (sloepBody != nullptr)
		{
			CCLOG(">>> No Slope");
			sloepBody->setDynamic(false);
			slope->setPhysicsBody(sloepBody);
		}

		return slope;
	}
	CC_SAFE_DELETE(slope);
	return slope = nullptr;
}

void SlopeSprite::setPosition(const Point& pos) {
	Sprite::setPosition(pos);
	//if (!_nextPosition.equals(pos)) {
	//	_nextPosition = pos;
	//}
}


