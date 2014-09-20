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