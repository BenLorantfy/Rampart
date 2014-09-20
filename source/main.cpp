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
 * 		FILE 			: main.cpp 					*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Driver for rampart game	*
 *													*
 * ================================================ */

#include <stdio.h>


#include <map>
#include <future>
#include <conio.h>
#include <conio.h>
#include <utility>

using namespace std;

#include "Matrix.h"
#include "Block.h"

#include "Console.h"
#include "Cannon.h"
#include "Overlay.h"
#include "WallOverlay.h"
#include "Base.h"

#include "Keyboard.h"
#include "Game.h"
#include "UI.h"


#pragma warning (disable : 4309 )
#pragma warning (disable : 4018 )
#pragma warning (disable : 4244 )

int main(void){
	
	//Creates interface
	UI rampart;

	//Difficulty variables
	int timeToFire = 15;
	int timeToRepair = 30;
	int roundCount = 0;

	//Show Menu
	while(rampart.ShowMenu()){
		//Show the instruction pages
		rampart.ShowInstructions();

		//Asks user for desired size of map
		rampart.AskWhatSize();

		//Starts the game
		rampart.StartGame();

		//Starts the select base stage
		rampart.SelectBase();

		//Stores the victor of the game
		int victor = -1;
		
	
		//While there is no victor
		while((victor = rampart.GetOutcome()) == -1){
			roundCount++; //Increase round count

			//Update difficulty variables
			if(roundCount == 5){
				rampart.MoreWallTypes();
				timeToRepair = 60;
				timeToFire = 25;
			}else if(roundCount == 7){
				timeToRepair = 90;
				timeToFire = 35;
			}

			//Start place cannons stage
			rampart.PlaceCannons(20);

			//Start fire cannons stage
			rampart.FireCannons(timeToFire);

			//Start repair walls stage
			rampart.RepairWalls(timeToRepair);
		}
	

		//Show the victory screen
		rampart.ShowVictoryScreen(victor);
	}

	return 0;
 }


