#include <lauxlib.h>
#include <lualib.h>
#include <stdio.h>

static int c_func(lua_State *L) {
  (void)L;
  puts("This from C host at 'c_func' function");
  return 0;
}

static int c_func2(lua_State *L) {
  (void)L;
  lua_Number a = lua_tonumber(L, -1); // c_func2(b, a)
  lua_Number b = lua_tonumber(L, -2); // c_func2(b, a)
  printf("a=%f, b=%f\n", a, b);
  lua_pushnumber(L, a * b); // local >x, y = c_func2(1998, 2)
  lua_pushnumber(L, a + b); // local  x,>y = c_func2(1998, 2)

  return 2;
}

struct data {
  int x;
  char *name;
};

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  lua_register(L, "c_func", c_func);
  lua_register(L, "c_func2", c_func2);
  luaL_dofile(L, "lib.lua");

  lua_getglobal(L, "Foo");
  lua_rawgeti(L, -1, 1);
  lua_Number first = lua_tonumber(L, -1);
  printf("rawgeti->%f\n", first);
  lua_rawgeti(L, -2, 2);
  lua_Number second = lua_tonumber(L, -1);
  printf("rawgeti->%f\n", second);
  lua_rawgeti(L, -3, 3);
  lua_Number third = lua_tonumber(L, -1);
  printf("rawgeti->%f\n", third);

  lua_getglobal(L, "Xprintf");
  lua_pushstring(L, "log.txt");
  lua_call(L, 1, 0);
  puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  lua_getglobal(L, "Ver");
  size_t sz = 0;
  const char *v = lua_tolstring(L, -1, &sz);
  printf("%s::%zu\n", v, sz);

  lua_getglobal(L, "Meta");
  lua_getfield(L, -1, "Ver");
  const char *d = lua_tolstring(L, -1, &sz);
  printf("%s::%zu\n", d, sz);

  /* create C struct and send to lua */
  struct data c_data = {736, "WELCOME FROM C STRUCT"};
  lua_newtable(L); /* or with lua_createtable(L, narr, nrec) */
  lua_pushnumber(L, c_data.x);
  lua_setfield(L, -2, "x");
  lua_pushstring(L, c_data.name);
  lua_setfield(L, -2, "name");
  lua_setglobal(L, "C_struct");

  lua_getglobal(L, "Printf_C_struct");
  lua_getglobal(L, "C_struct");
  lua_call(L, 1, 0);

  lua_getglobal(L, "Meta");
  lua_pushcfunction(L, c_func);
  lua_setfield(L, -2, "mycfunc");

  lua_getglobal(L, "Meta");
  lua_getfield(L, -1, "mycfunc");
  lua_CFunction fn = lua_tocfunction(L, -1);
  fn(L);

  lua_close(L);
  return 0;
}
