#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��es de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar o usu�rio no sistema
{
	//inicio da cria��o das v�riaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o das vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s para salvar uma string
	
	strcpy(arquivo,cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file= fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file, ","); //apenas para colocar a v�rgula e separar os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s", nome);
	
	file=fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ","); //apenas para colocar a v�rgula e separar os dados
	fclose(file); //fecha o arquivo

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ","); //apenas para colocar a v�rgula e separar os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausa o sistema.
	
	
}
int consulta() //fun��o respons�vel por consultar o usu�rio no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s para salvar uma string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, CPF n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //fun��o respons�vel por deletar o usu�rio no sistema
{
	char cpf[40];
	printf("Digite o CPF a ser deletado: ");
	
	scanf ("%s",cpf);
	
	remove (cpf);
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("O usu�rio foi deletado com sucesso!\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo Variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n\n");
		printf("\t2 - Consultar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n"); //fim do menu
		
		printf("Op��o:");
		
		scanf("%d" ,&opcao);  //armazenando a escolha do usuario
		
		system("cls"); //respons�vel por limpara tela
		
		switch (opcao) //inicio da sele��o do menu
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
			
			default:
			printf("Esta op��o n�o est� dispon�vel!\n\n");
			system("pause");
			break;
		}	//fim da sele��o
	}
}