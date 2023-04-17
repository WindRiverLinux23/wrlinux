require linux-yocto-wrlinux.inc
include srcrev.inc
require linux-yocto-extra-kernel-src.inc

TARGET_SUPPORTED_KTYPES:append:qemuall = " preempt-rt"

KERNEL_VERSION_SANITY_SKIP ?= "1"

FILESEXTRAPATHS:prepend:osv-wrlinux := "${THISDIR}/linux-yocto-rt:"
SRC_URI:append:osv-wrlinux = " \
    file://0001-Revert-mm-memcg-Only-perform-the-debug-checks-on-PRE.patch \
"
