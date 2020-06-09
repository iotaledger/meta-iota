SUMMARY = "HORNET Helper Tools "
DESCRIPTION = "HORNET Helper Tools "
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git://github.com/honeycombOS/hornetctl.git;protocol=https"
SRCREV = "108ba111702e6a1561be726b67438fa48296a1b5"

S = "${WORKDIR}/git"

RDEPENDS_${PN} = " hornet python python3-pyyaml python3-urllib3"

do_install(){

    install -m 0755 -d ${D}${bindir}

    # install hornet helper scripts
    install -m 0755 ${S}/hornetctl ${D}${bindir}
}
