SUMMARY = "honeycomb Package Group"

inherit packagegroup

PROVIDES = "${PACKAGES}"
PACKAGES = " \
             packagegroup-honeycomb-misc \
             packagegroup-honeycomb-networking \
             packagegroup-honeycomb-development \
             packagegroup-honeycomb-iota \
             packagegroup-honeycomb-cockpit \
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
                                        python \
                                        python-dev \
                                        python-pip \
                                        python-setuptools \
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

RDEPENDS_packagegroup-honeycomb-cockpit = " \
                                            cockpit \
                                            cockpit-ws \
                                            cockpit-system \
                                            cockpit-dashboard \
                                            cockpit-bridge \
                                            cockpit-pcp \
                                            honeycomb-cockpit-plugins \
"
