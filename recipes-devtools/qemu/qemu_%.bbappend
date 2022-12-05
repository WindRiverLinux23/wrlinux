#
# Copyright (C) 2022 Wind River Systems, Inc.
#

FILESEXTRAPATHS:append := ":${THISDIR}/files"

# carry over cpu affinity command line option patches
SRC_URI += " \
        file://0001-qemu-kvm-Add-options-to-pin-and-prioritize-vcpus.patch \
        file://0001-qemu-vcpu-avoid-using-ifdef-CONFIG_KVM-in-common-cod.patch \
"
