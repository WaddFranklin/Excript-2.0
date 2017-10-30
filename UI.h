/*
 * Limpa a tela do console. Sem parâmetros. Não retorna nada
 */
void clear_screen ();

/*
 * Verifica se a opção digitada pelo usuário é válida. Recebe
 * option. Retorna 1 caso seja uma opção válida e 0 caso con-
 * trário.
 */
short int is_valid_option (short int option);

/*
 * Exibe a tela de título do programa. Sem parâmetros. Não
 * retorna nada.
 */
void title_screen ();

/*
 * Imprime o menu principal. Recebe um ponteiro para option
 * para controlar a continuidade ou não do programa. Não
 * retorna nada.
 */
void print_menu (short int *option);

/*
 * Executa a funcionalidade escolhida pelo usuário. Recebe
 * option (a opção selecionada). Não retorna nada.
 */
void execute_option (short int option);

/*
 * Exibe uma mensagem ao usuário perguntando se deseja rea-
 * lizar mais alguma operação. Sem parâmetros. Não retorna
 * nada.
 */
void continue_or_finish ();

/*
 * Exibe uma mensagem de encerramento do programa. Sem
 * parâmetros. Não retorna nada.
 */
void bye ();

/*
 * Chama as funções necessárias para a exibição da interface
 * do usuário. Sem parâmetros. Não retorna nada.
 */
void main_menu ();
