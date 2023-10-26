#!/bin/sh
# This is the init script for NFS boot.

read_args() {
    # Parse the kernel command line for NFS options
    [ -z "$CMDLINE" ] && CMDLINE=`cat /proc/cmdline`
    nfsopts="nolock"
    for arg in $CMDLINE; do
        optarg=`expr "x$arg" : 'x[^=]*=\(.*\)'`
        case $arg in
            nfsroot=*)
                    nfsroot="$optarg" ;;
            ro)
                    nfsopts="$nfsopts,ro" ;;
        esac
    done

    # Split the nfsroot option into location and mount options
    if [ -n "$nfsroot" ]; then
        location=`expr "x$nfsroot" : 'x\([^,]*\)'`
        cliopts=`expr "x$nfsroot" : 'x[^,]*,\(.*\)'`
    fi

    # Add mount options from command-line to NFS options
    if [ -n "$cliopts" ]; then
        nfsopts="$cliopts,$nfsopts"
    fi
}

mount_nfs_rootfs() {
    # Mount the real root filesystem
    mkdir -p /sysroot
    mount -t nfs -o ${nfsopts} ${location} /sysroot

    # Check mount was successful
    if [ $? -ne 0 ]; then
        echo "Error: cannot mount NFS rootfs!"
        exit 1
    fi
}

read_args
mount_nfs_rootfs
