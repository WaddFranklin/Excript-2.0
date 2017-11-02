

/*
 * Exibe na tela a mensagem decifrada. Recebe um ponteiro para
 * a string com a mensagem criptografada e o
 * inverso de e módulo (p - 1)*(q - 1). Não retorna nada.
 */
void print_decrypted_text (char *str, long int d);

/*
 * Recebe o expoente "e" e "module" (= (p - 1)*(q - 1)).
 * Retorna o inverso de "e" módulo "module".
 */
long int search_inverse_mod (long int e, long int module);

/*
 * Recebe o valor do caractere criptografado "M" e o inver-
 * so do expoente "e" módulo (p - 1)*(q - 1). Retorna o valor do ca-
 * ractere decifrado m dado por M = m ^ (d * e) pela fór-
 * mula de Euler.
 */
long int extract_root_mod (long int M, long int d);

/*
 * Chama as funções necessárias para decifrar a mensagem
 * criptografada. Sem parâmetros. Não retorna nada.
 */
void decript ();
