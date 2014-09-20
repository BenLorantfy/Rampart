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