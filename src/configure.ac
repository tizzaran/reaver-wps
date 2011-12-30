AC_INIT(reaver, 1.1)

AC_PROG_CC
AC_LANG(C)

CFLAGS="-Wall $CFLAGS"
CONFDIR="/etc"

AC_CHECK_LIB(pcap, pcap_open_live, [], [echo "error: pcap library not found!"; exit -1])

AC_DEFINE_UNQUOTED(CONF_DIR, "${CONFDIR}/${PACKAGE_NAME}")
cp confdefs.h config.h

AC_SUBST(confdir, $CONFDIR)
AC_SUBST(target, $PACKAGE_NAME)
AC_OUTPUT(Makefile)
