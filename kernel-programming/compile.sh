# to build module

make -C /lib/modules/`uname -r`/build M=${PWD} modules

#install kernel module
sudo insmod helloworld.ko


# to clean output files
#make -C /lib/modules/`uname -r`/build M=${PWD} clean
