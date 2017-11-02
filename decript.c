
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define STR_SIZE 100000

long int search_inverse_mod (long int e, long int module) {

    if (module == 1) {

        return ((-1) * (e / module));
    }
    else {
        return search_inverse_mod(module, e % module);
    }
}

long int extract_root_mod (long int M, long int d) {

    return pow(M, d);
}

void print_decrypted_text (char *str, long int d) {

    int i;
    long int number;
    int count = 0;
    char str_aux[3];

    for (i = 0 ; i < strlen(str) ; i++) {

        str_aux[count++] = str[i];

        if (count == 3) {

            number = atoi(str_aux);
            number = extract_root_mod(number, d);
            printf("%c", number);
            count = 0;
            i++;
        }
    }

    printf("\n\n");
    return;
}

void decript () {

    char encrypted_text[STR_SIZE];
    long int p, q, e, d, module;

    // ler o 'p', 'q' e o 'e' de um arquivo
    module = (p - 1) * (q - 1);
    d = search_inverse_mod(e, module);

    printf("Digite a mensagem codificada:\n\n > ");
    scanf("%[^\n]s", encrypted_text);
    getchar();

    print_decrypted_text(encrypted_text, d);
    return;
}
