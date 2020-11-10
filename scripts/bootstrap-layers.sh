#!/usr/bin/env bash

# Copyright (c) 2020 IOTA Stiftung
# https://github.com/iotaledger/meta-iota

# Refer to the LICENSE file for licensing information

mkdir -p ${HOME}/yocto
cd ${HOME}/yocto

BRANCH=dunfell

if [ ! -d meta-iota ]
then
	git clone https://github.com/iotaledger/meta-iota.git
fi

if [ ! -d poky ]
then
	git clone https://git.yoctoproject.org/git/poky.git -b $BRANCH
fi

if [ ! -d meta-openembedded ]
then
	git clone https://github.com/openembedded/meta-openembedded.git -b $BRANCH
fi

if [ ! -d meta-raspberrypi ]
then
	git clone https://git.yoctoproject.org/git/meta-raspberrypi.git -b $BRANCH
fi

if [ ! -d meta-st-stm32mp ]
then
	git clone https://github.com/STMicroelectronics/meta-st-stm32mp.git -b $BRANCH
fi

if [ ! -d meta-rock64 ]
then
	git clone https://github.com/bernardoaraujor/meta-rock64.git
fi
