#
# Copyright (C) 2019 Wind River Systems, Inc.
#
# used by template feature/run-container

python check_container_config () {
    if d.getVar('BB_CURRENT_MC') == 'default':
        return

    containers = d.getVar('WR_CONTAINER_NAMES')
    priorities = d.getVar('WR_CONTAINER_PRIORITIES')
    host_images = d.getVar('WR_HOST_IMAGES')

    if not (host_images and containers and priorities):
        bb.fatal('Please set WR_CONTAINER_NAMES, WR_CONTAINER_PRIORITIES and WR_HOST_IMAGES correctly.')

    if len(containers.split()) != len(priorities.split()):
        bb.fatal('WR_CONTAINER_NAMES and WR_CONTAINER_PRIORITIES are associated, please set them correctly.')

    common = set(containers.split()).intersection(set(host_images.split()))
    if common:
        bb.fatal('Recipe(s) %s not allowed set both in WR_CONTAINER_NAMES and WR_HOST_IMAGES.' % ' '.join(common))

    if (d.getVar('BB_CURRENT_MC') == 'wr-host' and
        not d.getVar('CNTR_TMPDIR')):
        bb.fatal("Please set CNTR_TMPDIR for multiconfig 'wr-host'.")
}

addhandler check_container_config
check_container_config[eventmask] = "bb.event.ConfigParsed"

# handle settings of hosts
python () {
    if d.getVar('BB_CURRENT_MC') == 'wr-container':
        d.appendVar('IMAGE_FSTYPES', ' tar.gz')
        d.appendVar('ROOTFS_POSTPROCESS_COMMAND', ' container_rootfs_postfun;')
        return

    pn = d.getVar('PN')
    host = d.getVar('WR_HOST_IMAGES').split()
    if pn in host:
        d.appendVar('IMAGE_INSTALL', ' run-container')
        d.appendVar('DEPENDS', ' sloci-image-native skopeo-native')

        containers = d.getVar('WR_CONTAINER_NAMES').split()
        d.appendVarFlag('do_rootfs', 'mcdepends', ' '.join(['multiconfig:wr-host:wr-container:%s:do_image_complete' % c for c in containers]))

        d.appendVar('ROOTFS_POSTPROCESS_COMMAND', ' rootfs_install_container;')
}

container_rootfs_postfun () {
    # mask serial-getty@.service manually
    if [ -d ${IMAGE_ROOTFS}/etc/systemd/system ]; then
        ln -sf /dev/null ${IMAGE_ROOTFS}/etc/systemd/system/serial-getty@.service
    fi
}

rootfs_install_container () {
    install -d ${IMAGE_ROOTFS}${CONTAINER_DEST_ON_HOST}

    cntr_path=${WORKDIR}/containers
    mkdir -p ${cntr_path}
    for container in ${WR_CONTAINER_NAMES}
    do
        cntr_image_path=$(ls -1t ${CNTR_TMPDIR}${TCLIBCAPPEND}/deploy/images/${MACHINE}/${container}*tar.gz | head -1)
        cntr_image=$(basename $cntr_image_path)

        # duplicate .tar.gz image which will be unpacked by gzip
        cp $cntr_image_path $cntr_path
        sloci-image -m ${HOST_ARCH} $cntr_path/$cntr_image $cntr_path/$container
        skopeo copy oci:$cntr_path/$container docker-archive:${IMAGE_ROOTFS}${CONTAINER_DEST_ON_HOST}/$container.tar
    done

    install -d ${IMAGE_ROOTFS}/etc/wr-containers
    touch ${IMAGE_ROOTFS}/etc/wr-containers/containers_to_run.txt

    echo "${WR_CONTAINER_NAMES}" >> ${IMAGE_ROOTFS}/etc/wr-containers/containers_to_run.txt
    echo "${WR_CONTAINER_PRIORITIES}" >> ${IMAGE_ROOTFS}/etc/wr-containers/containers_to_run.txt
    echo -n "${CONTAINER_DEST_ON_HOST}" >> ${IMAGE_ROOTFS}/etc/wr-containers/containers_to_run.txt
}

do_rootfs[cleandirs] = "${WORKDIR}/containers"
