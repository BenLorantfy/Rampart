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
 * 		FILE 			: WallOverlay.h 			*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Wall Overlay defination	*
 *													*
 * ================================================ */
 
/// 
/// \class WallOverlay
///
/// \brief This class models the behaviour of a wall overlay.  This includes the wall's shape and rotation.
///
/// \author Ben Lorantfy
///
 
#ifndef __WALLOVERLAY_H__
#define __WALLOVERLAY_H__

#define WALL1 1
#define WALL2 2
#define WALL3 3
#define WALL4 4


class WallOverlay : public Overlay{
private:
	matrix<int> shape;
	int maxType;
	int minType;
	int type;
	int rotation;

public:
	WallOverlay(void);
	WallOverlay(int x, int y,int maxType=4);

	///
	/// \details <b>Details</b>
	/// Randomizes the type of wall
	///
	void RandomizeType(int maxType=4);

	///
	/// \details <b>Details</b>
	/// Sets type
	///
	int SetType(int type);

	///
	/// \details <b>Details</b>
	/// Gets the shape matrix of wall blocks
	///
	matrix<int> GetShape(void);

	///
	/// \details <b>Details</b>
	/// Sets the shape matrix of wall blocks
	/// \note
	/// Considers the current rotation frame of the wall overlay
	///
	void SetRotationFrame(void);


	///
	/// \details <b>Details</b>
	/// Rotates wall overlay by one state/frame
	///
	void Rotate(bool backwards=false);

};

#endif