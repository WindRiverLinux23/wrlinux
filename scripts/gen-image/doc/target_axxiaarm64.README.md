@common_introduction.md@
## Supported BSPs
- Intel ARM64 AXM5616 Victoria: ARM Cortex A57 Processor, only run with axxiaarm64

## How to install/boot binary image

### On Host PC
    NOTE: The following u-boot.img is from WRLinux LAB, it isn't integrated into
    WRLinux because of the license issue. Here is the steps to create:
    $ mkdir path_to_your_project && cd path_to_your_project
    $ git clone --branch WRLINUX_10_23_BASE --single-branch https://github.com/WindRiverLinux23/wrlinux-x.git
    $ ./wrlinux-x/setup.sh --machines=axxiaarm64 --accept-eula=yes
    $ . ./environment-setup-x86_64-wrlinuxsdk-linux
    $ . ./oe-init-build-env
    $ cat << _EOF >> conf/local.conf
MACHINE_FEATURES += " bootloader-axxia"
WRL_RECIPES:wr-axxiaarm += 'u-boot-axxia'
BB_NO_NETWORK = '0'
_EOF
    $ bitbake u-boot-axxia

    Due to the weak function support of the old u-boot on the board,
    if board network is accessible, setup a tftp server for u-boot to
    download u-boot.img; else prepare a ext2/3/4 USB storage, and copy
    ./u-boot.img to it
    $ mkdir tmp; sudo mount /dev/sdX1 ./tmp; sudo cp ./u-boot.img ./tmp
    $ sudo umount /dev/sdX*
    $ eject /dev/sdX

@target_common_usb.md@
Now burn the image onto the micro SD card:
    For full image
    $ zcat wrlinux-image-full-axxiaarm64.ustart.img.gz | sudo dd of=/dev/sdX bs=1M status=progress conv=fsync

    Or minimal image
    $ zcat wrlinux-image-minimal-axxiaarm64.ustart.img.gz | sudo dd of=/dev/sdX bs=1M status=progress conv=fsync

### On Board
This should give you a bootable micro SD card device. Insert the SD card into
SD slot on the board, and then power on, then enter u-boot shell, the image
should boot, enter the following commands to update u-boot.img and bootcmd

Upgrade bootloader:
    Load from tftp server
    $ tftp 0x4000000 <TFTP-SERVER-IPADDR>:path-to/u-boot.img
    $ sf probe 0
    $ sf erase 0x100000 0x200000
    $ sf write 0x4000000 0x100000 0x200000
    $ reset

    Or, Load from ext2/3/4 USB storage
    $ usb start
    $ usb reset
    $ ext4load usb 0:1 0x4000000 u-boot.img
    $ sf probe 0
    $ sf erase 0x100000 0x200000
    $ sf write 0x4000000 0x100000 0x200000
    $ reset

Set boot commands:
    $ setenv scriptaddr 0x2000000
    $ setenv boot_a_script "usb start; usb reset; fatload usb 0:1 ${scriptaddr} boot.scr; source ${scriptaddr}"
    $ setenv ostree_boot "run boot_a_script"
    $ setenv bootcmd "run ostree_boot"
    $ saveenv
    $ boot

@target_common_installer.md@
@common_package_manager.md@
