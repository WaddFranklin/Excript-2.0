
/*
 * Verifica se um número e é coprimo em relação
 * a pq. Recebe o valor do expoente 'e' e (p - 1)*(q - 1).
 * retorna 1 se forem coprimos e 0 caso contrário.
 */
int isCoprime(int e, int pq);

/*
 * Verivica se o número é primo ou não. Recebe um inteiro
 * prime. Retorna 1 caso seja primo e 0 caso contrário.
 */
int isPrime(int prime);

/*
 * Chama as funções para gerar a chave pública. Sem parâmetros.
 * Não retorna nada.
 */
void gerarKey();
