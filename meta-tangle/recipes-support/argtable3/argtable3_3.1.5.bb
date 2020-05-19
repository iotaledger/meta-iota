DESCRIPTION = "A single-file, ANSI C, command-line parsing library that parses GNU-style command-line options."
HOMEPAGE = "https://www.argtable.org/"
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/BSD-2-Clause;md5=8bef8e6712b1be5aa76af1ebde9d6378"

SRC_URI = "git://github.com/argtable/argtable3.git;protocol=https"
SRCREV = "v3.1.5.1c1bb23"

S = "${WORKDIR}/git"

inherit cmake
