#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura TreeNode_t
struct TreeNode_t {
    int val;
    struct TreeNode_t* esquerda;
    struct TreeNode_t* direita;
};

/*
===============================================================================
findDif
 Função auxiliar para encontrar o segundo valor mínimo diferente de um dado valor
===============================================================================
*/
int findDif_r( struct TreeNode_t* root, int val ) {
    if ( root == NULL )
        return -1;

    if ( root->val != val )
        return root->val;

    int leftValue = findDif_r( root->esquerda, val );
    int rightValue = findDif_r( root->direita, val );

    if ( leftValue == -1 )
        return rightValue;

    if ( rightValue == -1 )
        return leftValue;

    return fmin( leftValue, rightValue );
}

/*
===============================================================================
findSecondMinimumValue
Função principal para encontrar o segundo valor mínimo diferente
===============================================================================
*/

int findSecondMinimumValue( struct TreeNode_t* root ) {
    // Vai chamar a função findDif_r com a raiz da árvore e o valor da raiz
    return findDif_r(root, root->val);
}

int main() {
    // Criar a árvore de exemplo: [2, 2, 5, null, null, 5, 7]
    struct TreeNode_t* root = ( struct TreeNode_t*)malloc(sizeof( struct TreeNode_t ) );
    root->val = 2;
    root->esquerda = ( struct TreeNode_t* )malloc( sizeof( struct TreeNode_t ) );
    root->esquerda->val = 2;
    root->esquerda->esquerda = NULL;
    root->esquerda->direita = NULL;
    root->direita = ( struct TreeNode_t* )malloc( sizeof( struct TreeNode_t ) );
    root->direita->val = 5;
    root->direita->esquerda = NULL;
    root->direita->direita = ( struct TreeNode_t* )malloc( sizeof( struct TreeNode_t ) );
    root->direita->direita->val = 7;
    root->direita->direita->esquerda = NULL;
    root->direita->direita->direita = NULL;

    int result = findSecondMinimumValue( root );
    printf( "Second minimum value: %d\n", result ); // output vai ser 5

    return 0;
}
