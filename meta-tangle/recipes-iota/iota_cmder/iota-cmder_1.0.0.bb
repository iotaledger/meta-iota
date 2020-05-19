SUMMARY = "A terminal-based application for interacting with the IOTA Tangle."
DESCRIPTION = "A terminal-based application for interacting with the Tangle through iota.c."
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git://github.com/oopsmonk/iota_cmder.git;branch=master"
SRCREV = "6280a8e4b152df32d85fd02ce4bf56bf8983e83f"

SRC_URI += " \
             file://0001-add-Yocto-CMake-option.patch \
             file://0002-add-pthread-to-link-libs.patch \
             file://0003-add-install-target.patch \
"

DEPENDS = "libcclient linenoise argtable3"

inherit cmake

EXTRA_OECMAKE = "-DYOCTO=ON -DCCLIENT_TEST=OFF"

S = "${WORKDIR}/git"
