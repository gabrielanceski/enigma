#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define NUM_LETTERS 26

// Comando para limpar a tela do terminal
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

static void clear_screen()
{
    system(CLEAR_SCREEN);
}

static inline uint8_t ltr_idx(uint8_t ltr)
{
    return (ltr - 'A') % NUM_LETTERS;
}

static inline uint8_t idx_ltr(uint8_t idx)
{
    return (idx % NUM_LETTERS) + 'A';
}

#endif