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
SRCREV_machine:kb-v6.1-base ?= "ca48fc16c49388400eddd6c6614593ebf7c7726a"
LINUX_VERSION:kb-v6.1-base = "6.1.27"
SRCREV_machine:kb-v6.1-standard-arm-versatile-926ejs ?= "df2cfcb92e63bdbdd34667d5915a71b1441ec723"
LINUX_VERSION:kb-v6.1-standard-arm-versatile-926ejs = "6.1.27"
SRCREV_machine:kb-v6.1-standard-base ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-base = "6.1.27"
SRCREV_machine:kb-v6.1-standard-bcm-2xxx-rpi ?= "37378fa10699a30cec4001648999ff20fd109233"
LINUX_VERSION:kb-v6.1-standard-bcm-2xxx-rpi = "6.1.27"
SRCREV_machine:kb-v6.1-standard-beaglebone ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-beaglebone = "6.1.27"
SRCREV_machine:kb-v6.1-standard-edgerouter ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-edgerouter = "6.1.27"
SRCREV_machine:kb-v6.1-standard-fsl-mpc8315e-rdb ?= "003c9561a3e1260cc707f47e7e185cd9c255fbbf"
LINUX_VERSION:kb-v6.1-standard-fsl-mpc8315e-rdb = "6.1.27"
SRCREV_machine:kb-v6.1-standard-mti-malta32 ?= "9cf687bf5869c57781cb399038d455351e4517e9"
LINUX_VERSION:kb-v6.1-standard-mti-malta32 = "6.1.27"
SRCREV_machine:kb-v6.1-standard-mti-malta64 ?= "6e551dbbbc3d447255314706f089a45670063901"
LINUX_VERSION:kb-v6.1-standard-mti-malta64 = "6.1.27"
SRCREV_machine:kb-v6.1-standard-nxp-ls20xx ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-nxp-ls20xx = "6.1.27"
SRCREV_machine:kb-v6.1-standard-nxp-sdk-6.1-nxp-soc ?= "35c7fe1e9556b421c8842037632386bce3cbd718"
LINUX_VERSION:kb-v6.1-standard-nxp-sdk-6.1-nxp-soc = "6.1.27"
SRCREV_machine:kb-v6.1-standard-preempt-rt-arm-versatile-926ejs ?= "939bede836ea53698fbe161bb6c1a6d26c1b275d"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-arm-versatile-926ejs = "6.1.27"
SRCREV_machine:kb-v6.1-standard-preempt-rt-base ?= "573386d3cb8c102496deecf92ca867ff9d044ae1"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-base = "6.1.27"
SRCREV_machine:kb-v6.1-standard-preempt-rt-bcm-2xxx-rpi ?= "cae9cacf1672ea151fb92cd9c3e0203fdc890148"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-bcm-2xxx-rpi = "6.1.27"
SRCREV_machine:kb-v6.1-standard-preempt-rt-nxp-sdk-6.1-nxp-soc ?= "80e1e893f84c5e570f489798b32bbccf36600bb3"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-nxp-sdk-6.1-nxp-soc = "6.1.27"
SRCREV_machine:kb-v6.1-standard-preempt-rt-x86 ?= "aa72ed45e1425372084dd647d3380b2d7250a344"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-x86 = "6.1.27"
SRCREV_machine:kb-v6.1-standard-qemuarm64 ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-qemuarm64 = "6.1.27"
SRCREV_machine:kb-v6.1-standard-qemuppc ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-qemuppc = "6.1.27"
SRCREV_machine:kb-v6.1-standard-sdkv6.1-xlnx-soc ?= "78d74cba4afb289dcd481e4ec75dfab8e859ab2b"
LINUX_VERSION:kb-v6.1-standard-sdkv6.1-xlnx-soc = "6.1.27"
SRCREV_machine:kb-v6.1-standard-ti-am335x ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-ti-am335x = "6.1.27"
SRCREV_machine:kb-v6.1-standard-tiny-arm-versatile-926ejs ?= "b9ba2fd01df245662e67fcee75ad4889feea5a6d"
LINUX_VERSION:kb-v6.1-standard-tiny-arm-versatile-926ejs = "6.1.27"
SRCREV_machine:kb-v6.1-standard-tiny-base ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-tiny-base = "6.1.27"
SRCREV_machine:kb-v6.1-standard-tiny-common-pc ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-tiny-common-pc = "6.1.27"
SRCREV_machine:kb-v6.1-standard-tiny-x86 ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-tiny-x86 = "6.1.27"
SRCREV_machine:kb-v6.1-standard-x86 ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-x86 = "6.1.27"
SRCREV_machine:kb-v6.1-standard-xilinx-zynqmp ?= "5595b9b98df96b1ef27dc5879d19b9b512cc5c14"
LINUX_VERSION:kb-v6.1-standard-xilinx-zynqmp = "6.1.27"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.1 = "yocto-6.1"
SRCREV_meta_6.1 = "9dfa5e697b9cefa78c1396291dddd126869f6016"
