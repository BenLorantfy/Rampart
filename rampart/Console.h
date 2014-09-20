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