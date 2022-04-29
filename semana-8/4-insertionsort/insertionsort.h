#ifndef DLinkedNode_H // guardas de cabeçalho, impedem inclusões cíclicas
#define DLinkedNode_H

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *prev, *next;
};


#endif