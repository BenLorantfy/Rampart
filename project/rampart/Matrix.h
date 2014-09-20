/* ================================================ *
 *											 		*
 * 		FILE 			: Matrix.h		 			*
 * 		PROJECT 		: DS/OOP final project		*
 * 		PROGRAMMER 		: Benjamin Lorantfy 		*
 * 		FIRST VERSION 	: 2014-04-18 				*
 * 		DESCRIPTION		: Matrix class defination	*
 *													*
 * ================================================ */
 
/// 
/// \class WallOverlay
///
/// \brief This class wraps a vector of vectors, simplifying the interface
///
/// \author Ben Lorantfy
///
 
#ifndef ___MATRIX_H__
#define ___MATRIX_H__

#include <vector>

template <typename T> 
class matrix : public std::vector<std::vector<T> >{
private:
	int matrixWidth;
	int matrixHeight;
public:
	matrix(void){
		matrixWidth = 0;
		matrixHeight = 0;
	}

	matrix(int iniWidth, int iniHeight){
		width(iniWidth);
		height(iniHeight);
	}

	matrix(int iniWidth, int iniHeight, T defaultValue){
		resize(iniWidth,iniHeight,defaultValue);
	}

	void resize(int newWidth, int newHeight){
		width(newWidth);
		height(newHeight);
	}

	///
	/// \details <b>Details</b>
	/// Resizes the matrix
	///
	void resize(int newWidth, int newHeight, T defaultValue){
		width(newWidth);


		for(int i = 0; i < matrixWidth; i++){
			vector::at(i).vector::resize(newHeight);
			for(int j = 0; j < newHeight; j++){
				vector::at(i).vector::at(j) = defaultValue;
			}
		}
		matrixHeight = newHeight;
	}

	///
	/// \details <b>Details</b>
	/// Gets the element at a set of coordinates
	///
	T& at(int x, int y){
		return vector::at(x).vector::at(y);
	}

	///
	/// \details <b>Details</b>
	/// Gets width
	///
	int width(int newWidth){
		vector::resize(newWidth);
		matrixWidth = newWidth;

		return newWidth;
	}

	///
	/// \details <b>Details</b>
	/// Sets width
	///
	int width(void){
		return matrixWidth;
	}

	///
	/// \details <b>Details</b>
	/// Sets height
	///
	int height(int newHeight){
		for(int i = 0; i < matrixWidth; i++){
			vector::at(i).vector::resize(newHeight);
		}
		matrixHeight = newHeight;

		return newHeight;
	}

	///
	/// \details <b>Details</b>
	/// Gets height
	///
	int height(void){
		return matrixHeight;
	}

};

#endif