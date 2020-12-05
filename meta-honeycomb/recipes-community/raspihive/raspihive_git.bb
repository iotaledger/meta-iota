SUMMARY = "The Plug and Play solution for a Raspberry Pi IOTA Fullnode with userfriendly UI and extensions"
DESCRIPTION = "Its simply created for the users, by the users. There are no highly paid developers or poorly paid support personnel on the phones ready to take your call. There are only users who have seen a problem and done their best to fix it. The goal is, to provide a complete ready-to-go Linux image to install (for best experience with a Raspberry Pi and a touchscreen). This image provides (depending on the stage of the project) diferrent options to install an IOTA Node, security, Dashboards, and make it accessible."

HOMEPAGE = "https://raspihive.org/"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=dd1880b84e99129b858e866ac9d939c0"

SRC_URI = "git://github.com/Raspihive/raspihive.git;protocol=https"
SRCREV = "05ebd57d40eaefcad3f5f38524529de7a52203a5"

S = "${WORKDIR}/git"

do_install() {

    # install executable
    install -d ${D}${bindir}
    install -m 0755 ${S}/raspihive.py ${D}${bindir}/raspihive

}
