#ifndef NoArvore_H // guardas de cabeçalho, impedem inclusões cíclicas
#define NoArvore_H

typedef struct NoArvore NoArvore;
struct NoArvore {
    char* chave;
    NoArvore *esq, *dir;
};

NoArvore *buscar(NoArvore *raiz, char *chave);
NoArvore *inserir(NoArvore *raiz, char *chave_nova);
NoArvore *remover(NoArvore *raiz, char *chave);
void liberar_arvore(NoArvore *raiz);

#endif
