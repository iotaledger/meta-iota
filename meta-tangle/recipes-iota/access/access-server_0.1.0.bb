SUMMARY = "IOTA Access Server Reference Implementation."
DESCRIPTION = "IOTA Access is a framework for decentralized access control."
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git://github.com/iotaledger/access-server.git;protocol=https;nobranch=1 \
           file://0001-fix-cmake-install-rpath.patch \
           file://0002-avoid-pigpio-cmake.patch \
           file://0003-config-ini-path.patch \
"

SRCREV = "969e9e100f913bc463599d7ab3999173f8dc8832"

S = "${WORKDIR}/git"

inherit cmake pkgconfig

DEPENDS = "libfastjson pigpio "

EXTRA_OECMAKE = "-DCMAKE_INSTALL_PREFIX=$PWD/ext_install "

do_install(){

    # install executable
    install -d ${D}${bindir}
    install -m 0755 ${B}/asri ${D}${bindir}

    # install config.ini and wallet_pem.txt
    install -m 0755 -d ${D}${sysconfdir}/access-server
    install -m 0644 ${S}/config.ini ${D}${sysconfdir}/access-server

    install -m 0644 ${S}/wallet_pem.txt ${D}${sysconfdir}/access-server

}

