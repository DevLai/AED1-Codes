int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // struct pra uma hashtable que vai aarmazenar os valores e o count
    struct hashtable {
        int valor;
        int count;
    };

     // Função de comparação pro qsort que tbm vai ordenar de forma decrescente
    int compararhash(const void *a, const void *b) {
        return ((struct hashtable *)b)->count - ((struct hashtable *)a)->count;
    }


    // Função de comparação pro qsort
    int comparar(const void *a, const void *b) {
        return *(const int *)a - *(const int *)b;
    }


    // malloc de memória pro array de saída
    int *array = malloc(k * sizeof(int));

    // struct de hashtable que vai contar a frequência dos valores
    struct hashtable hash[numsSize];
    memset(hash, 0, sizeof(struct hashtable) * numsSize); // eu tentei fazer essa parte com sizeof,
    //mas não estava conseguindo e o código sempre retornava erro, então pesquisei uma outra alternativa e descobri o memset

    int i;
    int count = 1;
    *returnSize = k;

   

    // Contar a frequência dos valores e armazenar na hashtable
    for (i = 1; i < numsSize; i++) {
        if (hash[count - 1].valor == nums[i]) {
            hash[count - 1].count++;
        } else {
            count++;
            hash[count - 1].valor = nums[i];
            hash[count - 1].count++;
        }
    }
     // Ordenar o array de entrada
    qsort(nums, numsSize, sizeof(int), comparar);

    hash[0].valor = nums[0];
    hash[0].count++;

    // Ordenar a hashtable pela contagem em ordem decrescente
    qsort(hash, count, sizeof(hash[0]), compararhash);

    // Preencher o array de saída com os k elementos mais frequentes
    for (i = 0; i < k; i++) {
        array[i] = hash[i].valor;
    }

    return array;
}

