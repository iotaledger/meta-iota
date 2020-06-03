#!/usr/bin/env bash

# Copyright (c) 2020 IOTA Stiftung
# https://github.com/iotaledger/meta-iota

# Refer to the LICENSE file for licensing information

mkdir -p ${HOME}/yocto
cd ${HOME}/yocto

BRANCH=warrior

git clone https://github.com/iotaledger/meta-iota.git
git clone https://git.yoctoproject.org/git/poky.git -b $BRANCH
git clone https://github.com/openembedded/meta-openembedded.git -b $BRANCH
git clone https://git.yoctoproject.org/git/meta-raspberrypi.git -b $BRANCH
git clone https://github.com/STMicroelectronics/meta-st-stm32mp.git -b $BRANCH
git clone https://github.com/bernardoaraujor/meta-rock64.git
