#include "plugboard.h"

/**
 * Cria uma placa de tomadas. (Steckerbrett)
 */
struct plugboard *plugboard_new()
{
    struct plugboard *plugboard = (struct plugboard *)malloc(sizeof(struct plugboard));
    if (plugboard == NULL)
    {
        printf("Erro ao alocar memória para a placa de tomadas.");
        exit(1);
    }
    plugboard->num_pairs = 0;
    return plugboard;
}

/**
 * Define um par de tomadas à placa de tomadas.
 */
void plugboard_pair(struct plugboard *plugboard, uint8_t a, uint8_t b)
{
    if (plugboard->num_pairs == MAX_PAIRS)
    {
        printf("Número máximo de pares de tomadas atingido.\n");
        return;
    }

    uint8_t i;
    for (i = 0; i < plugboard->num_pairs; i++)
    {
        if (plugboard->pairs[i][0] == a || plugboard->pairs[i][0] == b ||
            plugboard->pairs[i][1] == a || plugboard->pairs[i][1] == b)
        {
            printf("Aviso: Tomadas já conectadas. Trocando o par [%c <-> %c] para [%c <-> %c]...\n",
                   plugboard->pairs[i][0], plugboard->pairs[i][1],
                   a, b);
            plugboard->pairs[i][0] = a;
            plugboard->pairs[i][1] = b;
            return;
        }
    }

    plugboard->pairs[plugboard->num_pairs][0] = a;
    plugboard->pairs[plugboard->num_pairs][1] = b;
    plugboard->num_pairs++;
    printf("Novo par de tomadas: [%c <-> %c]\n", idx_ltr(a), idx_ltr(b));
}

/**
 * Imprime a placa de tomadas
 */
void plugboard_print(struct plugboard *plugboard)
{
    printf("Placa de tomadas (%d pares):\n", plugboard->num_pairs);
    if (plugboard->num_pairs == 0)
    {
        printf("Nenhum par de tomadas definido.\n");
        return;
    }
    int i;
    for (i = 0; i < plugboard->num_pairs; i++)
    {
        printf("[%c <-> %c]\n", idx_ltr(plugboard->pairs[i][0]), idx_ltr(plugboard->pairs[i][1]));
    }
}

/**
 * Envia um sinal adiante na placa de tomadas.
 */
uint8_t plugboard_forward(struct plugboard *plugboard, uint8_t signal)
{
    if (plugboard->num_pairs > 0)
    {
        uint8_t i;
        for (i = 0; i < plugboard->num_pairs; i++)
        {
            if (plugboard->pairs[i][0] == signal)
            {
                return plugboard->pairs[i][1];
            }
            else if (plugboard->pairs[i][1] == signal)
            {
                return plugboard->pairs[i][0];
            }
        }
    }
    return signal;
}