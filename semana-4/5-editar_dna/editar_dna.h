#ifndef LinkedNode_H // guardas de cabeçalho, impedem inclusões cíclicas
#define LinkedNode_H

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char data;
   LinkedNode *next;
};
LinkedNode *editar_dna(LinkedNode *dna_original, LinkedNode *seq_edicao);
#endif
