#include "game/widget/Widget.h"
#include "manager_utils/RsrcMgr.h"
#include "manager_utils/DrawMgr.h"

#include <iostream>

void Widget::moveUp()
{
	this->_drawParams.pos.y -= 10;
}

void Widget::moveDown()
{
	this->_drawParams.pos.y += 10;
}

void Widget::moveLeft()
{
	this->_drawParams.pos.x -= 10;
}

void Widget::moveRight()
{
	this->_drawParams.pos.x += 10;
}

void Widget::setNextFrame()
{
	if (1 == this->_drawParams.numFrames)
	{
		std::cerr << "Trying to set next frame to image that has only one frame" << std::endl;
		return;
	}

	std::unordered_map<int32_t, Frames> frames;
	frames = gRsrcMgr->getImageDimensions();
	frames.find(this->_drawParams.rsrcId);

	for (int32_t i = 0; i < this->_drawParams.numFrames; i++)
	{
		std::cout << "x = " << frames.at(this->_drawParams.rsrcId).at(i).x << " y = " << frames.at(this->_drawParams.rsrcId).at(i).y << std::endl;
	}

	++this->_drawParams.currFrame;
	if (this->_drawParams.numFrames == this->_drawParams.currFrame)
	{
		this->_drawParams.currFrame = 0;
	}

	this->_drawParams.frame = frames.at(this->_drawParams.rsrcId).at(this->_drawParams.currFrame);
	std::cout << "curr frame = " << this->_drawParams.currFrame << std::endl;
	std::cout << "rsrc ID = " << this->_drawParams.rsrcId << std::endl;
}

void Widget::setPrevFrame()
{
	if (1 == this->_drawParams.numFrames)
	{
		std::cerr << "Trying to set prev frame to image that has only one frame" << std::endl;
		return;
	}

	std::unordered_map<int32_t, Frames> frames;
	frames = gRsrcMgr->getImageDimensions();
	frames.find(this->_drawParams.rsrcId);

	for (int32_t i = 0; i < this->_drawParams.numFrames; i++)
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

void Widget::setPosition(const Point& position)
{
	this->_drawParams.pos = position;
}

void Widget::setFlipMode(const FlipMode& flipMode)
{
	this->_drawParams.flipMode = flipMode;
}

void Widget::setWidth(const int32_t delta)
{
	if (0 > (this->_drawParams.w += delta))
	{
		std::cerr << "You are trying to set this->_drawParams.w less than 0" << std::endl;
		return;
	}
	this->_drawParams.w += delta;
}

void Widget::setHeight(const int32_t delta)
{
	if (0 > (this->_drawParams.h += delta))
	{
		std::cerr << "You are trying to set this->_drawParams.h less than 0" << std::endl;
		return;
	}
	this->_drawParams.h += delta;
}

void Widget::rotateLeft(const double delta)
{
	this->_drawParams.rotationAngle -= delta;
}

void Widget::rotateRight(const double delta)
{
	this->_drawParams.rotationAngle += delta;
}

void Widget::setRotationCenter(const Point& newRotCenter)
{
	this->_drawParams.rotationCenter = newRotCenter;
}

void Widget::draw() const
{
	SDL_Texture* texture = nullptr;

	gRsrcMgr->getTextureForDrawing(texture, this->_drawParams);

	gDrawMgr->drawTexture(texture, this->_drawParams);
}
