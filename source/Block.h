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
 * 		FILE 			: Block.h 					*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Block	Class defination	*
 *													*
 * ================================================ */
 
/// 
/// \class WallOverlay
///
/// \brief This class models the behaviour of a game block.  Used to store the properites of a type of game object, including things such as walls and cannons.
///
/// \author Ben Lorantfy
///
 
#ifndef ___BLOCK_H__
#define ___BLOCK_H__

using namespace std;
class Block{
private:
	string type;
	string quadrants;
	bool enclosed;
public:
	Block(void);
	
	Block(string type);

	Block& operator=(string type);

	///
	/// \details <b>Details</b>
	/// Sets the block's enclosed flag
	///
	void SetEnclosed(void);

	///
	/// \details <b>Details</b>
	/// Clears the block's enclosed flag
	///
	void SetNotEnclosed(void);

	///
	/// \details <b>Details</b>
	/// Checks the block's enclosed flag
	///
	bool IsEnclosed(void);


	bool operator==(string type);

	bool operator!=(string type);

	///
	/// \details <b>Details</b>
	/// Get's block type
	///
	string GetType(void);

	///Set's block type and updates charachter quadrants with corresponding appearence
	void SetType(string type);

	///
	/// \details <b>Details</b>
	/// Gets the charachter quadrants
	///
	string GetQuadrants(void);
};
 
#endif