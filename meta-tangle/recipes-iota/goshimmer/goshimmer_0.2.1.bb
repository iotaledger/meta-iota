require ${PN}_${PV}.inc

inherit systemd

SRC_URI += " \
             file://goshimmer.service \
"

FILES_${PN} += " goshimmer.service"

CONFFILES_${PN} = "${localstatedir}/lib/goshimmer/config.json"

SYSTEMD_PACKAGES = "${PN}"
SYSTEMD_SERVICE_${PN} = "goshimmer.service"
SYSTEMD_AUTO_ENABLE = "disable"

# avoid tests
PTEST_ENABLED="0"

# avoid cache disabling
export GOCACHE = "${B}/.cache"

do_compile_prepend(){

    # avoid tests
    rm -rf ${S}/src/github.com/iotaledger/goshimmer/tools/integration-tests/
    rm -rf ${S}/src/github.com/iotaledger/goshimmer/dapps/valuetransfers/packages/test
    rm -rf ${S}/src/github.com/iotaledger/goshimmer/packages/binary/messagelayer/test

    # not using docker
    rm -rf ${S}/src/github.com/iotaledger/goshimmer/tools/docker-network

}

do_install_append(){

    # create goshimmer directory in /var/lib
    install -m 0755 -d ${D}${localstatedir}/lib/goshimmer

    # populate config.json
    install -m 0644 ${WORKDIR}/${PN}-${PV}/src/github.com/iotaledger/goshimmer/config.default.json ${D}${localstatedir}/lib/goshimmer/config.json

    # create systemd directory
    install -m 0755 -d ${D}${systemd_system_unitdir}

    # populate systemd service file
    install -m 0755 ${WORKDIR}/goshimmer.service ${D}${systemd_system_unitdir}
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

	# if goshimmer user doesn't exist, create it
	if [ ! $(getent passwd goshimmer) ]; then
		useradd --no-create-home --system goshimmer > /dev/null
	fi

	chown -R goshimmer:goshimmer /var/lib/goshimmer

	systemctl $OPTS disable goshimmer.service

	if [ -z "$D" -a "disable" = "enable" ]; then
		systemctl --no-block restart goshimmer.service
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
    rm -rf /var/lib/goshimmer/*
    rm -rf /etc/goshimmer/*
    ;;
purge)
    rm -rf /var/lib/goshimmer
    ;;
upgrade | failed-upgrade | abort-install | abort-upgrade | disappear) ;;

*)
    echo "postrm called with unknown argument \`$1'" >&2
    exit 1
    ;;
esac
}
