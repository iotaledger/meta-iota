DESCRIPTION = "A minimal, zero-config, BSD licensed, readline replacement."
LICENSE = "BSD-2-Clause"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/BSD-2-Clause;md5=8bef8e6712b1be5aa76af1ebde9d6378"

SRC_URI = "git://github.com/antirez/linenoise.git;protocol=https"
SRCREV = "4a961c0108720741e2683868eb10495f015ee422"

S = "${WORKDIR}/git"

#INSANE_SKIP_${PN}-dev += "dev-elf"

do_compile(){
    ${CC} -c linenoise.c -o linenoise.o ${LDFLAGS}
 #   ${CC} -shared linenoise.o -o liblinenoise.so ${LDFLAGS}
    ${AR} rcs liblinenoise.a linenoise.o

}

do_install(){
    install -m 0755 -d ${D}${libdir}
    install -m 0755 -d ${D}${includedir}
    install -m 0755 ${S}/liblinenoise.a ${D}${libdir}
    install -m 0644 ${S}/linenoise.h ${D}${includedir}
}
