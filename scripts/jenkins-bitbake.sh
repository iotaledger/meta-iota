#!/usr/bin/env bash

cd ${HOME}/yocto
source poky/oe-init-build-env build-$1
cp ${HOME}/yocto/meta-iota/templates/bblayers.conf.sample conf/bblayers.conf
cp ${HOME}/yocto/meta-iota/templates/local.conf.sample conf/local.conf

# wait until there's no bitbake workers running
while [ -a ${HOME}/yocto/build-$1/bitbake.lock ]
do
    sleep 10
    echo "waiting for other BitBake job to finish..."
done

MACHINE=$1 bitbake $2
