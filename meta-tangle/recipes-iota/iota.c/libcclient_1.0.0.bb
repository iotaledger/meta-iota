SUMMARY = "IOTA CClient Library."
DESCRIPTION = "IOTA client library implementation in C"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git://github.com/iotaledger/iota.c.git;branch=master"
SRCREV = "959c1e20e7bc8660a736c9db7042264e1e79854f"

RDEPENDS_${PN}-dev = ""
DEPENDS = "libcommon keccak uthash mbedtls logger http-parser cjson"

inherit cmake

EXTRA_OECMAKE = "-DYOCTO=ON -DCCLIENT_TEST=OFF"

S = "${WORKDIR}/git"
