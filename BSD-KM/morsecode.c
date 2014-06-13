/**
 * Morse Code Translator
 * BSD kernel module
 * Copyright (C) 2014 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under FreeBSD clang version 3.3 (tags/RELEASE_33/final 183502) 20130610
 * Target: x86_64-unknown-freebsd10.0
 */
#include <sys/param.h>      /* defines used in kernel.h */
#include <sys/module.h>
#include <sys/kernel.h>     /* types used in module initialization */
#include <sys/systm.h>      /* uprintf */
#include <sys/conf.h>       /* cdevsw struct */
#include <sys/uio.h>        /* uio struct */
#include <sys/malloc.h>     /* MALLOC_DECLARE/DEFINE */
#include "morse.h"

MALLOC_DECLARE(M_MORSECODE);
MALLOC_DEFINE(M_MORSECODE, "morsecode_buffer", "buffer for morsecode");
MALLOC_DECLARE(M_USRINPUT);
MALLOC_DEFINE(M_USRINPUT, "usrinput_buffer", "buffer for usrinput");

static d_open_t     morsecode_open;
static d_close_t    morsecode_close;
static d_read_t     morsecode_read;
static d_write_t    morsecode_write;

static struct cdevsw morse_cdevsw = {
    .d_version  =   D_VERSION,
    .d_open     =   morsecode_open,
    .d_close    =   morsecode_close,
    .d_read     =   morsecode_read,
    .d_write    =   morsecode_write,
    .d_name     =   "morsecode"
};

struct cdev *morsedev;
static char *morses, *usrinput;
static Morse_map *mm;


static int morsecode_open(struct cdev *dev __unused, int oflags __unused,
        int devtype __unused, struct thread *td __unused)
{
    int error = 0;
    if (!morses) {
        uprintf("(%d) !morses\n", __LINE__);
    }
    //printf("%s opened\n", morse_cdevsw.d_name);
    return error;
}


static int morsecode_close(struct cdev *dev __unused, int fflag __unused, 
        int devtype __unused, struct thread *td __unused)
{
    //printf("%s closed\n", morse_cdevsw.d_name);
    return 0;
}


static int morsecode_read(struct cdev *dev __unused, struct uio *uio,
        int ioflag __unused)
{
    size_t len;
    int error;
    if (!morses) {
        printf("(%d) !morses\n", __LINE__);
        error = EINVAL;
        return error;
    } else {
        //printf("(%d) morses->%s\n", __LINE__, morses);
    }

    //printf("uio->uio_resid->%zu, uio->uio_offset->%ld, strlen(morses)->%ld\n",
    //        uio->uio_resid, uio->uio_offset, strlen(morses));
    len = MIN(uio->uio_resid, (strlen(morses) - uio->uio_offset > 0) ?
            strlen(morses) - uio->uio_offset : 0);
    //printf("(%d) len->%zu, morses->%s\n", __LINE__, len, morses);

    if ((error = uiomove(morses + uio->uio_offset, len, uio)) != 0)
        printf("-E- (%d) uiomove failed!\n", __LINE__);
        
    return error;
}


static int morsecode_write(struct cdev *dev __unused, struct uio *uio,
        int ioflag __unused)
{
    size_t len;
    int error = 0;
    if (morses)
        free(morses, M_MORSECODE);
    usrinput = malloc(uio->uio_iov->iov_len * (sizeof(char) + 1),
                    M_USRINPUT, M_WAITOK | M_ZERO);
    morses = malloc(uio->uio_iov->iov_len * (MORSE_CODE_AVG_CHAR *
                    sizeof(char)) + 1, M_MORSECODE, M_WAITOK | M_ZERO);

    if (!(morses && usrinput)) {
        printf("-E- Failed to allocate memory\n");
        error = EINVAL;
    }

    len = MIN(uio->uio_resid, (strlen(usrinput) - 1 - uio->uio_offset) > 0 ?
            strlen(usrinput) - 1 - uio->uio_offset : 0);
    if (len == 0)
        return error;
    error = uiomove(usrinput, len, uio);

    if (error != 0) {
        printf("-E- Write failed: bad address!\n");
        return error;
    }

    usrinput[len] = '\0';
    printf("-I- usrinput: %s\n", usrinput);
    line_to_morse(morses, usrinput, mm);

    return error;
}


/**
 * init function called by kld[un]load system calls to determine what
 * actions to take when a module is loaded or unloaded.
 */
static int morsedev_init(struct module *m __unused, int what, void *arg __unused)
{
    int error = 0;
    switch (what) {
        case MOD_LOAD:
            error = make_dev_p(MAKEDEV_CHECKNAME | MAKEDEV_WAITOK,
                    &morsedev,
                    &morse_cdevsw,
                    0,
                    UID_ROOT,
                    GID_WHEEL,
                    0666,
                    "morsecode");
            if (error != 0)
                break;
            mm = Morse_map_create();
            printf("Morsecode device loaded.\n");
            break;
        case MOD_UNLOAD:
            destroy_dev(morsedev);
            free(morses, M_MORSECODE);
            free(usrinput, M_USRINPUT);
            cleanup();
            printf("Morsecode device unloaded.\n");
            break;
        default:
            error = EOPNOTSUPP;
            break;
    }

    return error;
}


DEV_MODULE(morsecode, morsedev_init, NULL);
