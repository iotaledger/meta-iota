SUMMARY = "IOTA Access SDK."
DESCRIPTION = "IOTA Access is a framework for decentralized access control."
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git:///home/bernardo/access-sdk;protocol=file;nobranch=1"

SRCREV = "v0.1.0-alpha"

S = "${WORKDIR}/git"

inherit cmake pkgconfig

DEPENDS = "libfastjson libcommon"

EXTRA_OECMAKE = "-DCMAKE_INSTALL_PREFIX=$PWD/ext_install -DCMAKE_NO_SYSTEM_FROM_IMPORTED=1"

do_install() {

    install -d ${D}${libdir}
    install -m 0644 ${B}/auth/*/*.a ${D}${libdir}
    install -m 0644 ${B}/auth/libauth.a ${D}${libdir}
    install -m 0644 ${B}/plugin/libplugin.a ${D}${libdir}
    install -m 0644 ${B}/policy/*/*.a ${D}${libdir}
    install -m 0644 ${B}/policy/encoding/json/libjson.a ${D}${libdir}
    install -m 0644 ${B}/utils/*/*.a ${D}${libdir}

    install -m 0755 -d ${D}${includedir}
    cp ${S}/plugin/*.h ${D}${includedir}
    cp ${S}/policy/p*p/*.h ${D}${includedir}
    cp ${S}/policy/p*p/*/*.h ${D}${includedir}
    cp ${S}/policy/pap/user/implementations/sqlite3_example/user_implementation.h ${D}${includedir}
    cp ${S}/policy/encoding/json/*.h ${D}${includedir}
    cp ${S}/auth/auth.h ${D}${includedir}
    cp ${S}/auth/${AUTH}/*.h ${D}${includedir}
    cp ${S}/auth/tcpip/tcpip.h ${D}${includedir}
    cp ${S}/utils/crypto/*.h ${D}${includedir}
    cp ${S}/utils/crypto/*/*.h ${D}${includedir}
    cp ${S}/utils/misc/globals_declarations.h ${D}${includedir}
    cp ${S}/utils/misc/*.h ${D}${includedir}

}
