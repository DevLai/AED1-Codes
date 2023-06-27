#include <stdio.h>

int main(){

float lenght, width, height, mass, volume;

printf("Digite comprimento: ");
scanf("%f", &lenght);

printf("Digite largura: ");
scanf("%f", &width);

printf("Digite peso: ");
scanf("%f", &mass);

volume = lenght * width * height;



if(lenght && width && height && mass >= 10^6 || volume == 10^9){
    printf("É volumoso\n");
}
else if(mass>=100){
    printf("É pesado\n");
}
// me perdi na lógica, depois termino

return 0;

}