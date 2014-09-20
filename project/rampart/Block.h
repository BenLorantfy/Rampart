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