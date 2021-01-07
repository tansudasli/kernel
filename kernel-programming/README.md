# kernel

core kernel module development

## How to Run

on a linux machine, 

- to check loaded modules `lsmod`, and `modinfo ..` for more detail
- to list module folder `ls /lib/modules/$(uname -r)`
- check `cat /boot/config-$(uname -r) | grep CONFIG_MODULES` with `=y` value.

then, to build w/
- `git clone ...`, `cd c-sandbox/kernel-programming` and
- `sudo apt-get install build-essential`
- Run `make all` to compile into .ko files,
    - to install kernel module `sudo insmod helloworld.ko`
    - to see kernel messages `dmesg` or `dmesg -w &` is much better (follow mode)
    - to remove kernel module `sudo rmmod helloworld.ko`
- Run `make clean` to clean .ko files