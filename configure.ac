#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
#AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_INIT([wzwWebServer], [0.0.1], [weizhenwei1988@gmail.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE(wzwWebServer, 0.0.1)

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h locale.h netinet/in.h stdlib.h string.h strings.h sys/socket.h syslog.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([bzero memset setlocale socket])

#AC_CONFIG_FILES([Makefile])

#Attention: this is import, list the Makefile need to generate
AC_OUTPUT(Makefile src/Makefile)
