SUMMARY = "IOTA Sensor MAM Demo."
DESCRIPTION = "An application which reads the env sensor data from a MAM channel."
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = " \
            git://github.com/iota-community/env-sensor-mam-writer.git;branch=json; \
"

SRCREV = "${AUTOREV}"

DEPENDS += " mam mbedtls http-parser uthash keccak logger"

S = "${WORKDIR}/git"

do_compile(){
    ${CC} -c iota/common.c
    ${CC} -c iota/send-common.c
    ${CC} -c iota/send-header.c
    ${CC} -c iota/send-msg.c
    ${CC} -c iota/send-packet.c
}
