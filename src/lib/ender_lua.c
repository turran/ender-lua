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
#include <lauxlib.h>

#define ENDER_LUA_CORE "ender.core"
/*============================================================================*
 *                                  Local                                     *
 *============================================================================*/
#define checkender(L, narg) ((Ender *) _checkudata((L), (narg)))

static void * _checkudata(lua_State * L, int narg)
{
	if (!lua_isuserdata(L, narg))
		luaL_typerror(L, narg, "userdata");
	return lua_touserdata(L, narg);
}
/*----------------------------------------------------------------------------*
 *                             The Lua C interface                            *
 *----------------------------------------------------------------------------*/
#if 0
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
#endif

static int ender_lua_load(lua_State *L)
{
	/* check the input params */
	/* load the lib we have requested */
	printf("load\n");
	return 0;
}

static const luaL_Reg ender_lua[] = {
	{ "load", ender_lua_load },
	{ NULL, NULL }
};

/*============================================================================*
 *                                   API                                      *
 *============================================================================*/
int luaopen_ender(lua_State *L)
{
	ender_init();
	lua_newtable(L);
	luaL_register(L, NULL, ender_lua);

	//luaL_newmetatable(L, ENDER_LUA_CORE);
	//luaL_register(L, NULL, ender_lua);

	return 1; /* api */
}
