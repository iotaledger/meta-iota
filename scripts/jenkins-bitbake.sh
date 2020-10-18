#!/usr/bin/env bash

# Copyright (c) 2020 IOTA Stiftung
# https://github.com/iotaledger/meta-iota

#Refer to the LICENSE file for licensing information

cd ${HOME}/yocto
source poky/oe-init-build-env build-$1
cp ${HOME}/yocto/meta-iota/templates/bblayers.conf.sample conf/bblayers.conf
cp ${HOME}/yocto/meta-iota/templates/local.conf.sample conf/local.conf

cat << EOF >> conf/local.conf
MACHINE ??= "$1"
EOF

# wait until there's no bitbake workers running
while [ -a ${HOME}/yocto/build-$1/bitbake.lock ]
do
    sleep 10
    echo "waiting for other BitBake job to finish..."
done

bitbake $2
