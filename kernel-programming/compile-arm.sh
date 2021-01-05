#to compile for arm
make -C /lib/modules/`uname -r`/build M=${PWD} modules \
  ARCH=arm \
  CROSS_COMPILE=arm-buildroot-linux-uclibcgnueabi-