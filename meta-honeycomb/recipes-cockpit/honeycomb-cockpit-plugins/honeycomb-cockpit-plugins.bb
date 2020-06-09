SUMMARY = "Cockpit plugins for Aero platform"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=0835ade698e0bcf8506ecda2f7b4f302"

DEPENDS = "cockpit"

SRCREV = "fdadebef9af641165be6d6a814fa8ad9f62bf549"
SRC_URI = "git://git@github.com/honeycombOS/honeycomb-cockpit-plugins.git;protocol=https"

S = "${WORKDIR}/git"

do_configure() {
}

do_compile() {
}

do_install() {
    cd ${S}
    make V=1 DEST=${D} install
}

FILES_${PN} = "${datadir}"
