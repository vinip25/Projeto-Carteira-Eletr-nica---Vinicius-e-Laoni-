#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>

typedef struct carteira
{
    int codigo;
    char categoria[200];
    float receita;
    //---------------------
    float mor;
    float est;
    float trans;
    float ali;
    float tra;
    //----------------------
    float deposito;
    int dia;
    int mes;
    int ano;
    char movimentacao[200];
    
} carteira;

carteira usuario;

void menu();
void daata();
//------------------------
void addmoradia();
void addestudos();
void addtransporte();
void addalimentacao();
void addtrabalho();
//------------------------
void depositar();
void extrato_moradia();
void movimentacoes();
void extrato_estudos();
void extrato_transporte();
void extrato_alimentacao();
void extrato_trabalho();
void extrato_anual();
void resetar();

int main()
{
    setlocale(LC_ALL,"portuguese");
    menu();
    return 0;
}

//Esse void será responsável pelas principais opções do programa
void menu()
{
    int opcao;
    do
    {
        printf(" \n Opções: ");
        printf(" \n 1. Registrar movimentação" );
        printf(" \n 2. Depositar" );
        printf(" \n 3. Mostrar relatório do ultimo mês referente a Moradia" );
        printf(" \n 4. Mostrar relatório do ultimo mês referente a Estudos" );
        printf(" \n 5. Mostrar relatório do ultimo mês referente a Transporte" );
        printf(" \n 6. Mostrar relatório do ultimo mês referente a Alimentação" );
        printf(" \n 7. Mostrar relatório do ultimo mês referente a Trabalho" );
        printf(" \n 8. Mostrar relatório anual" );
        printf(" \n 9. Resetar carteira" );

        printf(" \n 10.Sair \n " );

        printf(" \n Digite a opção desejada: ");
        scanf("%d%*c", &opcao);

        switch(opcao)
        {
            //O case 1 vai ser responsável por todas as movimentações

            //Faz o print pergutando ao cliente qual vai ser seu tipo de movimentação 
            case 1:
                printf(" \n Movimentações: ");
                printf(" \n 10. Moradia" );
                printf(" \n 11. Estudos" );
                printf(" \n 12. Transporte" );
                printf(" \n 13. Alimentação" );
                printf(" \n 14. Trabalho ");
                printf(" \n 15. Sair \n ");

                printf(" \n Selecione a categoria da movimentação: ");

                scanf("%d%*c", &opcao);

                 //Direciona à função referente a Movimentação escolhida
                case 10:
                  addmoradia();
                  break;
                case 11:
                  addestudos();
                  break;
                case 12:
                  addtransporte();
                  break;
                case 13:
                  addalimentacao();
                  break;
                case 14:
                  addtrabalho();
                  break;
                case 15:
                  break;

            case 2:
                depositar();
            break;   
            case 3:
                extrato_moradia();
            break;
            case 4:
                extrato_estudos();
            break;
            case 5:
                extrato_transporte();
            break;
            case 6:
                extrato_alimentacao();
            break;
            case 7:
                extrato_trabalho();
            break;
            case 8:
                extrato_anual();
            break;
            case 9:
                resetar();
            break;

            default:
                 printf(" \n Opção não existente. ");
                 printf("\n");
                 sleep(1);
            break;
        }
    }
    while(opcao!=11);
}


void extrato_moradia()
{
    printf(" \n Relatorio de %.2d/%.2d/%.2d: Débito => %.2f R$ ---- Compra => %s ", usuario.dia, usuario.mes, usuario.ano, usuario.mor, usuario.movimentacao );
    printf(" \n \n");
}

void depositar()
{
  printf("\n");
  printf("Deposito \n\n");
  printf ("Digite a quantia a ser depositada: R$ ");
  scanf ("%f",&usuario.deposito);
  printf ("\n");
  usuario.receita = usuario.receita + usuario.deposito;
  printf("\n");
  printf("Aguarde...");
  printf("\n");
  sleep(2);
  printf("\n O Depósito foi feito com sucesso! ");
  printf("\n");
}



void extrato_estudos()
{
    printf(" \n Relatorio de %.2d/%.2d/%.2d: Débito => %.2f R$ ---- Compra => %s  ", usuario.dia, usuario.mes, usuario.ano, usuario.est, usuario.movimentacao );
    
    printf(" \n \n");
    
}


void extrato_transporte()
{ 
   printf(" \n Relatorio de %.2d/%.2d/%.2d: Débito => %.2f R$ ---- Compra => %s  ", usuario.dia, usuario.mes, usuario.ano, usuario.trans, usuario.movimentacao );
    
   printf(" \n \n");
}

void extrato_alimentacao()
{
   printf(" \n Relatorio de %.2d/%.2d/%.2d: Débito => %.2f R$ ---- Compra => %s  ", usuario.dia, usuario.mes, usuario.ano, usuario.ali, usuario.movimentacao );
    
   printf(" \n \n");
}

void extrato_trabalho()
{
  printf(" \n Relatorio de %.2d/%.2d/%.2d: Débito => %.2f R$ ---- Compra => %s  ", usuario.dia, usuario.mes, usuario.ano, usuario.tra, usuario.movimentacao );
    
  printf(" \n \n");
}

void extrato_anual()
{
     printf(" \n Extrato anual:  %s ---- %.2f R$ ---- \n ", usuario.movimentacao, usuario.receita);

    
    printf(" \n \n");
}

void resetar()
{
    usuario.receita = 0;
    strcpy(usuario.movimentacao, "NULL");
    printf("\n");
    printf(" A carteira foi resetada!");
    printf("\n");
}

//---------------------------
//Voids de movimentação
void addmoradia()
{
  printf (" Digite o qual é a movimentação: ");
  scanf ("%s",usuario.movimentacao);
  printf("\n");
  printf (" Digite o Débito a ser gasto: R$ ");
  scanf ("%f",&usuario.deposito);
  printf("\n");
  printf (" Digite o dia atual: ");
  scanf("%d", &usuario.dia);
  printf("\n");
  printf (" Digite o mes atual: ");
  scanf("%d", &usuario.mes);
  printf("\n");
  printf (" Digite o ano atual: ");
  scanf("%d", &usuario.ano);
  printf ("\n");

  //Verifica se o saldo é suficiente para movimentação
  if ((usuario.receita-usuario.deposito > 0))
  {
      printf("\n");
      usuario.receita = usuario.receita - usuario.deposito;
      usuario.mor = usuario.mor - usuario.deposito;
      printf(" Aguarde...");
      printf("\n");
      sleep(2);
      printf("\n Movimentação concluída com sucesso! ");
      printf("\n");
  }
  else 
  {
      printf ("\n"); 
      printf("\n Saldo Insuficiente!");
      printf("\n");
  }
}

void addestudos()
{
  printf (" Digite o qual é a movimentação: ");
  scanf ("%s",usuario.movimentacao);
  printf("\n");
  printf (" Digite o Débito a ser gasto: R$ ");
  scanf ("%f",&usuario.deposito);
  printf("\n");

  printf (" Digite o dia atual: ");
  scanf("%d", &usuario.dia);
  printf("\n");
  printf (" Digite o mes atual: ");
  scanf("%d", &usuario.mes);
  printf("\n");
  printf (" Digite o ano atual: ");
  scanf("%d", &usuario.ano);
  printf ("\n");

  //Verifica se o saldo é suficiente para movimentação
  if ((usuario.receita-usuario.deposito > 0))
  {
      printf("\n");
      usuario.receita = usuario.receita - usuario.deposito;
      usuario.est = usuario.est - usuario.deposito;
      printf(" Aguarde...");
      printf("\n");
      sleep(2);
      printf("\n Movimentação concluída com sucesso! ");
      printf("\n");
  }
  else 
  {
      printf ("\n"); 
      printf("\n Saldo Insuficiente!");
      printf("\n");
  }
}

void addtransporte()
{
  printf("\n");
  printf (" Digite o qual é a movimentação: ");
  scanf ("%s",usuario.movimentacao);
  printf("\n");
  printf (" Digite o Débito a ser gasto: R$ ");
  scanf ("%f",&usuario.deposito);
  printf("\n");
  printf (" Digite o dia atual: ");
  scanf("%d", &usuario.dia);
  printf("\n");
  printf (" Digite o mes atual: ");
  scanf("%d", &usuario.mes);
  printf("\n");
  printf (" Digite o ano atual: ");
  scanf("%d", &usuario.ano);
  printf ("\n");

  //Verifica se o saldo é suficiente para movimentação
  if ((usuario.receita-usuario.deposito > 0))
  {
      printf("\n");
      usuario.receita = usuario.receita - usuario.deposito;
      usuario.trans = usuario.trans - usuario.deposito;
      printf(" Aguarde...");
      printf("\n");
      sleep(2);
      printf("\n Movimentação concluída com sucesso! ");
      printf("\n");
  }
  else 
  {
      printf ("\n"); 
      printf("\n Saldo Insuficiente!");
      printf("\n");
  }
}

void addalimentacao()
{
  printf("\n");
  printf (" Digite o qual é a movimentação: ");
  scanf ("%s",usuario.movimentacao);
  printf("\n");
  printf (" Digite o Débito a ser gasto: R$ ");
  scanf ("%f",&usuario.deposito);
  printf("\n");
  printf (" Digite o dia atual: ");
  scanf("%d", &usuario.dia);
  printf("\n");
  printf (" Digite o mes atual: ");
  scanf("%d", &usuario.mes);
  printf("\n");
  printf (" Digite o ano atual: ");
  scanf("%d", &usuario.ano);
  printf ("\n");

  //Verifica se o saldo é suficiente para movimentação
  if ((usuario.receita-usuario.deposito > 0))
  {
      printf("\n");
      usuario.receita = usuario.receita - usuario.deposito;
      usuario.ali = usuario.ali - usuario.deposito;
      printf(" Aguarde...");
      printf("\n");
      sleep(2);
      printf("\n Movimentação concluída com sucesso! ");
      printf("\n");
  }
  else 
  {
      printf ("\n"); 
      printf("\n Saldo Insuficiente!");
      printf("\n");
  }
}

void addtrabalho()
{
  printf("\n");
  printf (" Digite o qual é a movimentação: ");
  scanf ("%s",usuario.movimentacao);
  printf("\n");
  printf (" Digite o Débito a ser gasto: R$ ");
  scanf ("%f",&usuario.deposito);
  printf("\n");
  printf (" Digite o dia atual: ");
  scanf("%d", &usuario.dia);
  printf("\n");
  printf (" Digite o mes atual: ");
  scanf("%d", &usuario.mes);
  printf("\n");
  printf (" Digite o ano atual: ");
  scanf("%d", &usuario.ano);
  printf ("\n");

  //Verifica se o saldo é suficiente para movimentação
  if ((usuario.receita-usuario.deposito > 0))
  {
      printf("\n");
      usuario.receita = usuario.receita - usuario.deposito;
      usuario.tra = usuario.tra - usuario.deposito;
      printf(" Aguarde...");
      printf("\n");
      sleep(2);
      printf("\n Movimentação concluída com sucesso! ");
      printf("\n");
  }
  else 
  {
      printf ("\n"); 
      printf("\n Saldo Insuficiente!");
      printf("\n");
  }
}