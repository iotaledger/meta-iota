SUMMARY = "pigpio is a library for the Raspberry which allows control of the General Purpose Input Outputs (GPIO)"
HOMEPAGE = "https://http://abyz.me.uk/rpi/pigpio/"
LICENSE = "Unlicense"
LIC_FILES_CHKSUM = "file://UNLICENCE;md5=61287f92700ec1bdf13bc86d8228cd13"

SRC_URI = " \
            git://github.com/joan2937/pigpio.git \
            file://0001-soft-assign-compiler-tools-on-Makefile.patch \
            file://0002-avoid-python-install-target-on-Makefile.patch \
            file://0003-rm-STRIP-from-Makefile.patch \
            file://0004-add-LDFLAGS-to-Makefile.patch \
"
SRCREV = "v74"

S = "${WORKDIR}/git"

FILES_${PN} = " ${exec_prefix} /opt"

do_compile (){
    oe_runmake
}

do_install() {
    oe_runmake DESTDIR=${D} install 
    mv ${D}${exec_prefix}/local/* ${D}${exec_prefix}
}
