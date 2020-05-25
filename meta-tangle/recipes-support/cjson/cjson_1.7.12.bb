# this recipe was borrowed from meta-iot-cloud
# it was originally written by Intel.
# the original version can be found at:
# https://github.com/intel-iot-devkit/meta-iot-cloud

DESCRIPTION = "Ultralightweight JSON parser in ANSI C"
HOMEPAGE = "https://github.com/DaveGamble/cJSON"
AUTHOR = "Dave Gamble"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=218947f77e8cb8e2fa02918dc41c50d0"

inherit cmake pkgconfig

PR = "r0"

SRC_URI = "\
    git://github.com/DaveGamble/cJSON.git \
"

SRCREV = "v${PV}"

S = "${WORKDIR}/git"

FILES_${PN}-dev += "\
    ${libdir}/cmake \
"

EXTRA_OECMAKE += "\
    -DENABLE_CUSTOM_COMPILER_FLAGS=OFF \
    -DBUILD_SHARED_AND_STATIC_LIBS=On \
"

do_install_append(){
    install -m 0644 ${S}/cJSON.h ${D}${includedir}
}
