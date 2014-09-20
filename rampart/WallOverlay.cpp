/* ================================================ *
 *											 		*
 * 		FILE 			: WallOverlay.cpp 			*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Source for wall class		*
 *													*
 * ================================================ */
 
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#include "Matrix.h"
#include "Overlay.h"
#include "WallOverlay.h"

WallOverlay::WallOverlay(void){
	maxType = 4;
	minType = 1;

	shape.resize(6,6,0);
	rotation = 1;
	RandomizeType();
		
}

WallOverlay::WallOverlay(int x, int y,int maxType) : Overlay(x,y){
	this->maxType = maxType;
	minType = 1;
	shape.resize(6,6,0);
	rotation = 1;
	RandomizeType();
		
}

void WallOverlay::RandomizeType(int maxType){	
	this->maxType = maxType;
	float outOf1 = (float)((float)rand())/((float)RAND_MAX);
	int typeNum = (int)(((int)(outOf1*(maxType - minType + 1))) + minType);
	SetType(typeNum);
}

int WallOverlay::SetType(int type){
	this->type = type;
	switch(type){

		/*
				BB
				B
		*/
		case 1:
			SetWidth(2);
			SetHeight(2);
			break;

		/*
				B
			BB
			B
		*/
		case 2:
			SetWidth(2);
			SetHeight(3);
			break;


		/*
			B
		*/
		case 3:
			SetWidth(1);
			SetHeight(1);
			break;

		/*
			BB
			B
			B
		*/
		case 4:
			SetWidth(2);
			SetHeight(3);
			break;

		/*

			    BBB
				B B

		*/
		case 5:
			SetWidth(3);
			SetHeight(2);
			break;

		/*
				BB
				B
			BB
		*/
		case 6:
			SetWidth(3);
			SetHeight(3);
			break;
	}
	SetRotationFrame();
	return type;
}

matrix<int> WallOverlay::GetShape(void){
	return shape;
}


void WallOverlay::SetRotationFrame(void){

	//Clear fill matrix for now
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			shape.at(i,j) = 0;
		}
	}

	switch(type){

	/*
			BB
			B
	*/
	case 1:
		switch(rotation){
		case 1:
			shape.at(0,0) = 1;
			shape.at(1,0) = 1;
			shape.at(0,1) = 1;
			shape.at(1,1) = 0;
			break;
		case 2:
			shape.at(0,0) = 1;
			shape.at(1,0) = 1;
			shape.at(0,1) = 0;
			shape.at(1,1) = 1;
			break;
		case 3:
			shape.at(0,0) = 0;
			shape.at(1,0) = 1;
			shape.at(0,1) = 1;
			shape.at(1,1) = 1;
			break;
		case 4:
			shape.at(0,0) = 1;
			shape.at(1,0) = 0;
			shape.at(0,1) = 1;
			shape.at(1,1) = 1;				
			break;
		}
		break;
			




	/*
			B
		BB
		B
	*/
	case 2:
		switch(rotation){
		case 1:
		case 3:
			shape.at(1,0) = 1;
			shape.at(0,1) = 1;
			shape.at(1,1) = 1;
			shape.at(0,2) = 1;
			break;
		case 2:
		case 4:
			shape.at(0,0) = 1;
			shape.at(1,0) = 1;
			shape.at(1,1) = 1;
			shape.at(2,1) = 1;
			break;
		}
		break;

	/*

		B

	*/
			
	case 3:
		shape.at(0,0) = 1;
		break;


	/*
		BB
		B
		B
	*/
	case 4:


		switch(rotation){
			case 1:

				shape.at(0,0) = 1;
				shape.at(1,0) = 1;
				shape.at(0,1) = 1;
				shape.at(0,2) = 1;

				break;
			case 2:


				shape.at(0,0) = 1;
				shape.at(1,0) = 1;
				shape.at(2,0) = 1;
				shape.at(2,1) = 1;

				break;
			case 3:

				shape.at(1,0) = 1;
				shape.at(1,1) = 1;
				shape.at(1,2) = 1;
				shape.at(0,2) = 1;


				break;
			case 4:

				shape.at(0,0) = 1;
				shape.at(0,1) = 1;
				shape.at(1,1) = 1;
				shape.at(2,1) = 1;


				break;
		}
		break;
			

	/*

			BBB
			B B

	*/
	case 5:
		switch(rotation){
			case 1:
				shape.at(0,0) = 1;
				shape.at(1,0) = 1;
				shape.at(2,0) = 1;
				shape.at(0,1) = 1;
				shape.at(2,1) = 1;	
				break;
			case 2:
				shape.at(0,0) = 1;
				shape.at(1,0) = 1;
				shape.at(1,1) = 1;
				shape.at(1,2) = 1;
				shape.at(0,2) = 1;
				break;
			case 3:
				shape.at(0,0) = 1;
				shape.at(0,1) = 1;
				shape.at(1,1) = 1;
				shape.at(2,1) = 1;
				shape.at(2,0) = 1;

				break;
			case 4:
				shape.at(0,0) = 1;
				shape.at(1,0) = 1;
				shape.at(0,1) = 1;
				shape.at(0,2) = 1;
				shape.at(1,2) = 1;

				break;
		}
		break;


	/*
		    BB
		    B
		BB

	*/
	case 6:
		switch(rotation){
		case 1:
			shape.at(1,0) = 1;
			shape.at(2,0) = 1;
			shape.at(1,1) = 1;
			shape.at(1,2) = 1;
			shape.at(0,2) = 1;
			break;

		case 2:
		case 4:
			shape.at(0,0) = 1;
			shape.at(0,1) = 1;
			shape.at(1,1) = 1;
			shape.at(2,1) = 1;
			shape.at(2,2) = 1;
			break;

		case 3:
			shape.at(0,2) = 1;
			shape.at(1,0) = 1;
			shape.at(2,0) = 1;
			shape.at(1,1) = 1;
			shape.at(1,2) = 1;
			break;
		}

		break;



	}




}










void WallOverlay::Rotate(bool backwards){
	int tempWidth = 0;

	if(backwards == false){
		rotation++;
		if(rotation > 4){
			rotation = 1;
		}
	}else{
		rotation--;
		if(rotation < 1){
			rotation = 4;
		}
	}

	//Transpose width and height
	tempWidth = GetWidth();
	SetWidth(GetHeight());
	SetHeight(tempWidth);

	SetRotationFrame();








}

