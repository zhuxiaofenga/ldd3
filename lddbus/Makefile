# Comment/uncomment the following line to disable/enable debugging
#DEBUG = y

# Add your debugging flag (or not) to CFLAGS
ifeq ($(DEBUG),y)
  DEBFLAGS = -O -g # "-O" is needed to expand inlines
else
  DEBFLAGS = -O2
endif

LDDINCDIR=$(PWD)/../include
EXTRA_CFLAGS  += $(DEBFLAGS) -I$(LDDINCDIR)

ifneq ($(KERNELRELEASE),)
# call from kernel build system

obj-m	:= lddbus.o
obj-m	+= ldddev.o
obj-m	+= ldddrv.o


else

KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD       := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) SUBDIRS=$(PWD) modules

endif



clean:
	rm -rf *.o *.ko *~ core .depend *.mod.c .*.cmd .tmp_versions .*.o.d

depend .depend dep:
	$(CC) $(EXTRA_CFLAGS) -M *.c > .depend


ifeq (.depend,$(wildcard .depend))
include .depend
endif
