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
