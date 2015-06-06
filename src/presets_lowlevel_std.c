/* Implementation of preset recalling when the standard i/o functionality is
 * available like fwrite fread etc. */
#include "presets_lowlevel.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

struct __presets_lowlevel_handle {
    char *filepath;
    FILE *file;
};

/* In this implementation, opt is a char* representing a path to a file */
presets_lowlevel_err_t presets_lowlevel_init(presets_lowlevel_handle_t
        **handle,void *opt)
{
    *handle = (presets_lowlevel_handle_t*)malloc(sizeof(presets_lowlevel_handle_t));
    if (!(*handle)) {
        return(-1);
    }
    (*handle)->filepath = (char*)malloc(strlen((char*)opt)+1);
    if (!(*handle)->filepath) {
        free(*handle);
        return(-1);
    }
    strcpy((*handle)->filepath,(char*)opt);
    (*handle)->file = fopen((*handle)->filepath,"w+");
    if (!(*handle)->file) {
        free((*handle)->filepath);
        free(*handle);
        return(-2);
    }
    return(0);
}

presets_lowlevel_err_t presets_lowlevel_read(presets_lowlevel_handle_t *handle,
        void *dest, size_t size, void *opt)
{
    size_t nmemb;
    rewind(handle->file);
    nmemb = fread(dest,1,size,handle->file);
    if (nmemb < size) {
        /* Not enough items read. */
        return(-1);
    }
    return(0);
}

presets_lowlevel_err_t presets_lowlevel_write(presets_lowlevel_handle_t *handle,
        void *src, size_t size, void *opt)
{
    size_t nmemb;
    rewind(handle->file);
    nmemb = fwrite(src,1,size,handle->file);
    if (nmemb < size) {
        /* Not enough items written. */
        return(-1);
    }
    return(0);
}
