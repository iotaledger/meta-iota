DESCRIPTION = "A Sato honeycombOS image"
LICENSE = "MIT"

require recipes-sato/images/core-image-sato.bb
require recipes-core/images/honeycomb-image-base.bb

IMAGE_INSTALL_append += "\
                          packagegroup-honeycomb-graphics \
"
