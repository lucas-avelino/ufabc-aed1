#ifndef NoArvore_H // guardas de cabeçalho, impedem inclusões cíclicas
#define NoArvore_H

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

#endif
