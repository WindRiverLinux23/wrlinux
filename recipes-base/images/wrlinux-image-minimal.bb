#
# Copyright (C) 2020 - 2021 Wind River Systems, Inc.
#
DESCRIPTION = "A busybox based minimal image that boots to a console."

require wrlinux-bin-image.inc

TARGET_CORE_BOOT ?= " \
    packagegroup-core-boot \
    dhcpcd \
    kernel-module-fuse \
    kernel-module-sch-fq-codel \
    glib-networking \
    systemd-extra-utils \
"

# Control the installed packages strictly
WRTEMPLATE_IMAGE = "0"

IMAGE_INSTALL = "\
    ${@bb.utils.contains('IMAGE_ENABLE_CONTAINER', '1', '${CONTAINER_CORE_BOOT}', '${TARGET_CORE_BOOT}', d)} \
    busybox \
    busybox-syslog \
    openssh \
    ca-certificates \
"

# Full Disk Encrypt
IMAGE_INSTALL:append:intel-x86 = " packagegroup-luks"

# - No packagegroup-core-base-utils which corresponds to busybox
#   function since it is busybox based.
# - The ostree are not needed for container image.
IMAGE_INSTALL:remove = "\
    packagegroup-core-base-utils \
"

# For ostree
IMAGE_INSTALL:append = " ${@bb.utils.contains('OSTREE_BOOTLOADER', 'u-boot', 'u-boot-uenv', '', d)}"

# For nxp-s32g
IMAGE_INSTALL:append:nxp-s32g = " u-boot-s32 atf-s32g"
IMAGE_INSTALL:append:ti-j72xx = " u-boot-ti-staging"

NO_RECOMMENDATIONS = "1"

# Remove debug-tweaks and x11-base
IMAGE_FEATURES:remove = "debug-tweaks x11-base"

# Enable dhcpcd service if NetworkManager is not installed.
ROOTFS_POSTPROCESS_COMMAND += "enable_dhcpcd_service; "
enable_dhcpcd_service() {
    if [ ! -e ${IMAGE_ROOTFS}${sbindir}/NetworkManager \
        -a -f ${IMAGE_ROOTFS}${systemd_unitdir}/system/dhcpcd.service ]; then
        ln -sf ${systemd_unitdir}/system/dhcpcd.service \
            ${IMAGE_ROOTFS}${sysconfdir}/systemd/system/multi-user.target.wants/dhcpcd.service
    fi
}
