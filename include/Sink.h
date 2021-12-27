#pragma once
#include "StaticObject.h"

class Sink : public StaticObject
{
public:
	Sink(float width, float height);
	void printFlow() override;
	void printNoflow() override;

private:
};