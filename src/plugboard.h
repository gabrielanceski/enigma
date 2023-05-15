#include "utils.h"
// Número máximo de pares suportados pela placa de conexões padrão da Enigma I.
#define MAX_PAIRS 10
#define PAIR_LENGTH 2

struct plugboard
{
    uint8_t pairs[MAX_PAIRS][PAIR_LENGTH];
    uint8_t num_pairs;
};

struct plugboard *plugboard_new();
void plugboard_pair(struct plugboard *plugboard, uint8_t a, uint8_t b);
void plugboard_print(struct plugboard *plugboard);
uint8_t plugboard_forward(struct plugboard *plugboard, uint8_t signal);