/*
 Copyright (C) 2011 by Ivan Safrin
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#pragma once
#include "PolyString.h"
#include "PolyGlobals.h"
#include <math.h>

//#ifdef _WINDOWS
	#include <assert.h>
//#endif 

namespace Polycode {

	/**
	* 3D Vector class. 
	*/
	class _PolyExport Vector3 {
		public:
		
			/**
			* Create from x,y,z coordinates.
			* @param x X coordinate.
			* @param y Y coordinate.			
			* @param z Z coordinate.						
			*/					
			Vector3(Number x,Number y,Number z);		
			
			/**
			* Default constructor.
			*/ 
			Vector3();
			virtual ~Vector3();

			/**
			* Sets the vector from x,y,z coordinates.
			* @param x X coordinate.
			* @param y Y coordinate.			
			* @param z Z coordinate.									
			*/
			void set(Number x, Number y, Number z);

			inline Vector3 operator - ( const Vector3& v2 ) const {
				return Vector3(x - v2.x, y - v2.y, z - v2.z);
			}

			/**
			* Returns the distance from this vector to another one.
			* @param vec2 Second vector.
			* @return Distance to the other vector.
			*/
			inline Number distance(const Vector3& vec2) const {
				return (*this - vec2).length();
			}
			
			// ----------------------------------------------------------------------------------------------------------------
			/** @name Operators
			*  Available vector operators.
			*/
			//@{
			

			inline Vector3& operator * (const Number val) {
				x *= val;
				y *= val;
				z *= val;
				return *this;				
			}

			inline Vector3& operator / (const Number val) {
				assert( val != 0.0 );
				x /= val;
				y /= val;
				z /= val;
				return *this;				
			}

			inline Vector3& operator = ( const Vector3& v2)  {
				x = v2.x;
				y = v2.y;
				z = v2.z;
				return *this;
			}

			inline Vector3& operator += ( const Vector3& v2)  {
				x += v2.x;
				y += v2.y;
				z += v2.z;
				return *this;
			}

			inline Vector3& operator -= ( const Vector3& v2)  {
				x -= v2.x;
				y -= v2.y;
				z -= v2.z;
				return *this;
			}
	
			inline Vector3 operator + ( const Vector3& v2 ) const {
				return Vector3(x + v2.x, y + v2.y, z + v2.z);
			}		


			inline bool operator == ( const Vector3& v2)  {
				return (v2.x == x && v2.y == y && v2.z == z);
			}		

			inline bool operator != ( const Vector3& v2)  {
				return (v2.x != x || v2.y != y || v2.z != z);
			}				
		
			//@}
			// ----------------------------------------------------------------------------------------------------------------
	

			/**
			* Returns the vector length.
			* @return Length of the vector.
			*/
			inline Number length () const {
				return sqrtf( x * x + y * y + z * z );
			}
			
			/**
			* Returns the dot product with another vector.
			* @return Dor product with the vector.
			*/			
			inline Number dot(Vector3 &u) {
				return x * u.x + y * u.y + z * u.z;
			}

			/**
			* Returns the cross product with another vector.
			* @param vec2 Second vector.
			* @return Cross product with the vector.
			*/
			inline Vector3 crossProduct( const Vector3& vec2 ) const {
				return Vector3(
					y * vec2.z - z * vec2.y,
					z * vec2.x - x * vec2.z,
					x * vec2.y - y * vec2.x);
			}			

			/**
			* Normalizes the vector.
			*/
			void Normalize();
		
			/**
			* X coordinate.
			*/
			Number x;
			
			/**
			* Y coordinate.
			*/			
			Number y;
			
			/**
			* Z coordinate.
			*/			
			Number z;			
			
		private:

	};
}