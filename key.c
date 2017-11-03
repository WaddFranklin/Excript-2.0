#include <stdio.h>
#include <math.h>
#include "UI.h"

int isPrime(int prime){
  int i;

  for(i = 2; i <= sqrt(prime); i++){

    if(prime%i == 0){
      return 0;
    }

  }
  return 1;
}

int isCoprime(int e, int pq){

    if(pq == 0){

      if(e == 1){
        return 1;
      }

      return 0;
    }

    return isCoprime(pq, e % pq);
}


void gerarKey(){

  int primo1, primo2, e, pq;

  while(1){
    print_option_1();
    while(1){

        printf("Digite o valor do primo P:\n");
        scanf("%d", &primo1);
        getchar();

      if(isPrime(primo1)){
        break;
      }

        printf("O valor digitado de P não é primo!");
        getchar();
        clear_screen();
    }

    while(1){

        printf("Digite o valor do primo Q:\n");
        scanf("%d", &primo2);
        getchar();

      if(isPrime(primo2)){
        break;
      }

        printf("O valor digitado de Q não é primo,\nAperte qualquer tecla para digitar outro valor de Q");
        getchar();
        clear_screen();
    }

    pq = primo1 * primo2;

    if(pq > 256){
      break;
    }

    printf("O valor de P*Q precisa ser maior que 256,\nAperte qualquer tecla para digitar outros valores de P e Q");
    getchar();
    clear_screen();
  }

  while(1){

        printf("Digite o valor do expoente:\n");
        scanf("%d", &e);
        getchar();

    if(isCoprime(e, (primo1-1)*(primo2-1))){
        break;
    }

    printf("O valor digitado não é Coprimo a (p-1)(q-1),\nAperte qualquer tecla para digitar outro valor");
    getchar();
    clear_screen();
}

    FILE *pf, *private_key;
    pf = fopen("public_key.txt", "wt");
    fprintf(pf,"O valor de N = P*Q é %d e o valor do expoente é %d", pq, e);
    fclose(pf);

    private_key = fopen("private_key.txt", "wt");
    fprintf(private_key, "p = %d\nq = %d\ne = %d", primo1, primo2, e);
    fclose(private_key);

    printf("Chave Pública gerada!\n");
}
