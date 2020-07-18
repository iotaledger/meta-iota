require conf/distro/poky.conf

DISTRO = "honeycomb"
DISTRO_NAME = "IOTA honeycombOS"
DISTRO_VERSION = "0.4.0"

MAINTAINER = "Bernardo A. Rodrigues <bernardo.araujo@iota.org>"

GOVERSION = "1.14%"

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
EXTRA_USERS_PARAMS = "usermod -P tangleisawesome root;"
