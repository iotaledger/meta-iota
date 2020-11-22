SUMMARY = "honeycomb Package Group"

inherit packagegroup

PROVIDES = "${PACKAGES}"
PACKAGES = " \
             packagegroup-honeycomb-misc \
             packagegroup-honeycomb-networking \
             packagegroup-honeycomb-development \
             packagegroup-honeycomb-iota \
"

RDEPENDS_packagegroup-honeycomb-misc = " \
                                       sudo \
                                       useradd-beekeeper \
                                       swapfile \
                                       expand-rootfs \
                                       screen \
                                       tmux \
                                       cronie \
                                       man-db \
                                       htop \
                                       gnupg \
                                       usbutils \
"

DENYLIST_swapfile = "qemuarm qemuarm64 qemux86 qemux86-64 genericx86 genericx86-64 "
RDEPENDS_packagegroup-honeycomb-misc_remove = "${@bb.utils.contains('DENYLIST_swapfile', 'MACHINE', 'swapfile', '', d)}"

DENYLIST_expand-rootfs = "qemuarm qemuarm64 qemux86 qemux86-64 stm32mp1-eval stm32mp1-disco "
RDEPENDS_packagegroup-honeycomb-misc_remove = "${@bb.utils.contains('DENYLIST_expand-rootfs', 'MACHINE', 'expand-rootfs', '', d)}"

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

# GoShimmer is not 32 bit compatible
RDEPENDS_packagegroup-honeycomb-iota_remove = "${@bb.utils.contains('MACHINE', 'stm32mp1-disco', '', 'goshimmer goshimmerctl', d)}"
RDEPENDS_packagegroup-honeycomb-iota_remove = "${@bb.utils.contains('MACHINE', 'qemuarm', '', 'goshimmer goshimmerctl', d)}"
