FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://LICENSE;md5=9bfa86579213cb4c6adaffface6b2820"

PV = "0.1.62"

SRC_URI = "https://github.com/ComplianceAsCode/content/releases/download/v${PV}/${BP}.tar.bz2 \
           file://0001-Add-product-WRLinux-LTS23.patch \
           file://0002-Add-prodtype-wrlinuxlts23-to-rules.patch \
           file://0003-Set-correct-package-names-for-wrlinuxlts23.patch \
           file://0004-Fix-path-of-systemctl-for-service_enable-service_dis.patch \
           file://0005-Fix-accounts_passwords_pam_faillock_deny.patch \
           file://0006-Fix-accounts_passwords_pam_faillock_deny_root.patch \
           file://0007-Fix-accounts_passwords_pam_faillock_unlock_time.patch \
           file://0008-Fix-accounts_passwords_pam_faillock_interval.patch \
           file://0009-Fix-accounts_password_pam_unix_remember.patch \
           file://0010-Fix-set_password_hashing_algorithm.patch \
           file://0011-Fix-display_login_attempts.patch \
           file://0012-Use-pam-pwquality-instead-of-pam-tally2.patch \
           file://0013-Fix-accounts_maximum_age_login_defs.patch \
           file://0014-Fix-accounts_password_set_max_life_existing.patch \
           file://0015-Fix-accounts_logon_fail_delay.patch \
           file://0016-Fix-accounts_umask_etc_login_defs.patch \
           file://0017-Fix-banner_etc_issue.patch \
           file://0018-Fix-no_empty_passwords.patch \
           file://0019-Fix-selinux_policytype.patch \
           file://0020-Fix-require_singleuser_auth.patch \
           file://0021-Fix-audit_rules.patch \
           file://0022-Fix-openssh-rules.patch \
           file://0023-Enable-sysctl-rules-for-wrlinux.patch \
           file://0024-Enable-snmpd_not_default_password-rule.patch \
           file://0025-Eanble-kernel_module_disabled-rule.patch \
           file://0026-Fix-sudo_remove_nopasswd.patch \
           file://0027-Fix-mount_option_home_nosuid.patch \
           file://0028-Fix-chronyd_or_ntpd_set_maxpoll.patch \
           file://0029-Fix-file_groupownership_home_directories.patch \
           file://0030-Replace-firewalld-with-iptables.patch \
           file://0031-Replace-aide-with-samhain.patch \
           "

SRC_URI[sha256sum] = "6d3398716bb0c7d2c01526af89f8cf42c0581ee10771e1dfbad98434d18098bf"

S = "${WORKDIR}/scap-security-guide-${PV}"

EXTRA_OECMAKE += "-DSSG_PRODUCT_DEFAULT=OFF \
                  -DSSG_PRODUCT_WRLINUXLTS23=ON \
                  "
