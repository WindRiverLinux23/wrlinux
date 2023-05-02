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
SRCREV_machine:kb-v6.1-base ?= "ca1c9012c941ab1520851938d5f695f5a4d23634"
LINUX_VERSION:kb-v6.1-base = "6.1.26"
SRCREV_machine:kb-v6.1-standard-arm-versatile-926ejs ?= "171d448bfb9e531c7395deae260edf96305eab9c"
LINUX_VERSION:kb-v6.1-standard-arm-versatile-926ejs = "6.1.26"
SRCREV_machine:kb-v6.1-standard-base ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-base = "6.1.26"
SRCREV_machine:kb-v6.1-standard-bcm-2xxx-rpi ?= "3a3b847059749e7f7ef66a574ccec2e84f2485a9"
LINUX_VERSION:kb-v6.1-standard-bcm-2xxx-rpi = "6.1.26"
SRCREV_machine:kb-v6.1-standard-beaglebone ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-beaglebone = "6.1.26"
SRCREV_machine:kb-v6.1-standard-edgerouter ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-edgerouter = "6.1.26"
SRCREV_machine:kb-v6.1-standard-fsl-mpc8315e-rdb ?= "35433e9554ac973a88733a2dc414c0b7e0063116"
LINUX_VERSION:kb-v6.1-standard-fsl-mpc8315e-rdb = "6.1.26"
SRCREV_machine:kb-v6.1-standard-mti-malta32 ?= "d637594e7e9c9037d7c609f9dfeef13a57a5aec4"
LINUX_VERSION:kb-v6.1-standard-mti-malta32 = "6.1.26"
SRCREV_machine:kb-v6.1-standard-mti-malta64 ?= "52e3ff0902681ac3d9128bcf037033e14ae20d68"
LINUX_VERSION:kb-v6.1-standard-mti-malta64 = "6.1.26"
SRCREV_machine:kb-v6.1-standard-nxp-ls20xx ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-nxp-ls20xx = "6.1.26"
SRCREV_machine:kb-v6.1-standard-nxp-sdk-6.1-nxp-soc ?= "deb2cfe9183f0d46a03bae2123211e907726d6f8"
LINUX_VERSION:kb-v6.1-standard-nxp-sdk-6.1-nxp-soc = "6.1.26"
SRCREV_machine:kb-v6.1-standard-preempt-rt-arm-versatile-926ejs ?= "816c0130cf6f3e517c37a758c257295e62d6f9cb"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-arm-versatile-926ejs = "6.1.26"
SRCREV_machine:kb-v6.1-standard-preempt-rt-base ?= "128a73d5e1339475618b41383121a0eef4bb29de"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-base = "6.1.26"
SRCREV_machine:kb-v6.1-standard-preempt-rt-bcm-2xxx-rpi ?= "7b06f28b01a03af082a95ff51890a31332f39ee2"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-bcm-2xxx-rpi = "6.1.26"
SRCREV_machine:kb-v6.1-standard-preempt-rt-nxp-sdk-6.1-nxp-soc ?= "9b6b861b049105b5bc1efddd71d9ad6c957cbdeb"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-nxp-sdk-6.1-nxp-soc = "6.1.26"
SRCREV_machine:kb-v6.1-standard-preempt-rt-x86 ?= "b46ea8f928087b052cec43cb6c2c4fe5586d09d9"
LINUX_VERSION:kb-v6.1-standard-preempt-rt-x86 = "6.1.26"
SRCREV_machine:kb-v6.1-standard-qemuarm64 ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-qemuarm64 = "6.1.26"
SRCREV_machine:kb-v6.1-standard-qemuppc ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-qemuppc = "6.1.26"
SRCREV_machine:kb-v6.1-standard-ti-am335x ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-ti-am335x = "6.1.26"
SRCREV_machine:kb-v6.1-standard-tiny-arm-versatile-926ejs ?= "65ada2d3b29a4d0ee61fb5156db15d74a2f784d3"
LINUX_VERSION:kb-v6.1-standard-tiny-arm-versatile-926ejs = "6.1.26"
SRCREV_machine:kb-v6.1-standard-tiny-base ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-tiny-base = "6.1.26"
SRCREV_machine:kb-v6.1-standard-tiny-common-pc ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-tiny-common-pc = "6.1.26"
SRCREV_machine:kb-v6.1-standard-tiny-x86 ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-tiny-x86 = "6.1.26"
SRCREV_machine:kb-v6.1-standard-x86 ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-x86 = "6.1.26"
SRCREV_machine:kb-v6.1-standard-xilinx-zynqmp ?= "c35e45ea5f134aad3ef0ccd3f1b7b672c801e402"
LINUX_VERSION:kb-v6.1-standard-xilinx-zynqmp = "6.1.26"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.1 = "yocto-6.1"
SRCREV_meta_6.1 = "224a8fb482cdd1cd0d6ab14ec91eea4eac827bfe"
