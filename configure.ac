# get rid of that stupid cache mechanism
rm -f config.cache

AC_INIT(enesim-lua, 0.0.1, enesim-devel@googlegroups.com)
AC_PREREQ(2.52)
AC_CONFIG_SRCDIR(configure.ac)
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_ISC_POSIX

AM_INIT_AUTOMAKE(1.6 dist-bzip2)
AM_CONFIG_HEADER(src/include/config.h)
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_PROG_CC
AM_PROG_CC_STDC
AC_HEADER_STDC
AC_C_CONST
AC_C_BIGENDIAN

AC_LIBTOOL_WIN32_DLL
define([AC_LIBTOOL_LANG_CXX_CONFIG], [:])dnl
define([AC_LIBTOOL_LANG_F77_CONFIG], [:])dnl
AC_PROG_LIBTOOL

VMAJ=`echo $PACKAGE_VERSION | awk -F. '{printf("%s", $1);}'`
VMIN=`echo $PACKAGE_VERSION | awk -F. '{printf("%s", $2);}'`
VMIC=`echo $PACKAGE_VERSION | awk -F. '{printf("%s", $3);}'`
SNAP=`echo $PACKAGE_VERSION | awk -F. '{printf("%s", $4);}'`
version_info=`expr $VMAJ + $VMIN`":$VMIC:$VMIN"
AC_SUBST(version_info)
AC_DEFINE_UNQUOTED(VERSION_MAJOR, ${VMAJ}, [Major version])
AC_DEFINE_UNQUOTED(VERSION_MINOR, ${VMIN}, [Minor version])
AC_DEFINE_UNQUOTED(VERSION_MICRO, ${VMIC}, [Micro version])

create_shared_lib=""
case "$host_os" in
    mingw|mingw32)
	create_shared_lib="-no-undefined"
    ;;
esac
AC_SUBST(create_shared_lib)

# Common
PKG_CHECK_MODULES(ENDER, [ender >= 0.0.1])

## LUA
# Lua pkg-config hack for different naming conventions
have_lua="yes"
requirement_lua=""
lua_libs=""
PKG_CHECK_MODULES([LUA], [lua >= 5.1.0], requirement_lua="lua",
   [PKG_CHECK_MODULES([LUA], [lua5.1 >= 5.1.0], requirement_lua="lua5.1",
      [PKG_CHECK_MODULES([LUA], [lua-5.1 >= 5.1.0], requirement_lua="lua-5.1",
         [PKG_CHECK_MODULES([LUA], [lua51 >= 5.1.0], requirement_lua="lua51",
            [have_lua="no"])])])])

if test "x${have_lua}" = "xno" ; then
   AC_MSG_CHECKING([whether lua_newstate() is in liblua])
   AC_CHECK_LIB([lua], [lua_newstate],
      [
       have_lua="yes"
       lua_libs="-llua"
      ],
      [have_lua="no"])
   AC_MSG_RESULT([${have_lua}])
fi
AC_SUBST(lua_libs)

ENESIM_LUA_CFLAGS="$ENDER_CFLAGS $LUA_CFLAGS"
ENESIM_LUA_LIBS="$ENDER_LIBS $LUA_LIBS"
AC_SUBST(ENESIM_LUA_CFLAGS)
AC_SUBST(ENESIM_LUA_LIBS)

## Make the debug preprocessor configurable

AC_OUTPUT([
Makefile
src/Makefile
src/lib/Makefile
src/include/Makefile
],[
])


#####################################################################
## Info

echo
echo
echo
echo "------------------------------------------------------------------------"
echo "$PACKAGE $VERSION"
echo "------------------------------------------------------------------------"
echo
echo
echo "Configuration Options Summary:"
echo
echo "Installation Path.........: $prefix"
echo
echo "Now type 'make' ('gmake' on some systems) to compile $PACKAGE,"
echo "and then afterwards as root (or the user who will install this), type"
echo "'make install'. Change users with 'su' or 'sudo' appropriately."
echo
