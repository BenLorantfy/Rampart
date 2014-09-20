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
