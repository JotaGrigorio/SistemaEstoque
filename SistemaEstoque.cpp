#include <iostream>
#include<string>
#include <locale.h>
#include<stdlib.h>
#include<vector>

using namespace std;

const int CADASTRAR_PRODUTO = 1; 
const int EXIBIR_ESTOQUE = 2;
const int EFETUAR_PEDIDO = 3;
const int ATUALIZAR_ESTOQUE = 4;
const int SAIR_SISTEMA = 5;

int qtdeProduto = 0, i = 0, codProdSolicitado = 0, qtdeProdDesejada = 0, codProdAtualizado = 0;
int novaQtdeProduto = 0;

struct infoProduto {
	int codProduto;
	std :: string nomeProduto;
	int estoqueProduto;
	int estoqueMinProduto;
};

void sairPrograma(){
	exit(0);
}

void exibirCabecalho(){
	std :: cout << "================================================" << std :: endl;
	std :: cout << "============ JUNIO GRIGÓRIO DA SILVA ===========" << std :: endl;
	std :: cout << "============ TÉCNICAS DE PROGRAMAÇÃO ===========" << std :: endl;
	std :: cout << "============== PROFº ANDRÉ FURLAN ==============" << std :: endl;
	std :: cout << "================================================" << std :: endl;
	std :: cout << "----- SGE - SISTEMA GERENCIADOR DE ESTOQUE -----\n" << std :: endl;
}

std :: vector<struct infoProduto> listaProdutos;

void cadastrarProduto() {
	
	exibirCabecalho();
	std :: cout << "------------- CADASTRO DE PRODUTOS -------------\n" << std :: endl;
	
	std :: cout << "Deseja cadastrar quantos produtos? ";
	std :: cin >> qtdeProduto;
		
	struct infoProduto novoProduto ;
	
	for(i = 0; i < qtdeProduto; i++)
	{
		std :: cout << "\nDigite o código do produto: ";
		std :: cin >> novoProduto.codProduto;
		
		std :: cout << "Digite o nome do produto: ";
		std :: cin >> novoProduto.nomeProduto;
		
		std :: cout << "Digite a quantidade em estoque do produto: ";
		std :: cin >> novoProduto.estoqueProduto;
		
		std :: cout << "Digite a quantidade mínima exigida do produto em estoque: ";
		std :: cin >> novoProduto.estoqueMinProduto;
		
		std :: cin.ignore();
		
		listaProdutos.push_back(novoProduto);

	}
	
	std :: cout << "\nCadastro efetuado com sucesso!!! :) \n"  << std :: endl;
	system("pause");
	system("cls");
}

void exibirEstoque(){
	
	exibirCabecalho();	
	std :: cout << "-------------------- ESTOQUE -------------------\n" << std :: endl;	
	
	if(listaProdutos.empty() == false){
		std :: cout << "Código -x- Nome -x- Quantidade" << std :: endl;
		std :: cout << "==============================\n" << std :: endl;
	   	
		for(int i = 0; i < listaProdutos.size(); i++){
			if(listaProdutos[i].estoqueProduto <= listaProdutos[i].estoqueMinProduto) {
				std :: cout << "ALERTA: Estoque do produto " << listaProdutos[i].nomeProduto << " em baixa!!! :/\n";
				std :: cout << "Estoque mínimo exigido do produto: " << listaProdutos[i].estoqueMinProduto<< " unidades" << std :: endl;;
				std :: cout << "" << std :: endl;
			}
			std :: cout << listaProdutos[i].codProduto << " -x- " << listaProdutos[i].nomeProduto << " -x- " << listaProdutos[i].estoqueProduto << std :: endl;
			std :: cout << "" << std :: endl;	
		}
			
		system("pause");
		system("cls");	
	}
	else
	{
	   	std :: cout << "Não há produtos no estoque neste momento :(\n" << std :: endl;
		system("pause");
		system("cls");
	}
}

void atualizarEstoque() {
	exibirCabecalho();
	std :: cout << "--------------- ATUALIZAR ESTOQUE --------------\n" << std :: endl;
	
	if(listaProdutos.empty() ==  false) {
		
		std :: cout << "Digite o código do produto a ser atualizado: ";
		std :: cin >> codProdAtualizado;
		 			
		i = 0;
					
		while ((codProdAtualizado != listaProdutos[i].codProduto) && (i < listaProdutos.size()))
		{
			i = i + 1;
		}
		
		if (i < listaProdutos.size()) 
		{
			std :: cout << "Digite a nova quantidade do produto: ";
			std :: cin >> novaQtdeProduto;
			std :: cout << "" << std :: endl;
			swap(novaQtdeProduto, listaProdutos[i].estoqueProduto);
			std :: cout << "Produto atualizado com sucesso!!! :)" << std :: endl;
			std :: cout << "" << std :: endl;
			system("pause");
			system("cls");
		}
		else 
		{
			std :: cout << "" << std :: endl;
			std :: cout << "Código do produto não encontrado. :(" << std :: endl;
			std :: cout << "" << std :: endl;
			system("pause");
			system("cls");
			exibirEstoque();
		}
	}
	else
	{
		std :: cout << "Não há produtos no estoque neste momento :(\n" << std :: endl;
		system("pause");
		system("cls");
	}
}

void efetuarPedido(){
	
		exibirCabecalho();
		std :: cout << "-------------------- PEDIDO --------------------\n" << std :: endl;
		
		if(listaProdutos.empty() ==  false) {
			
			std :: cout << "Digite o código do produto desejado: ";
			std :: cin >> codProdSolicitado;
			 			
			i = 0;
						
			while ((codProdSolicitado != listaProdutos[i].codProduto) && (i < listaProdutos.size()))
			{
				i = i + 1;
			}
			
			if (i < listaProdutos.size()) 
			{
				std :: cout << "Digite a quantidade desejada: ";
				std :: cin >> qtdeProdDesejada;
							
				if(qtdeProdDesejada <= listaProdutos[i].estoqueProduto)
				{
					std :: cout << "\nPedido atendido, obrigado e volte sempre!!! :) \n" << std :: endl;
					listaProdutos[i].estoqueProduto = listaProdutos[i].estoqueProduto - qtdeProdDesejada;
					system("pause");
					system("cls");
					exibirEstoque();
				}
				else 
				{
					std :: cout << "\nNão temos estoque suficiente deste produto. :( \n" << std :: endl;
					system("pause");
					system("cls");
					exibirEstoque();		
				} 
			}
			else 
			{
				std :: cout << "" << std :: endl;
				std :: cout << "Código do produto não encontrado. :(" << std :: endl;
				std :: cout << "" << std :: endl;
				system("pause");
				system("cls");
				exibirEstoque();
			}
		}
		else
		{
			std :: cout << "Não há produtos no estoque neste momento :(\n" << std :: endl;
			system("pause");
			system("cls");
		}
}

int exibirMenu(){
	
	exibirCabecalho();
	std :: cout << "--------------------- MENU ---------------------\n" << std :: endl;
	
	std :: cout << "Escolha uma das opções abaixo:\n" << std :: endl;
	std :: cout << CADASTRAR_PRODUTO <<" - Cadastrar produtos" << std :: endl; 
	std :: cout << EXIBIR_ESTOQUE <<" - Exibir o estoque" << std :: endl;
	std :: cout << EFETUAR_PEDIDO <<" - Efetuar um pedido" << std :: endl;
	std :: cout << ATUALIZAR_ESTOQUE <<" - Atualizar o estoque" << std :: endl;
	std :: cout << SAIR_SISTEMA <<" - Sair\n" << std :: endl;
	int escolha = 0;
	std :: cin >> escolha ;
	system("cls");
    return escolha ; 
}

int main( int argc , char ** argv ) {
	
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	while(true){
		
		int escolha = exibirMenu();
		
		if(escolha==CADASTRAR_PRODUTO){
			cadastrarProduto();
		}
		if(escolha==EXIBIR_ESTOQUE){
			exibirEstoque();
		}
		if(escolha==EFETUAR_PEDIDO){
			efetuarPedido();
		}
		if(escolha==ATUALIZAR_ESTOQUE){
			atualizarEstoque();
		}
		if(escolha==SAIR_SISTEMA){
			sairPrograma();
		}
	}		
}	