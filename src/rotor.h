#ifndef ROTOR_H
#define ROTOR_H

#include "utils.h"

struct rotor {
    char *name;
    uint8_t wirings[NUM_LETTERS];
    uint8_t inverse_wirings[NUM_LETTERS];
    uint8_t position; // Posição de rotação.
    uint8_t notch; // Posição de encaixe do rotor, serve para determinar o giro do próximo rotor da máquina.
    uint8_t ring_setting; // Posição de rotação do anel.
};

struct rotor *rotor_new(char *name, char *wirings, char notch);
void rotor_position(struct rotor *rotor, uint8_t position);
void rotor_ring(struct rotor *rotor, uint8_t ring_setting);
void rotor_rotate(struct rotor *rotor);
uint8_t rotor_forward(struct rotor *rotor, uint8_t input);
uint8_t rotor_backward(struct rotor *rotor, uint8_t input);

#endif