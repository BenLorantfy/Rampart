/* ================================================ *
 *											 		*
 * 		FILE 			: Base.cpp 					*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Source for base class		*
 *													*
 * ================================================ */

#include "Base.h"

Base::Base(int x, int y, int player){
	this->x = x;
	this->y = y;
	this->player = player;
}
int Base::GetPlayer(void){
	return player;
}
int Base::GetX(void){
	return x;
}
int Base::GetY(void){
	return y;
}
