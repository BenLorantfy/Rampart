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