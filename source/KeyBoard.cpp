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
 * 		FILE 			: Keyboard.cpp 				*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Source keyboard class		*
 *													*
 * ================================================ */
 
#include <stdio.h>
#include <windows.h>
#include <map>

#define IS_DOWN 0x8000

using namespace std;

#include "KeyBoard.h"

KeyBoard::KeyBoard(void){
	//keepChecking = true;
	//async(&KeyBoard::Check,this);
}

bool KeyBoard::KeyIsDown(char key){
	return (GetAsyncKeyState(key) & IS_DOWN);
}

bool KeyBoard::KeyIsUp(char key){
	return !KeyIsDown(key);
}

int KeyBoard::KeyChange(char key){
	int change = KEY_NO_CHANGE;

	//If key is in map
	if(keys.count(key)>0){
		//If key is currently pressed down...
		if(KeyIsDown(key)){
			//...and key was previously up...
			if(keys[key] == false){
				//...flag key as being down...
				keys[key] = true;

				//...and set changed flag to true and return it later
				change = KEY_DOWN;
			}
		//Else if key is currently up...
		}else{
			//...and key was previously down..
			if(keys[key] == true){
				//...flag key as being up...
				keys[key] = false;

				//...and set changed flag to true and return it later
				change = KEY_UP;
			}
		}
	//else if key hasn't been added to map, add to map
	}else{
		keys[key] = KeyIsDown(key);
	}

	return change;
}

KeyBoard::~KeyBoard(void){
	//keepChecking = false;
}