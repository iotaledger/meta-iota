SUMMARY = "IOTA Common functions and crypto implementations in C."
DESCRIPTION = "IOTA Common functions and crypto implementations in C "
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git://github.com/iotaledger/iota_common.git;branch=master"
SRCREV = "e37169cdaf9864ed36ba2a7d32504121a3ab1d04"

RDEPENDS_${PN}-dev = ""
DEPENDS = "keccak uthash mbedtls logger http-parser cjson"

inherit cmake

OECMAKE_FIND_ROOT_PATH_MODE_PROGRAM = "BOTH"
EXTRA_OECMAKE = "-DCMAKE_INSTALL_PREFIX=${D}"

S = "${WORKDIR}/git"

do_install(){
    #install libcommon.a

    install -d ${D}${libdir}
    install -m 0644 ${B}/libcommon.a ${D}${libdir}

    ## install headers
    # copy a bunch of stuff (including headers)

    install -m 0755 -d ${D}${includedir}
    cp -r ${S}/common ${D}${includedir}
    cp -r ${S}/utils ${D}${includedir}

    ## install headers
    # delete everything that's not *.h
    find ${D}${includedir} -type f -not -name '*.h' -print0 | xargs -0 -I {} rm -r {}
}
