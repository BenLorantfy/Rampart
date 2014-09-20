/* ================================================ *
 *											 		*
 * 		FILE 			: Overlay.cpp 				*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Source for overlay class	*
 *													*
 * ================================================ */

#include "Overlay.h"

Overlay::Overlay(int x,int y,int height,int width){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Overlay::SetWidth(int width){
	this->width = width;
}

void Overlay::SetHeight(int height){
	this->height = height;
}

int Overlay::GetWidth(void){
	return width;
}
	
int Overlay::GetHeight(void){
	return height;
}

int Overlay::SetX(int x){
	this->x = x;
	return x;
}
	
int Overlay::SetY(int y){
	this->y = y;
	return y;
}
	
int Overlay::GetX(void){
	return x;
}

int Overlay::GetY(void){
	return y;
}
	
int Overlay::AddX(int deltaX){
	x += deltaX;
	return x;
}

int Overlay::MinusX(int deltaX){
	x -= deltaX;
	return x;
}

int Overlay::AddY(int deltaY){
	y += deltaY;
	return y;
}

int Overlay::MinusY(int deltaY){
	y -= deltaY;
	return y;
}
