#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <initializer_list>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <time.h>
using namespace std;

const int MAX_CLIENTES = 20;
const int MAX_PRODUTOS = 20;
string nome[MAX_CLIENTES];
string endereco[MAX_CLIENTES];
string email[MAX_CLIENTES];
string telefone[MAX_CLIENTES];
string produto[MAX_PRODUTOS];
int codigo_produto[MAX_PRODUTOS];
int quantidade_de_entrada[MAX_PRODUTOS];
int numerocad[MAX_CLIENTES];
int taxadeentrega[2];
int valordataxa;
float preco_custo[MAX_PRODUTOS];
float valorproduto[MAX_PRODUTOS];
float valorpedido[MAX_PRODUTOS];
float valorfinalpedido = 0.0;
float Vvalorfinalpedido[0];

void clearScreen()
{
    // Limpa a tela do console no Windows
    cout << "\033[2J\033[H";
}

void cadastrarCliente(string nome[], string telefone[], string email[], string endereco[], int numerocad[], int MAX_CLIENTES)
{
    // clearScreen();
    system("cls");
    for (int x = 0; x < MAX_CLIENTES; x++)
    {
        cout << "____________________________________\n";
        cout << "------- CADASTRE SEU CLIENTE ------  \n";
        cout << "CADASTRO N°: " << x + 1 << " digite nome a ser cadastrado: ";
        numerocad[x] = x;
        getline(cin >> ws, nome[x]);

        cout << "CADASTRO N°: " << x + 1 << " digite telefone a ser cadastrado: ";
        getline(cin >> ws, telefone[x]);

        cout << "CADASTRO N°: " << x + 1 << " digite o email a ser cadastrado: ";
        getline(cin >> ws, email[x]);

        cout << "CADASTRO N°: " << x + 1 << " digite o endereço e n° da residência a ser cadastrado: ";
        getline(cin >> ws, endereco[x]);

        cout << "Deseja realizar outro cadastro? Digite 1 para sim e 3 para não: ";
        string r;
        cin >> r;
        if (r == "3")
            break;
    }
}

void listarClientes(string nome[], string telefone[], string email[], string endereco[], int MAX_CLIENTES)
{
    system("cls");
    cout << "---- lista de clientes cadastrados ---------- aberta ---------\n";
    for (int x = 0; x < MAX_CLIENTES; x++)
    {
        if (nome[x].empty())
            break;
        cout << "---------------------------------------------------\n";
        cout << " CADASTRO n°" << x + 1 << " nome: " << nome[x] << endl;
        cout << " CADASTRO n°" << x + 1 << " telefone: " << telefone[x] << endl;
        cout << " CADASTRO n°" << x + 1 << " email: " << email[x] << endl;
        cout << " CADASTRO n°" << x + 1 << " endereço: " << endereco[x] << endl
             << endl;
        cout << "---------------------------------------------------\n";
    }
}

void cadastrarEstoque(string produto[], int codigo_produto[], int quantidade_de_entrada[], float preco_custo[], float valorproduto[], int MAX_PRODUTOS)
{
    system("cls");
    cout << "            Aberto seçao cadastro de estoque\n";
    for (int i = 0; i < MAX_PRODUTOS; i++)
    {
        cout << " *--------*  seção de cadastro de estoque  *---------*\n";
        cout << "______________________________________________________\n";
        cout << "Digite o nome do produto: ";
        getline(cin >> ws, produto[i]);

        cout << "Digite o número do código: ";
        cin >> codigo_produto[i];
        cin.ignore(); // Limpar o buffer de entrada

        cout << "Digite a quantidade de entrada no estoque: ";
        cin >> quantidade_de_entrada[i];
        cin.ignore(); // Limpar o buffer de entrada

        cout << "Digite o preço de custo do produto: ";
        cin >> preco_custo[i];
        cin.ignore(); // Limpar o buffer de entrada

        // Calcula o valor do produto (valor de revenda)
        valorproduto[i] = preco_custo[i] * 1.5;

        cout << "Deseja fazer outro cadastro? Digite 1 para sim e 3 para não: ";
        int r;
        cin >> r;
        if (r == 3)
        {
            break;
        }
    }
}

void listarEstoque(string produto[], int codigo_produto[], int quantidade_de_entrada[], float preco_custo[], float valorproduto[], int MAX_PRODUTOS)
{

    // clearScreen();
    system("cls");
    cout << "                                                        ESTOQUE ABERTO\n";
    cout << "=== Código ===  Quantidade no estoque === Preço de custo === Valor de revenda ====   Descrição do produto ======== \n";
    for (int i = 0; i < MAX_PRODUTOS; i++)
    {
        if (produto[i].empty())
        {
            break;
        }
        cout << "      " << codigo_produto[i] << "                 " << quantidade_de_entrada[i] << "                       " << preco_custo[i] << "               " << valorproduto[i] << "                         " << produto[i] << endl;
    }
}
void abre_catalogo(string produto[], float valorproduto[], int MAX_PRODUTOS)
{
    system("cls");
    // clearScreen();
    cout << " *********************** CATALOGO DE VENDAS ***************************\n";
    cout << "\n Compras acima de R$ 150,00 O FRETE É GRÁTIS   -------------------------\n";
    cout << "-------------------------------          Prazo de entrega em até 7 dias \n";
    cout << "--------- Taxa de entrega para Curitiba e região metropolitana R$:30,00\n";
    cout << "Taxa de entrega para fora da região metropolitana ou do estado R$:60,00\n\n";

    for (int i = 0; i < MAX_PRODUTOS; i++)
    {
        if (produto[i].empty())
        {
            break;
        }
        cout << " PRODUTO N°: " << i + 1 << "         " << produto[i] << "            R$: " << valorproduto[i] << endl;
        cout << "-------------------------------------------------------------------\n";
    }
}
void fazer_pedido(string produto[], int numerocad[], string nome[], string endereco[], string email[], string telefone[], float floVvalorfinalpedido[], int taxadeentrega[], int MAX_PRODUTOS)
{
    system("cls");
    int regiaoentrega;
    int outroped, repeat_p;
    int numerocadastro, k;
    cout << " ESCOLHA UMA REGIÃO PARA CALCULAR A TAXA DE ENTREGA\n\n";
    cout << "     Curitiba ou região metropolitana digite <1>\n";
    cout << "   Fora do estado ou região metropolitana digite <2>\n";

    cin >> regiaoentrega;
    switch (regiaoentrega)
    {
    case 1:
        valordataxa = 30;
        taxadeentrega[0] = valordataxa;
        break;
    case 2:
        valordataxa = 60;
        taxadeentrega[0] = valordataxa;
        break;
    default:
        valordataxa = 80;
        taxadeentrega[0] = valordataxa;
        break;
    }
    for (int i = 0; i < MAX_PRODUTOS; i++)
    {
        if (produto[i].empty())
        {
            break;
        }
        cout << " PRODUTO N°: " << i + 1 << "         " << produto[i] << "            R$: " << valorproduto[i] << endl;
        cout << "-------------------------------------------------------------------\n";
    }
    cout << "Digite o número do cadastro do cliente: ";
    cin >> numerocadastro;
    k = numerocadastro - 1; // Ajustando o índice para acessar corretamente o vetor numerocad
    cout << "Cliente: " << nome[k] << " -- Telefone: " << telefone[k] << endl;
    cout << "Endereço: " << endereco[k] << " -- Email: " << email[k] << endl;

    time_t seconds;
    tm *p;
    time(&seconds);
    p = localtime(&seconds);
    cout << "Data: " << p->tm_mday << '/' << (p->tm_mon + 1) << '/' << (p->tm_year + 1900);
    cout << "    Hora: " << p->tm_hour << ':' << p->tm_min << ':' << p->tm_sec << endl;

    int n = 1;
    while (true)
    {
        cout << "------------------------------------------------------------------- PEDIDO N° " << n << " ABERTO ----------------\n";

        for (int i = 0; i < MAX_PRODUTOS; i++)
        {
            int quantidadeproduto = 0;
            cout << "Digite o número correspondente ao produto desejado: ";
            int numeroproduto;
            cin >> numeroproduto;

            if (numeroproduto < 1 || numeroproduto > MAX_PRODUTOS)
            {
                cout << "Número de produto inválido. Tente novamente.\n";
                continue;
            }

            cout << "Digite a quantidade do produto desejado: ";
            cin >> quantidadeproduto;

            if (quantidadeproduto > quantidade_de_entrada[numeroproduto - 1])
            {
                cout << "Quantidade indisponível em estoque. Tente novamente.\n";
                continue;
            }

            quantidade_de_entrada[numeroproduto - 1] -= quantidadeproduto;
            float valorpedido = quantidadeproduto * valorproduto[numeroproduto - 1];
            valorfinalpedido += valorpedido;

            cout << "Valor do pedido atual: R$ " << valorfinalpedido << endl;
            cout << "Deseja adicionar outro produto ao pedido? (1 para sim, 3 para não): ";
            cin >> outroped;
            if (outroped == 3)
            {
                break;
            }
        }

        cout << "Deseja realizar outro pedido? (1 para sim, 0 para não): ";
        cin >> repeat_p;
        if (repeat_p == 0)
        {
            break;
        }
        n++;
    }

    if (valorfinalpedido > 150.0)
    {
        taxadeentrega[0] = 0.0;
    }
    valorfinalpedido += taxadeentrega[0];
    floVvalorfinalpedido[0] = valorfinalpedido;

    cout << "Valor total do pedido com taxa de entrega: R$ " << valorfinalpedido << endl;
}
void lista_pedido_realizado(string produto[], float valorproduto[], int taxadeentrega[], string nome[], string endereco[], string email[], string telefone[], int MAX_PRODUTOS, int MAX_CLIENTES)
{
    system("cls");
    string produtoescolhido[MAX_PRODUTOS];
    float valordoprodutoescolhido[MAX_PRODUTOS];
    int quantidadeescolhida[MAX_PRODUTOS];

    int codigodopedido;
    cout << "Digite o número do cadastro do cliente para listar pedidos realizados: ";
    cin >> codigodopedido;
    int clienteIndex = codigodopedido - 1; // Ajustando o índice para acessar corretamente os vetores
    if (clienteIndex < 0 || clienteIndex >= MAX_CLIENTES)
    {
        cout << "Número de cadastro inválido.\n";
        return;
    }
    else
    {
        cout << "--------------------------------------------------+  PEDIDO  ---------- realizado +-\n";
        cout << "---- Listagem de Pedidos Realizados para Cliente: " << nome[clienteIndex] << " ----\n";
        cout << " endereço: " << endereco[clienteIndex] << "  ";
        cout << "   telefone:" << telefone[clienteIndex] << " ----\n";
        cout << "\n                      PEDIDO REALIZADO " << endl;
        for (int z = 0; z < MAX_PRODUTOS; z++)
        {
            if (produto[z].empty())
            {
                break;
            }
            produtoescolhido[z] = produto[z];
            valordoprodutoescolhido[z] = valorproduto[z];
            quantidadeescolhida[z] = 1; // Presumindo que quantidade é 1, ajuste conforme necessário
            cout << "Produtos: " << produtoescolhido[z] << "  R$: " << valordoprodutoescolhido[z] << "    Qtde.Pedida: " << quantidadeescolhida[z] << endl;
        }
        cout<< "endereço ......................................." << endereco[clienteIndex]<< endl;
        cout << "taxa de entrega R$:........................... " << taxadeentrega[0] << endl;                    // Acessando o índice correto de taxadeentrega
        cout << "total R$:..................................... " << valorfinalpedido + taxadeentrega[0] << endl; // Corrigido para calcular o total correto
        time_t seconds;
        tm *p;
        time(&seconds);
        p = localtime(&seconds);
        cout << "Data da compra: " << p->tm_mday << '/' << (p->tm_mon + 1) << '/' << (p->tm_year + 1900) <<"     ";
        cout << "entrega prevista 7 dias uteis após a compra . ";
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op;

    do
    {
        cout << "" << endl;
        cout << "   __   __  _______  __    _  __   __ " << endl;
        cout << "  |  |_|  ||       ||  |  | ||  | |  |" << endl;
        cout << "  |       ||    ___||   |_| ||  | |  |" << endl;
        cout << "  |       ||   |___ |       ||  |_|  |" << endl;
        cout << "  |       ||    ___||  _    ||       |" << endl;
        cout << "  | ||_|| ||   |___ | | |   ||       |" << endl;
        cout << "  |_|   |_||_______||_|  |__||_______|\n"
             << endl;
        cout << "============== SISTEMA DE LOJA ==============\n";
        cout << "         1 - Cadastrar Cliente\n";
        cout << "         2 - Listar Clientes\n";
        cout << "         3 - Cadastrar Estoque\n";
        cout << "         4 - Listar Estoque\n";
        cout << "         5 - Abrir Catálogo\n";
        cout << "         6 - Fazer Pedido\n";
        cout << "         7 - Listar Pedidos Realizados\n";
        cout << "         0 - Sair\n";
        cout << "=============================================\n";
        cout << "Digite a opção desejada: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cadastrarCliente(nome, telefone, email, endereco, numerocad, MAX_CLIENTES);
            break;
        case 2:
            listarClientes(nome, telefone, email, endereco, MAX_CLIENTES);
            break;
        case 3:
            cadastrarEstoque(produto, codigo_produto, quantidade_de_entrada, preco_custo, valorproduto, MAX_PRODUTOS);
            break;
        case 4:
            listarEstoque(produto, codigo_produto, quantidade_de_entrada, preco_custo, valorproduto, MAX_PRODUTOS);
            break;
        case 5:
            abre_catalogo(produto, valorproduto, MAX_PRODUTOS);
            break;
        case 6:
            fazer_pedido(produto, numerocad, nome, endereco, email, telefone, Vvalorfinalpedido, taxadeentrega, MAX_PRODUTOS);
            break;
        case 7:
            lista_pedido_realizado(produto, valorproduto, taxadeentrega, nome, endereco, email, telefone, MAX_PRODUTOS, MAX_CLIENTES);
            break;
        case 0:
            cout << "Saindo do sistema...\n";
            break;
        default:
            cout << "Opção inválida. Tente novamente.\n";
            break;
        }
    } while (op != 0);

    return 0;
}
