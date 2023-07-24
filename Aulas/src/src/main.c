#include <stdio.h>

const int MAX = 10;

struct Aluno {
    int ra;
    char nome[50];
};

struct Pilha {
    struct Aluno alunos[MAX]; 
    int topo;
    int base;
    int limite;
};

void Listar(struct Pilha *pilha) { 
    if (pilha->topo == pilha->base) {
        printf("A pilha esta vazia.\n");
        return;
    }

    printf("Conteudo da pilha:\n");

    for (int i = pilha->topo - 1; i >= pilha->base; i--) {
        printf("RA: %d\tNome: %s\n", pilha->alunos[i].ra, pilha->alunos[i].nome);
    }
}

int main() {
    
    struct Pilha pilha;
    pilha.topo = 0;
    pilha.base = 0;
    pilha.limite = MAX;
    
    struct Aluno aluno1 = {123, "Joao"};
    struct Aluno aluno2 = {456, "Maria"};

    pilha.alunos[pilha.topo++] = aluno1;
    pilha.alunos[pilha.topo++] = aluno2;

    Listar(&pilha);

    return 0;
}
