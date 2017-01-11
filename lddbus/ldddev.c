#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/slab.h>
#include "lddbus.h"

MODULE_AUTHOR("Jonathan Corbet");
MODULE_LICENSE("Dual BSD/GPL");

static struct ldd_device *p = NULL;

static int __init ldd_dev_init(void)
{
    int ret;
        printk("in function %s line %d\n", __FUNCTION__,__LINE__);
    if (!p);
        p = kzalloc(sizeof(struct ldd_device),GFP_KERNEL);
    if (!p)
    {
        printk("kzalloc fail \n");
        return -1;
    }

    p->name = "myldddev";

    ret = register_ldd_device(p);
    if (ret)
        return -1;
    return 0;
}

static void ldd_dev_exit(void)
{ 
        printk("in function %s line %d\n", __FUNCTION__,__LINE__);
    unregister_ldd_device(p);
    kfree(p);
    p = NULL;
}

module_init(ldd_dev_init);
module_exit(ldd_dev_exit);
