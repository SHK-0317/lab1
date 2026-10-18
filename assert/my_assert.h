#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifdef NDEBUG
#define my_assert(expr) ((void)0)
#else
#define my_assert(expr)                                               \
    ((expr) ? (void)0                                                 \
            : (fprintf(stderr, "%s: %s:%d: %s: Assertion `%s' failed.\n", \
                       program_invocation_short_name,                 \
                       __FILE__, __LINE__, __func__, #expr),          \
               abort()))
#endif

#endif
