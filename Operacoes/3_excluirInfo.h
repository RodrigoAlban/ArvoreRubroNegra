#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, pNohArvore sentinela, void *info, FuncaoComparacao fc){

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

    printf("\n ----------- Excluindo info: %d ---\n", *((int*)info));
    pNohArvore novaRaiz;
    novaRaiz = excluirInfoRecursivo(arvore->raiz, arvore->sentinela, info, pfc);
    if (novaRaiz != NULL){
        arvore->raiz      = novaRaiz;
        arvore->raiz->cor = BLACK;
        arvore->quantidadeNohs--;
    }
    else
        printf("\n --> Chave não encontrada! <--");

}

#endif
