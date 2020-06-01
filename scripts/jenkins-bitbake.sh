#!/usr/bin/env bash

cd ${HOME}/yocto
source poky/oe-init-build-env build
cp ${HOME}/yocto/meta-iota/templates/bblayers.conf.sample conf/bblayers.conf
cp ${HOME}/yocto/meta-iota/templates/local.conf.sample conf/local.conf
MACHINE=$1 bitbake $2
