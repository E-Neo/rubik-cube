#include <lua.h>
#include <lauxlib.h>
#include "cube/cube.h"

static void rubik_Cube_return (lua_State *L, cube_t *cube);

static int
rubik_Cube_state (lua_State *L)
{
  int i;
  cube_t *cube = lua_touserdata (L, lua_upvalueindex (1));
  lua_createtable (L, 0, 6);
  lua_createtable (L, 9, 0);
  for (i = 0; i < 9; i++)
    {
      lua_pushinteger (L, cube->F[i]);
      lua_rawseti (L, -2, i);
    }
  lua_setfield (L, -2, "F");
  lua_createtable (L, 9, 0);
  for (i = 0; i < 9; i++)
    {
      lua_pushinteger (L, cube->B[i]);
      lua_rawseti (L, -2, i);
    }
  lua_setfield (L, -2, "B");
  lua_createtable (L, 9, 0);
  for (i = 0; i < 9; i++)
    {
      lua_pushinteger (L, cube->U[i]);
      lua_rawseti (L, -2, i);
    }
  lua_setfield (L, -2, "U");
  lua_createtable (L, 9, 0);
  for (i = 0; i < 9; i++)
    {
      lua_pushinteger (L, cube->D[i]);
      lua_rawseti (L, -2, i);
    }
  lua_setfield (L, -2, "D");
  lua_createtable (L, 9, 0);
  for (i = 0; i < 9; i++)
    {
      lua_pushinteger (L, cube->L[i]);
      lua_rawseti (L, -2, i);
    }
  lua_setfield (L, -2, "L");
  lua_createtable (L, 9, 0);
  for (i = 0; i < 9; i++)
    {
      lua_pushinteger (L, cube->R[i]);
      lua_rawseti (L, -2, i);
    }
  lua_setfield (L, -2, "R");
  return 1;
}

static int
rubik_Cube_tostring (lua_State *L)
{
  cube_t *cube = lua_touserdata (L, lua_upvalueindex (1));
  char format[] =
    "            +---+---+---+\n"
    "            | %hhd | %hhd | %hhd |\n"
    "            +---+---+---+\n"
    "            | %hhd | %hhd | %hhd |\n"
    "            +---+---+---+\n"
    "            | %hhd | %hhd | %hhd |\n"
    "+---+---+---+---+---+---+---+---+---+---+---+---+\n"
    "| %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd |\n"
    "+---+---+---+---+---+---+---+---+---+---+---+---+\n"
    "| %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd |\n"
    "+---+---+---+---+---+---+---+---+---+---+---+---+\n"
    "| %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd | %hhd |\n"
    "+---+---+---+---+---+---+---+---+---+---+---+---+\n"
    "            | %hhd | %hhd | %hhd |\n"
    "            +---+---+---+\n"
    "            | %hhd | %hhd | %hhd |\n"
    "            +---+---+---+\n"
    "            | %hhd | %hhd | %hhd |\n"
    "            +---+---+---+\n";
  char str[sizeof (format) - 9 * 6 * 3];
  sprintf (str, format,
           cube->U[0], cube->U[1], cube->U[2],
           cube->U[3], cube->U[4], cube->U[5],
           cube->U[6], cube->U[7], cube->U[8],
           cube->L[0], cube->L[1], cube->L[2],
           cube->F[0], cube->F[1], cube->F[2],
           cube->R[0], cube->R[1], cube->R[2],
           cube->B[0], cube->B[1], cube->B[2],
           cube->L[3], cube->L[4], cube->L[5],
           cube->F[3], cube->F[4], cube->F[5],
           cube->R[3], cube->R[4], cube->R[5],
           cube->B[3], cube->B[4], cube->B[5],
           cube->L[6], cube->L[7], cube->L[8],
           cube->F[6], cube->F[7], cube->F[8],
           cube->R[6], cube->R[7], cube->R[8],
           cube->B[6], cube->B[7], cube->B[8],
           cube->D[0], cube->D[1], cube->D[2],
           cube->D[3], cube->D[4], cube->D[5],
           cube->D[6], cube->D[7], cube->D[8]);
  lua_pushstring (L, str);
  return 1;
}

static int
rubik_Cube_move_F (lua_State *L)
{
  cube_t *cube = lua_touserdata (L, lua_upvalueindex (1));
  cube_move_F (cube);
  rubik_Cube_return (L, cube);
  return 1;
}

static int
rubik_Cube_move_B (lua_State *L)
{
  cube_t *cube = lua_touserdata (L, lua_upvalueindex (1));
  cube_move_B (cube);
  rubik_Cube_return (L, cube);
  return 1;
}

static int
rubik_Cube_move_U (lua_State *L)
{
  cube_t *cube = lua_touserdata (L, lua_upvalueindex (1));
  cube_move_U (cube);
  rubik_Cube_return (L, cube);
  return 1;
}

static int
rubik_Cube_move_D (lua_State *L)
{
  cube_t *cube = lua_touserdata (L, lua_upvalueindex (1));
  cube_move_D (cube);
  rubik_Cube_return (L, cube);
  return 1;
}

static int
rubik_Cube_move_L (lua_State *L)
{
  cube_t *cube = lua_touserdata (L, lua_upvalueindex (1));
  cube_move_L (cube);
  rubik_Cube_return (L, cube);
  return 1;
}

static int
rubik_Cube_move_R (lua_State *L)
{
  cube_t *cube = lua_touserdata (L, lua_upvalueindex (1));
  cube_move_R (cube);
  rubik_Cube_return (L, cube);
  return 1;
}

static void
rubik_Cube_return (lua_State *L, cube_t *cube)
{
  lua_createtable (L, 0, 7);
  lua_createtable (L, 0, 1);
  lua_pushlightuserdata (L, cube);
  lua_pushcclosure (L, rubik_Cube_tostring, 1);
  lua_setfield (L, -2, "__tostring");
  lua_setmetatable (L, -2);
  lua_pushlightuserdata (L, cube);
  lua_pushcclosure (L, rubik_Cube_move_F, 1);
  lua_setfield (L, -2, "F");
  lua_pushlightuserdata (L, cube);
  lua_pushcclosure (L, rubik_Cube_move_B, 1);
  lua_setfield (L, -2, "B");
  lua_pushlightuserdata (L, cube);
  lua_pushcclosure (L, rubik_Cube_move_U, 1);
  lua_setfield (L, -2, "U");
  lua_pushlightuserdata (L, cube);
  lua_pushcclosure (L, rubik_Cube_move_D, 1);
  lua_setfield (L, -2, "D");
  lua_pushlightuserdata (L, cube);
  lua_pushcclosure (L, rubik_Cube_move_L, 1);
  lua_setfield (L, -2, "L");
  lua_pushlightuserdata (L, cube);
  lua_pushcclosure (L, rubik_Cube_move_R, 1);
  lua_setfield (L, -2, "R");
  lua_pushlightuserdata (L, cube);
  lua_pushcclosure (L, rubik_Cube_state, 1);
  lua_setfield (L, -2, "state");
}

static int
rubik_Cube (lua_State *L)
{
  cube_t *cube = lua_newuserdata (L, sizeof(cube_t));
  cube_init (cube);
  rubik_Cube_return (L, cube);
  return 1;
}

static const luaL_Reg rubiklib[] = {
  {"Cube", rubik_Cube},
  {NULL, NULL}
};

extern int luaopen_rubik (lua_State *L)
{
  luaL_newlib (L, rubiklib);
  return 1;
}
