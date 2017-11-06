/*
 * Calcula o inverso_modular de 'e' módulo 'n'. Recebe o expoente 'e'
 * e o Coeficiente de Euler 'n'. Retorna o inverso modular.
 */
long int modular_inverse (long int e, long int n);

/*
 * Calcula a potência de (base ^ exponent) % momdulo de forma mais
 * eficiente. Recebe a base da potenciação, o expoente e o módulo.
 * retorna o resultado da potenciação mod módulo.
 */
long int exp_mod (long int base, long int exponent, long int modulo);

/*
 * Escreve o texto desencriptado na tela. Recebe a string com o texto
 * codificado, o inverso modular 'd' e a chave pública N = p*q.
 * Não retorna nada.
 */
void print_decrypted_text (char *str, long int d, long int N);

/*
 * Chama as funções necessárias para descriptografar uma mensagem.
 * Sem parâmetros. Não retorna nada.
 */
void decript ();
