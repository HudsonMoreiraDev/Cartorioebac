#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocações de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar o usuário no sistema
{
	//inicio da criação das váriaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s para salvar uma string
	
	strcpy(arquivo,cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file= fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file=fopen(arquivo, "a");
	fprintf(file, ","); //apenas para colocar a vírgula e separar os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s", nome);
	
	file=fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ","); //apenas para colocar a vírgula e separar os dados
	fclose(file); //fecha o arquivo

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ","); //apenas para colocar a vírgula e separar os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausa o sistema.
	
	
}
int consulta() //função responsável por consultar o usuário no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s para salvar uma string
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, CPF não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //função responsável por deletar o usuário no sistema
{
	char cpf[40];
	printf("Digite o CPF a ser deletado: ");
	
	scanf ("%s",cpf);
	
	remove (cpf);
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(cpf,"r"); //cria o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("O usuário foi deletado com sucesso!\n");
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
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n\n");
		printf("\t2 - Consultar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do programa\n"); //fim do menu
		
		printf("Opção:");
		
		scanf("%d" ,&opcao);  //armazenando a escolha do usuario
		
		system("cls"); //responsável por limpara tela
		
		switch (opcao) //inicio da seleção do menu
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
			printf("O programa está sendo encerrado.");
			return 0;
			break;
			
			default:
			printf("Esta opção não está disponível!\n\n");
			system("pause");
			break;
		}	//fim da seleção
	}
}
