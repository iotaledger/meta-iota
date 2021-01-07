DESCRIPTION = "A minimal honeycombOS image"
LICENSE = "MIT"

require recipes-core/images/core-image-minimal.bb

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
