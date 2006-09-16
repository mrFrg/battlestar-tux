/* Plasma.cpp
 *
 * Copyright 2005-2006 Eliot Eshelman
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


#include "Plasma.h"
#include "../../FighterAmmo.h"

Plasma::Plasma( WeaponSystem* w, Game* g ) : Weapon( w, g ) {
	mount = PRIMARY_WEAPON | SECONDARY_WEAPON_L | SECONDARY_WEAPON_R;

	type = PLASMA;

	rechargeTime = 10.0;

	velocity = 0.7;
	damage = 100.0;
	penetration = 0.0;
}

std::string Plasma::getName() { return "Plasma"; }
