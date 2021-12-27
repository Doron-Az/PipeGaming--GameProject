#pragma once
#include "Pipe.h"

class PipeCossSection :public Pipe
{
public:
	PipeCossSection(float width, float height, int rand);
	void printFlow() override;
	void printNoflow() override;
private:
	
};
