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
 * 		FILE 			: Block.cpp 				*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Source for block class	*
 *													*
 * ================================================ */

using namespace std;

#include <string>
#include "Block.h"

Block::Block(void){
	type = "blank";
	quadrants = "    ";
	enclosed = false;
}
	
Block::Block(string type){
	SetType(type);
}

Block& Block::operator=(string type){
	SetType(type);
	return *this;
}

void Block::SetEnclosed(void){
	enclosed = true;
}

void Block::SetNotEnclosed(void){
	enclosed = false;
}

bool Block::IsEnclosed(void){
	return enclosed;
}


bool Block::operator==(string type){
	return (this->type == type);
}

bool Block::operator!=(string type){
	return (this->type != type);
}

string Block::GetType(void){
	return type;
}

void Block::SetType(string type){
	if(type == "wall"){
		quadrants = "";
		quadrants.push_back(219);
		quadrants.push_back(219);
		quadrants.push_back(219);
		quadrants.push_back(219);
	}else if(type == "blocked"){
		quadrants = "";
		quadrants.push_back(176);
		quadrants.push_back(176);
		quadrants.push_back(176);
		quadrants.push_back(176);
	}else if(type == "cannonTopLeft"){
		quadrants = "-/@@";
	}else if(type == "cannonTopRight"){
		quadrants = "\\-@@";
	}else if(type == "cannonBottomLeft"){
		quadrants = "@@\\-";
	}else if(type == "cannonBottomRight"){
		quadrants = "@@-/";
	}else if(type == "baseTopLeft"){
		quadrants = "";
		quadrants.push_back(205);
		quadrants.push_back(201);
		quadrants.push_back(186);
		quadrants.push_back(218);
	}else if(type == "baseTopRight"){
		quadrants = "";
		quadrants.push_back(187);
		quadrants.push_back(205);
		quadrants.push_back(191);
		quadrants.push_back(186);
	}else if(type == "baseBottomLeft"){
		quadrants = "";
		quadrants.push_back(192);
		quadrants.push_back(186);
		quadrants.push_back(200);
		quadrants.push_back(205);
	}else if(type == "baseBottomRight"){
		quadrants = "";
		quadrants.push_back(186);
		quadrants.push_back(217);
		quadrants.push_back(205);
		quadrants.push_back(188);
	}else if(type == "target"){
		quadrants = "";
		quadrants.push_back(192);
		quadrants.push_back(217);
		quadrants.push_back(191);
		quadrants.push_back(218);
	}else if(type == "cannonBall"){
		quadrants = "\\/\\/";
	}else if(type == "leftRiverBank"){
		quadrants = "\\";
		quadrants.push_back(179);
		quadrants.push_back(179);
		quadrants += "/";
	}else if(type == "rightRiverBank"){
			
		quadrants.push_back(179);
		quadrants += "\\";
		quadrants += "/";
		quadrants.push_back(179);
	}else if(type == "river"){
		quadrants = "    ";

		//25% chance river block has wave
		//25% chance for each quadrant of block to have wave charachter
		float outOf1 = (float)((float)rand())/((float)RAND_MAX);
		int wave = (int)(((int)(outOf1*(15 - 0 + 1))) + 0);

		if(wave <= 3){
			quadrants.at(wave) = '~';
		}
		
	}else if(type == "blank"){
		quadrants = "    ";
	}
	this->type = type;
}

string Block::GetQuadrants(void){
	return quadrants;
}
