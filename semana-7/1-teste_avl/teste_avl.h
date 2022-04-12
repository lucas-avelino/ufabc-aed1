#ifndef NoArvore_H // guardas de cabeçalho, impedem inclusões cíclicas
#define NoArvore_H

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    int altura;
    NoArvore *esq, *dir;
};

NoArvore *inserir(NoArvore *raiz, int valor);
NoArvore *allocNode(int valor, int altura);
int altura(NoArvore *n);
int alturaRec(NoArvore *n);

#endif