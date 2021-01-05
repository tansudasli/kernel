# kernel

core kernel module development

## How to Run

on a linux machine, `git clone ...`,

- to check loaded modules `lsmod`, and `modinfo ..` for more detail
- to list module folder `ls /lib/modules/$(uname -r)`
- check  `cat /boot/config-$(uname -r) | grep CONFIG_MODULES` with `=y` value.