DESCRIPTION = "A single-file, ANSI C, command-line parsing library that parses GNU-style command-line options."
HOMEPAGE = "https://www.argtable.org/"
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/BSD-3-Clause;md5=550794465ba0ec5312d6919e203a55f9"

SRC_URI = "git://github.com/argtable/argtable3.git;protocol=https"
SRCREV = "v3.1.5.1c1bb23"

S = "${WORKDIR}/git"

inherit cmake
