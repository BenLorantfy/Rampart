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
 * 		FILE 			: UI.h 						*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: UI class defination		*
 *													*
 * ================================================ */
 
/// 
/// \class WallOverlay
///
/// \brief This class is used to serve as the user interface for the game. This is done by acting as the interface between the Game class and the user.
///
/// \author Ben Lorantfy
///


#define PLAYER1 0
#define PLAYER2 1

#define CANNON_OFFSET 4
#define CASTLE_OFFSET 5
#define KEYS_OFFSET 20




class UI{
private:
	KeyBoard keyboard;
	Game	 game;
	
	int width;
	int height;

	int timeLeft;
public:
	///
	/// \details <b>Details</b>
	/// Shows the menu
	///
	bool ShowMenu(void);

	///
	/// \details <b>Details</b>
	/// Shows the instructions
	///
	void ShowInstructions(void);

	///
	/// \details <b>Details</b>
	/// Asks for size of screen
	///
	void AskWhatSize(void);

	///
	/// \details <b>Details</b>
	/// Creates a new game object with width/height
	///
	void StartGame(void);

	///
	/// \details <b>Details</b>
	/// Starts the select base stage
	///
	void SelectBase(void);

	///
	/// \details <b>Details</b>
	/// Starts the place cannons stage
	///
	void PlaceCannons(int duration=30);

	///
	/// \details <b>Details</b>
	/// Starts the repair walls stage
	///
	void RepairWalls(int duration=30);

	///
	/// \details <b>Details</b>
	/// Starts the fire cannons stage
	///
	void FireCannons(int duration=30);


	///
	/// \details <b>Details</b>
	/// Update's the timer
	///
	void UpdateTimer(void);
	
	///
	/// \details <b>Details</b>
	/// Increases the number of possible wall types
	///
	/// \note
	/// Use this to increase difficulty
	///
	void MoreWallTypes(void);

	///
	/// \details <b>Details</b>
	/// Checks player 1's controls for keypresses, doing the appropiate wall actions
	///
	void ControlPlayer1Wall(void);


	///
	/// \details <b>Details</b>
	/// Checks player 2's controls for keypresses, doing the appropiate wall actions
	///
	void ControlPlayer2Wall(void);

	///
	/// \details <b>Details</b>
	/// Checks player 1's controls for keypresses, doing the appropiate cannon actions
	///
	void ControlPlayer1Cannon(void);

	///
	/// \details <b>Details</b>
	/// Checks player 2's controls for keypresses, doing the appropiate cannon actions
	///
	void ControlPlayer2Cannon(void);

	///
	/// \details <b>Details</b>
	/// Checks player 1's controls for keypresses, doing the appropiate target actions
	///
	void ControlPlayer1Target(void);

	///
	/// \details <b>Details</b>
	/// Checks player 2's controls for keypresses, doing the appropiate target actions
	///
	void ControlPlayer2Target(void);

	///
	/// \details <b>Details</b>
	/// Checks player's 1 controls for keypresses, doing the appropiate base actions
	///
	bool ControlPlayer1BaseSelection(void);

	///
	/// \details <b>Details</b>
	/// Checks player's 2 controls for keypresses, doing the appropiate base actions
	///
	bool ControlPlayer2BaseSelection(void);
	
	///
	/// \details <b>Details</b>
	/// Gets a code representing the outcome
	///
	int GetOutcome(void);

	///
	/// \details <b>Details</b>
	/// Shows the victory screen
	///
	void ShowVictoryScreen(int player);

};