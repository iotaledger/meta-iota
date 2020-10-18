SRC_URI += "file://honeycomb"

do_image_append() {
    # install honeycombOS logo
    install -d ${D}${datadir}/cockpit/branding
    cp -r ${WORKDIR}/honeycomb ${D}${datadir}/cockpit/branding
}
