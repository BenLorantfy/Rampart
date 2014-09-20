/* ================================================ *
 *											 		*
 * 		FILE 			: Console.cpp 				*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Source for console class	*
 *													*
 * ================================================ */

#include <windows.h>
#include <stdio.h>

#include <mutex>

using namespace std;

#include "Block.h"
#include "Console.h"

mutex output;

void Console::MoveCursor(int x, int y){
	COORD point = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void Console::PrintGameChar(int x, int y, char charchter){
	y += 5;
	MoveCursor(x,y);
	printf("%c",charchter);
}

void Console::Print(int x, int y, char* str){
	output.lock();
	MoveCursor(x,y);
	printf("%s",str);
	output.unlock();
}

void Console::Print(int x, int y, string str){
	output.lock();
	MoveCursor(x,y);
	printf("%s",str.c_str());
	output.unlock();
}

void Console::DrawBlock(int x, int y, Block& block){
	output.lock();
	x *= 2;
	y *= 2;
	if(block.IsEnclosed() && block == "blank"){
		PrintGameChar(x + 1,y    ,177);
		PrintGameChar(x    ,y    ,177);
		PrintGameChar(x    ,y + 1,177);
		PrintGameChar(x + 1,y + 1,177);
	}else{
		string quadrants = block.GetQuadrants();

		PrintGameChar(x + 1,y    ,quadrants.at(0));
		PrintGameChar(x    ,y    ,quadrants.at(1));
		PrintGameChar(x    ,y + 1,quadrants.at(2));
		PrintGameChar(x + 1,y + 1,quadrants.at(3));
	}
	output.unlock();
}

void Console::Clear(void){
	system("cls");
}
