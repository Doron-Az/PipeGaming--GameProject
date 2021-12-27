#pragma once
#include "Pipe.h"

class PipeRounded :public Pipe
{
public:
	PipeRounded(float width, float height, int rand);
	void printFlow() override;
	void printNoflow() override;
private:
};