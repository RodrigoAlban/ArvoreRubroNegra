#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, pNohArvore sentinela, void *info, FuncaoComparacao fc)
{
    // caso base 1
    if (raiz == NULL || raiz == sentinela)
        return NULL;

    // caso base 2
    if (fc(raiz->info, info) == 0)
    {
        // caso base 2.1
        printf("Achou");
        if (raiz->cor == BLACK)
        {
            pNohArvore filhoEsq = raiz->esquerda;
            pNohArvore filhoDir = raiz->direita;
            pNohArvore paiRaiz = raiz->pai;

            free(raiz);

            // caso base 2.1.1
            if (filhoEsq == sentinela || filhoDir == sentinela)
            {
                if (filhoEsq != sentinela)
                {
                    filhoEsq->cor = BLACK;
                    return filhoEsq;
                }
                else
                {
                    filhoDir->cor = BLACK;
                    return filhoDir;
                }
            }
        }
    }

    // caso recursivo
    pNohArvore novoNoh = NULL;
    if (fc(raiz->info, info) < 0)
    {
        novoNoh = excluirInfoRecursivo(raiz->esquerda, sentinela, info, fc);
        if (novoNoh != NULL)
            raiz->esquerda = novoNoh;
        else
            return NULL;
    }
    else
    {
        novoNoh = excluirInfoRecursivo(raiz->direita, sentinela, info, fc);
        if (novoNoh != NULL)
            raiz->direita = novoNoh;
        else
            return NULL;
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{

    printf("\n ----------- Excluindo info: %d ---\n", *((int *)info));
    pNohArvore novaRaiz;
    novaRaiz = excluirInfoRecursivo(arvore->raiz, arvore->sentinela, info, pfc);
    if (novaRaiz != null)
    {
        arvore->raiz = novaRaiz;
        arvore->raiz->cor = BLACK;
        arvore->quantidadeNohs--;
    }
    else
        printf("\n --> Chave não encontrada! <--");
}

#endif
