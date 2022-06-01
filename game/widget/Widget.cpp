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
		std::cout << "x = " << frames.at(this->_drawParams.rsrcId).at(i).x << " y = " << frames.at(this->_drawParams.rsrcId).at(i).y << std::endl;
	}

	++this->_drawParams.currFrame;
	if (6 == this->_drawParams.currFrame)
	{
		this->_drawParams.currFrame = 0;
	}

	this->_drawParams.frame = frames.at(this->_drawParams.rsrcId).at(this->_drawParams.currFrame);
	std::cout << "curr frame = " << this->_drawParams.currFrame << std::endl;
	std::cout << "rsrc ID = " << this->_drawParams.rsrcId << std::endl;
}

void Widget::setPrevFrame()
{
	if (!this->_drawParams._hasFrames)
	{
		std::cerr << "Trying to set prev frame to image that has only one frame" << std::endl;
		return;
	}

	std::unordered_map<int32_t, Frames> frames;
	frames = gRsrcMgr->getImageDimensions();
	frames.find(this->_drawParams.rsrcId);

	for (size_t i = 0; i < 6; i++)
	{
		std::cout << "x = " << frames.at(this->_drawParams.rsrcId).at(i).x << " y = " << frames.at(this->_drawParams.rsrcId).at(i).y << std::endl;
	}

	--this->_drawParams.currFrame;
	if (-1 == this->_drawParams.currFrame)
	{
		this->_drawParams.currFrame = this->_drawParams.numFrames - 1;;
	}

	this->_drawParams.frame = frames.at(this->_drawParams.rsrcId).at(this->_drawParams.currFrame);
	std::cout << "curr frame = " << this->_drawParams.currFrame << std::endl;
	std::cout << "rsrc ID = " << this->_drawParams.rsrcId << std::endl;
}

void Widget::setOpacity(const int32_t delta)
{
	this->_drawParams.opacity += delta;
}

DrawParams Widget::getDrawParams() const
{
	return this->_drawParams;
}
