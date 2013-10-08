/*
Copyright (c) 2013 Daniele Bartolini, Michele Rossi
Copyright (c) 2012 Daniele Bartolini, Simone Boscaratto

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "Types.h"
#include "Vector3.h"

namespace crown
{

class Matrix3x3;
class Matrix4x4;

/// Quaternion.
///
/// @a Note:
/// This implementation uses the standard quaternion
/// multiplication equation, so, the order of multiplication
/// for multiple rotations is in a reverse fashion:
/// p' = qpq^-1 where p is the point and q the rotation quaternion
/// 
/// p' = (ba)p(ba)^-1 where p is the point and (ba) the concatenation of two successive rotations
/// In this case, the point p is first rotated by the quaternion a and then by the quaternion b.
/// The transformation order is reversed.
class Quaternion
{
public:

	Vector3		v;
	float		w;

public:

	/// Does nothing
						Quaternion();

	/// Constructs from individual components.
						Quaternion(float nx, float ny, float nz, float nw);

	/// Builds the quaternion from an @a axis and a @a angle.							
						Quaternion(const Vector3& axis, float angle);	

	/// Negates the quaternion.
	void				negate();

	/// Builds the identity quaternion.
	void				load_identity();

	/// Returns the lenght of the quaternion.
	float				length() const;		

	/// Conjugates the quaternion.
	void				conjugate();

	/// Returns the quaternion's conjugate.
	Quaternion				get_conjugate() const;

	/// Quaternion's inverse				
	Quaternion				get_inverse() const;

	Matrix3x3				to_mat3() const;
	Matrix4x4				to_mat4() const;

	/// Cross product
	Quaternion				operator*(const Quaternion& b) const;

	/// Multiplication by a scalar		
	Quaternion				operator*(const float& k) const;

	Quaternion				power(float exp);

public:

	static const Quaternion	IDENTITY;
};

} // namespace crown
