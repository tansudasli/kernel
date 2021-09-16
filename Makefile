obj-m := hello.o
hello-objs := helloworld.o other.o

all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules
clean:
	make -C /lib/modules/`uname -r`/build M=$(PWD) clean
install:
	sudo insmod hello.ko
remove:
	sudo rmmod hello.ko