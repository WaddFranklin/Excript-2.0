#include <string.h>
#include <stdio.h>
#include <math.h>

unsigned int expo(unsigned int a, unsigned int b){
  int result = 1;

  while (b){
    if (b%2==1){
      result *= a;
    }
    b /= 2;
    a *= a;
  }

  return result;
}

void writeEncryptedTxt(unsigned int encriptedMessage[], int size){

  FILE *f = fopen("/home/franca/Downloads/encripted.txt", "w");
  if (f == NULL){

    printf("Erro ao abrir arquivo!\n");
  }

  int i;

  for(i = 0 ; i < size ; i++){
    fprintf(f, "%03d", encriptedMessage[i]);

    if(!(i+1 == size)){
      fprintf(f, " ");
    }
  }
  fclose(f);
}

void encript(){

  char message[100000];
  unsigned int publicKey, e_number;
  printf("Digite a mensagem que deseja encriptar: ");
  scanf("%[^\n]s", message);
  getchar();

  printf("Digite sua chave pública: ");
  scanf("%d", &publicKey); // read publicKey N to calculate [ASCII]^e % N
  printf("Digite seu número e: "); // read number e to calculate [ASCII]^e % N
  scanf("%d", &e_number);

  unsigned int i;
  int messageSize = strlen(message);
  unsigned int encriptedMessage[messageSize];

  for(i = 0 ; i < messageSize ; i++){
    encriptedMessage[i] = expo(message[i], e_number) % publicKey;
  }

  writeEncryptedTxt(encriptedMessage, messageSize);
}

int main(){

//Saber como será passado o numero -> e <-
  encript();

  return 0;
}
