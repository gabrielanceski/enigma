#include "rotor.h"

/**
 * Cria um novo rotor.
 * @param name Nome do rotor.
 * @param wirings Mapeamento de fios.
 * @param notch Posição de encaixe do rotor, serve para determinar o giro do próximo rotor da máquina.
 */
struct rotor *rotor_new(char *name, char *wirings, char notch)
{
    struct rotor *rotor = malloc(sizeof(struct rotor));
    rotor->name = name;
    rotor->notch = ltr_idx(notch);
    rotor->position = 0;
    rotor->ring_setting = 0;
    uint8_t i;
    for (i = 0; i < NUM_LETTERS; i++)
    {
        uint8_t letter_idx = ltr_idx(wirings[i]);
        rotor->wirings[i] = letter_idx;
        rotor->inverse_wirings[letter_idx] = i;
    }
    return rotor;
}

/**
 * Define a posição inicial do rotor.
 * @param rotor Rotor.
 * @param position Posição inicial. (0-25)
 */
void rotor_position(struct rotor *rotor, uint8_t position)
{
    rotor->position = position;
}

/**
 * Define a posição inicial do anel.
 * @param rotor Rotor.
 * @param ring_setting Posição inicial. (0-25)
 */
void rotor_ring(struct rotor *rotor, uint8_t ring_setting)
{
    rotor->ring_setting = ring_setting;
}

/**
 * Gira o rotor.
 * @param rotor Rotor.
 */
void rotor_rotate(struct rotor *rotor)
{
    rotor->position = (rotor->position + 1) % NUM_LETTERS;
}

/**
 * Sinal enviado em direção ao refletor (da direita para a esquerda).
 * @param rotor Rotor.
 * @param input Sinal de entrada.
 * @return Sinal de saída.
 */
uint8_t rotor_forward(struct rotor *rotor, uint8_t input)
{
    int shift = rotor->position - rotor->ring_setting;
    return (rotor->wirings[(input + shift + NUM_LETTERS) % NUM_LETTERS] - shift + NUM_LETTERS) % NUM_LETTERS;
}

/**
 * Sinal de retorno após passar pelo refletor (da esquerda para a direita).
 * @param rotor Rotor.
 * @param input Sinal de entrada.
 * @return Sinal de saída.
 */
uint8_t rotor_backward(struct rotor *rotor, uint8_t input)
{
    int shift = rotor->position - rotor->ring_setting;
    return (rotor->inverse_wirings[(input + shift + NUM_LETTERS) % NUM_LETTERS] - shift + NUM_LETTERS) % NUM_LETTERS;
}