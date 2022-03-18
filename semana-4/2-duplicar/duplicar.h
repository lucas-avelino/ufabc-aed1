#ifndef LinkedNode_H // guardas de cabeçalho, impedem inclusões cíclicas
#define LinkedNode_H

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *next, *prev;
};
#endif
