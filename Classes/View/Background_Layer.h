#ifndef _Start_Layer_
#define _Start_Layer_
#include "cocos2d.h"
USING_NS_CC;

class Background_Layer : public Layer
{
public:
	Background_Layer();
	~Background_Layer();
	static Background_Layer * create_Start_Layer();
	bool init();
};

#endif