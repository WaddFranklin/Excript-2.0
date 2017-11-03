/*
* Recebe array de inteiros com o valor de cada letra encriptada.
 * Recebe o tamanho da string.
 */
void writeEncryptedTxt(unsigned int encriptedMessage[], int size);

/*
 *Recebe o número e que será utilizado junto com a chave pública para encriptar os caracteres baseados
 *no número da tabela ASCII.
 */
void encript(long int e);

/*
 *Recebe dois números inteiros, que será feito a exponenciação de a^b
 */
unsigned int expo(unsigned int a, unsigned int b);
