/* Textures.cpp
 *
 * Copyright 2007 Eliot Eshelman
 * battlestartux@6by9.net
 *
 *
 *  This file is part of Battlestar Tux.
 *
 *  Battlestar Tux is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 2 of the License.
 *
 *  Battlestar Tux is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Battlestar Tux; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#include <math.h>

#include "Simplex.h"
#include "Textures.h"


// 2D Marble Noise: x-axis.
float marbleNoise( const float octaves, const float persistence, const float scale, const float x, const float y ) {
	return cosf( x * scale + simplexNoise(octaves, persistence, scale / 3, x, y) );
}


// 3D Marble Noise: x-axis.
float marbleNoise( const float octaves, const float persistence, const float scale, const float x, const float y, const float z ) {
	return cosf( x * scale + simplexNoise(octaves, persistence, scale / 3, x, y, z) );
}


// 4D Marble Noise: x-axis.
float marbleNoise( const float octaves, const float persistence, const float scale, const float x, const float y, const float z, const float w ) {
	return cosf( x * scale + simplexNoise(octaves, persistence, scale / 3, x, y, z, w) );
}
