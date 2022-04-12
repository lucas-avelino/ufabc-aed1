#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
typedef struct FindWithComparassionCountResult FindWithComparassionCountResult;

struct NoArvore
{
  int ra;
  int nota;
  int altura;
  NoArvore *esq, *dir;
};

struct FindWithComparassionCountResult
{
  int operationCount;
  NoArvore *node;
};

// Tree Base functions
NoArvore *menor(NoArvore *raiz)
{
  if (raiz == NULL)
    return NULL;

  NoArvore *actual = raiz;

  while (actual->esq != NULL)
    actual = actual->esq;

  return actual;
}

NoArvore *buscarPai(NoArvore *raiz, int ra)
{
  if (raiz == NULL)
  {
    return NULL;
  }

  NoArvore *actual = raiz;
  NoArvore *prev = raiz;

  while (actual != NULL)
  {
    if (ra == actual->ra)
    {
      break;
    }
    prev = actual;
    if (ra < actual->ra)
    {
      actual = actual->esq;
    }
    else
    {
      actual = actual->dir;
    }
  }

  if (actual == prev)
  {
    return NULL;
  }

  return prev;
}

NoArvore *buscar(NoArvore *raiz, int ra)
{
  if (raiz == NULL)
    return NULL;

  if (ra == raiz->ra)
  {
    return raiz;
  }

  NoArvore *nextToSearch = ra > raiz->ra ? raiz->dir : raiz->esq;

  NoArvore *found = buscar(nextToSearch, ra);
  return found;
}

NoArvore *sucessor(NoArvore *raiz, int ra)
{
  NoArvore *item = buscar(raiz, ra);
  if (raiz == NULL || item == NULL)
  {
    return NULL;
  }

  if (item->dir != NULL)
  {
    return menor(item->dir);
  }

  NoArvore *itemParent = buscarPai(raiz, ra);
  if (itemParent == NULL)
  {
    return NULL;
  }

  int prevKey = ra;
  int smallKey = menor(itemParent->dir)->ra;

  while (smallKey <= ra)
  {
    if (prevKey < itemParent->ra)
    {
      return itemParent;
    }

    prevKey = itemParent->ra;
    itemParent = buscarPai(raiz, itemParent->ra);

    if (itemParent == NULL)
    {
      return NULL;
    }
    smallKey = menor(itemParent->dir)->ra;
  }

  return itemParent;
}

//

FindWithComparassionCountResult findWithComparassionCount(NoArvore *raiz, int ra)
{
  if (raiz == NULL)
    return (FindWithComparassionCountResult){0, NULL};

  if (ra == raiz->ra)
  {
    return (FindWithComparassionCountResult){1, raiz};
  }

  NoArvore *nextToSearch = ra > raiz->ra ? raiz->dir : raiz->esq;

  FindWithComparassionCountResult found = findWithComparassionCount(nextToSearch, ra);
  found.operationCount++;
  return found;
}

// SD
NoArvore *simpleRightRotation(NoArvore *root)
{
  NoArvore *pivot = root->esq;
  NoArvore *temp = pivot->dir;

  pivot->dir = root;
  root->esq = temp;
  // printf("[x=%d y=%d z=%d]\n", pivot->esq->ra, pivot->ra, root->ra);
  return pivot;
}

// SE
NoArvore *simpleLeftRotation(NoArvore *root)
{
  NoArvore *pivot = root->dir;
  NoArvore *temp = pivot->esq;

  pivot->esq = root;
  root->dir = temp;

  // printf("[x=%d y=%d z=%d]\n", pivot->esq->ra, pivot->ra, root->ra);
  return pivot;
}

// DE
NoArvore *doubleLeftRotation(NoArvore *root)
{
  root->dir = simpleRightRotation(root->dir);
  root = simpleLeftRotation(root);

  return root;
}

// DD
NoArvore *doubleRightRotation(NoArvore *root)
{
  root->esq = simpleLeftRotation(root->esq);
  root = simpleRightRotation(root);

  return root;
}

int alturaRec(NoArvore *n)
{
  if (n == NULL)
  {
    return 0;
  }

  int altEsquerda = alturaRec(n->esq);
  int altDiretira = alturaRec(n->dir);

  return 1 + (altEsquerda > altDiretira ? altEsquerda : altDiretira);
}

NoArvore *allocNode(int ra, int nota, int altura)
{
  NoArvore *newNode = malloc(sizeof(NoArvore));
  newNode->altura = altura;
  newNode->ra = ra;
  newNode->nota = nota;
  newNode->esq = NULL;
  newNode->dir = NULL;
  return newNode;
}

int balancedFactor(NoArvore *raiz)
{
  if (raiz == NULL)
    return 0;
  return alturaRec(raiz->esq) - alturaRec(raiz->dir);
}

int testAVL(NoArvore *raiz, int valor)
{
  if (raiz == NULL)
    return 1;

  int result = balancedFactor(raiz);
  result = result < 0 ? result * -1 : result; // Modulo

  NoArvore *nextToSearch = valor > raiz->ra ? raiz->dir : raiz->esq;
  int resultRec = testAVL(nextToSearch, valor);

  return result <= 1 && resultRec == 1 ? 1 : 0;
}

NoArvore *getDesbalancedNode(NoArvore *root)
{
  if (root == NULL)
    return NULL;

  int result = balancedFactor(root);

  NoArvore *desbalancedLeft = getDesbalancedNode(root->esq);
  NoArvore *desbalancedRight = getDesbalancedNode(root->dir);

  if (desbalancedLeft == NULL && desbalancedRight == NULL && (result < 0 ? result * -1 : result) > 1)
  {
    return root;
  }
  return desbalancedLeft != NULL ? desbalancedLeft : desbalancedRight;
}

NoArvore *balanceTree(NoArvore *root)
{
  if (balancedFactor(root) > 1)
  {
    if (balancedFactor(root->esq) >= 0)
    {
      printf("[Rotacao: SD]\n");
      root = simpleRightRotation(root);
      printf("[x=%d y=%d z=%d]\n", root->esq->ra, root->ra, root->dir->ra);
      return root; // Rotação simples
    }
    else
    {
      printf("[Rotacao: DD]\n");
      root = doubleRightRotation(root);
      printf("[x=%d y=%d z=%d]\n", root->esq->ra, root->ra, root->dir->ra);
      return root;
    }
  }
  if (balancedFactor(root) < -1)
  {
    if (balancedFactor(root->dir) <= 0)
    {
      printf("[Rotacao: SE]\n");
      root = simpleLeftRotation(root);
      printf("[x=%d y=%d z=%d]\n", root->esq->ra, root->ra, root->dir->ra);
      return root; // Rotação simples
    }
    else
    {
      printf("[Rotacao: DE]\n");
      root = doubleLeftRotation(root);
      printf("[x=%d y=%d z=%d]\n", root->esq->ra, root->ra, root->dir->ra);
      return root;
    }
  }
}

NoArvore *balance(NoArvore *raiz)
{
  NoArvore *desbalancedNode = getDesbalancedNode(raiz);
  if (desbalancedNode == NULL)
  {
    printf("[Ja esta balanceado]\n");
  }
  else
  {
    while (desbalancedNode != NULL)
    {
      printf("[No desbalanceado: %d]\n", desbalancedNode->ra);
      if (raiz == desbalancedNode)
      {
        raiz = balanceTree(desbalancedNode);
      }
      else
      {
        NoArvore *parent = buscarPai(raiz, desbalancedNode->ra);
        if (parent->ra < desbalancedNode->ra)
        {
          parent->dir = balanceTree(desbalancedNode);
        }
        else
        {
          parent->esq = balanceTree(desbalancedNode);
        }
      }
      desbalancedNode = getDesbalancedNode(raiz);
    }
  }

  return raiz;
}

NoArvore *inserir(NoArvore *raiz, int ra, int nota)
{
  int altura = 1;
  if (raiz == NULL)
  {
    raiz = allocNode(ra, nota, altura);
  }
  else
  {
    NoArvore *actual = raiz;
    while (actual != NULL)
    {
      altura++;
      if (actual->ra == ra)
      {
        actual->nota = nota;
        break;
      }
      NoArvore *temp = ra > actual->ra ? actual->dir : actual->esq;

      if (temp == NULL && ra > actual->ra)
      {
        actual->dir = allocNode(ra, nota, altura);
        break;
      }

      if (temp == NULL && ra < actual->ra)
      {
        actual->esq = allocNode(ra, nota, altura);
        break;
      }

      actual = temp;
    }
  }
  NoArvore *desbalancedNode = getDesbalancedNode(raiz);
  if (desbalancedNode == NULL)
  {
    printf("[Ja esta balanceado]\n");
  }
  else
  {
    printf("[No desbalanceado: %d]\n", desbalancedNode->ra);
    if (raiz == desbalancedNode)
      return balanceTree(desbalancedNode);
    else
    {
      NoArvore *parent = buscarPai(raiz, desbalancedNode->ra);
      if (parent->ra < desbalancedNode->ra)
      {
        parent->dir = balanceTree(desbalancedNode);
      }
      else
      {
        parent->esq = balanceTree(desbalancedNode);
      }
    }
  }
  return raiz;
}

void liberar_arvore(NoArvore *raiz)
{
  if (raiz == NULL)
    return;
  liberar_arvore(raiz->esq);
  liberar_arvore(raiz->dir);
  free(raiz);
}

NoArvore *remover(NoArvore *raiz, int ra)
{
  NoArvore *toRemove = buscar(raiz, ra);
  if (raiz == NULL || toRemove == NULL)
  {
    raiz = balance(raiz);
    return raiz;
  }
  NoArvore *toRemoveParent = buscarPai(raiz, ra);

  if (toRemoveParent == NULL) // é a raiz
  {
    if (toRemove->dir == NULL && toRemove->esq == NULL) // Se nó é folha
    {
      raiz = NULL;
    }
    else if (!(toRemove->dir != NULL && toRemove->esq != NULL))
    {
      raiz = toRemove->dir != NULL ? toRemove->dir : toRemove->esq;
    }
    else if (toRemove->dir != NULL && toRemove->esq != NULL)
    {
      NoArvore *suc = sucessor(raiz, ra);
      NoArvore *sucParent = buscarPai(raiz, suc->ra);

      int strCompare = sucParent->ra - suc->ra;
      if (strCompare < 0)
        sucParent->dir = NULL;
      else
        sucParent->esq = NULL;

      raiz = suc;

      if (suc->esq == NULL)
        suc->esq = toRemove->esq;
      if (suc->dir == NULL)
        suc->dir = toRemove->dir;
    }
  }
  else
  {
    int toRemoveParentStrCompare = toRemoveParent->ra - ra;

    // Se nó é folha
    if (toRemove->dir == NULL && toRemove->esq == NULL)
    {
      if (toRemoveParentStrCompare < 0)
      {
        toRemoveParent->dir = NULL;
      }
      else
      {
        toRemoveParent->esq = NULL;
      }
    }
    // Se nó tem um filho
    if (toRemove->dir != NULL && toRemove->esq == NULL)
    {
      if (toRemoveParentStrCompare < 0)
      {
        toRemoveParent->dir = toRemove->dir;
      }
      else
      {
        toRemoveParent->esq = toRemove->dir;
      }
    }

    // Se nó tem um filho
    if (toRemove->dir == NULL && toRemove->esq != NULL)
    {
      if (toRemoveParentStrCompare < 0)
      {
        toRemoveParent->dir = toRemove->esq;
      }
      else
      {
        toRemoveParent->esq = toRemove->esq;
      }
    }

    // Se nó tem dois filhos
    if (toRemove->dir != NULL && toRemove->esq != NULL)
    {
      NoArvore *suc = sucessor(raiz, ra);
      NoArvore *sucParent = buscarPai(raiz, suc->ra);

      int strCompare = sucParent->ra - suc->ra;
      if (strCompare < 0)
      {
        sucParent->dir = NULL;
      }
      else
      {
        sucParent->esq = NULL;
      }

      if (toRemoveParentStrCompare < 0)
      {
        toRemoveParent->dir = suc;
      }
      else
      {
        toRemoveParent->esq = suc;
      }

      if (suc->esq == NULL)
        suc->esq = toRemove->esq;
      if (suc->dir == NULL)
        suc->dir = toRemove->dir;
    }
  }

  toRemove->dir = NULL;
  toRemove->esq = NULL;
  liberar_arvore(toRemove);

  raiz = balance(raiz);

  return raiz;
}

int altura(NoArvore *n)
{
  return alturaRec(n) - 1;
}

void print(NoArvore *raiz)
{
  if (raiz == NULL)
    return;
  print(raiz->esq);
  print(raiz->dir);
  printf("%d ", raiz->ra);
}

/**
 * @brief main
 *
 * @return int
 */
int main()
{
  NoArvore *raiz = NULL;
  char operacao;
  do
  {
    scanf(" %c", &operacao);
    switch (operacao)
    {
    case 'I':
    {
      int RA, nota;
      scanf(" %d %d", &RA, &nota);
      raiz = inserir(raiz, RA, nota);
      break;
    }
    case 'A':
    {
      printf("A=%d\n", altura(raiz));
      break;
    }
    case 'B':
    {
      int ra;
      scanf(" %d", &ra);
      FindWithComparassionCountResult resultadoBusca = findWithComparassionCount(raiz, ra);
      printf("C=%d Nota=%d\n", resultadoBusca.operationCount, resultadoBusca.node == NULL ? -1 : resultadoBusca.node->nota);
      break;
    }
    case 'R':
    {
      int ra;
      scanf(" %d", &ra);
      raiz = remover(raiz, ra);
      break;
    }
    case 'P':
    {
      printf("[");
      print(raiz);
      printf("]\n");
      liberar_arvore(raiz);
      break;
    }
    }
  } while (operacao != 'P');

  return 0;
}