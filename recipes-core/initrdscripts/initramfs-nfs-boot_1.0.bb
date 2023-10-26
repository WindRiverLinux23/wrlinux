SUMMARY = "initramfs for NFS boot"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

inherit systemd

SRC_URI += "file://init-nfs.sh \
	        file://nfs-boot.service \
"

do_install() {
	install -m 0755 ${WORKDIR}/init-nfs.sh ${D}/init-nfs.sh
	install -d ${D}${systemd_unitdir}/system
	install -m 0644 ${WORKDIR}/nfs-boot.service ${D}${systemd_unitdir}/system/
}

SYSTEMD_SERVICE:${PN} = "nfs-boot.service"

FILES:${PN} += " /init-nfs.sh"

