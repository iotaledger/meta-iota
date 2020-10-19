SUMMARY = "GoShimmer implementation of IOTA Coordicide."
DESCRIPTION = "Prototype node software for an IOTA network without the Coordinator."

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

SRC_URI = "git://github.com/iotaledger/goshimmer.git;protocol=https;name=goshimmer;destsuffix=${BPN}-${PV}/src/github.com/iotaledger/goshimmer"

inherit go go-mod pkgconfig
GO_IMPORT = "github.com/iotaledger/goshimmer"
GO_LINKSHARED = ""

GOBUILDFLAGS_append = " -modcacherw"
export GO111MODULE = "on"