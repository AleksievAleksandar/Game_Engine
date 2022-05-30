#include "game/widget/Widget.h"
#include "manager_utils/RsrcMgr.h"

#include <iostream>

void Widget::moveUp()
{
	this->_drawParams.pos.y--;
}

void Widget::moveDown()
{
	this->_drawParams.pos.y++;
}

void Widget::moveLeft()
{
	this->_drawParams.pos.x--;
}

void Widget::moveRight()
{
	this->_drawParams.pos.x++;
}

void Widget::setNextFrame()
{
	if (!this->_drawParams._hasFrames)
	{
		std::cerr << "Trying to set next frame to image that has only one frame" << std::endl;
		return;
	}

	std::unordered_map<int32_t, Frames> frames;
	frames = gRsrcMgr->getImageDimensions();
	frames.find(this->_drawParams.rsrcId);

	for (size_t i = 0; i < 6; i++)
	{
		std::cout << "x = " << frames.at(6).at(i).x << " y = " << frames.at(6).at(i).y << std::endl;
		//std::cout << "w = " << it->second[i].w << " h = " << it->second[i].h << std::endl;
	}

	++this->_drawParams.currFrame;
	if (6 == this->_drawParams.currFrame)
	{
		this->_drawParams.currFrame = 0;
	}

	//for (size_t i = 0; i < 6; i++)
	//{
	//	std::cout << "x = " << it->second[i].x << " y = " << it->second[i].y << std::endl;
	//	//std::cout << "w = " << it->second[i].w << " h = " << it->second[i].h << std::endl;
	//}

	this->_drawParams.frame = frames.at(6).at(this->_drawParams.currFrame);
	std::cout << "curr frame = " << this->_drawParams.currFrame << std::endl;
	std::cout << "rsrc ID = " << this->_drawParams.rsrcId << std::endl;

	//std::cout << "drawParam.frame.x = " << it->second[this->_drawParams.currFrame].x << std::endl;
	//std::cout << "drawParam.frame.y = " << it->second[this->_drawParams.currFrame].y << std::endl;
	//std::cout << "drawParam.frame.w = " << it->second[this->_drawParams.currFrame].w << std::endl;
	//std::cout << "drawParam.frame.h = " << it->second[this->_drawParams.currFrame].h << std::endl;



	//this->_drawParams.frame.x = 256;
}

void Widget::setPrevFrame()
{
	auto it = gRsrcMgr->getImageDimensions().find(this->_drawParams.rsrcId);

	//for (int32_t i = 0; i < 6; i++)
	//{
	//	std::cout << "x = " << it->second[i].x << " y = " << it->second[i].y << std::endl;
	//	//std::cout << "w = " << it->second[i].w << " h = " << it->second[i].h << std::endl;
	//}

	--this->_drawParams.currFrame;
	if (-1 == this->_drawParams.currFrame)
	{
		this->_drawParams.currFrame = 5;
	}

	this->_drawParams.frame = it->second[this->_drawParams.currFrame];
	std::cout << "curr frame = " << this->_drawParams.currFrame << std::endl;
	std::cout << "rsrc ID = " << this->_drawParams.rsrcId << std::endl;

	std::cout << "drawParam.frame.x = " << it->second[this->_drawParams.currFrame].x << std::endl;
	std::cout << "drawParam.frame.y = " << it->second[this->_drawParams.currFrame].y << std::endl;
	std::cout << "drawParam.frame.w = " << it->second[this->_drawParams.currFrame].w << std::endl;
	std::cout << "drawParam.frame.h = " << it->second[this->_drawParams.currFrame].h << std::endl;
}

void Widget::setOpacity(const int32_t delta)
{
	this->_drawParams.opacity += delta;
}

DrawParams Widget::getDrawParams() const
{
	return this->_drawParams;
}
