#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// inicio cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo [40];
	// final cria��o de vari�veis/string
	
	printf("digite o cpf a ser cadastrado: "); //coletando inform��o do usu�rio
	scanf ("%s", cpf); //%s refere-se a string
	
	strcpy (arquivo, cpf); // Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen  (arquivo, "w"); //cria o arquivo o "w" significa escrever
	fprintf (file,cpf); //salvo o valor da vari�vel
	fclose (file); //fecha o arquivo
	
	file = fopen (arquivo, "a");  
	fprintf (file, ",");
	fclose (file);
	
	printf("digite o nome a ser cadastrado: "); //coletando inform��o do usu�rio
	scanf ("%s",nome);
	
	file = fopen (arquivo, "a");
	fprintf (file, nome);
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
	
	printf("digite o sobrenome a ser cadastrado: "); //coletando inform��o do usu�rio
	scanf ("%s",sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, ",");
	fclose (file);
	
	printf("digite o cargo a ser cadastrado: "); //coletando inform��o do usu�rio
	scanf ("%s", cargo);
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose (file);
	
	system ("pause");
		
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r" );
	
	if (file == NULL)
	{
		printf ("N�o foi poss�vel abrir o arquivo, n�o localizado! . \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL )
	{
		printf("\nEssas s�o as informa��es do us�ario: ");
		printf("%s" , conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}

int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema
{
	char cpf[40];
	printf("digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{	
     printf(" O us�ario n�o se encontra no sistema!.\n");
     system("pause"); 
	}
	
}

	int main ()
{
	 
	int opcao=0; //Definindo vari�veis
	int laco=1;
	for(laco=1;laco=1;)
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem

    system("cls"); //respons�vel por limpar a tela
	
	printf("###Cart�rio da EBAC###\n\n"); //In�cio do menu
	printf("Escolha a op��o desejada no menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("Op��o: "); //Fim do menu

	scanf("%d", &opcao); //Armazenando a escolha do usu�rio

	system("cls");

	switch(opcao) //In�cio da sele��o do menu
	{
	    case 1: 
		registro(); //chamada de fun��es
		system("pause");
		break;
	
	    case 2: 
	    consulta();
	    system("pause");
		break;

        case 3: 
	    deletar();
	    system("pause");
		break;

	    default:
		printf("Essa op��o n�o est� dispon�vel!\n");
        system("pause");
		break;
		//fim da sele��o
	 } 

  }

}
