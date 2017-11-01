#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
/*
 * Recebe o expoente "e" e "module" (= (p - 1)*(q - 1)).
 * Retorna o inverso de "e" módulo "module".
 */
long int search_inverse_mod (long int e, long int module);

/*
 * Recebe o valor do caractere criptografado "M" e o inver-
 * so do expoente "e" módulo "N". Retorna o valor do ca-
 * ractere decifrado m dado por M = m ^ (d * e) pela fór-
 * mula de Euler.
 */
long int extract_root_mod (long int M, long int d);

/*
 * Chama as funções necessárias para decifrar a mensagem
 * criptografada. ... . Não retorna nada;
 */
void decript ();
