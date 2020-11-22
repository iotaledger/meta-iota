PACKAGECONFIG_append = " networkd"

# avoid messing with systemd-networkd on qemu*
DENYLIST_systemd_networkd = "qemuarm qemuarm64 qemux86 qemux86-64 "
PACKAGECONFIG_append = "${@bb.utils.contains('DENYLIST_systemd_networkd', 'MACHINE', 'networkd', '', d)}"
