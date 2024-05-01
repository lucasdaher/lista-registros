#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_PRODUTOS 40

struct Produto
{
  int codigo;
  char descricao[50];
  double precoCompra;
  double precoVenda;
  int quantidadeEstoque;
  int estoqueMinimo;
};

void cadastrarProdutos(struct Produto produtos[])
{
  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    printf("Digite o codigo do produto %d: ", i + 1);
    scanf("%d", &produtos[i].codigo);

    printf("Digite a descricao do produto %d: ", i + 1);
    scanf(" %[^\n]", produtos[i].descricao);

    printf("Digite o preco de compra do produto %d: ", i + 1);
    scanf("%lf", &produtos[i].precoCompra);

    printf("Digite o peco de venda do produto %d: ", i + 1);
    scanf("%lf", &produtos[i].precoVenda);

    printf("Digite a quantidade em estoque do produto %d: ", i + 1);
    scanf("%d", &produtos[i].quantidadeEstoque);

    printf("Digite o estoque minimo permitido do produto %d: ", i + 1);
    scanf("%d", &produtos[i].estoqueMinimo);
  }
}

void calcularLucro(struct Produto produto)
{
  double lucro = (produto.precoVenda - produto.precoCompra) * produto.quantidadeEstoque;
  double percentualLucro = (lucro / (produto.precoCompra * produto.quantidadeEstoque)) * 100.0;

  printf("Lucro obtido com a venda do produto %s: R$ %.2lf (%.2lf%%)\n", produto.descricao, lucro, percentualLucro);
}

void mostrarProdutosAbaixoMinimo(struct Produto produtos[])
{
  printf("Produtos com quantidade em estoque abaixo do minimo:\n");
  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    if (produtos[i].quantidadeEstoque < produtos[i].estoqueMinimo)
    {
      printf("Codigo: %d, Descricao: %s\n", produtos[i].codigo, produtos[i].descricao);
    }
  }
}

int main()
{
  struct Produto produtos[MAX_PRODUTOS];

  cadastrarProdutos(produtos);

  int opcao;
  do
  {
    printf("\nMenu de opcoes:\n");
    printf("1. Calcular lucro de um produto\n");
    printf("2. Mostrar produtos abaixo do estoque minimo\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Digite o codigo do produto: ");
      int codigo;
      scanf("%d", &codigo);
      for (int i = 0; i < MAX_PRODUTOS; i++)
      {
        if (produtos[i].codigo == codigo)
        {
          calcularLucro(produtos[i]);
          break;
        }
      }
      break;
    case 2:
      mostrarProdutosAbaixoMinimo(produtos);
      break;
    case 3:
      printf("Saindo do programa...\n");
      system("pause");
      break;
    default:
      printf("Opcao invalida. Tente novamente.\n");
    }
  } while (opcao != 3);

  getch();
  return 0;
}
