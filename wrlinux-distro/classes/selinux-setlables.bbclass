selinux_setlabels() {
    if [ -f ${IMAGE_ROOTFS}/${sysconfdir}/selinux/config ]; then
        if ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'true', 'false', d)}; then
            # Make sure /etc/machine-id exists and can be labeled.
            touch ${IMAGE_ROOTFS}${sysconfdir}/machine-id
        fi

        POL_TYPE=$(sed -n -e "s&^SELINUXTYPE[[:space:]]*=[[:space:]]*\([0-9A-Za-z_]\+\)&\1&p" ${IMAGE_ROOTFS}/${sysconfdir}/selinux/config)
        if ! setfiles -m -r ${IMAGE_ROOTFS} ${IMAGE_ROOTFS}/${sysconfdir}/selinux/${POL_TYPE}/contexts/files/file_contexts ${IMAGE_ROOTFS}
        then
            bbwarn "WARNING: Failed to set security contexts. Restoring security contexts will run on first boot."
            echo "# first boot relabelling" > ${IMAGE_ROOTFS}/.autorelabel
            exit 0
        fi
    fi
}

IMAGE_PREPROCESS_COMMAND:append = " ${@'selinux_setlabels;' if d.getVar('FIRST_BOOT_RELABEL') != '1' else ''}"
