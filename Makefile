obj-m := hw.o

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	make -C $(KERNELDIR) M=$(PWD) modules

