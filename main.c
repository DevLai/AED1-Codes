#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
===============================================================================
Struct para uma hashtable que vai armazenar os valores e a contagem
===============================================================================
*/
struct hashtable {
    int valor;
    int count;
};

/*
===============================================================================
Função de comparação para o qsort que também vai ordenar de forma decrescente
===============================================================================
*/
int compararhash(const void *a, const void *b) {
    return ((struct hashtable *)b)->count - ((struct hashtable *)a)->count;
}

/*
===============================================================================
Função de comparação para o qsort
===============================================================================
*/
int comparar(const void *a, const void *b) {
    return *(const int *)a - *(const int *)b;
}

/*
===============================================================================
Função para encontrar os k elementos mais frequentes em um array de inteiros
===============================================================================
*/
int *topKFrequent(int *nums, int numsSize, int k, int *returnSize) {

/*
===============================================================================
Malloc de memória para o array de saída
===============================================================================
*/

    int *array = malloc(k * sizeof(int));

/*
===============================================================================
Struct de hashtable que vai contar a frequência dos valores
===============================================================================
*/

    struct hashtable hash[numsSize];
    memset(hash, 0, sizeof(struct hashtable) * numsSize);

    int i;
    int count = 1;
    *returnSize = k;

/*
===============================================================================
Contar a frequência dos valores e armazenar na hashtable
===============================================================================
*/

    for (i = 1; i < numsSize; i++) {
        if (hash[count - 1].valor == nums[i]) {
            hash[count - 1].count++;
        } else {
            count++;
            hash[count - 1].valor = nums[i];
            hash[count - 1].count++;
        }
    }

/*
===============================================================================
Ordenar o array de entrada
===============================================================================
*/
    qsort(nums, numsSize, sizeof(int), comparar);

    hash[0].valor = nums[0];
    hash[0].count++;

/*
===============================================================================
Ordenar a hashtable pela contagem em ordem decrescente
===============================================================================
*/

    qsort(hash, count, sizeof(hash[0]), compararhash);

/*
===============================================================================
Preencher o array de saída com os k elementos mais frequentes
===============================================================================
*/

    for (i = 0; i < k; i++) {
        array[i] = hash[i].valor;
    }

    return array;
}

/*
===============================================================================
Função principal
===============================================================================
*/
int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int numsSize = 6;
    int k = 2;
    int returnSize;
    int *result = topKFrequent(nums, numsSize, k, &returnSize);

    printf("Os %d elementos mais frequentes são: ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    
/*
===============================================================================
Liberar a memória alocada para o resultado
===============================================================================
*/

    free(result);

    return 0;
}
