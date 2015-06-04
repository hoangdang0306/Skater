﻿#include "Coin.h"
#include "Other/XHelper.h"
#include "Other/Tags.h"

Coin::Coin(){}
Coin::~Coin(){}

Coin* Coin::create(string fileName)
{
	Coin* coin = new Coin();
	coin->init(fileName);
	coin->autorelease();
	return coin;
}

bool Coin::init(string fileName)
{
	if (!Node::init())
		return false;

	//-------------  Khởi tạo sprite chính -------------
	_sprite = Sprite::create(fileName);
	_sprite->setPosition(0, 0);
	this->addChild(_sprite);



	//-------------   Physic Body  --------------
	body = PhysicsBody::createBox(_sprite->getBoundingBox().size, PhysicsMaterial(100.0f, 0.0f, 100.0f), Vec2(0, 0));
	body->setGravityEnable(false);
	body->setDynamic(true);
	body->setTag(Tags::COIN);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);

	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);


	return true;
}