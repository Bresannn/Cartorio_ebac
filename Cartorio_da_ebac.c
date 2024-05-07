#include <stdio.h>   //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //Biblioteca de aloca��o de espa�o com mem�ria
#include <locale.h>  //Biblioteca de aloca��o de texto por regi�o
#include <string.h>  //Biblioteca respons�vel por cuidar das string

int registro()  //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da cria��o de vari�veis/string
    	
    printf("DIGITE O CPF:");//Coletando informa��o do usu�rio
    scanf("%s", cpf);//%s refere-se a string
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
    
    FILE *file;   //Cria o arquivo
    file = fopen(arquivo, "w");// Cria o arquivo e o "w" significa escrever
    fprintf(file, cpf);//Salvo o valor da variavel
    fclose(file);      //Fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("DIGITE O NOME:");
    scanf("%s", nome);
    
    file =fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
   
    printf("DIGITE O SOBRENOME:");
    scanf("%s", sobrenome);
   
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
   
   
    printf("DIGITE SEU CARGO:");
    scanf("%s", cargo);
   
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    
    system("pause");
   	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s" ,cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
	{
	   printf("Esse usu�rio n�o existe\n");
	}
	
    while(fgets(conteudo, 200, file) != NULL)
    {
       printf("\nInforma��es do usu�rio :");
	   printf("%s", conteudo);
	   printf("\n\n");
	}

    system("pause");


}

int deletar()
{
   char cpf[40];
   
   printf("Digite O CPF a ser deletado :");
   scanf("%s", cpf);
   
   remove(cpf);// deleta o arquivo
   
   FILE *file;
   file = fopen(cpf, "r");
   
  
   if(file == NULL)//Se o arquivo n�o for achado Vai gerar a mensagem abaixo
   {
   	   printf("\t\tNo momento esse usu�rio n�o existe no nosso sitema.\n");
   	   system("pause");
   }
     
}

int main ()
  {
	int opcao=0;     //Definindo vari�veis 
	int ouroboros=1;
	char senhadigitada[10]="a";
	char logindigitado[10]="a";
	int comparacao;
	int login;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t\t\t\t ### CART�RIO DA EBAC ###\n\n\n");
	printf("\t\tLogin de Administrador!\n\n ");
	printf("Digite o usu�rio :");
	
	scanf("%s", logindigitado);
	
	printf("Digite a Senha:\n ");
	
	scanf("%s", senhadigitada);
	
	login = strcmp(logindigitado, "admin");
	
	comparacao = strcmp(senhadigitada, "12345");
	
	if(comparacao == 0 && login == 0)
	{
	
    	for(ouroboros=1;ouroboros=1;) 
        {
  	
    	system("cls");//Respons�vel por limpar a tela
  	
	    setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	 
	    printf("\t\t\t\t ### CART�RIO DA EBAC ###\n\n\n");//In�cio do menu
	    printf("\t\tEscolha a op��o desejada do menu : \n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n");
     	printf("\t4 - Sair do programa.\n\n");
	    printf("Op��o :"); //Fim do Menu
	
	    scanf("%d", &opcao);//Armazenando a escolha do usu�rio
	
	    system("cls");//Respons�vel por limpar a tela
	
	    switch(opcao)
        {
	    //In�cio da sele��o    	
	    case 1:
        registro();//chamada de fun��o
	    break;		  
	
	    case 2:
        consulta();
    	break;
		  
	    case 3:
     	deletar();
	    break;
	
    	case 4:
	    printf("OBRIGADO POR USAR NOSSO SISTEMA!");
    	return 0;// fecha o sistema
    	break;
		
	    default:
	    printf("ESSA OP��O N�O EXISTE!\n");
	    system("pause");
	    break;
        }//Fim da sele��o
	
      }
	 
    }
	 
	else 
	    printf("\t\t\tA SENHA OU O USU�RIO EST� INCORRETA, TENTE NOVAMENTE!\n\n");
	    system("pause");

}
