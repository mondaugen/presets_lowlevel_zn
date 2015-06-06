#ifndef PRESETS_LOWLEVEL_H
#define PRESETS_LOWLEVEL_H 
#include <stddef.h> 

typedef struct __presets_lowlevel_handle presets_lowlevel_handle_t;
typedef int presets_lowlevel_err_t;

presets_lowlevel_err_t presets_lowlevel_init(presets_lowlevel_handle_t
        **handle,void *opt);
presets_lowlevel_err_t presets_lowlevel_read(presets_lowlevel_handle_t *handle,
        void *dest, size_t size, void *opt);
presets_lowlevel_err_t presets_lowlevel_write(presets_lowlevel_handle_t *handle,
        void *src, size_t size, void *opt);
#endif /* PRESETS_LOWLEVEL_H */
