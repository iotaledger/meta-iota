SUMMARY = "A terminal-based application for interacting with the IOTA Tangle."
DESCRIPTION = "A terminal-based application for interacting with the Tangle through iota.c."
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git://github.com/oopsmonk/iota_cmder.git;branch=master"
SRCREV = "6280a8e4b152df32d85fd02ce4bf56bf8983e83f"

RDEPENDS_${PN} = "cjson"
DEPENDS = "linenoise argtable3 cjson"

inherit cmake

OECMAKE_FIND_ROOT_PATH_MODE_PROGRAM = "BOTH"
EXTRA_OECMAKE = "-DCCLIENT_TEST=OFF -DCMAKE_INSTALL_PREFIX=${D} -DCMAKE_SKIP_RPATH=ON"

S = "${WORKDIR}/git"

do_install(){
    install -d ${D}${bindir}
    install -m 0755 ${B}/iota_cmder ${D}${bindir}
}
