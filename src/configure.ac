AC_INIT(reaver, 1.3 beta)

AC_PROG_CC
AC_LANG(C)

CFLAGS="-Wall $CFLAGS"
CONFDIR="/etc"

AC_CHECK_LIB(pcap, pcap_open_live, [], [echo "error: pcap library not found!"; exit -1])
AC_CHECK_LIB(sqlite3, sqlite3_open, [], [echo "error: sqlite3 library not found!"; exit -1])
AC_CHECK_HEADERS([stdlib.h stdint.h string.h],[],[echo "error: missing standard header files" && exit -1])
AC_CHECK_HEADERS([pcap.h],[],[echo "error: missing sqlite3 header files" && exit -1])
AC_CHECK_HEADERS([sqlite3.h],[],[echo "error: missing sqlite3 header files" && exit -1])

AC_DEFINE_UNQUOTED(CONF_DIR, "${CONFDIR}/${PACKAGE_NAME}")
cp confdefs.h config.h

AC_SUBST(confdir, $CONFDIR)
AC_SUBST(target, $PACKAGE_NAME)
AC_OUTPUT(Makefile)
