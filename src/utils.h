#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define NUM_LETTERS 26

static inline uint8_t ltr_idx(uint8_t ltr)
{
    return (ltr - 'A') % NUM_LETTERS;
}

static inline uint8_t idx_ltr(uint8_t idx)
{
    return (idx % NUM_LETTERS) + 'A';
}

#endif