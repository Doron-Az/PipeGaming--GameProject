#pragma once
#include "Pipe.h"

class PipeStraight : public Pipe
{
public:
	PipeStraight(float width, float height, int rand);
	void printFlow() override;
	void printNoflow() override;
private:
};