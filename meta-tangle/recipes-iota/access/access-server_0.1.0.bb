SUMMARY = "IOTA Access Server Reference Implementation."
DESCRIPTION = "IOTA Access is a framework for decentralized access control."
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git:///home/bernardo/access-server;protocol=file"

# tag v0.1.0
SRCREV = "c973995b9bcb0006d375c854c8fe80b38d38fc72" 

S = "${WORKDIR}/git"

inherit cmake pkgconfig

DEPENDS = "libfastjson pigpio "

EXTRA_OECMAKE = "-DCMAKE_INSTALL_PREFIX=$PWD/ext_install "

do_configure_prepend() {

    # temporary workaround
    # todo: gitsm when public
    cp -r /home/bernardo/access-sdk ${S}
    cp -r ${S}/access-sdk ${B}

    # allow CMake 3.14 workaround
    sed -i 's/16/14/g' ${S}/CMakeLists.txt

    # there's a separate recipe for pigpio
    sed -i '36,43d' ${S}/CMakeLists.txt
    sed -i '70,72d' ${S}/CMakeLists.txt

}

do_install(){

    # install executable
    install -d ${D}${bindir}
    install -m 0755 ${B}/asri ${D}${bindir}

    # install config.ini
    install -m 0755 -d ${D}${sysconfdir}/access-server
    install -m 0644 ${S}/config.ini ${D}${sysconfdir}/access-server

}

