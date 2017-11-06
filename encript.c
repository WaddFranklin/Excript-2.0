#include <string.h>
#include <stdio.h>
#include <math.h>
#include "decript.h"

void writeEncryptedTxt(unsigned int encriptedMessage[], int size){

  FILE *f = fopen("encripted.txt", "w");
  if (f == NULL){

    printf("Erro ao abrir arquivo!\n");
  }

  int i;

  for(i = 0 ; i < size ; i++){
    fprintf(f, "%d", encriptedMessage[i]);

    if(!(i+1 == size)){
      fprintf(f, " ");
    }
  }
  fprintf(f, " ");
  fclose(f);
}

void encript() {

    printf(" ____      _____                 _       _             \n");
    printf("|___ \\    | ____|_ __   ___ _ __(_)_ __ | |_ __ _ _ __ \n");
    printf("  __) |   |  _| | '_ \\ / __| '__| | '_ \\| __/ _` | '__|\n");
    printf(" / __/ _  | |___| | | | (__| |  | | |_) | || (_| | |   \n");
    printf("|_____(_) |_____|_| |_|\\___|_|  |_| .__/ \\__\\__,_|_|   \n");
    printf("                                  |_|                  \n\n");

  char message[100000];
  long int publicKey, e_number;
  printf("Digite a mensagem que deseja encriptar: ");
  scanf("%[^\n]s", message);
  getchar();

  printf("\nDigite sua chave pública: ");
  scanf("%ld", &publicKey); // read publicKey N to calculate [ASCII]^e % N
  getchar();
  printf("\nDigite seu número e: "); // read number e to calculate [ASCII]^e % N
  scanf("%ld", &e_number);
  getchar();

  unsigned int i;
  int messageSize = strlen(message);
  unsigned int encriptedMessage[messageSize];

  for(i = 0 ; i < messageSize ; i++){
    encriptedMessage[i] = exp_mod(message[i], e_number, publicKey);
  }

  writeEncryptedTxt(encriptedMessage, messageSize);
  printf("\nMensagem criptografada!\n\n");
}
