#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int modular_inverse (long int e, long int n) {

    int i;

    for (i = 0 ; i <= (n - 1) ; i++) {

        if (((e * i) % n) == 1) {
            return i;
        }
    }
    return -1;
}

long int exp_mod (long int base, long int exponent, long int modulo) {

    long int x;

    if (exponent == 0) {
        return 1;
    }

    if (exponent == 1) {
        return base;
    }

    if ((exponent % 2) == 0) {

        x = exp_mod(base, exponent / 2, modulo) % modulo;
        return (x * x) % modulo;
    }
    else {

        return (base * exp_mod(base, exponent - 1, modulo)) % modulo;
    }
}

void print_decrypted_text (char *str, long int d, long int N) {

    int i;
    int j = 0;
    long int number;
    char str_aux[256];

    for (i = 0 ; i < strlen(str) ; i++) {

        if (str[i] != ' ') {

            str_aux[j++] = str[i];
        }
        else {
            str_aux[j] = '\0';
            number = atoi(str_aux);
            number = exp_mod(number, d, N);
            printf("%c", number);
            j = 0;
        }
    }
    printf(" ---\n\n");
}

void decript () {

    printf(" _____    ____                                 _       _             \n");
    printf("|___ /   |  _ \\  ___  ___  ___ _ __   ___ _ __(_)_ __ | |_ __ _ _ __ \n");
    printf("  |_ \\   | | | |/ _ \\/ __|/ _ \\ '_ \\ / __| '__| | '_ \\| __/ _` | '__|\n");
    printf(" ___) |  | |_| |  __/\\__ \\  __/ | | | (__| |  | | |_) | || (_| | |   \n");
    printf("|____(_) |____/ \\___||___/\\___|_| |_|\\___|_|  |_| .__/ \\__\\__,_|_|   \n");
    printf("                                                |_|                  \n\n");

    long int p, q, e, N, n, d;
    char encrypted_txt[256];

    printf("Digite o 'p' da chave privada: ");
    scanf("%ld", &p);

    printf("\nDigite o 'q' da chave privada: ");
    scanf("%ld", &q);

    printf("\nDigite o 'e' da chave privada: ");
    scanf("%ld", &e);
    getchar();

    N = p * q;
    n = (p - 1) * (q - 1);
    d = modular_inverse(e, n);

    printf("\nDigite a mensagem criptografada:\n > ");
    scanf("%[^\n]s", encrypted_txt);
    getchar();

    printf("\n--- ");
    print_decrypted_text(encrypted_txt, d, N);
}
