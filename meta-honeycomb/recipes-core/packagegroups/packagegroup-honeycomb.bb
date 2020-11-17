SUMMARY = "honeycomb Package Group"

inherit packagegroup

PROVIDES = "${PACKAGES}"
PACKAGES = " \
             packagegroup-honeycomb-misc \
             packagegroup-honeycomb-networking \
             packagegroup-honeycomb-development \
             packagegroup-honeycomb-iota \
"

ROOTFS_MACHINE_BLACKLIST = "stm32mp1-disco"

RDEPENDS_packagegroup-honeycomb-misc = " \
                                       sudo \
                                       useradd-beekeeper \
                                       ${@bb.utils.contains("MACHINE", "${ROOTFS_MACHINE_BLACKLIST}", "", "swapfile", d)} \
                                       ${@bb.utils.contains("MACHINE", "${ROOTFS_MACHINE_BLACKLIST}", "", "expand-rootfs", d)} \
                                       screen \
                                       tmux \
                                       cronie \
                                       man-db \
                                       htop \
                                       gnupg \
                                       usbutils \
"

RDEPENDS_packagegroup-honeycomb-networking = " \
                                             net-tools \
                                             wpa-supplicant \
                                             openvpn \
                                             wget \
                                             curl \
                                             ca-certificates \
                                             nginx \
                                             acme \
"

RDEPENDS_packagegroup-honeycomb-development += " \
                                        git \
                                        nano \
                                        vim \
                                        jq \
                                        python3 \
                                        python3-dev \
                                        python3-pip \
                                        python3-setuptools \
                                        go \
                                        go-runtime \
"

RDEPENDS_packagegroup-honeycomb-iota = " \
                                       seed-gen \
                                       iota-cmder \
                                       hornet \
                                       hornetctl \
                                       goshimmer \
                                       goshimmerctl \
                                       honeycomb-package-feeds \
"

RDEPENDS_packagegroup-honeycomb-iota_remove = "${@bb.utils.contains('MACHINE', 'stm32mp1-disco', '', 'goshimmer', d)}"
RDEPENDS_packagegroup-honeycomb-iota_remove = "${@bb.utils.contains('MACHINE', 'stm32mp1-disco', '', 'goshimmerctl', d)}"
RDEPENDS_packagegroup-honeycomb-iota_remove = "${@bb.utils.contains('MACHINE', 'qemuarm', '', 'goshimmer', d)}"
RDEPENDS_packagegroup-honeycomb-iota_remove = "${@bb.utils.contains('MACHINE', 'qemuarm', '', 'goshimmerctl', d)}"

RDEPENDS_packagegroup-honeycomb-cockpit = " \
                                            cockpit \
                                            cockpit-ws \
                                            cockpit-systemd \
                                            cockpit-dashboard \
                                            cockpit-bridge \
                                            cockpit-pcp \
                                            honeycomb-cockpit-plugins \
"
