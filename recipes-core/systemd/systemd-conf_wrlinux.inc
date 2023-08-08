#
# Copyright (C) 2022-2023 Wind River Systems, Inc.
#

pkg_postinst:${PN}:append() {
    if ! ${@bb.utils.contains('DISTRO_FEATURES','wr-allow-wired-default','true','false',d)}; then
        mkdir -p $D${sysconfdir}/systemd/network

        cat <<EOF > $D${sysconfdir}/systemd/network/80-wired.network
#
# Copyright (C) 2023 Wind River Systems, Inc.
#
# This file suppresses systemd-networkd processing of wired interfaces
# which use dhcp.  WRLinux uses dhcpcd for this by default.  The list
# of interfaces considered by dhcpcd is in /etc/default/dhcpcd.
#
EOF

    fi
}
