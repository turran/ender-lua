/* Enesim Lua Bindings - 
 * Copyright (C) 2011 Jorge Luis Zapata
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 * If not, see <http://www.gnu.org/licenses/>.
 */
#include "Ender.h"
#include <lua.h>
/*============================================================================*
 *                                  Local                                     *
 *============================================================================*/
/*----------------------------------------------------------------------------*
 *                             The Lua C interface                            *
 *----------------------------------------------------------------------------*/
static int l_ender_element_new(lua_State *L)
{

}

static int l_ender_element_value_set(lua_State *L)
{

}

static int l_ender_element_value_get(lua_State *L)
{

}

static int l_ender_element_value_add(lua_State *L)
{

}

static int l_ender_element_value_remove(lua_State *L)
{

}

static int l_ender_element_value_clear(lua_State *L)
{

}

static const luaL_reg _ender_api[] = {
	{ "element_new", l_ender_element_new },
	{ NULL, NULL }
};
/*============================================================================*
 *                                   API                                      *
 *============================================================================*/
int luaopen_ender(lua_State * L)
{
  	luaL_register (L, "ender", _ender_api);
	return 1; /* api */
}


