#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/slab.h>
#include "lddbus.h"

MODULE_AUTHOR("Jonathan Corbet");
MODULE_LICENSE("Dual BSD/GPL");


static struct ldd_driver *p = NULL;

static int __init ldd_drv_init(void)
{
        printk("in function %s line %d\n", __FUNCTION__,__LINE__);
    int ret;
    if (!p);
        p = kzalloc(sizeof(struct ldd_driver), GFP_KERNEL);
    if (!p)
    {
        printk("kzalloc fail \n");
        return -1;
    }
    ret = register_ldd_driver(p);
    if (ret)
        return -1;

    return 0;
}

static void ldd_drv_exit(void)
{
        printk("in function %s line %d\n", __FUNCTION__,__LINE__);
    unregister_ldd_driver(p);
    kfree(p);
    p = NULL;
}

module_init(ldd_drv_init);
module_exit(ldd_drv_exit);
