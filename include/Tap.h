#pragma once

#include "MovingObject.h"

class Tap : public MovingObject 
{
public:
	Tap(float width, float height, int rand);
	void printFlow() override;
	void printNoflow() override;
private:
	
};