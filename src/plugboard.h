#include "utils.h"
// Número máximo de pares suportados pela placa de conexões padrão da Enigma I.
#define MAX_PAIRS 10
#define PAIR_LENGTH 2

typedef struct
{

    uint8_t pairs[MAX_PAIRS][PAIR_LENGTH];
    uint8_t num_pairs;
} plugboard_t;

plugboard_t *plugboard_create();
void plugboard_pair(plugboard_t *plugboard, uint8_t a, uint8_t b);
void plugboard_print(plugboard_t *plugboard);
uint8_t plugboard_forward(plugboard_t *plugboard, uint8_t signal);