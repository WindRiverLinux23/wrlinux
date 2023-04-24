#
# This file is generated based on:
#     linux-yocto-6.1
#     yocto-kernel-cache
#
# Any manual changes will be overwritten.
#
# This will cause SRCREV_machine:kb-<KBRANCH> take priority over SRCREV_machine:<machine>
MACHINEOVERRIDES .= ":kb-${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel', 'linux-yocto-dev', 'dev-', '', d)}${@d.getVar('KBRANCH', True).replace("/", "-")}"

# linux-yocto-6.1 entries

# linux-yocto-6.1 branch entries
SRCREV_machine:kb-master ?= "f17b0ab65d17988d5e6d6fe22f708ef3721080bf"
LINUX_VERSION:kb-master = "6.1.25"
SRCREV_machine:kb-v6.1-base ?= "f17b0ab65d17988d5e6d6fe22f708ef3721080bf"
LINUX_VERSION:kb-v6.1-base = "6.1.25"
SRCREV_machine:kb-v6.1-standard-arm-versatile-926ejs ?= "0b80e90b38ae1735c7dab701ca3d0b2447376ccc"
LINUX_VERSION:kb-v6.1-standard-arm-versatile-926ejs = "6.1.25"
SRCREV_machine:kb-v6.1-standard-base ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-base = "6.1.25"
SRCREV_machine:kb-v6.1-standard-bcm-2xxx-rpi ?= "97092042b62c251d20a8369bbebd10eee167df33"
LINUX_VERSION:kb-v6.1-standard-bcm-2xxx-rpi = "6.1.25"
SRCREV_machine:kb-v6.1-standard-beaglebone ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-beaglebone = "6.1.25"
SRCREV_machine:kb-v6.1-standard-edgerouter ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-edgerouter = "6.1.25"
SRCREV_machine:kb-v6.1-standard-fsl-mpc8315e-rdb ?= "8291aeb5815229bdb86d72b4ee4b34241a35fc4e"
LINUX_VERSION:kb-v6.1-standard-fsl-mpc8315e-rdb = "6.1.25"
SRCREV_machine:kb-v6.1-standard-mti-malta32 ?= "db61d7fe3540904fbe77b532ce3e37aeb737524a"
LINUX_VERSION:kb-v6.1-standard-mti-malta32 = "6.1.25"
SRCREV_machine:kb-v6.1-standard-mti-malta64 ?= "aacc52b6216955723cebb5bc493a4210357b23b2"
LINUX_VERSION:kb-v6.1-standard-mti-malta64 = "6.1.25"
SRCREV_machine:kb-v6.1-standard-nxp-ls20xx ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-nxp-ls20xx = "6.1.25"
SRCREV_machine:kb-v6.1-standard-nxp-sdk-6.1-nxp-soc ?= "05a1e28fa2d335ed038cc5ddd35762bf32c8ccd3"
LINUX_VERSION:kb-v6.1-standard-nxp-sdk-6.1-nxp-soc = "6.1.25"
SRCREV_machine:kb-v6.1-standard-preempt-rt-arm-versatile-926ejs ?= "1428361a8aecf7bc798ecb0677dad4bcc029e394"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-arm-versatile-926ejs = "6.1.25"
SRCREV_machine:kb-v6.1-standard-preempt-rt-base ?= "f974a72071f8b481fc4e38517219bc5c503e14f6"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-base = "6.1.25"
SRCREV_machine:kb-v6.1-standard-preempt-rt-bcm-2xxx-rpi ?= "70a5914e040e95a7fd4354549ac1a2646a6a0bb1"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-bcm-2xxx-rpi = "6.1.25"
SRCREV_machine:kb-v6.1-standard-preempt-rt-nxp-sdk-6.1-nxp-soc ?= "878db9a00635ad9ebf24fe32f71ce52ab2f38a60"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-nxp-sdk-6.1-nxp-soc = "6.1.25"
SRCREV_machine:kb-v6.1-standard-preempt-rt-x86 ?= "be8daf393a5dbae42151d94b7428e59803538745"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-x86 = "6.1.25"
SRCREV_machine:kb-v6.1-standard-qemuarm64 ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-qemuarm64 = "6.1.25"
SRCREV_machine:kb-v6.1-standard-qemuppc ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-qemuppc = "6.1.25"
SRCREV_machine:kb-v6.1-standard-ti-am335x ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-ti-am335x = "6.1.25"
SRCREV_machine:kb-v6.1-standard-tiny-arm-versatile-926ejs ?= "378637bfb89658e68f8c0219d4c0df54f33ff48e"
LINUX_VERSION:kb-v6.1-standard-tiny-arm-versatile-926ejs = "6.1.25"
SRCREV_machine:kb-v6.1-standard-tiny-base ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-tiny-base = "6.1.25"
SRCREV_machine:kb-v6.1-standard-tiny-common-pc ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-tiny-common-pc = "6.1.25"
SRCREV_machine:kb-v6.1-standard-tiny-x86 ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-tiny-x86 = "6.1.25"
SRCREV_machine:kb-v6.1-standard-x86 ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-x86 = "6.1.25"
SRCREV_machine:kb-v6.1-standard-xilinx-zynqmp ?= "581dc1aa2f340fff2cc010067257185fa2c993f9"
LINUX_VERSION:kb-v6.1-standard-xilinx-zynqmp = "6.1.25"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.1 = "yocto-6.1"
SRCREV_meta_6.1 = "36901b5b298e601fe73dd79aaff8b615a7762013"
