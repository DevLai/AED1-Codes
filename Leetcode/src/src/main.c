#include <stdio.h>

int minSecondsToFill(int quantidade[3]) {
    int totalSeconds = 0;

    // Enquanto houver algum copo que precisa ser enchido
    while (quantidade[0] > 0 || quantidade[1] > 0 || quantidade[2] > 0) {
        // Encha 2 copos de tipos diferentes (se possível)
        if (quantidade[0] + quantidade[1] + quantidade[2] >= 2) {
            totalSeconds++;
            // Reduza a quantidade de copos enchidos
            quantidade[0] -= 1;
            quantidade[1] -= 1;
            quantidade[2] -= 1;
        } else {
            // Encha 1 copo de qualquer tipo
            for (int i = 0; i < 3; i++) {
                if (quantidade[i] > 0) {
                    totalSeconds++;
                    quantidade[i] -= 1;
                    break;
                }
            }
        }
    }

    return totalSeconds;
}

int main() {
    int quantidade[3];
    
    // Preencha a matriz com os valores de entrada
    for (int i = 0; i < 3; i++) {
        printf("Digite a quantidade de copos de água do tipo %d: ", i);
        scanf("%d", &quantidade[i]);
    }

    int result = minSecondsToFill(quantidade);
    printf("O número mínimo de segundos necessários é: %d\n", result);

    return 0;
}

