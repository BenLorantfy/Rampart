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
 * 		FILE 			: Console.h 				*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Console class defination	*
 *													*
 * ================================================ */
 
/// 
/// \class WallOverlay
///
/// \brief This class is used to access the terminal window.  It allows the Game class to print to the screen without refreshing the entireity of it.
///
/// \author Ben Lorantfy
///

#ifndef ___CONSOLE_H__
#define ___CONSOLE_H__


class Console{
public:
	///
	/// \details <b>Details</b>
	/// Moves cursor to a location
	/// \note 
	/// y is inverted (i.e. increases towards bottom of screen)
	/// not thread safe
	///
	void MoveCursor(int x, int y);

	///
	/// \details <b>Details</b>
	/// Prints a charachter to the screen with additonal checks (i.e. does something different if blocked)
	/// \note
	/// Thread safe
	///
	void PrintGameChar(int x, int y, char charchter);

	///
	/// \details <b>Details</b>
	/// Prints a c style string to the screen
	/// \note
	/// Thread safe
	///
	void Print(int x, int y, char* str);

	///
	/// \details <b>Details</b>
	/// Prints a string object to the screen
	/// \note
	/// Thread safe
	///
	void Print(int x, int y, string str);

	///
	/// \details <b>Details</b>
	/// Prints a game block to the screen
	/// \note
	/// Thread safe
	///
	void DrawBlock(int x, int y, Block& block);

	///
	/// \details <b>Details</b>
	/// Clears the screen
	///
	void Clear(void);
};
#endif