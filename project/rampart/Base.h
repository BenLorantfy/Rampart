/* ================================================ *
 *											 		*
 * 		FILE 			: Base.h 					*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Base class defination		*
 *													*
 * ================================================ */
 
/// 
/// \class WallOverlay
///
/// \brief This class models the behaviour of a base.  Used to store x,y, and owner of base game object.
///
/// \author Ben Lorantfy
///
 
#ifndef ___BASE_H__
#define ___BASE_H__

class Base{
private:
	int x;
	int y;
	int player;
public:
	Base(int x, int y, int player);
	///
	/// \details <b>Details</b>
	/// Get's the owner of basae
	///
	int GetPlayer(void);

	///
	/// \details <b>Details</b>
	/// Get the X value of base
	///
	int GetX(void);

	///
	/// \details <b>Details</b>
	/// Gets the Y value of base
	///
	int GetY(void);
};

#endif