#ifndef _UI_H_
#define _UI_H_

#include "key.h"
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

  FILE *pf;
  pf = fopen("Key.txt", "wt");
  fprintf(pf,"O valor de P*Q é %d e o valor do expoente é %d", pq, e);

}

#endif
