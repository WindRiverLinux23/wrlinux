#
# Copyright (C) 2012-2014, 2019 Wind River Systems, Inc.
#

RDEPENDS:${PN} += "policycoreutils"

FILESEXTRAPATHS:prepend := "${THISDIR}/refpolicy-wr:"

SRC_URI += "\
        file://0001-policy-modules-system-selinuxutil-allow-secadm-to-ma.patch \
        file://0002-corenetwork-label-port-18120-udp-with-radius.patch \
        file://0003-policy-modules-system-init-set-bin_t-label-for-rc.lo.patch \
        file://0004-policy-modules-services-ftp-fix-avc-denials-for-ftpd.patch \
        file://0005-policy-modules-services-mta-allow-user_mail_t-to-man.patch \
        file://0006-policy-modules-services-ntp-fix-avc-denials-for-ntpd.patch \
        file://0007-policy-modules-services-acpi-make-acpid_t-MLS-truste.patch \
        file://0008-Revert-kernel-Drop-unlabeled_t-as-a-files_mountpoint.patch \
        file://0009-policy-modules-roles-sysadm-allow-sysadm_t-to-read-f.patch \
        "

OSTREE_POLICY_PATCHES = "\
        file://wr-policy-Add-ostree-policy.patch \
        file://wr-policy-file_contexts.subs_dist-set-aliases-for-ostree-direc.patch \
        file://wr-policy-files-add-lable-for-symlinks-mnt-opt-media-and-root.patch \
        file://wr-policy-system-mount.te-allow-mount-on-symlink-file.patch \
        file://wr-policy-system-locallogin.te-allow-login-read-symlink-file.patch \
        file://wr-policy-allow-mount-to-dirs-under-tmp.patch \
        file://wr-policy-modules-system-mount-allow-mount-command-to-m.patch \
        file://wr-policy-modules-system-systemd-allow-systemd_generato.patch \
        file://wr-policy-modules-system-userdomain-allow-domain-read-h.patch \
        file://wr-policy-modules-system-systemd-allow-systemd_tmpfiles.patch \
        file://wr-policy-modules-system-systemd-fix-avc-denials-for-os.patch \
        file://wr-policy-Allow-sshd_t-and-staff_t-read-symlinks.patch \
        "

SRC_URI += "${@bb.utils.contains('DISTRO_FEATURES', 'ostree', '${OSTREE_POLICY_PATCHES}', '', d)}"
