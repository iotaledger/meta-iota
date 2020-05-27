require ${PN}_0.4.0.inc

inherit systemd

RDEPENDS_${PN} += " systemd"

SRC_URI += " \
           file://hornet.service \
           file://hornet.env \
"

FILES_${PN} += " hornet.service"
CONFFILES_${PN} += " ${localstatedir}/lib/hornet/config.json \
                     ${localstatedir}/lib/hornet/peering.json \
                     ${localstatedir}/lib/hornet/mqtt_config.json \
                     ${localstatedir}/lib/hornet/config_comnet.json \
                     ${localstatedir}/lib/hornet/profiles.json \
                     ${sysconfdir}/default/hornet \
"

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = "hornet.service"
SYSTEMD_AUTO_ENABLE = "disable"

# avoid cache disabling
export GOCACHE = "${B}/.cache"

do_compile_prepend(){

    # fix sha3 import error: https://stackoverflow.com/questions/48635662/code-in-directory-expects-import
    sed -i '$ d' src/github.com/iotaledger/iota.go/kerl/sha3/doc.go
    echo "package sha3" >> src/github.com/iotaledger/iota.go/kerl/sha3/doc.go

    # rm tests
    rm -rf src/github.com/gohornet/hornet/pkg/model/coordinator/test
}

do_install_append(){

    # create systemd directory
    install -m 0755 -d ${D}${systemd_system_unitdir}

    # create /var/lib/hornet
    install -m 0755 -d ${D}${localstatedir}/lib/hornet

    # populate .json files
    install -m 0644 ${WORKDIR}/${PN}-${PV}/src/github.com/gohornet/hornet/config.json ${D}${localstatedir}/lib/hornet
    install -m 0644 ${WORKDIR}/${PN}-${PV}/src/github.com/gohornet/hornet/mqtt_config.json ${D}${localstatedir}/lib/hornet
    install -m 0644 ${WORKDIR}/${PN}-${PV}/src/github.com/gohornet/hornet/config_comnet.json ${D}${localstatedir}/lib/hornet
    install -m 0644 ${WORKDIR}/${PN}-${PV}/src/github.com/gohornet/hornet/peering.json ${D}${localstatedir}/lib/hornet
    install -m 0644 ${WORKDIR}/${PN}-${PV}/src/github.com/gohornet/hornet/profiles.json ${D}${localstatedir}/lib/hornet


    # populate systemd service file
    install -m 0755 ${WORKDIR}/hornet.service ${D}${systemd_system_unitdir}

    # populate environment file
    install -m 0755 -d ${D}${sysconfdir}/default
    install -m 0755 ${WORKDIR}/hornet.env ${D}${sysconfdir}/default/hornet
}

pkg_postinst_ontarget_${PN}(){
OPTS=""

if [ -n "$D" ]; then
    OPTS="--root=$D"
fi

if type systemctl >/dev/null 2>/dev/null; then
	if [ -z "$D" ]; then
		systemctl daemon-reload
	fi

	# if hornet user doesn't exist, create it
	if [ ! $(getent passwd hornet) ]; then
		useradd --no-create-home --system hornet > /dev/null
	fi

	chown -R hornet:hornet /var/lib/hornet

	systemctl $OPTS disable hornet.service

	if [ -z "$D" -a "disable" = "enable" ]; then
		systemctl --no-block restart hornet.service
	fi
fi
}

pkg_postrm_${PN}(){
OPTS=""

if [ -n "$D" ]; then
    OPTS="--root=$D"
fi

systemctl --system daemon-reload >/dev/null || true

case "$1" in
remove)
    rm -rf /var/lib/hornet/*
    ;;
purge)
    rm -rf /var/lib/hornet
    deluser hornet >/dev/null
    ;;
upgrade | failed-upgrade | abort-install | abort-upgrade | disappear) ;;

*)
    echo "postrm called with unknown argument \`$1'" >&2
    exit 1
    ;;
esac
}
