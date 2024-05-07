#include <stdio.h>   //Biblioteca de comunicação com o usuário
#include <stdlib.h>  //Biblioteca de alocação de espaço com memória
#include <locale.h>  //Biblioteca de alocação de texto por região
#include <string.h>  //Biblioteca responsável por cuidar das string

int registro()  //Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da criação de variáveis/string
    	
    printf("DIGITE O CPF:");//Coletando informação do usuário
    scanf("%s", cpf);//%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsável por copiar os valores das string
    
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
	   printf("Esse usuário não existe\n");
	}
	
    while(fgets(conteudo, 200, file) != NULL)
    {
       printf("\nInformações do usuário :");
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
   
  
   if(file == NULL)//Se o arquivo não for achado Vai gerar a mensagem abaixo
   {
   	   printf("\t\tNo momento esse usuário não existe no nosso sitema.\n");
   	   system("pause");
   }
     
}

int main ()
  {
	int opcao=0;     //Definindo variáveis 
	int ouroboros=1;
	char senhadigitada[10]="a";
	char logindigitado[10]="a";
	int comparacao;
	int login;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t\t\t\t ### CARTÓRIO DA EBAC ###\n\n\n");
	printf("\t\tLogin de Administrador!\n\n ");
	printf("Digite o usuário :");
	
	scanf("%s", logindigitado);
	
	printf("Digite a Senha:\n ");
	
	scanf("%s", senhadigitada);
	
	login = strcmp(logindigitado, "admin");
	
	comparacao = strcmp(senhadigitada, "12345");
	
	if(comparacao == 0 && login == 0)
	{
	
    	for(ouroboros=1;ouroboros=1;) 
        {
  	
    	system("cls");//Responsável por limpar a tela
  	
	    setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	 
	    printf("\t\t\t\t ### CARTÓRIO DA EBAC ###\n\n\n");//Início do menu
	    printf("\t\tEscolha a opção desejada do menu : \n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n");
     	printf("\t4 - Sair do programa.\n\n");
	    printf("Opção :"); //Fim do Menu
	
	    scanf("%d", &opcao);//Armazenando a escolha do usuário
	
	    system("cls");//Responsável por limpar a tela
	
	    switch(opcao)
        {
	    //Início da seleção    	
	    case 1:
        registro();//chamada de função
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
	    printf("ESSA OPÇÃO NÃO EXISTE!\n");
	    system("pause");
	    break;
        }//Fim da seleção
	
      }
	 
    }
	 
	else 
	    printf("\t\t\tA SENHA OU O USUÁRIO ESTÁ INCORRETA, TENTE NOVAMENTE!\n\n");
	    system("pause");

}
