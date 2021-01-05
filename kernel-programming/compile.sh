# to build module

make -C /lib/modules/`uname -r`/build M=${PWD} modules

# to clean output files
#make -C /lib/modules/`uname -r`/build M=${PWD} clean