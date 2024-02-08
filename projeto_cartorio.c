#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() // Função responsavel por cadastrar os usuários no sistema
{
	//Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informçao do usuário
	scanf("%s", cpf);// %s Refere-se a string/salvar string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salva o valor da varialvel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo  e o "A" significa atualizar e acessar o arquivo existente
	fprintf(file,","); // salva o valor da varialvel
	fclose(file); // fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome); 
	fclose(file); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: "); 
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,sobrenome); 
	fclose(file); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: "); 
	scanf("%s",cargo); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,cargo); 
	fclose(file); 
	
	system("pause"); //Pausa o programa  

}

int consulta() // Função responsavel por consultar os usuários no sistema
{
	setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem
	
	// inicio da criação de variavel/string 
	char cpf[40]; 
	char conteudo[200];
	// fim da criação de variavel/string 
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s",cpf); // %s Refere-se a string/salvar string
	
	FILE *file; // cria o arquivo 
	file = fopen(cpf,"r"); // abre o arquivo  e o "r" significa ler o arquivo
	
	if(file == NULL) // criando uma vailidação null 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //Coletando informação do usuário
	}
	while(fgets(conteudo, 200, file) != NULL) // laço do repeticão pra buscar o conteudo ate traser todo conteudo
	{
		printf("\nEssas são as informacões do usuário: "); //Coletando informação do usuário
		printf("%s", conteudo); 
		printf("\n\n");
		 		
	}
	
	system("pause"); //Pausa o programa  
}

int deletar() // Função responsavel por deletar os usuários no sistema
{	
	//Inicio criação de variáveis/string
	char cpf[40]; 
	//Final criação de variáveis/string
	
	
	printf("Digite o CPF do usuário ser deletado: "); //Coletando informação do usuário
	scanf("%s",cpf); // %s Refere-se a string/salvar string
	
	remove(cpf); // deletar o arquivo
	
	FILE *file; // cria o arquivo 
	file = fopen(cpf,"r"); // abre o arquivo  e o "r" significa ler o arquivo
	
	if(file == NULL) // criando uma vailidação null 
	{
		printf("O usuário não se encontra no sistema!.\n"); //Coletando informação do usuário
		system("pause"); //Pausa o programa  
	}
}



int main()
{
	
	int opcao=0; // Definindo a variávéis
	int laco=1;
	
	for(laco=1;laco=1;) //repetir
	{
	
		system("cls"); // responsavel por limpar a tela
	
		setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem

		printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Opcao:");  // Final do menu
		
		scanf("%d", &opcao); // armazenamento a escolha do usuário

		system("cls"); // responsavel por limpar a tela
	
	
		switch(opcao) // inicio da seleção do menu
		{
			case 1: // chamada de funções
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			
			default:
			printf("Essa opção não está disponivel!\n"); //Coletando informação do usuário
			system("pause"); //Pausa o programa  
			break; 
		}	// fim da seleção
 
	
	}
}
