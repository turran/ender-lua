MAINTAINERCLEANFILES = Makefile.in

lib_LTLIBRARIES = libender_lua.la

libender_lua_la_SOURCES = ender_lua.c
libender_lua_la_LIBADD = @ENDER_LUA_LIBS@
libender_lua_la_LDFLAGS = -no-undefined
libender_lua_la_CFLAGS = @ENDER_LUA_CFLAGS@

install-exec-hook:
	mkdir -p $(LUA_CMOD_DIR)
	ln -f -s $(libdir)/libender_lua.so $(LUA_CMOD_DIR)/ender.so
