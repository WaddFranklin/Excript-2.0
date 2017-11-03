#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "decript.h"
#include "key.h"
#include "UI.h"

short int title_screen_flag = 1;

void clear_screen () {

    system("clear");
}

void bye () {

    clear_screen();
    system("cowsay -f bud-frogs 'DONATE US! \(^u^)/   Agência: 1234 | Conta: 567890 | Caixa Federal Econômica do Brasil'");
}

short int is_valid_option (short int option) {

    return ((option == 1) || (option == 2) || (option == 3) || (option == 0));
}

void title_screen () {

    printf("\n\n              __________________________________________________\n");
    printf("             | ________________________________________________ |\n");
    printf("             |/     _______                  _                 \\|\n");
    printf("             ||    (_______)                (_)      _         ||\n");
    printf("             ||     _____   _   _ ____  ____ _ ____ | |_       ||\n");
    printf("             ||    |  ___) ( \\ / ) ___)/ ___) |  _ \\|  _)      ||\n");
    printf("             ||    | |_____ ) X ( (___| |   | | | | | |__      ||\n");
    printf("             ||    |_______|_/ \\_)____)_|   |_| ||_/ \\___)     ||\n");
    printf("             ||                               |_|              ||\n");
    printf("             |\\________________________________________________/|\n");
    printf("             |__________________________________________________|\n\n");

    printf("\n\n\t          ----- Pressione ENTER para iniciar -----\n\n");

    printf("\n\n                         --- Desenvolvido por ---\n\n");
    printf("         França Macdowell   |   John Victor   |   Waddinsohn Franklin\n\n");

    getchar();
}

void print_option_1 () {

    printf(" _     ____                       ____        _      _  __          \n");
    printf("/ |   / ___| ___ _ __ __ _ _ __  |  _ \\ _   _| |__  | |/ /___ _   _ \n");
    printf("| |  | |  _ / _ \\ '__/ _` | '__| | |_) | | | | '_ \\ | ' // _ \\ | | |\n");
    printf("| |_ | |_| |  __/ | | (_| | |    |  __/| |_| | |_) || . \\  __/ |_| |\n");
    printf("|_(_) \\____|\\___|_|  \\__,_|_|    |_|    \\__,_|_.__(_)_|\\_\\___|\\__, |\n");
    printf("                                                              |___/ \n\n");
}

void print_menu (short int *option) {

    printf("                        _____               _       _           \n");
    printf("                       | ____|_  _____ _ __(_)_ __ | |_         \n");
    printf("                _____  |  _| \\ \\/ / __| '__| | '_ \\| __|  _____ \n");
    printf("               |_____| | |___ >  < (__| |  | | |_) | |_  |_____|\n");
    printf("                       |_____/_/\\_\\___|_|  |_| .__/ \\__|        \n");
    printf("                                             |_|                \n\n");
    printf("        ---------------------------------------------------------------\n\n");

    printf(" \t\t\t    1. Gerar Chave Pública\n\n");
    printf(" \t\t\t    2. Criptografar\n\n");
    printf(" \t\t\t    3. Descriptografar\n\n");
    printf(" \t\t\t    0. Sair\n\n");

    printf(" \t\t\t    Entre com uma das opções: > ");
    scanf("%hd", option);
    getchar();
}

void execute_option (short int option) {

    char decision = '*';

    switch (option) {

        case 1:
            clear_screen();
            gerarKey();
            break;
        case 2:
            clear_screen();
            puts("Criptografar\n");
            break;
        case 3:
            clear_screen();
            decript();
            break;
        case 0:
            clear_screen();

            printf("   ___     __       _      \n");
            printf("  / _ \\   / _\\ __ _(_)_ __ \n");
            printf(" | | | |  \\ \\ / _` | | '__|\n");
            printf(" | |_| |  _\\ \\ (_| | | |   \n");
            printf("  \\___(_) \\__/\\__,_|_|_|   \n\n");

            printf(" Tem certeza que deseja sair? [S/N] > ");
            scanf("%c", &decision);
            decision = toupper(decision);
            getchar();

            while (!((decision == 'S') || (decision == 'N'))) {

                clear_screen();
                printf(" Entrada inválida! \n\n Entre com -S- para SIM ou -N- para NÃO > ");
                scanf("%c", &decision);
                decision = toupper(decision);
                getchar();
            }

            if (decision == 'S') {

                bye();
                exit(0);
            }
            else {
                clear_screen();
                main_menu();
            }
            break;
        default:
            break;
    }
}

void continue_or_finish () {

    char decision = '*';

    printf("Deseja realizar mais alguma operação? [S/N] > ");
    scanf("%c", &decision);
    decision = toupper(decision);
    getchar();

    while (!((decision == 'S') || (decision == 'N'))) {

        clear_screen();
        printf(" Entrada inválida! \n\n Entre com -S- para SIM ou -N- para NÃO > ");
        scanf("%c", &decision);
        decision = toupper(decision);
        getchar();
    }

    if (decision == 'N') {
        bye();
        exit(0);
    }
    else {
        clear_screen();
        main_menu();
    }
}

void main_menu() {

    short int option = -1;

    if (title_screen_flag) {
        title_screen();
        title_screen_flag = 0;
    }

    clear_screen();
    print_menu(&option);

    while (!(is_valid_option(option))) {

        clear_screen();
        printf("   Esta opção é inválida! u_u'   Leia direito e entre com uma opção válida!\n\n");
        print_menu(&option);
    }

    execute_option(option);
    continue_or_finish();
}
