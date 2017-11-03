#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define STR_SIZE 100000

int search_inverse_mod (int e, int module) {

    if (module == 1) {

        return ((-1) * (e / module));
    }
    else {
        return search_inverse_mod(module, e % module);
    }
}

int extract_root_mod (int M, int d) {

    return pow(M, d);
}

void print_decrypted_text (char *str, int d) {

    int i;
    int number;
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
    int p, q, e, d, module;

    printf("Digite os valores de 'p', 'q' e 'e' da sua chave privada:\n\n");
    printf("p = ");
    scanf("%d", &p);

    printf("\nq = ");
    scanf("%d", &q);

    printf("\ne = ");
    scanf("%d", &e);

    module = (p - 1) * (q - 1);
    d = search_inverse_mod(e, module);

    printf("Digite a mensagem codificada:\n\n > ");
    scanf("%[^\n]s", encrypted_text);
    getchar();

    print_decrypted_text(encrypted_text, d);
    return;
}
