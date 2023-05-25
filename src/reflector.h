#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "utils.h"

struct reflector {
    char *name;
    uint8_t wirings[NUM_LETTERS];
};

struct reflector *reflector_new(char *name, char* wirings);
uint8_t reflector_reflect(struct reflector *reflector, uint8_t input);

#endif