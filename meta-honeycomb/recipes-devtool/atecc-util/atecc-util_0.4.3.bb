SUMMARY = "Linux command-line tool for ATECC608A and ATECC508A."
DESCRIPTION = "Linux command-line tool for ATECC608A and ATECC508A ICs connected via i2c. Uses Microchip CryptoAuthLib."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=c4f97be8892be06acd4500b030c4e20d \
                    file://debian/copyright;md5=d41d8cd98f00b204e9800998ecf8427e \
                    file://cryptoauthlib/license.txt;md5=3d131499ca4e4938a757bc45996429d1 \
                    file://cryptoauthlib/test/unity_license.txt;md5=2d59abcf18c449020ce3b039475f0f0e"

SRC_URI = "gitsm://github.com/wirenboard/atecc-util;protocol=https"
SRCREV = "d13c10ab1952ddd682429a77fcea39fa4d61d1ac"

S = "${WORKDIR}/git"

TARGET_CC_ARCH += "${LDFLAGS}"

do_compile () {
  oe_runmake
}

do_install () {
	oe_runmake install 'DESTDIR=${D}'
}
