DESCRIPTION = "A headless HoneyComb image"
LICENSE = "MIT"

require recipes-core/images/core-image-base.bb

IMAGE_FEATURES += " \
                   tools-debug \
                   tools-sdk \
                   ssh-server-openssh \
                   package-management \
                   doc-pkgs \
"

IMAGE_INSTALL_append += "\
                          packagegroup-honeycomb-misc \
                          packagegroup-honeycomb-networking \
                          packagegroup-honeycomb-development \
                          packagegroup-honeycomb-iota \
"

IMAGE_ROOTFS_MAXSIZE_stm32mp1-disco = "3000000"