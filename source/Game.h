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
 * 		FILE 			: Game.h 					*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Game Class defination		*
 *													*
 * ================================================ */
 
/// 
/// \class Game
///
/// \brief The Game class contains the majority of the functional requirements.  This includes overlay movement,animating cannons, calculating enclosed blocks. etc.
///
/// \author Ben Lorantfy
///

#ifndef ___GAME_H__
#define ___GAME_H__

class Game{
	private:
		Console console;
		matrix <Block> grid;
		vector<Cannon> cannons;
		vector<Base> bases;

		int width;
		int height;
		int maxPlayer1X;
		int maxPlayer2X;
		int maxWallTypes;

		vector<WallOverlay> wallOverlays;
		vector<Overlay> cannonOverlays;
		vector<Overlay> targetOverlays;
		vector<int> startingBases;

		bool animate;

		int numPlayer1Cannons;
		int numPlayer2Cannons;

		

	public:
		Game(int width=75, int height=25);

		///
		/// \details <b>Details</b>
		/// Adds a block to the grid container and draws the block to the console
		///
		void PlaceBlock(int x, int y, Block& block);

		///
		/// \details <b>Details</b>
		/// Adds a base to the grid container and draws it to the console
		///
		void PlaceBase(int x, int y,int player);

		///
		/// \details <b>Details</b>
		/// Gives each player 3 more cannons, to a maximum of 3
		///
		void RefillNumCannons(void);

		///
		/// \details <b>Details</b>
		/// Creates the starting wall overlay
		///
		void NewWallOverlay(int player,int x=0, int y=0);

		///
		/// \details <b>Details</b>
		/// Place the wall overlay on the grid
		///
		bool PlaceWallOverlay(int player);

		///
		/// \details <b>Details</b>
		/// Draws the wall overlay to the console
		///
		void DrawWallOverlay(int player);

		///
		/// \details <b>Details</b>
		/// Draws the objects under the overlay ontop of the overlay
		///
		void ClearWallOverlay(int player);

		///
		/// \details <b>Details</b>
		/// Moves the wall overlay left
		///
		void WallOverlayLeft(int player);

		///
		/// \details <b>Details</b>
		/// Moves the wall overlay right
		///
		void WallOverlayRight(int player);

		///
		/// \details <b>Details</b>
		/// Moves the wall overlay up
		///
		void WallOverlayUp(int player);

		///
		/// \details <b>Details</b>
		/// Moves overlay down
		///
		void WallOverlayDown(int player);

		///
		/// \details <b>Details</b>
		/// Rotate's wall overlay
		///
		void WallOverlayRotate(int player);

		///
		/// \details <b>Details</b>
		/// Checks if rotation will cause it to rotate off screen
		///
		bool CanRoate(WallOverlay& overlay);

		///
		/// \brief Outputs the radio information
		/// \details <b>Details</b>
		/// Creates a new cannon overlay
		///
		void NewCannonOverlay(int player,int x=0,int y=0);

		///
		/// \details <b>Details</b>
		/// Checks if player has anymore unplaced cannons
		///
		bool HasCannons(int player);

		///
		/// \details <b>Details</b>
		/// Places the cannon overlay on the grid
		///
		bool PlaceCannonOverlay(int player);
		
		///
		/// \details <b>Details</b>
		/// Draws the cannon to the console
		///
		void DrawCannonOverlay(int player);

		///
		/// \details <b>Details</b>
		/// Draws the blocks under the cannon overlay ontop of the overlay
		///
		void ClearCannonOverlay(int player);

		///
		/// \details <b>Details</b>
		/// Moves cannon overlay left
		///
		void CannonOverlayLeft(int player);

		///
		/// \details <b>Details</b>
		/// Moves cannon overlay right
		///
		void CannonOverlayRight(int player);

		///
		/// \details <b>Details</b>
		/// Moves cannon overlay up
		///
		void CannonOverlayUp(int player);

		///
		/// \details <b>Details</b>
		/// Moves cannon overlay down
		///
		void CannonOverlayDown(int player);

		///
		/// \details <b>Details</b>
		/// Calculates and flags all the blocks that are enclosed within walls
		///
		void MarkEnclourses(void);

		///
		/// \details <b>Details</b>
		/// Recursive function that checks all blocks around current block
		///
		void MarkBlock(int x, int y);


		///
		/// \details <b>Details</b>
		/// Creates a new target overlay
		///
		void NewTargetOverlay(int player, int x=0, int y=0);

		///
		/// \details <b>Details</b>
		/// Moves target overlay left
		///
		void TargetOverlayLeft(int player);

		///
		/// \details <b>Details</b>
		/// Moves target overlay right
		///
		void TargetOverlayRight(int player);

		///
		/// \details <b>Details</b>
		/// Moves target overlay up
		///
		void TargetOverlayUp(int player);

		///
		/// \details <b>Details</b>
		/// Moves target overlay down
		///
		void TargetOverlayDown(int player);

		///
		/// \details <b>Details</b>
		/// Draws objects underneath target overlay ontop of overlay
		///
		void ClearTargetOverlay(int player);

		///
		/// \details <b>Details</b>
		/// Draws target overlay to the console
		///
		void DrawTargetOverlay(int player);

		///
		/// \details <b>Details</b>
		/// Checks if an overlay would be out of bounds if created
		///
		bool CanBeCreated(WallOverlay& overlay);

		///
		/// \details <b>Details</b>
		/// Checks if an overlay would be out of bounds if moved left
		///
		bool CanMoveLeft(Overlay& overlay);

		///
		/// \details <b>Details</b>
		/// Checks if an overlay would be out of bounds if moved right
		///
		bool CanMoveRight(Overlay& overlay);

		///
		/// \details <b>Details</b>
		/// Checks if an overlay would be out of bounds if moved up
		///
		bool CanMoveUp(Overlay& overlay);

		///
		/// \details <b>Details</b>
		/// Checks if an overlay would be out of bounds if moved down
		///
		bool CanMoveDown(Overlay& overlay);

		///
		/// \details <b>Details</b>
		/// Finds a cannon that can be fired, if any, and flags as being fired
		///
		void FireCannon(int player);

		///
		/// \details <b>Details</b>
		/// Starts cannonball animation
		///
		void StartAnimations(void);

		///
		/// \details <b>Details</b>
		/// Sets a "stop all animations" flag
		///
		void FinishAnimations(void);

		///
		/// \details <b>Details</b>
		/// Animates all fired cannon's and their cannonballs
		///
		void AnimateCannons(void);

		///
		/// \details <b>Details</b>
		/// Select's next base
		///
		void ToggleBase(int player);

		///
		/// \details <b>Details</b>
		/// Draw's the first base for each player
		///
		void DrawFirstStartBase(int player);

		///
		/// \details <b>Details</b>
		/// Draws walls and territory of player starting base
		///
		void DrawStartBase(int base);

		///
		/// \details <b>Details</b>
		/// Erases selected walls and territory of former starting base
		///
		void ClearStartBase(int base);

		///
		/// \details <b>Details</b>
		/// Checks wether player has atleast one base surrounded in walls
		///
		bool IsPlayerSafe(int player);
	
		///
		/// \details <b>Details</b>
		/// Draws the dividing river
		///
		void DrawRiver(void);
		
		///
		/// \details <b>Details</b>
		/// Draws the top status bar
		///
		void DrawTopBar(void);

		///
		/// \details <b>Details</b>
		/// Prints the time in the top status bar
		///
		void PrintTime(int time);

		///
		/// \details <b>Details</b>
		/// Update's the "number of cannons" display in the top status bar
		///
		void UpdateCannonDisplay(int player);

		///
		/// \details <b>Details</b>
		/// Writes to the top bar what stage players are in
		///
		void WriteStage(string stage);

		///
		/// \details <b>Details</b>
		/// Set's the maximum wall type (use this to increase/decrease difficulty)
		///
		void SetNumWallTypes(int num);
};

#endif