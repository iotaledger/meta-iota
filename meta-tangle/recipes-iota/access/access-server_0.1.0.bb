SUMMARY = "IOTA Access."
DESCRIPTION = "IOTA Access is a framework for decentralized access control."
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git:///home/bernardo/access-server;protocol=file"

# tag v0.1.0
SRCREV = "c973995b9bcb0006d375c854c8fe80b38d38fc72" 

S = "${WORKDIR}/git"

inherit cmake pkgconfig

AUTH = "eddsa"
POL = "json"

EXTRA_OECMAKE = "-DCMAKE_INSTALL_PREFIX=$PWD/ext_install -DAUTH_FLAVOUR=${AUTH} -DPOLICY_FORMAT=${POL}"
