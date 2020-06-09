SUMMARY = "GoShimmer Helper Tools "
DESCRIPTION = "GoShimmer Helper Tools "
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git://github.com/honeycombOS/goshimmerctl.git;protocol=https"
SRCREV = "ae71081aedecd1fb21955b50ff7df01a4f7a6504"

S = "${WORKDIR}/git"

RDEPENDS_${PN} = " goshimmer python3"

do_install(){

    install -m 0755 -d ${D}${bindir}

    # install goshimmer helper tools
    install -m 0755 ${S}/goshimmerctl ${D}${bindir}
}
