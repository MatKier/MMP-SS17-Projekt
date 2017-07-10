#include "SlopeSprite.h"
#include "GlobalValues.h"
#include "MyBodyParser.h"

SlopeSprite::SlopeSprite()
{
}

SlopeSprite::~SlopeSprite()
{
}

SlopeSprite * SlopeSprite::createSlopeSprite()
{
	auto spritePNG = spriteHelperSlopeMedium;
	
	auto slope = new SlopeSprite();

	if (slope && slope->initWithFile(spritePNG)) {
		slope->autorelease();
		
		bool b = MyBodyParser::getInstance()->parseJsonFile(jsonSlope);
		if (b) {
			CCLOG(">>> TRUE");
		}
		auto sloepBody = MyBodyParser::getInstance()->bodyFormJson(slope, jsonNameSlope, PHYSICSBODY_MATERIAL_DEFAULT);
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



