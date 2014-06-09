/**
 * Morse Code Translator
 * Linux kernel module
 * Copyright (C) 2014 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under GNU C gcc 4.7.2, linux kernel 3.14.3-x86_64
 */
#include <linux/module.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/vmalloc.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include "morsecode.h"
#include "morse.h"

MODULE_AUTHOR("TzyLuen Ng <tzyluen.ng@gmail.com>");
MODULE_DESCRIPTION("Morse code translator device");
MODULE_LICENSE("GPL");

static char *morses, *usrinput;
static Morse_map *mm;


static int morsecode_open(struct inode *inod, struct file *fil)
{
    if (!morses) {
        printk(KERN_INFO "(%d) !morses\n", __LINE__);
        return 0;
    }
    printk(KERN_INFO "%s opened\n", THIS_MODULE->name);

    return 0;
}


static int morsecode_release(struct inode *inod, struct file *fil)
{
    printk(KERN_INFO "%s released\n", THIS_MODULE->name);
    return 0;
}


/**
 * A nonnegative return value represents the number of bytes successfully
 * read (the return value is a "signed size" type, usually the native integer
 * type for the target platform)
 */
static ssize_t morsecode_read(
    struct file *filp,
    char __user *buff,
    size_t len,
    loff_t *off)
{
    ssize_t retval, length = 0;
    int ret = 0;
    if (!morses) {
        printk(KERN_INFO "(%d) !morses\n", __LINE__);
        return 0;
    } else {
        printk(KERN_INFO "(%d) morses->%s\n", __LINE__, morses);
    }

    /**
     * copy_to_user: returns number of bytes that could not be copied, on
     * success, this will be zero.
     */
    length = (len >= strlen(morses)) ? strlen(morses) : len;
    ret = copy_to_user(buff, morses, length);
    if (*off >= strlen(morses)) {
        retval = 0;
        goto out;
    }

    if (ret < 0) {
        printk(KERN_INFO "Failed to copy_to_user\n");
        retval = -EFAULT;
        goto out;
    }

    printk(KERN_INFO "(%d) morses->%s\n", __LINE__, morses);
    printk(KERN_INFO "(%d) len->%zu, ret->%d\n", __LINE__, len, ret);

    /*if (ret > (len - strlen(morses)))
        retval = ret;
    else {
        retval = length;
        goto out;
    }*/
    retval = length;
    *off += length;
    printk(KERN_INFO "(%d) retval->%zu\n", __LINE__, retval);

    return retval;

 out:
    printk(KERN_INFO "(%d) retval->%zu\n", __LINE__, retval);
    return retval;
}


static ssize_t morsecode_write(
    struct file *filp,
    const char __user *buff,
    size_t len,
    loff_t *off)
{
    if (morses)
        kfree(morses);
    morses = (char *)kzalloc(len * MORSE_CODE_AVG_CHAR * sizeof(char),
            GFP_KERNEL);
    usrinput = (char *)kzalloc(len * sizeof(char) + 1, GFP_KERNEL);
    if (!(morses && usrinput)) {
        printk(KERN_INFO "Failed to allocate memory\n");
        return -EFAULT;
    }

    if (copy_from_user(usrinput, buff, len)) {
        printk(KERN_INFO "Failed to copy_from_user\n");
        return -EFAULT;
    }
    //option_handler();

    printk(KERN_INFO "(%d) usrinput->%s, strlen(%s)->%lu\n",
            __LINE__, usrinput, usrinput, strlen(usrinput));
    line_to_morse(morses, usrinput, mm);
    printk(KERN_INFO "(%d) morses->%s\n", __LINE__, morses);

    kfree(usrinput);

    return len;
}


static int __init morsedev_init(void)
{
    int ret = register_chrdev(MORSEDEV_MAJOR, THIS_MODULE->name, &fops);
    if (ret < 0) {
        printk(KERN_ERR "Device '%s' registration failed.\n", THIS_MODULE->name);
        return ret;
    }

    printk(KERN_INFO "Device '%s' registered.\n", THIS_MODULE->name);
    mm = Morse_map_create();

    return 0;
}


static void __exit morsedev_exit(void)
{
    if (mm) kfree(mm);
    if (morses) kfree(morses);
    if (usrinput) kfree(usrinput);

    unregister_chrdev(MORSEDEV_MAJOR, THIS_MODULE->name);
}


/*static void option_handler(char *s)
{
    switch () {
        case 'c':
            memset();
        default:
    }
}*/


module_init(morsedev_init);
module_exit(morsedev_exit);
