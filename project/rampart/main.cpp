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


