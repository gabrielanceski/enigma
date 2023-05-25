#include "reflector.h"

/**
 * Cria um novo refletor com o nome e as conexões informadas.
 * @param name Nome do refletor.
 * @param wirings Conexões do refletor.
 * @return Novo refletor.
 */
struct reflector *reflector_new(char *name, char *wirings)
{
    struct reflector *reflector = (struct reflector *)malloc(sizeof(struct reflector));
    reflector->name = name;

    uint8_t i;
    for (i = 0; i < NUM_LETTERS; i++)
        reflector->wirings[i] = ltr_idx(wirings[i]);

    return reflector;
}

/**
 * Reflete um sinal enviado.
 * @param reflector Refletor.
 * @param input Sinal de entrada.
 * @return Sinal refletido.
 */
uint8_t reflector_reflect(struct reflector *reflector, uint8_t input)
{
    return reflector->wirings[input];
}