#ifndef AB_RESULT_H
#define AB_RESULT_H

#include "ab_types.h"
#include "ab_err.h"

#define DEFINE_RESULT(type)      \
    typedef struct result_##type \
    {                            \
        bool is_err;             \
        union                    \
        {                        \
            type value;          \
            AbErr err;           \
        };                       \
    } Result_##type;

#define OK(type, val) \
    (Result_##type) { .is_err = false, .value = (val) }

#define ERR(type, err) \
    (Result_##type) { .is_err = true, .err = (err) }

#define IS_OK(res) (!(res).is_err)

#define UNWRAP(res) \
    ((res).is_err ? (ab_panic("UNWRAP on Err"), (res).value) : (res).value)

#define ERR_CODE(res) ((res).err)

#endif