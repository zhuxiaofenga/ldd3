#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/slab.h>
#include "lddbus.h"

MODULE_AUTHOR("Jonathan Corbet");
MODULE_LICENSE("Dual BSD/GPL");

/* for me to see*/
static struct ldd_driver sculld_driver = {
	.version = "$Revision: 1.21 $",
	.module = THIS_MODULE,
	.driver = {
		.name = "sculld",
	},
};

static struct ldd_driver *p = NULL;

static int ldd_probe()
{
   return 0; 
}

static int __init ldd_drv_init(void)
{
    int ret;
        printk("in function %s line %d\n", __FUNCTION__,__LINE__);
    if (!p);
        p = kzalloc(sizeof(struct ldd_driver), GFP_KERNEL);
    if (!p)
    {
        printk("kzalloc fail \n");
        return -1;
    }
    p->version = "aaaa";
    p->module = THIS_MODULE;
    p->driver.name = "ldd1";
    p->driver.probe = ldd_probe;

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
