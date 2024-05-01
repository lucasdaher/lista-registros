#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_CONTAS 15

struct Conta
{
  int numero;
  char nome[50];
  double saldo;
};

void cadastrarConta(struct Conta contas[], int *numContas)
{
  if (*numContas >= MAX_CONTAS)
  {
    printf("Limite de contas atingido.\n");
    return;
  }

  struct Conta novaConta;
  printf("Digite o número da conta: ");
  scanf("%d", &novaConta.numero);

  for (int i = 0; i < *numContas; i++)
  {
    if (contas[i].numero == novaConta.numero)
    {
      printf("Já existe uma conta com esse número.\n");
      return;
    }
  }

  printf("Digite o nome do cliente: ");
  scanf(" %[^\n]", novaConta.nome);
  printf("Digite o saldo: ");
  scanf("%lf", &novaConta.saldo);

  contas[*numContas] = novaConta;
  (*numContas)++;
  printf("Conta cadastrada com sucesso!\n");
}

void visualizarContasCliente(struct Conta contas[], int numContas, char nomeCliente[])
{
  printf("Contas do cliente %s:\n", nomeCliente);
  for (int i = 0; i < numContas; i++)
  {
    if (strcmp(contas[i].nome, nomeCliente) == 0)
    {
      printf("Conta %d - Saldo: %.2lf\n", contas[i].numero, contas[i].saldo);
    }
  }
}

void excluirContaMenorSaldo(struct Conta contas[], int *numContas)
{
  if (*numContas == 0)
  {
    printf("Não há contas cadastradas.\n");
    return;
  }

  int indiceMenorSaldo = 0;
  for (int i = 1; i < *numContas; i++)
  {
    if (contas[i].saldo < contas[indiceMenorSaldo].saldo)
    {
      indiceMenorSaldo = i;
    }
  }

  printf("Conta %d com menor saldo excluída.\n", contas[indiceMenorSaldo].numero);
  contas[indiceMenorSaldo] = contas[(*numContas) - 1];
  (*numContas)--;
}

int main()
{
  struct Conta contas[MAX_CONTAS];
  int numContas = 0;
  int opcao;

  do
  {
    printf("\nMenu de opções:\n");
    printf("1. Cadastrar contas\n");
    printf("2. Visualizar todas as contas de determinado cliente\n");
    printf("3. Excluir a conta com menor saldo\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      cadastrarConta(contas, &numContas);
      break;
    case 2:
      printf("Digite o nome do cliente: ");
      char nomeCliente[50];
      scanf(" %[^\n]", nomeCliente);
      visualizarContasCliente(contas, numContas, nomeCliente);
      break;
    case 3:
      excluirContaMenorSaldo(contas, &numContas);
      break;
    case 4:
      printf("Saindo do programa...");
      system("pause");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao <= 0 || opcao > 4);

  getch();
  return 0;
}
