#ifndef ItemVetor_H // guardas de cabeçalho, impedem inclusões cíclicas
#define ItemVetor_H

typedef struct ItemVetor ItemVetor;
struct ItemVetor {
    char *modelo;
    char *planeta;
    int autonomia;
};


#endif