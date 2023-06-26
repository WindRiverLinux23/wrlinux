def get_qemu_rpms(d):
    targetarch = "${@'i386' if d.getVar('TARGET_ARCH') in ['x86', 'i486', 'i586', 'i686'] else d.getVar('TARGET_ARCH').replace('_', '-')}"
    return 'nativesdk-qemu-system-' + targetarch + ' ' + 'nativesdk-qemu-user-' + targetarch

RDEPENDS:${PN} += "\
    nativesdk-mtools \
    nativesdk-syslinux \
    nativesdk-rpm-build \
    ${@get_qemu_rpms(d)} \
    "
