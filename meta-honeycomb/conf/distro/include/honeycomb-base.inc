require conf/distro/poky.conf

DISTRO = "honeycomb"
DISTRO_NAME = "IOTA honeycombOS"
DISTRO_VERSION = "0.4.0"

MAINTAINER = "Bernardo A. Rodrigues <bernardo.araujo@iota.org>"

GOVERSION = "1.15%"

DISTRO_FEATURES += " \
                   systemd \
                   wifi \
                   pam \
                   polkit \
"

VIRTUAL-RUNTIME_init_manager = "systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"

PACKAGE_CLASSES = "package_deb"

INHERIT += "extrausers"

DENYLIST_usermod = "qemuarm qemuarm64 qemux86 qemux86-64 genericx86 genericx86-64 "
EXTRA_USERS_PARAMS = "${@bb.utils.contains('DENYLIST_usermod', 'MACHINE', 'usermod -P tangleisawesome root;', '', d)}"
