#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando inform�ao do usu�rio
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

int consulta() // Fun��o responsavel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem
	
	// inicio da cria��o de variavel/string 
	char cpf[40]; 
	char conteudo[200];
	// fim da cria��o de variavel/string 
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); // %s Refere-se a string/salvar string
	
	FILE *file; // cria o arquivo 
	file = fopen(cpf,"r"); // abre o arquivo  e o "r" significa ler o arquivo
	
	if(file == NULL) // criando uma vailida��o null 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //Coletando informa��o do usu�rio
	}
	while(fgets(conteudo, 200, file) != NULL) // la�o do repetic�o pra buscar o conteudo ate traser todo conteudo
	{
		printf("\nEssas s�o as informac�es do usu�rio: "); //Coletando informa��o do usu�rio
		printf("%s", conteudo); 
		printf("\n\n");
		 		
	}
	
	system("pause"); //Pausa o programa  
}

int deletar() // Fun��o responsavel por deletar os usu�rios no sistema
{	
	//Inicio cria��o de vari�veis/string
	char cpf[40]; 
	//Final cria��o de vari�veis/string
	
	
	printf("Digite o CPF do usu�rio ser deletado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); // %s Refere-se a string/salvar string
	
	remove(cpf); // deletar o arquivo
	
	FILE *file; // cria o arquivo 
	file = fopen(cpf,"r"); // abre o arquivo  e o "r" significa ler o arquivo
	
	if(file == NULL) // criando uma vailida��o null 
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //Coletando informa��o do usu�rio
		system("pause"); //Pausa o programa  
	}
}



int main()
{
	
	int opcao=0; // Definindo a vari�v�is
	int laco=1;
	
	for(laco=1;laco=1;) //repetir
	{
	
		system("cls"); // responsavel por limpar a tela
	
		setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem

		printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Opcao:");  // Final do menu
		
		scanf("%d", &opcao); // armazenamento a escolha do usu�rio

		system("cls"); // responsavel por limpar a tela
	
	
		switch(opcao) // inicio da sele��o do menu
		{
			case 1: // chamada de fun��es
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			
			default:
			printf("Essa op��o n�o est� disponivel!\n"); //Coletando informa��o do usu�rio
			system("pause"); //Pausa o programa  
			break; 
		}	// fim da sele��o
 
	
	}
}
