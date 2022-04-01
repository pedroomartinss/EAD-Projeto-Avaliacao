/**
*  @file Main.c
 * @author Pedro Martins Nº23527
 * @email a23527@alunos.ipca.pt
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 *	Manipulação de Lista Ligada Simples

 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 * @see http://fnch.users.sourceforge.net/doxygen_c.html
 *
 * @bug bugs desconhecidos.
*/
#include <stdio.h>
#include <locale.h>
#include "Dados.h"

#define MAX 10

int main() {

	setlocale(LC_ALL, "Portuguese");

#pragma region Fase 1

	Maquina* m1 = NULL;
		m1 = criaMaquina(7,123);

	Maquina* m2 = criaMaquina(9,456);
	Maquina* m3 = criaMaquina(111,147);
	Maquina* nova = criaMaquina(15,789);

	Maquina* headLista = NULL;		//inicio da lista


	ListaMaquinas* aux = NULL;
	aux = InsereMaquinaListaMaquinas(aux,m1);
	aux = InsereMaquinaListaMaquinas(aux, m2);
	printf("Lista de Máquinas:\n");
	MostraMaquina(aux);

	Operacao* o1 = criaOperacao(7);
	Operacao* o2 = criaOperacao(9);
	Operacao* o3 = criaOperacao(111);
	Operacao* nova2 = criaOperacao(15);

	Operacao* aux2 = NULL;
	aux2 = InsereOperacao(aux2,nova2);
	aux2 = InsereOperacao(aux2, o1);
	aux2 = InsereOperacao(aux2, o2);
	aux2 = InsereOperacao(aux2, o3);
	
	aux2 = RemoveOperacao(o3,111);
	aux2 = AlteraOperacao(o1,7,12);

	aux2 = InsereMaquinaOperacao(aux2,m1,12);
	aux2 = InsereMaquinaOperacao(aux2, m2, 9);
	aux2 = InsereMaquinaOperacao(aux2, m3, 12);
	printf("Operacao encontrada com o codigo 12:\n");
	MostraMaquinasOperacao(aux2,12);

	printf("Lista de operacoes:\n");
	MostraOperacao(aux2);




	printf("\n");
	Minimo(aux2, m1, 5555);
	traverse(aux2,m1,123);





















	/*headLista = inserirMaquina(headLista, m1);
	headLista = inserirMaquina(headLista, m2);
	headLista = inserirMaquina(headLista, m3);
	headLista = inserirMaquina(headLista, nova);
	*/
	
	//headLista = InsereMaquinaListaMaquinas(headLista, m1);
	////MostraLista2(headLista);

	//Operacao* inicio = NULL;
	//inicio = InsereMaquinaOperacao(inicio, m1, 7);

	//MostraOperacoesComMaquinas(inicio, 7);
	////headLista = gravarOperacoes(o1, nova2);
	//getche();
	/*
	MostraLista2(headLista);
	
	headLista = RemoveMaquina(headLista, 9);
	printf("\nApós remover 9");
	MostraLista2(headLista);
	getche();

	headLista = AlteraMaquina(headLista, 7, 123);

	nova = criaMaquina(7, 963);

	headLista = inserirMaquina(headLista, nova);
	MostraLista2(headLista);
	getche();*/
#pragma endregion
	
	return 1;
}
