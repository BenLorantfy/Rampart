/* ================================================ *
 *											 		*
 * 		FILE 			: Keyboard.h 				*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Keyboard class defination	*
 *													*
 * ================================================ */
 
/// 
/// \class KeyBoard
///
/// \brief This class is used to get the state of the keyboard
///
/// \author Ben Lorantfy
///

#ifndef ___KEYBOARD_H__
#define ___KEYBOARD_H__

#define KEY_DOWN 0
#define KEY_UP 1
#define KEY_NO_CHANGE 2

class KeyBoard{
	private:
		std::map<char,bool> keys;
	public:
		KeyBoard(void);

		///
		/// \details <b>Details</b>
		/// Checks if key is currently pressed down
		///
		bool KeyIsDown(char key);

		///
		/// \details <b>Details</b>
		/// Checks if the key is currently up
		///
		bool KeyIsUp(char key);

		///
		/// \details <b>Details</b>
		/// Gets last key press
		///
		int KeyChange(char key);

		~KeyBoard(void);
};
 
#endif