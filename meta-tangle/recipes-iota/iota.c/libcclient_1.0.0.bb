SUMMARY = "IOTA CClient Library."
DESCRIPTION = "IOTA client library implementation in C"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git://github.com/iotaledger/iota.c.git;branch=master"
SRCREV = "6b1ad26cfecacbebdd5302b7ce377df14a017a00"

RDEPENDS_${PN}-dev = ""
DEPENDS = "mbedtls http-parser cjson"

inherit cmake

OECMAKE_FIND_ROOT_PATH_MODE_PROGRAM = "BOTH"
EXTRA_OECMAKE = "-DCCLIENT_TEST=OFF -DCMAKE_INSTALL_PREFIX=${D}"

S = "${WORKDIR}/git"

do_install(){
    #install libcclient.a

    install -d ${D}${libdir}
    install -m 0644 ${B}/libcclient.a ${D}${libdir}

    ## install headers
    # copy a bunch of stuff (including headers)

    install -m 0755 -d ${D}${includedir}
    cp -r ${S}/cclient ${D}${includedir}

    ## install headers
    # delete everything that's not *.h
    find ${D}${includedir} -type f -not -name '*.h' -print0 | xargs -0 -I {} rm -r {}
}
