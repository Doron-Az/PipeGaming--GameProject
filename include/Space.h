#include "StaticObject.h"

class Space : public StaticObject 
{
public:
	Space(float height,float width);
	void printFlow() override;
	void printNoflow() override;


private:
};