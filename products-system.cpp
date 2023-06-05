#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int code = 0;

struct Products {
	
	char nameProducts[50];
	float prices;
	int stocks;
	char suppliers[50];
	
};

struct Products prdct[9];

void exitSystem() {
	
	printf("#==============================#");
	printf("\n#  OBRIGADO PELA PREFERÊNCIA!  #");
	printf("\n#==============================#\n");
	system("exit");
	
}

void searchProduct() {
	
	int codee;
	
	printf("#=======================#");
	printf("\n#    BUSCAR PRODUTO     #");
	printf("\n#=======================#");
	printf("\n\nInsira o Código do Produto -> ");
	scanf(" %d", &codee);
	
	system("cls");
	codee--;
	
	if (codee < 0 || codee > code) {
		
		printf("#===============================#");
		printf("\n#    PRODUTO NÃO CADASTRADO!    #");
		printf("\n#===============================#\n");
		
		system("pause");
		system("cls");
		
	} else {
		
			printf("#===========================#");
			printf("\n#    PRODUTO ENCONTRADO!    #");
			printf("\n#===========================#");
			printf("\n");
			printf("\n|Produto: %s", prdct[codee].nameProducts);
			printf("\n|Preço: R$%.2f", prdct[codee].prices);
			printf("\n|Estoque: %d", prdct[codee].stocks);
			printf("\n|Fornecedor: %s", prdct[codee].suppliers);
			printf("\n");
			printf("\n#===========================#");
			
			system("pause");
			system("cls");
		
	}
	
}

void registerProduct() {
	
	char newRegister;
	
	if (code > 9) {
		
		printf("#=======================================#");
		printf("#   SISTEMA CHEIO! (MAX. 10 PRODUTOS)   #");
		printf("#=======================================#");
		system("exit");
		
	} else {
		
		do{
		
			printf("#=======================#");
			printf("\n#   CADASTRAR PRODUTO   #");
			printf("\n#=======================#");
			
			fflush(stdin);
			printf("\n\nNome do Produto -> ");
			gets(prdct[code].nameProducts);
			
			printf("Preço do Produto -> R$");
			scanf(" %f", &prdct[code].prices);
			
			printf("Estoque Disponível -> ");
			scanf(" %d", &prdct[code].stocks);
			
			fflush(stdin);
			printf("Fornecedor -> ");
			gets(prdct[code].suppliers);
			
			printf("\nCódigo do Produto: %d", ++code);
			printf("\n - Deseja Cadastrar Novo Produto? (S/N) -> ");
			scanf(" %c", &newRegister);
			
			system("cls");
		
		} while (toupper(newRegister) == 'S');
		
	}
	
}

void redirect(int option) {
	
	switch (option) {
		
		case 1:
			
			system("color 1f");
			registerProduct();
			break;
			
		case 2:
			
			searchProduct();
			break;
			
		case 3:
			
			exitSystem();
			break;
		
	}
	
}

int main() {
	setlocale(LC_ALL, "portuguese");
	
	int opt;
	
	while (opt != 3) {
		
		printf("#=======================#");
		printf("\n#         MENU          #");
		printf("\n#=======================#");
		printf("\n|                       |");
		printf("\n|1 - Cadastrar Produto  |");
		printf("\n|2 - Buscar Produto     |");
		printf("\n|3 - Sair do Sistema    |");
		printf("\n|                       |");
		printf("\n#=======================#");
		
		printf("\n\n-> ");
		scanf(" %d", &opt);
		
		system("cls");
		redirect(opt);
		
	}
	
}
