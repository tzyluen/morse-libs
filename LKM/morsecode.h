/**
 * Morse Code Translator
 * Linux kernel module
 * Copyright (C) 2014 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under GNU C gcc 4.7.2, linux kernel 3.14.0
 */
#ifndef MORSECODE_H
#define MORSECODE_H

#define MORSEDEV_MAJOR      77

static int morsecode_open(struct inode *, struct file *);
static int morsecode_release(struct inode *, struct file *);
static ssize_t morsecode_read(struct file *, char *, size_t, loff_t *);
static ssize_t morsecode_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops = {
    .owner      = THIS_MODULE,
    .open       = morsecode_open,
    .release    = morsecode_release,
    .read       = morsecode_read,
    .write      = morsecode_write
};

#endif
