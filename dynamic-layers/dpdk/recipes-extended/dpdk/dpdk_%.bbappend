COMPATIBLE_MACHINE:qemux86 = "${MACHINE}"
COMPATIBLE_MACHINE:qemux86-64 = "${MACHINE}"

DPDK_TARGET_MACHINE:qemux86 = "corei7"
DPDK_TARGET_MACHINE:qemux86-64 = "corei7"

DPDK_EXTRA_CFLAGS:append:qemux86 = " -march=corei7"
DPDK_EXTRA_CFLAGS:append:qemux86-64 = " -march=corei7"
