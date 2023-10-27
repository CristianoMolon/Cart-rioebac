#include <stdio.h> //biblioteca de comuncação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar oas usuarios no sistema
{
	//inicio da criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coleta de informções do usuario
	scanf("%s", cpf); //%s -> strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
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

int consulta() //Função responsável pela consulta aos usuários
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da criação de variaveis/strings
	char cpf[40];
	char consulta[200];
	//inicio da criação de variaveis/strings
	
	printf("Digite o cpf a ser consultado: "); //coleta de informações
	scanf("%s", cpf);
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r");
	
	if(file == NULL) //Responsável caso o arquivo não esteja no sistema
	{
		printf("Não foi possivel abrir o arquivo, não localizado\n");
	}
	
	while(fgets(consulta, 200, file) != NULL) //Responsavel por mostrar os dados do usuario
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", consulta);
		printf("\n\n");
	
	}
	
	system("pause");
	
}

int deletar() //Função responsável por deletar os usuários
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser Detado: ");
	scanf("%s",cpf);
	
	remove(cpf); //deleta o usuario do sistema
	
	FILE *file;
	file == fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usúario não se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("~~~ Cartório EBAC ~~~\n\n"); //inicio menu
		printf("Selecione a opção desejada:\n\n");
		printf("\t1 - Registrar um Nome:\n\n");
		printf("\t2 - Consultar Nome:\n\n");
		printf("\t3 - Deletar um Nome:\n\n"); 
		printf("\t4 - Sair do menu\n");
		printf("Opção: "); //fim menu
		
		scanf("%d", &opcao); //armazenando escolha do usúario
		
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da seleção
		{
			
			case 1:
			registro(); //chamada de funções
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
			printf("Opção não disponivel\n");
			system("pause");
			break;
			
}
}
}
