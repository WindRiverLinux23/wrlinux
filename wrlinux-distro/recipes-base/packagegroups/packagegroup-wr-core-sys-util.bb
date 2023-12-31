#
# Copyright (C) 2012-2013 Wind River Systems Inc.
#
# This package matches a FEATURE_PACKAGES_packagegroup-wr-core-sys-util definition in
# wrlinux-image.bbclass that may be used to customize an image by
# adding "wr-core-sys-util" to IMAGE_FEATURES.
#

DESCRIPTION = "Wind River Linux core package group: sys-util"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

PR = "r4"

ALLOW_EMPTY:${PN} = "1"

STRACE = "strace"
STRACE:riscv32 = ""

RDEPENDS:${PN} = " \
    util-linux-fsck \
    e2fsprogs-e2fsck \
    e2fsprogs-mke2fs \
    elfutils \
    hdparm \
    iproute2 \
    iptables \
    iputils \
    iw \
    ldd \
    lsof \
    lvm2 \
    mdadm \
    mtd-utils \
    ${@bb.utils.contains('DISTRO_FEATURES', 'pam', 'pam-plugin-wheel', '', d)} \
    quota \
    sdparm \
    setserial \
    ${STRACE} \
    usbutils \
    watchdog \
    wireless-regdb-static \
    ${@bb.utils.contains('INCOMPATIBLE_LICENSE', 'GPL-3.0-or-later', '', 'parted', d)} \
    "
RRECOMMENDS:${PN} = " \
    mtd-utils-jffs2 \
    mtd-utils-ubifs \
    mtd-utils-misc \
    "

RDEPENDS:${PN}:append:x86 = " pmtools iasl"
RDEPENDS:${PN}:append:x86-64 = " pmtools iasl"
