FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

DENYLIST_systemd_networkd = "qemuarm qemuarm64 qemux86 qemux86-64 "

SRC_URI += " \
    ${@bb.utils.contains('DENYLIST_systemd_networkd', 'MACHINE', 'file://eth.network', '', d)} \
    ${@bb.utils.contains('DENYLIST_systemd_networkd', 'MACHINE', 'file://wlan.network', '', d)} \
"

FILES_${PN} += " \
    ${@bb.utils.contains('DENYLIST_systemd_networkd', 'MACHINE', '${sysconfdir}/systemd/network/eth.network', '', d)} \
    ${@bb.utils.contains('DENYLIST_systemd_networkd', 'MACHINE', '${sysconfdir}/systemd/network/wlan.network', '', d)} \
"

do_install_append() {
    if [[ ${DENYLIST_systemd_networkd} = *"${MACHINE}"*]]; then
        install -d ${D}${sysconfdir}/systemd/network
        install -m 0644 ${WORKDIR}/eth.network ${D}${sysconfdir}/systemd/network
        install -m 0644 ${WORKDIR}/wlan.network ${D}${sysconfdir}/systemd/network
    fi
}
