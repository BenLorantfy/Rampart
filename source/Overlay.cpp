/*

Copyright (c) 2014, Benjamin Lorantfy
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

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
