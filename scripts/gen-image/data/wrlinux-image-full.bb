#
# Copyright (C) 2020 Wind River Systems, Inc.
#
DESCRIPTION = "A full functional image that boots to a console."

LICENSE = "MIT"

CONTAINER_CORE_BOOT ?= " \
    base-files \
    base-passwd \
    ${VIRTUAL-RUNTIME_update-alternatives} \
"

IMAGE_INSTALL = "\
    ${@bb.utils.contains('IMAGE_ENABLE_CONTAINER', '1', '${CONTAINER_CORE_BOOT}', 'packagegroup-core-boot kernel-modules', d)} \
    openssh \
    ca-certificates \
    "

# - The ostree are not needed for container image.
# - No docker or k8s by default
IMAGE_INSTALL_remove = "\
    ${@bb.utils.contains('IMAGE_ENABLE_CONTAINER', '1', 'ostree ostree-upgrade-mgr', '', d)} \
    kubernetes \
    docker \
    virtual/containerd \
    python3-docker-compose \
"

# Only need tar.bz2 for container image
IMAGE_FSTYPES_remove = " \
    ${@bb.utils.contains('IMAGE_ENABLE_CONTAINER', '1', 'live wic wic.bmap ostreepush otaimg', '', d)} \
"

# No recomendations for container image
NO_RECOMMENDATIONS = "${@bb.utils.contains('IMAGE_ENABLE_CONTAINER', '1', '1', '0', d)}"

# No bsp packages for container
python () {
    if bb.utils.to_boolean(d.getVar('IMAGE_ENABLE_CONTAINER')):
        d.setVar('WRTEMPLATE_CONF_WRIMAGE_MACH', 'wrlnoimage_mach.inc')
    else:
        d.appendVar('IMAGE_FEATURES', ' wr-bsps')
}

IMAGE_FEATURES += "package-management"

inherit wrlinux-image
