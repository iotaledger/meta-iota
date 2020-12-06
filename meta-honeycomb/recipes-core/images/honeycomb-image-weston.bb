DESCRIPTION = "A Weston honeycombOS image"
LICENSE = "MIT"

require recipes-graphics/images/core-image-weston.bb
require recipes-core/images/honeycomb-image-base.bb

IMAGE_INSTALL_append += "\
                          packagegroup-honeycomb-graphics\
"