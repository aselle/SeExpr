/*
 SEEXPR SOFTWARE
 Copyright 2011 Disney Enterprises, Inc. All rights reserved
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are
 met:
 
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in
 the documentation and/or other materials provided with the
 distribution.
 
 * The names "Disney", "Walt Disney Pictures", "Walt Disney Animation
 Studios" or the names of its contributors may NOT be used to
 endorse or promote products derived from this software without
 specific prior written permission from Walt Disney Pictures.
 
 Disclaimer: THIS SOFTWARE IS PROVIDED BY WALT DISNEY PICTURES AND
 CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
 BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE, NONINFRINGEMENT AND TITLE ARE DISCLAIMED.
 IN NO EVENT SHALL WALT DISNEY PICTURES, THE COPYRIGHT HOLDER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND BASED ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
*/

#ifndef SeVec3d_h
#define SeVec3d_h

#ifndef MAKEDEPEND
#include <iostream>
#include <math.h>
#endif

/**
 * @brief A 3d point/vector class.
 *
 * This class represents 3d points and vectors of doubles. In reality, this
 * is a vector with the base point at the global origin. Why? Because
 * you cant really add points, subtract points, and so forth -- at least
 * mathematically.
 */
class SeVec3d
{
 public:

    /** Default constructor. */
    SeVec3d() {}

    /** Scalar constructor. */
    SeVec3d( double v )
    { setValue( v, v, v ); }

    /** Component constructor. */
    SeVec3d( double x, double y, double z )
    { setValue( x, y, z ); }

    /** Array constructor. */
    SeVec3d( const double* v )
    { setValue( v[0], v[1], v[2] ); }

    /** Array constructor. */
    SeVec3d( const float* v )
    { setValue( v[0], v[1], v[2] ); }

    //! for compatibility with double array[3]
    typedef double array[3];
    operator array&() { return _vec; }

    //! Accesses indexed component of vector
    double       &operator []( int i )          { return (_vec[i]); }

    //! Accesses indexed component of vector (const)
    double operator []( int i ) const    { return (_vec[i]); }

    /** Assignment. */
    SeVec3d &operator =( const SeVec3d &v )
    { _vec[0]=v[0]; _vec[1]=v[1]; _vec[2]=v[2]; return *this; }

    /** Component-wise scalar multiplication. */
    SeVec3d &operator *=( double d )
    { _vec[0]*=d; _vec[1]*=d; _vec[2]*=d; return *this; }

    /** Component-wise scalar division. */
    SeVec3d &operator /=( double d )
    { *this *= 1/d; return *this; }

    /** Component-wise vector addition. */
    SeVec3d &operator +=( const SeVec3d &v )
    { _vec[0]+=v[0]; _vec[1]+=v[1]; _vec[2]+=v[2]; return *this; } 

    /** Component-wise vector subtraction. */
    SeVec3d &operator -=( const SeVec3d &v )
    { _vec[0]-=v[0]; _vec[1]-=v[1]; _vec[2]-=v[2]; return *this; } 
    
    /** Nondestructive unary negation - returns a new vector. */
    SeVec3d operator -() const
    { return SeVec3d( -_vec[0], -_vec[1], -_vec[2] ); }

    /** Equality comparison. */
    bool operator ==( const SeVec3d &v ) const
    { return (_vec[0] == v[0] && _vec[1] == v[1] && _vec[2] == v[2]); }

    /** Inequality comparison. */
    bool operator !=( const SeVec3d &v ) const
    { return !(*this == v); }

    /** Component-wise binary scalar multiplication. */
    SeVec3d operator *( double d ) const
    { return SeVec3d( _vec[0]*d, _vec[1]*d, _vec[2]*d ); }
    
    /** Component-wise binary scalar division */
    SeVec3d operator /( double d ) const
    { return *this * (1/d); }
    
    /** Component-wise binary scalar multiplication. */
    friend SeVec3d operator *( double d, const SeVec3d &v )
    { return v * d; }
    
    /** Component-wise binary vector multiplication. */
    SeVec3d operator *( const SeVec3d &v ) const
    { return SeVec3d(_vec[0]*v[0], _vec[1]*v[1], _vec[2]*v[2]); }

    /** Component-wise binary vector division. */
    SeVec3d operator /( const SeVec3d &v ) const
    { return SeVec3d(_vec[0]/v[0], _vec[1]/v[1], _vec[2]/v[2]); }

    /** Component-wise binary vector addition. */
    SeVec3d operator +( const SeVec3d &v ) const
    { return SeVec3d( _vec[0]+v[0], _vec[1]+v[1], _vec[2]+v[2] ); }

    /** Component-wise binary vector subtraction. */
    SeVec3d operator -( const SeVec3d &v ) const
    { return SeVec3d( _vec[0]-v[0], _vec[1]-v[1], _vec[2]-v[2]); }

    /** Output a formatted string for the vector to a stream. */
    friend std::ostream & operator <<( std::ostream  &os, const SeVec3d &v )
    { os << "(" << v[0] << "," << v[1] << "," << v[2] << ")"; return os; }

    /** Get coordinates. */
    void getValue( double &x, double &y, double &z ) const
    { x = _vec[0]; y = _vec[1]; z = _vec[2]; }
    
    /** Get coordinates as array. */
    const double *getValue() const
    { return _vec; }

    /** Set coordinates. */
    void setValue( double x, double y, double z )
    { _vec[0] = x; _vec[1] = y; _vec[2] = z; }
    
    /** Set coordinates as array. */
    void setValue( const double* v )
    { _vec[0] = v[0]; _vec[1] = v[1]; _vec[2] = v[2]; }

    /** Inner product. */
    double dot( const SeVec3d &v ) const
    { return _vec[0]*v[0] + _vec[1]*v[1] + _vec[2]*v[2]; }

    /** Cross product. */
    SeVec3d cross( const SeVec3d &v ) const
    { return SeVec3d(_vec[1]*v[2] - _vec[2]*v[1],
		     _vec[2]*v[0] - _vec[0]*v[2],
		     _vec[0]*v[1] - _vec[1]*v[0]); }
    
    /** Negate vector. */
    void negate()
    { _vec[0]*=-1; _vec[1]*=-1; _vec[2]*=-1; }

    /** Length of vector. */
    double length() const
    { return sqrt( _vec[0]*_vec[0]+_vec[1]*_vec[1]+_vec[2]*_vec[2] ); }

    /** Return normalized vector */
    SeVec3d normalized() const 
    {
	double len = length();
        if ( len ) return *this / len;
	else return 0.0;
    }

    /** Normalize vector. */
    void normalize()
    {
	double len = length();
        if ( len ) *this /= len;
    }

    /** Return a vector orthogonal to the current vector. */
    SeVec3d orthogonal() const {
        return SeVec3d( _vec[1]+_vec[2], _vec[2]-_vec[0], -_vec[0]-_vec[1] );
    }

    /**
     * Returns the angle in radians between the current vector and the
     * passed in vector.
     */
    double angle( const SeVec3d &v ) const
    { 	double len = this->length()*v.length();
	if (len == 0) return 0;
	return acos(this->dot(v) / len);
    }

    /**
     * Returns the vector rotated by the angle given in radians about
     * the given axis. (Axis must be normalized)
     */
    SeVec3d rotateBy( const SeVec3d &axis, double angle_ ) const
    {
	double c = cos(angle_), s = sin(angle_);
	const SeVec3d& v = *this;
	return c*v + (1-c)*v.dot(axis)*axis - s*v.cross(axis);
    }
    
 private:

    /** Coordinates. */
    double  _vec[3];
};


#endif
