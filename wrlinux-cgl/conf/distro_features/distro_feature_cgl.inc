WRTEMPLATE:append:df-cgl = " feature/cgl-full"

# add l2tp.scc to include CONFIG_L2TP=y and CONFIG_PPPOL2TP=m
# as openl2tp CUT case needs it
# add iscsi.scc to include CONFIG_ISCSI_TCP=m
# as iscsi CUT case needs it
# add drbd.cfg to include CONFIG_BLK_DEV_DRBD=y
# as drbd CUT case needs it

KERNEL_FEATURES:append:df-cgl = " \
                                 features/nfsd/nfsd-enable.scc \
                                 features/ecryptfs/ecryptfs.scc \
                                 features/aufs/aufs-enable.scc  \
                                 features/vrf/vrf.scc \
                                 cgl/cfg/dmm.scc \
                                 cgl/cfg/fs/ocfs2.scc \
                                 cgl/cfg/net/l2tp.scc \
                                 cgl/cfg/iscsi.scc \
                                 cgl/cfg/drbd.cfg \
                                 cgl/cfg/scsi_dh.scc \
                                 cgl/cfg/scsi_dh_rdac.scc \
                                 cgl/cfg/scsi_dh_emc.scc \
                                 cgl/cfg/scsi_dh_alua.scc \
                                 cgl/features/aoe/aoe.scc \
                                 cgl/features/mip6/mip6.scc \
                                 cgl/features/quota/quota.scc \
                                 "

require wrlinux-cgl-recipelists.inc
