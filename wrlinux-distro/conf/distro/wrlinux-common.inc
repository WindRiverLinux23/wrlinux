#
# Copyright (C) 2012 - 2019 Wind River Systems, Inc.
#
# information common to all wrlinux distros
#

# Provide a way to override default machine behavior for all WRLinux distros
# We need this to add multilib support to the built-in QEMU BSPs
include conf/distro/include/wrlinux-bsp-${MACHINE}.inc

# PACKAGECONFIG settings for WRLinux
include conf/distro/include/wrlinux-packageconfigs.inc

MAINTAINER = "Wind River <info@windriver.com>"

WRLINUX_VARIANT ??= ""
DISTRO_NAME ?= "${WRLINUX_BRANDING}${WRLINUX_VARIANT} ${WRLINUX_BRANCH}"

DISTRO_VERSION ?= "${WRLINUX_VERSION}"
SDK_VERSION ?= "${WRLINUX_PRODUCT_VERSION}"
DISTRO_PRETTY_VERSION ?= "${WRLINUX_PRODUCT_VERSION}${@' Update ${WRLINUX_UPDATE_VERSION}' if d.getVar('WRLINUX_UPDATE_VERSION') != '0' else ''}"

SDK_VENDOR = "-wrlinuxsdk"
TARGET_VENDOR = "-wrs"

# Append 'osv-wrlinux' to the DISTROOVERRIDE
DISTROOVERRIDES:append = "${@['', ':'][(d.getVar('DISTRO', True) != '')]}osv-wrlinux"

LOCALCONF_VERSION = "2"

SDK_NAME = "${DISTRO}-${TCLIBC}-${SDK_ARCH}-${TARGET_ARCH}"
SDK_PS1 ??= "(wrlinuxsdk-${SDK_ARCH}-${TARGET_ARCH}) \${PS1#(wrlinuxsdk-${SDK_ARCH}-${TARGET_ARCH}) }"
SDKPATHINSTALL = "/opt/windriver/${DISTRO}/${SDK_VERSION}"
TCSDKMACH = "${@['', '_${SDK_OS}']['${SDK_OS}' != 'linux']}"
TOOLCHAIN_OUTPUTNAME = "${DISTRO}-${DISTRO_VERSION}-${TCLIBC}-${SDK_ARCH}${TCSDKMACH}-${MACHINE_ARCH}-${PN}-sdk"
TOOLCHAINEXT_OUTPUTNAME = "${DISTRO}-${DISTRO_VERSION}-${TCLIBC}-${SDK_ARCH}${TCSDKMACH}-${MACHINE_ARCH}-${PN}-sdk-ext"

TOOLCHAIN_OUTPUTNAME:pn-buildtools-tarball:forcevariable = "${SDK_ARCH}-buildtools-nativesdk-standalone-${DISTRO_VERSION}"

# Workaround for extensible SDK
TOOLCHAIN_OUTPUTNAME:pn-uninative-tarball = "${SDK_ARCH}-nativesdk-libc"
ESDK_CLASS_INHERIT_DISABLE:append = " packagefeed-stability"

# Override these in wrlinux based distros to modify DISTRO_*
WRLINUX_DEFAULT_DISTRO_FEATURES = "largefile multiarch pulseaudio kvm virtualization"
WRLINUX_DEFAULT_EXTRA_RDEPENDS = "packagegroup-core-boot"
WRLINUX_DEFAULT_EXTRA_RRECOMMENDS = "kernel-module-af-packet"

DISTRO_FEATURES ?= "${DISTRO_FEATURES_DEFAULT} ${WRLINUX_DEFAULT_DISTRO_FEATURES}"
DISTRO_FEATURES:class-native ?= "${DISTRO_FEATURES_DEFAULT} ${WRLINUX_DEFAULT_DISTRO_FEATURES}"
DISTRO_FEATURES:class-nativesdk ?= "${DISTRO_FEATURES_DEFAULT} ${WRLINUX_DEFAULT_DISTRO_FEATURES}"
DISTRO_EXTRA_RDEPENDS += " ${WRLINUX_DEFAULT_EXTRA_RDEPENDS}"
DISTRO_EXTRA_RRECOMMENDS += " ${WRLINUX_DEFAULT_EXTRA_RRECOMMENDS}"

# do not include qemu-config by default
#WRLINUXQEMUDEPS = "${@bb.utils.contains("INCOMPATIBLE_LICENSE", "GPL-3.0-only", "", "qemu-config",d)}"
WRLINUXQEMUDEPS = ""

DISTRO_EXTRA_RDEPENDS:append:qemuall = " ${WRLINUXQEMUDEPS}"

#TCLIBCAPPEND = ""

#default locale / local language processing settings
IMAGE_LINGUAS ?= ""

# MIRRORS are used only if we don't have a local copy, and the stated upstream
# is no longer available.
MIRRORS =+ "\
bzr://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
cvs://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
git://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
gitsm://.*/.*    http://downloads.yoctoproject.org/mirror/sources/ \n \
hg://.*/.*       http://downloads.yoctoproject.org/mirror/sources/ \n \
osc://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
p4://.*/.*       http://downloads.yoctoproject.org/mirror/sources/ \n \
svn://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
ftp://.*/.*      http://downloads.yoctoproject.org/mirror/sources/ \n \
http://.*/.*     http://downloads.yoctoproject.org/mirror/sources/ \n \
https://.*/.*    http://downloads.yoctoproject.org/mirror/sources/ \n"

# The CONNECTIVITY_CHECK_URI's are used to test whether we can succesfully
# fetch from the network (and warn you if not). To disable the test set
# the variable to be empty.
CONNECTIVITY_CHECK_URIS ?= "https://www.example.com/"

# Default hash policy for distro
BB_SIGNATURE_HANDLER ?= 'OEBasicHash'

# Add our license to the acceptable restricted license list
LICENSE_FLAGS_ACCEPTED += "commercial_windriver"

# QA check settings - a little stricter than the OE-Core defaults
WARN_TO_ERROR_QA ?= "already-stripped compile-host-path install-host-path \
                    installed-vs-shipped ldflags pn-overrides rpaths staticdev \
                    unknown-configure-option useless-rpaths"
WARN_QA:remove = "${WARN_TO_ERROR_QA}"
ERROR_QA:append = " ${WARN_TO_ERROR_QA}"

# Allow dangling .bbappends for now
BB_DANGLINGAPPENDS_WARNONLY = "1"

# Change base package dependency in -dbg packages from recommends to suggests
RRECOMMENDS:${PN}-dbg = ""
RSUGGESTS:${PN}-dbg = "${PN} (= ${EXTENDPKGV})"

# lsb distro adjust
require conf/distro/include/wrlinux-lsb-distro-adjust.inc

# Make sure DISTRO_FEATURES backfill has pulseaudio 
# this is a temporary fix until pulseaudio is fixed

DISTRO_FEATURES_BACKFILL_CONSIDERED += "pulseaudio"

# Make sure that ldconfig is only enabled when the user has added ldconfig
# to the DISTRO_FEATURES
DISTRO_FEATURES_BACKFILL_CONSIDERED += "ldconfig"

# Make sure that X11 is only enabled in a graphics configuration
DISTRO_FEATURES_BACKFILL_CONSIDERED += "x11"

# Multilib configuration
MULTILIBS ?= ""
MULTILIB_CONF = "${@'conf/multilib.conf' if d.getVar('MULTILIBS') else ''}"
require ${MULTILIB_CONF}

# dnsmasq and named (provided by bind) use the same default port 53:
# | dnsmasq: failed to create listening socket for port 53: Address already in use
# So disable the service by default, and if the user want to use both of them,
# it need to be set to a different port in dnsmasq.conf before starting the service.
INITSCRIPT_PARAMS:pn-dnsmasq = "stop 20 0 1 6 ."
SYSTEMD_AUTO_ENABLE:pn-dnsmasq = "disable"

require conf/distro/include/wrlinux-distro-settings.conf

# Exclude download layers from eSDK.
SDK_LAYERS_EXCLUDE_PATTERN ?= ".*-dl$ .*-dl-[0-9.]+$"

# By default we only support 'standard' kernels.  A machine configuration,
# user, or other configuration file can override this.
TARGET_SUPPORTED_KTYPES ??= "standard"

# Packages blacklisted by default for wrlinux.
SKIP_RECIPE[bsd-headers] ?= "only glibc is supported for wrlinux"
SKIP_RECIPE[fts] ?= "only glibc is supported for wrlinux"
SKIP_RECIPE[gcompat] ?= "only glibc is supported for wrlinux"
SKIP_RECIPE[libssp-nonshared] ?= "only glibc is supported for wrlinux"
SKIP_RECIPE[libucontext] ?= "only glibc is supported for wrlinux"
SKIP_RECIPE[musl] ?= "only glibc is supported for wrlinux"
SKIP_RECIPE[musl-obstack] ?= "only glibc is supported for wrlinux"
SKIP_RECIPE[musl-utils] ?= "only glibc is supported for wrlinux"
SKIP_RECIPE[libc-test] ?= "only glibc is supported for wrlinux"
SKIP_RECIPE[newlib] ?= "only glibc is supported for wrlinux"

# do_kernel_version_sanity_check in oe-core checks if the defined version in
# metadata(LINUX_VERSION) matches the version written in the source code. For
# release branches we have Jenkins to take care of the version updating. For
# CI/CD branch we aim to use the latest source and directly use Yocto kernel
# source code which frequently gets updated. But oe-core does not tightly follow
# the latest version. We don't necessarily frequently manually bump up the
# version.
KERNEL_VERSION_SANITY_SKIP = "1"

# SANITY_TESTED_DISTROS used to defined the distribution list which we used to build wrlinux
SANITY_TESTED_DISTROS ?= " \
            ubuntu-20.04 \n \
            ubuntu-22.04 \n \
            fedora-37 \n \
            fedora-38 \n \
            opensuseleap-15.4 \n \
            rhel-8.8 \n \
            rhel-9.2 \n \
            sled-15.4 \n \
            centos-7 \n \
            "
