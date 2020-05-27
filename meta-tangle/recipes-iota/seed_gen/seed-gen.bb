SUMMARY = "IOTA (Extremely Unsafe) Seed Generator"
DESCRIPTION = "An extremely unsafe way to generate IOTA seeds"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

SRC_URI = " file://iota_seed_gen"

do_install(){
    install -m 0744 -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/iota_seed_gen ${D}${bindir}
}
