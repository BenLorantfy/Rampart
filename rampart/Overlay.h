/* ================================================ *
 *											 		*
 * 		FILE 			: Overlay.h 				*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Overlay class defination	*
 *													*
 * ================================================ */
 
/// 
/// \class WallOverlay
///
/// \brief This class models the behaviour of a generic overlay. 
///
/// \notes
/// WallOverlay inherits from this class
///
/// \author Ben Lorantfy
///

#ifndef ___OVERLAY_H__
#define ___OVERLAY_H__
class Overlay{
private:
	int x;
	int y;
	int width;
	int height;
public:	
	Overlay(int x=0,int y=0,int height=1,int width=1);

	void SetWidth(int width);
	void SetHeight(int height);

	int GetWidth(void);
	
	int GetHeight(void);

	int SetX(int x);
	int SetY(int y);
	
	int GetX(void);

	int GetY(void);
	
	int AddX(int deltaX=1);

	int MinusX(int deltaX=1);

	int AddY(int deltaY=1);

	int MinusY(int deltaY=1);
};
#endif