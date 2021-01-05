# to build module

make -C /lib/modules/`uname -r`/build M=${PWD} modules

# to clean output files
#make -C /lib/modules/`uname -r`/build M=${PWD} clean

#list modinfo
modinfo helloworld.ko

#install kernel module
sudo insmod helloworld.ko

#be sure that u see at top your new module
lsmod | less

#check init and exit
dmesg

#remove module
rmmod helloworld.ko