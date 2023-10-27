#include <stdio.h> //biblioteca de comunca��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar oas usuarios no sistema
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coleta de inform��es do usuario
	scanf("%s", cpf); //%s -> strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta() //Fun��o respons�vel pela consulta aos usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da cria��o de variaveis/strings
	char cpf[40];
	char consulta[200];
	//inicio da cria��o de variaveis/strings
	
	printf("Digite o cpf a ser consultado: "); //coleta de informa��es
	scanf("%s", cpf);
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r");
	
	if(file == NULL) //Respons�vel caso o arquivo n�o esteja no sistema
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado\n");
	}
	
	while(fgets(consulta, 200, file) != NULL) //Responsavel por mostrar os dados do usuario
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", consulta);
		printf("\n\n");
	
	}
	
	system("pause");
	
}

int deletar() //Fun��o respons�vel por deletar os usu�rios
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser Detado: ");
	scanf("%s",cpf);
	
	remove(cpf); //deleta o usuario do sistema
	
	FILE *file;
	file == fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O us�ario n�o se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("~~~ Cart�rio EBAC ~~~\n\n"); //inicio menu
		printf("Selecione a op��o desejada:\n\n");
		printf("\t1 - Registrar um Nome:\n\n");
		printf("\t2 - Consultar Nome:\n\n");
		printf("\t3 - Deletar um Nome:\n\n"); 
		printf("\t4 - Sair do menu\n");
		printf("Op��o: "); //fim menu
		
		scanf("%d", &opcao); //armazenando escolha do us�ario
		
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da sele��o
		{
			
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!!\n");
			return 0;
			break;
			
			default:
			printf("Op��o n�o disponivel\n");
			system("pause");
			break;
			
}
}
}
