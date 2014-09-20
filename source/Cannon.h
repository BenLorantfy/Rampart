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
 * 		FILE 			: Cannon.h 					*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Cannon class defination	*
 *													*
 * ================================================ */
 
/// 
/// \class WallOverlay
///
/// \brief This class models the behaviour of a cannon.  This primarily includes the animation of cannonballs.
///
/// \author Ben Lorantfy
///
#ifndef ___CANNON_H___
#define ___CANNON_H__

class Cannon{
private:
	int x;
	int y;
	
	int ballX;
	int ballY;
	
	int step;

	int distanceX;
	int distanceY;

	int destinationX;
	int destinationY;

	int StepRemaining;

	bool firing;
	bool hit;

	bool enabled;

	int player;
public:
	Cannon(int x, int y, int player);

	///
	/// \details <b>Details</b>
	/// Sets firing attributes including cannonball destination and x/y step
	///
	void Aim(int x, int y);

	///
	/// \details <b>Details</b>
	/// Returns the next block in the cannonball animation
	///
	pair<int,int> NextFrame(void);

	///
	/// \details <b>Details</b>
	/// Returns if cannon is firing
	///
	bool GetFiring(void);

	///
	/// \details <b>Details</b>
	/// Sets firing
	///
	void SetFiring(bool firing);

	///
	/// \details <b>Details</b>
	/// Gets Hit
	///
	bool GetHit(void);

	///
	/// \details <b>Details</b>
	/// Sets Hit
	///
	void SetHit(bool hit);

	///
	/// \details <b>Details</b>
	/// Gets the current x of cannonball
	///
	int GetBallX(void);

	///
	/// \details <b>Details</b>
	/// Gets the current y of cannonball
	///
	int GetBallY(void);

	///
	/// \details <b>Details</b>
	/// Gets owner of cannon
	///
	int GetPlayer(void);
	
	///
	/// \details <b>Details</b>
	/// Enables/Disables cannon
	/// \notes
	/// This is used to disable cannons if they are not in player's territory
	///
	void SetEnabled(bool enabled);

	///
	/// \details <b>Details</b>
	/// Gets cannon's x
	///
	int GetX(void);

	///
	/// \details <b>Details</b>
	/// Gets cannon's y
	///
	int GetY(void);

	///
	/// \details <b>Details</b>
	/// Get's wether the cannon is enabled or not
	///
	bool GetEnabeled(void);
};

#endif