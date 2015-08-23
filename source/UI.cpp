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
 * 		FILE 			: WallOverlay.cpp 			*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Source for base class		*
 *													*
 * ================================================ */

#include <map>
#include <future>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <utility>

using namespace std;

#include "Matrix.h"
#include "Block.h"

#include "Console.h"
#include "Cannon.h"
#include "Overlay.h"
#include "WallOverlay.h"
#include "Base.h"

#include "Game.h"
#include "Keyboard.h"

#include "UI.h"


bool UI::ShowMenu(void){
	bool play = true;
	char option = 'a';
	system("cls");

	printf("\n");
	printf("%*s    _____ _____ _____ _____ _____ _____ _____ \n",17,"");
	printf("%*s   | __  |  _  |     |  _  |  _  | __  |_   _|\n",17,"");
	printf("%*s   |    -|     | | | |   __|     |    -| | |  \n",17,"");
	printf("%*s   |__|__|__|__|_|_|_|__|  |__|__|__|__| |_|  \n",17,"");
	printf("\n");
	printf("%*s=================================================\n",17,"");
	printf("\n");

		
	//http://www.retrojunkie.com/asciiart/weapons/cannon.htm
	//http://www.ascii-art.de/ascii/c/castle.txt

	printf("%*s                    "    ,CANNON_OFFSET,"");		printf("%*s                            ,.=,,==. ,,_\n"               ,CASTLE_OFFSET,"");
	printf("%*s                    "    ,CANNON_OFFSET,"");		printf("%*s           _ ,====, _    |I|`` ||  `|I `|\n"              ,CASTLE_OFFSET,"");
	printf("%*s                    "    ,CANNON_OFFSET,"");		printf("%*s          |`I|    || `==,|``   ^^   ``  |\n"              ,CASTLE_OFFSET,"");
	printf("%*s     Press space    "    ,CANNON_OFFSET,"");		printf("%*s          | ``    ^^    ||_,===TT`==,,_ |\n"              ,CASTLE_OFFSET,"");
	printf("%*s      to start      "    ,CANNON_OFFSET,"");		printf("%*s          |,==Y``Y==,,__| \\L=_-`'   +J/`\n"              ,CASTLE_OFFSET,"");
	printf("%*s   or 'q' to quit   "    ,CANNON_OFFSET,"");		printf("%*s           \\|=_  ' -=#J/..-|=_-     =|\n"                ,CASTLE_OFFSET,"");
	printf("%*s                    "    ,CANNON_OFFSET,"");		printf("%*s            |=_   -;-='`. .|=_-     =|----T--,\n"         ,CASTLE_OFFSET,"");
	printf("%*s                __  "    ,CANNON_OFFSET,"");		printf("%*s            |=/\\  -|=_-. . |=_-/^\\  =||-|-|::|____\n"   ,CASTLE_OFFSET,"");
	printf("%*s               /  \\ "   ,CANNON_OFFSET,"");		printf("%*s            |=||  -|=_-. . |=_-| |  =|-|-||::\\____\n"    ,CASTLE_OFFSET,"");
	printf("%*s         .-.  |    |"    ,CANNON_OFFSET,"");		printf("%*s            |=LJ  -|=_-. . |=_-|_|  =||-|-|:::::::\n"     ,CASTLE_OFFSET,"");
	printf("%*s *    _.-'  \\  \\__/ "  ,CANNON_OFFSET,"");		printf("%*s            |=_   -|=_-_.  |=_-     =|-|-||::::::\n"      ,CASTLE_OFFSET,"");
	printf("%*s  \\.-'       \\      "  ,CANNON_OFFSET,"");		printf("%*s            |=_   -|=//^\\. |=_-     =||-|-|:::::::\n"    ,CASTLE_OFFSET,"");
	printf("%*s /          _/      "    ,CANNON_OFFSET,"");		printf("%*s        ,   |/&_,_-|=||  | |=_-     =|-|-||:::::::\n"     ,CASTLE_OFFSET,"");
	printf("%*s|      _  /\"        "   ,CANNON_OFFSET,"");		printf("%*s     ,--``8%%,/    ',%%||  | |=_-     =||-|-|%%::::::\n"  ,CASTLE_OFFSET,"");
	printf("%*s|     /_\\'          "   ,CANNON_OFFSET,"");		printf("%*s ,---`_,888`  ,.'''''`-.,|,|/!,--,.&\|&\\-,|&#:::::\n"    ,CASTLE_OFFSET,"");
	printf("%*s \\    \\_/           "  ,CANNON_OFFSET,"");		printf("%*s|;:;K`__,...;=\\_____,=``           %%%%%%&     %%#,---\n",CASTLE_OFFSET,"");
	printf("%*s  \"\"\"\"              ",CANNON_OFFSET,"");		printf("%*s|;::::::::::::|       `'.________+-------\\   ``"         ,CASTLE_OFFSET,"");
		
	bool doALoopJob = true;
	while(doALoopJob){
		if(keyboard.KeyChange('Q') == KEY_UP){
			doALoopJob = false;
			play = false;
		}else if(keyboard.KeyChange(' ') == KEY_UP){
			doALoopJob = false;
		}
	}

	return play;
}

void UI::ShowInstructions(void){

	system("cls");
	printf("\n");
	printf(" Instructions\n");
	printf(" ============\n\n");

	printf(" 1) Select Your Base:\n");
	printf(" The first stage of the game will let you select from a number of bases.\n");
	printf(" Press your controls' up and down key to change bases, and your controls'\n");
	printf(" action key to select the base.  The base you select will be surrounded\n");
	printf(" with your starting walls, and your initial territory will be marked.\n\n");

	printf(" 2) Place Cannons:\n");
	printf(" The next stage will give you an opportunity to place your starting cannons.\n");
	printf(" You are only able to place cannons in the territory you own.  You own all\n");
	printf(" territory surrounded by your walls.  Cannons in territory you used to own\n");
	printf(" will not work.\n\n");

	printf(" 3) Fire Cannons:\n");
	printf(" In this stage you are given a change to fire your cannons at your opponent's\n");
	printf(" walls.  Use your movement keys to place your target over your opponent's walls\n");
	printf(" and press your action key to fire a cannonball at the wall.  Once a cannonball\n");
	printf(" hits a wall, the block of wall hit will be destroyed.\n\n");

	printf(" Press space for next page...");

	bool doALoopJob = true;
	while(doALoopJob){
		if(keyboard.KeyChange(' ') == KEY_UP){
			doALoopJob = false;
		}
	}
	doALoopJob = true;

	system("cls");
	printf("\n");
	printf(" Instructions\n");
	printf(" ============\n\n");

	printf(" 4) Repair your walls:\n");
	printf(" In this stage, you will be given wall shapes to repair your walls with. All\n");
	printf(" area that you surround with walls will be marked as your territory.  If you\n");
	printf(" cannot repair walls to surround a base before the time expires, the game ends.\n\n");

	printf(" The previous 3 stages will repeat until atleast one player fails to surround\n");
	printf(" atleast one base.  If both players do not surround their base with walls, the\n");
	printf(" game is a draw.  Otherwise, if one player doesn't and one does, the player\n");
	printf(" left will win.\n\n");

	printf(" Press space for next page...");

	while(doALoopJob){
		if(keyboard.KeyChange(' ') == KEY_UP){
			doALoopJob = false;
		}
	}
	doALoopJob = true;

	system("cls");
	printf("\n");
	printf(" Controls\n");
	printf(" ========\n\n");

	printf("%*s                 Up\n",KEYS_OFFSET,"");
	printf("%*s                 |\n",KEYS_OFFSET,"");
	printf("%*s         _____  _____  _____\n",KEYS_OFFSET,"");
	printf("%*s        |     ||     ||     |\n",KEYS_OFFSET,"");
	printf("%*sPlace - | Q/U || W/I || E/O | - Rotate\n",KEYS_OFFSET,"");
	printf("%*s        |_____||_____||_____|\n",KEYS_OFFSET,"");
	printf("%*s         _____  _____  _____\n",KEYS_OFFSET,"");
	printf("%*s        |     ||     ||     |\n",KEYS_OFFSET,"");
	printf("%*sLeft -  | A/J || S/K || D/L | - Right\n",KEYS_OFFSET,"");
	printf("%*s        |_____||_____||_____|\n",KEYS_OFFSET,"");
	printf("\n");
	printf("%*s                 |\n",KEYS_OFFSET,"");
	printf("%*s                Down\n\n",KEYS_OFFSET,"");
	printf(" Player 1 will be on the left side of the river, and use Q/W/E/A/S/D\n");
	printf(" Player 2 will be on the right side of the river, and use U/I/O/J/K/L\n\n");

	printf(" Press space to continue...");

	while(doALoopJob){
		if(keyboard.KeyChange(' ') == KEY_UP){
			doALoopJob = false;
		}
	}
	doALoopJob = true;

}

void UI::AskWhatSize(void){
	char size = 'a';
	bool reAsk = true;

	system("cls");

	printf("\n");
	printf(" Map Size\n");
	printf(" ========\n");

	printf(" Select a map size by pressing the corrosponding option number\n");

	printf("\n\n");
	printf(" 1) 40 x 25\n");
	printf(" 2) 60 x 25\n");
	printf(" 3) 80 x 30\n");

	while(reAsk){
		size = getch();
		if(size == '1' || size == '2' || size == '3'){
			switch(size){
				case '1':
					width = 40;
					height = 25;
					break;
				case '2':
					width = 60;
					height = 25;
					break;
				case '3':
					width = 80;
					height = 30;
					break;
			}
			reAsk = false;
		}
	}

}

void UI::StartGame(void){
	system("cls");

	char size[50] = "";
	sprintf(size,"mode %d,%d",width*2,height*2 + 5);
	srand(time(NULL));
	system(size);
		
	game = Game(width,height);

	game.PlaceBase(width/5,height/4,PLAYER1);
	game.PlaceBase(width/5,3*(height/4),PLAYER1);

	game.PlaceBase(4*(width/5),height/4,PLAYER2);
	game.PlaceBase(4*(width/5),3*(height/4),PLAYER2);

	game.DrawTopBar();
	game.DrawRiver();
}

void UI::SelectBase(void){
	timeLeft = 15;
	thread timerThread(&UI::UpdateTimer,ref(*this));

	game.WriteStage("Select Base");
	game.DrawFirstStartBase(PLAYER1);
	game.DrawFirstStartBase(PLAYER2);

	bool player1Selected = false;
	bool player2Selected = false;

	while(timeLeft > 0 && (player1Selected == false || player2Selected == false)){
		if(player1Selected == false){
			player1Selected = ControlPlayer1BaseSelection();
		}
		if(player2Selected == false){
			player2Selected = ControlPlayer2BaseSelection();
		}
		if(player1Selected && player2Selected){
			timeLeft = 0;
		}
	}
		
	
	timerThread.join();
}

void UI::PlaceCannons(int duration){
	game.WriteStage("Place Cannons");

	timeLeft = duration;
	thread timerThread(&UI::UpdateTimer,ref(*this));

	game.RefillNumCannons();

	game.NewCannonOverlay(PLAYER1);
	game.NewCannonOverlay(PLAYER2);

	while(timeLeft > 0 && (game.HasCannons(PLAYER1) || game.HasCannons(PLAYER2))){
		if(game.HasCannons(PLAYER1)){
			ControlPlayer1Cannon();
		}
		if(game.HasCannons(PLAYER2)){
			ControlPlayer2Cannon();
		}
	}

	timeLeft = 0;

	game.ClearCannonOverlay(PLAYER1);
	game.ClearCannonOverlay(PLAYER2);

	timerThread.join();
}

void UI::RepairWalls(int duration){
	game.WriteStage("Place Walls");
		

	timeLeft = duration;
	thread timerThread(&UI::UpdateTimer,ref(*this));
		


	game.NewWallOverlay(PLAYER1);
	game.NewWallOverlay(PLAYER2);


	while(timeLeft > 0){
		ControlPlayer1Wall();
		ControlPlayer2Wall();
	}

	game.ClearWallOverlay(PLAYER1);
	game.ClearWallOverlay(PLAYER2);

	timerThread.join();

}

void UI::FireCannons(int duration){
	game.WriteStage("Shoot Enemy");

	timeLeft = duration;
	thread timerThread(&UI::UpdateTimer,ref(*this));
	
	game.StartAnimations();
	thread cannonsThread(&Game::AnimateCannons,ref(game));

	game.NewTargetOverlay(PLAYER1);
	game.NewTargetOverlay(PLAYER2);

	while(timeLeft > 0){
		ControlPlayer1Target();
		ControlPlayer2Target();
	}

	game.ClearTargetOverlay(PLAYER1);
	game.ClearTargetOverlay(PLAYER2);

	timerThread.join();
	game.FinishAnimations();
	cannonsThread.join();
}


	
void UI::UpdateTimer(void){
	while(timeLeft > 0){
		Sleep(1000);
		timeLeft--;
			
		if(timeLeft < 0){
			timeLeft = 0;
		}
			

		game.PrintTime(timeLeft);
	}
	game.PrintTime(timeLeft);
}
	
void UI::MoreWallTypes(void){
	game.SetNumWallTypes(6);
}

void UI::ControlPlayer1Wall(void){
	if(keyboard.KeyChange('A') == KEY_UP){
		game.WallOverlayLeft(0);
	}

	if(keyboard.KeyChange('D') == KEY_UP){
		game.WallOverlayRight(0);
	}

	if(keyboard.KeyChange('W') == KEY_UP){
		game.WallOverlayUp(0);
	}

	if(keyboard.KeyChange('S') == KEY_UP){
		game.WallOverlayDown(0);
	}

	if(keyboard.KeyChange('E') == KEY_UP){
		game.WallOverlayRotate(0);
	}

	if(keyboard.KeyChange('Q') == KEY_UP){
		game.PlaceWallOverlay(0);
	}

}
void UI::ControlPlayer2Wall(void){
	//Move wall up
	if(keyboard.KeyChange('I') == KEY_UP){
		game.WallOverlayUp(1);
	}

	//Move wall Left
	if(keyboard.KeyChange('J') == KEY_UP){
		game.WallOverlayLeft(1);
	}

	//Move wall down
	if(keyboard.KeyChange('K') == KEY_UP){
		game.WallOverlayDown(1);
	}

	//Move wall right
	if(keyboard.KeyChange('L') == KEY_UP){
		game.WallOverlayRight(1);
	}

	//Place wall
	if(keyboard.KeyChange('U') == KEY_UP){
		game.PlaceWallOverlay(1);
	}

	//Rotate wall
	if(keyboard.KeyChange('O') == KEY_UP){
		game.WallOverlayRotate(1);
	}
}

void UI::ControlPlayer1Cannon(void){
	if(keyboard.KeyChange('A') == KEY_UP){
		game.CannonOverlayLeft(PLAYER1);
	}

	if(keyboard.KeyChange('D') == KEY_UP){
		game.CannonOverlayRight(PLAYER1);
	}

	if(keyboard.KeyChange('W') == KEY_UP){
		game.CannonOverlayUp(PLAYER1);
	}

	if(keyboard.KeyChange('S') == KEY_UP){
		game.CannonOverlayDown(PLAYER1);
	}

	if(keyboard.KeyChange('Q') == KEY_UP){
		game.PlaceCannonOverlay(PLAYER1);
	}
}

void UI::ControlPlayer2Cannon(void){
	if(keyboard.KeyChange('J') == KEY_UP){
		game.CannonOverlayLeft(PLAYER2);
	}

	if(keyboard.KeyChange('L') == KEY_UP){
		game.CannonOverlayRight(PLAYER2);
	}

	if(keyboard.KeyChange('I') == KEY_UP){
		game.CannonOverlayUp(PLAYER2);
	}

	if(keyboard.KeyChange('K') == KEY_UP){
		game.CannonOverlayDown(PLAYER2);
	}

	if(keyboard.KeyChange('U') == KEY_UP){
		game.PlaceCannonOverlay(PLAYER2);
	}
}

void UI::ControlPlayer1Target(void){
	if(keyboard.KeyChange('A') == KEY_UP){
		game.TargetOverlayLeft(PLAYER1);
	}

	if(keyboard.KeyChange('D') == KEY_UP){
		game.TargetOverlayRight(PLAYER1);
	}

	if(keyboard.KeyChange('W') == KEY_UP){
		game.TargetOverlayUp(PLAYER1);
	}

	if(keyboard.KeyChange('S') == KEY_UP){
		game.TargetOverlayDown(PLAYER1);
	}

	if(keyboard.KeyChange('Q') == KEY_UP){
		game.FireCannon(PLAYER1);
	}
}

void UI::ControlPlayer2Target(void){
	if(keyboard.KeyChange('J') == KEY_UP){
		game.TargetOverlayLeft(PLAYER2);
	}

	if(keyboard.KeyChange('L') == KEY_UP){
		game.TargetOverlayRight(PLAYER2);
	}

	if(keyboard.KeyChange('I') == KEY_UP){
		game.TargetOverlayUp(PLAYER2);
	}

	if(keyboard.KeyChange('K') == KEY_UP){
		game.TargetOverlayDown(PLAYER2);
	}

	if(keyboard.KeyChange('U') == KEY_UP){
		game.FireCannon(PLAYER2);
	}
}

bool UI::ControlPlayer1BaseSelection(void){
	bool selected = false;
	if(keyboard.KeyChange('W') == KEY_UP || keyboard.KeyChange('S') == KEY_UP){
		game.ToggleBase(PLAYER1);
	}
	if(keyboard.KeyChange('Q') == KEY_UP){
		selected = true;
	}
	return selected;
}

bool UI::ControlPlayer2BaseSelection(void){
	bool selected = false;
	if(keyboard.KeyChange('I') == KEY_UP || keyboard.KeyChange('K') == KEY_UP){
		game.ToggleBase(PLAYER2);
	}
	if(keyboard.KeyChange('U') == KEY_UP){
		selected = true;
	}
	return selected;
}
	
int UI::GetOutcome(void){
	int outcome = -1;
	if(game.IsPlayerSafe(PLAYER1)){
			
		if(game.IsPlayerSafe(PLAYER2) == false){
			outcome = PLAYER1;
		}
	}else if(game.IsPlayerSafe(PLAYER2)){
		outcome = PLAYER2;
	}else{
		outcome = 2;
	}
	return outcome;
}

void UI::ShowVictoryScreen(int player){
	system("cls");
	system("mode 80,25");
	string victoryMessage = "";
	string menuString = "Press space to return to menu";
	if(player == 2){
		victoryMessage = "Both players couldn't repair their walls: Draw!";
	}else{
		if(player == 0){
			victoryMessage = "The damage to player 2's walls was too great: Player 1 Wins!";
		}else{
			victoryMessage = "The damage to player 1's walls was too great: Player 2 Wins!";
		}
	}

	printf("\n\n\n%*s%s\n",40 - victoryMessage.length()/2,"",victoryMessage.c_str());
	printf("%*s%s",40 - menuString.length()/2,"",menuString.c_str());

	bool doALoopJob = true;
	while(doALoopJob){
		if(keyboard.KeyChange(' ') == KEY_UP){
			doALoopJob = false;
		}
	}
}

