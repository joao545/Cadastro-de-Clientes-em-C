#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente {    //Struct com variáveis nome e email que podem armazenar até 100 caracteres.
    char nome[100];
    char email[100];
};

int main(){
    struct Cliente clientes[100]; //Array para armazenar até 100 clientes
    int opcao, numClientes = 0; // Variável opcao para armazenar a opcao escolhida e numClientes sendo o contador de clientes.

    do{
        printf("Selecione uma opcao: \n");      //Menu de escolhas do usuário.
        printf("1 - Adicionar cliente: \n");
        printf("2 - Visualizar clientes: \n");
        printf("3 - Editar cliente: \n");
        printf("4 - Excluir cliente: \n");
        printf("5 - Sair \n\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
       case 1:  //Ler o nome e o e-mail do cliente, e adiciona na array Clientes
            printf("Digite o nome do cliente: ");
            scanf("%s", clientes[numClientes].nome);

            printf("Digite o email do cliente: ");
            scanf("%s", clientes[numClientes].email);

            numClientes++;

            printf("Cliente adicionado com sucesso. \n\n");
            break;
       
        case 2: {       //Exibe o nome de cada cliente cadastrado.
            printf("Clientes cadastrados: \n\n");   

            for (int i = 0; i < numClientes; i++){
                printf("Nome: %s \n", clientes[i].nome);
                printf("Email: %s \n", clientes[i].email);
                printf("----------------------------- \n\n");
            }
            break;
        }

        case 3: {   //Procura o cliente na array clientes e dá opção de editar tanto o nome quanto o e-mail.
            char nome[100];
        
            printf("Digite o nome do cliente que deseja editar: \n");
            scanf("%s", nome);

            for (int i = 0; i < numClientes; i++) {
                if(strcmp(clientes[i].nome, nome) == 0) {
                    printf("Digite o novo nome do cliente: ");
                    scanf("%s", clientes[i].nome);

                    printf("Digite o novo email do cliente: ");
                    scanf("%s", clientes[i].email);

                    printf("Cliente editado com sucesso. \n\n");
                   
                }
                 
            }
            break;
        }

        case 4: {   //Procura o nome do cliente na array clientes, caso encontrário o mesmo será excluído.
            char nome[100];

            printf("Digite o nome do cliente que deseja excluir: ");
            scanf("%s", nome);

            for(int i = 0; i < numClientes; i++){
                if (strcmp(clientes[i].nome, nome) == 0){
                    for (int j = i; j < numClientes - 1; j++) {
                        clientes[j] = clientes[j + 1];
                    }

                    numClientes--;

                    printf("Cliente excluido com sucesso. \n\n");
                    ;
                }
            }
            break;
        }

        case 5:     //Opção para encerrar o loop, o programa.
            printf("Encerrando o programa... \n");
            break;
        

        default:    //Resposta caso o usuário escolher uma opção que não está na lista.
            printf("Opcao Invalida");
            break;
        }
    } while (opcao != 5);


    return 0;
}