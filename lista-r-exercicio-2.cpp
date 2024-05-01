#include <stdio.h>
#include <string.h>
#include <conio.h>

#define NUM_FUNCIONARIOS 15
#define NUM_MESES 3

struct Funcionario
{
  char nome[50];
  double vendas[NUM_MESES];
  double pontuacao;
};

void cadastrarFuncionarios(struct Funcionario funcionarios[])
{
  for (int i = 0; i < NUM_FUNCIONARIOS; i++)
  {
    printf("Digite o nome do funcionário %d: ", i + 1);
    scanf(" %[^\n]", funcionarios[i].nome);

    for (int j = 0; j < NUM_MESES; j++)
    {
      printf("Digite as vendas do funcionário %d no mês %d: ", i + 1, j + 1);
      scanf("%lf", &funcionarios[i].vendas[j]);
    }
  }
}

void calcularPontuacao(struct Funcionario funcionarios[])
{
  for (int i = 0; i < NUM_FUNCIONARIOS; i++)
  {
    double totalVendas = 0.0;
    for (int j = 0; j < NUM_MESES; j++)
    {
      totalVendas += funcionarios[i].vendas[j];
    }
    funcionarios[i].pontuacao = totalVendas / 1000.0;
  }
}

void calcularPontuacaoGeral(struct Funcionario funcionarios[])
{
  double pontuacaoMes[NUM_MESES] = {0.0};

  for (int i = 0; i < NUM_FUNCIONARIOS; i++)
  {
    for (int j = 0; j < NUM_MESES; j++)
    {
      pontuacaoMes[j] += funcionarios[i].vendas[j];
    }
  }

  printf("Pontuação geral de todos os funcionários a cada mês:\n");
  for (int j = 0; j < NUM_MESES; j++)
  {
    printf("Mês %d: %.2lf pontos\n", j + 1, pontuacaoMes[j] / 1000.0);
  }
}

void encontrarMaiorPontuacao(struct Funcionario funcionarios[])
{
  double maiorPontuacao = 0.0;
  char nomeMaiorPontuacao[50];

  for (int i = 0; i < NUM_FUNCIONARIOS; i++)
  {
    if (funcionarios[i].pontuacao > maiorPontuacao)
    {
      maiorPontuacao = funcionarios[i].pontuacao;
      strcpy(nomeMaiorPontuacao, funcionarios[i].nome);
    }
  }

  printf("Maior pontuação atingida: %.2lf pontos (Funcionário: %s)\n", maiorPontuacao, nomeMaiorPontuacao);
}

double calcularValorTotalVendido(struct Funcionario funcionarios[])
{
  double valorTotal = 0.0;

  for (int i = 0; i < NUM_FUNCIONARIOS; i++)
  {
    for (int j = 0; j < NUM_MESES; j++)
    {
      valorTotal += funcionarios[i].vendas[j];
    }
  }

  return valorTotal;
}

int main()
{
  struct Funcionario funcionarios[NUM_FUNCIONARIOS];

  cadastrarFuncionarios(funcionarios);
  calcularPontuacao(funcionarios);
  calcularPontuacaoGeral(funcionarios);
  encontrarMaiorPontuacao(funcionarios);

  double valorTotalVendido = calcularValorTotalVendido(funcionarios);
  printf("Valor total vendido: %.2lf\n", valorTotalVendido);

  getch();
  return 0;
}
