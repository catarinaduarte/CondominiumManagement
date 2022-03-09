#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#define MAX_RGTS 100
typedef struct{
    int cpf;
    char nome[20];
    int res;
    float deb;
}Registro;
Registro reg[MAX_RGTS];
int clear(){
    system("cls");
}
int a0(){
    clear();
    printf("Administracao Residencial\n\n\n");
    printf("Obrigado por utilizar nossos serviÃ§os!\n\n");
    printf("Volte sempre!\n\n\n");
    return 0;
}
int a1(){
    FILE *fileA1;
    char str[15],txt[5] = {".txt"};
    Registro reg;
    int result;
    printf("Administracao Residencial\n\n");
    printf("Insira o CPF: ");
    scanf("%s",&str);
    strcat(str,txt);
    result = access(str,F_OK);
    fileA1 = fopen(str,"a+");

    if(result){
        printf("Insira o nome: ");
        scanf("%s",&reg.nome);
        fprintf(fileA1,"%s\n",reg.nome);
        printf("Insira o Numero da Residencia: ");
        scanf("%d",&reg.res);
        fprintf(fileA1,"%d\n",reg.res);
        printf("Insira o debito: ");
        scanf("%f",&reg.deb);
        fprintf(fileA1,"%0.2f\n",reg.deb);
        fclose(fileA1);
        clear();
        printf("Cadastro realizado!\n\n");
    }
    else{
        clear();
        printf("\n\nEste CPF já registrado!\n\n");
    }
    main();
}
int a2(){
    int result,i = 0,j;
    char txt[5] = {".txt"},perfil[100],ask,consul[30];
    char* palavras[50];
    FILE *fileA2;
    printf("Administracao Residencial\n\n");
    printf("Insira o CPF do Condomino para Consulta:\n\n");
    printf("\\\\ ");
    scanf("%s",&consul);
    strcat(consul,txt);
    result = access(consul,F_OK);
    fileA2 = fopen(consul,"r");
    if(!result){
        clear();
        printf("Administracao Residencial\n\n");
        printf("Condomino encontrado!\n\n");
        printf("      Perfil\n");
        printf("==================\n");
        while(fgets(perfil, sizeof(perfil),fileA2) != NULL){
            palavras = strdup(perfil);
            i++;
        }
        printf("Nome: %s",palavras[0]);
        printf("Apartamento: %s",palavras[1]);
        printf("Debito: %s",palavras[2]);
        printf("==================\n");
        fclose(fileA2);
        printf("\n\nDeseja Refazer Operacao?\n\n");
        printf("(S/N) | === ");
        scanf("%s",&ask);
        if(ask == 's' || ask == 'S'){
            clear();
            a2();
        }
        else{
            clear();
            main();
        }
    }
    else{
        clear();
        printf("Administracao Residencial\n\n");
        printf("Condômino nao encontrado!\n");
        printf("Deseja realizar este processo novamente ?\n\n");
        printf("(S/N) | === ");
        scanf("%s",&ask);
        if(ask == 's' || ask == 'S'){
            clear();
            a2();
        }
        else{
            clear();
            main();
        }
    }
}
int a3(){
    char op[30],perfil[30],nome[20] = {"Sardinha"};
    char* palavras[50];
    int result,i=0,deb;
    printf("\nAdministracao Residencial\n\n");
    printf("Insira o CPF do condomino para atualizar o debito\n\n");
    printf("=== ");
    scanf("%s",&op);
    strcat(op,".txt");
    FILE *fileA3;
    result = access(op,F_OK);
    fileA3 = fopen(op,"r");
    if(!result){
        while(fgets(perfil, sizeof(perfil),fileA3) != NULL){
            palavras = strdup(perfil);
            i++;
        }
        printf("\n\n==================\n");
        printf("Nome: %s",palavras[0]);
        printf("Seu debito atual: %s",palavras[2]);
        printf("==================\n\n");
        printf("Atualize seu debito: ");
        fclose(fileA3);
    }
}
int a6(){
    char str[30],txt[5] = {".txt"};
    char ask;
    printf("\nAdministracao Residencial\n\n");
    printf("Insira o CPF do condomino para o remover\n");
    printf("=== ");
    scanf("%s",&str);
    strcat(str,txt);
    if(remove(str)==0){
        clear();
        printf("Condomino removido com sucesso!\n\n");
        printf("Deseja realizar este processo novamente ?\n\n");
        printf("(S/N) | > > > ");
        scanf("%s",&ask);
        if(ask == 's' || ask == 'S'){
            a6();
        }
        else{
            clear();
            main();
        }
    }else{
        clear();
        printf("Condomino nao encontrado!\n\n");
        printf("Deseja realizar este processo novamente ?\n\n");
        printf("(S/N) | > > > ");
        scanf("%s",&ask);
        if(ask == 's' || ask == 'S'){
            clear();
            a6();
        }
        else{
            clear();
            main();
        }
    }
}
int menu(int n1){
    printf("Administracao Residencial\n\n");
    printf("[1]-Inserir um novo condomino\n");
    printf("[2]-Consultar condômino pelo CPF\n");
    printf("[3]-Atualizar o débito do condômino pelo CPF\n");
    printf("[4]-Exibir condômino devedores\n");
    printf("[5]-Exibir condômino quites\n");
    printf("[6]-Remover condômino\n");
    printf("[0]-Sair do programa\n\n");
    printf("> > > ");
    scanf("%d",&n1);
    return(n1);
}
int main()
{
    setlocale(LC_ALL,"portuguese");
    int n1,valor;
    valor = menu(n1);
    clear();
    switch(valor){
        case 0:
            a0();
        break;
        case 1:
            a1();
        break;
        case 2:
            a2();
        break;
        case 3:
            a3();
        break;
        case 6:
            a6();
        break;
    }
    return 0;
}