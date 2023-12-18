#
# Copyright (C) 2012-2013 Wind River Systems, Inc.
#
DESCRIPTION = "A basic initramfs image that boots to a console."

LICENSE = "MIT"

IMAGE_FSTYPES = "${INITRAMFS_FSTYPES}"

inherit wrlinux-image

IMAGE_INSTALL_INITRAMFS += "packagegroup-core-boot-wrs shadow \
                            ${@bb.utils.contains("DISTRO_FEATURES", "iscsi-boot", "initramfs-iscsi-boot", "", d)}"
IMAGE_LINGUAS = ""

QB_DEFAULT_FSTYPE = "cpio.gz"

export IMAGE_BASENAME = "wrlinux-image-initramfs"

# Use PACKAGE_INSTALL to only install specific packages
PACKAGE_INSTALL = "${IMAGE_INSTALL_INITRAMFS}"

USE_DEVFS = "0"
