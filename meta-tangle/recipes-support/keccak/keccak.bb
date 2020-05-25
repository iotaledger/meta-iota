SUMMARY = "eXtended Keccak Code Package."
DESCRIPTION = "The eXtended Keccak Code Package (or the Xoodoo and Keccak Code Package, in both cases abbreviated as XKCP) gathers different free and open-source implementations of the Keccak sponge function family and closely related variants."
HOMEPAGE = "https://keccak.team/"
LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI = " \
            https://github.com/XKCP/XKCP/archive/a7a105cefc172178c3c9bb7e5f0768e0b226016b.tar.gz \
            file://0001-remove-native-gcc-options.patch \
"

SRC_URI[md5sum] = "af2f1c33e8593fb3fc666f54419b06ef"
SRC_URI[sha256sum] = "245418d6dd84c7eabfa77c93c5b0eff32c405e691048589bb8d6a253d139bfa3"

S = "${WORKDIR}/XKCP-a7a105cefc172178c3c9bb7e5f0768e0b226016b"

RDEPENDS_${PN}-dev = ""
DEPENDS = "libxslt-native"

do_compile() {
    oe_runmake compact/libkeccak.a
}

do_install() {
    #install libkeccak.a

    install -d ${D}${libdir}
    install -m 0644 ${S}/bin/compact/libkeccak.a ${D}${libdir}

    ## install headers
    install -d ${D}${includedir}
    cp -r ${S}/lib/high/Keccak/FIPS202/ ${D}${includedir}
    cp ${S}/lib/low/KeccakP-1600/Reference/KeccakP-1600-SnP.h ${D}${includedir}
    cp ${S}/lib/high/Keccak/KeccakSpongeWidth1600.h ${D}${includedir}
    cp ${S}/lib/high/Keccak/KeccakSponge-common.h ${D}${includedir}
    cp ${S}/lib/common/align.h ${D}${includedir}
}
