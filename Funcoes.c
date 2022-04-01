/**
*  @file Funcoes.c
 * @author Pedro Martins Nº23527
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Dados.h"

#pragma region Máquinas

Maquina* criaMaquina(int cod, char* funcao, int tempo)
{
	Maquina* novaMaquina = (Maquina*)malloc(sizeof(Maquina));

	if (novaMaquina == NULL) return NULL;

	novaMaquina->CodMaquina = cod;
	strcpy(novaMaquina->funcao, funcao);
	novaMaquina->tempo = tempo;
	return novaMaquina;
}


ListaMaquinas* CriaNodoListaMaquinas(Maquina* m) {
	ListaMaquinas* nova = (ListaMaquinas*)malloc(sizeof(ListaMaquinas));
	nova->maquina.CodMaquina = m->CodMaquina;
	strcpy(nova->maquina.funcao, m->funcao);
	nova->maquina.tempo = m->tempo;
	nova->seguinte = NULL;
	return nova;
}


ListaMaquinas* InsereMaquinaListaMaquinas(ListaMaquinas* h, Maquina* novamaquina) {
	if (novamaquina == NULL)	return h;	//se novo está vazio
	//Cria novo nodo da lista de contactos
	ListaMaquinas* nova = CriaNodoListaMaquinas(novamaquina);
	if (h == NULL) h = nova;		//se lista está vazia
	else {
		//Assumir que se insere sempre no inicio
		nova->seguinte = h;
		h = nova;
	}
	return h;
}

Operacao* InsereMaquinaOperacao(Operacao* h, Maquina* m, int cod) {
	if (h == NULL) return NULL;	// se lista vazia
	if (m == NULL) return h;	//se contacto não tem informação

	Operacao* aux = ProcuraOperacao(h, cod);
	if (aux) {		//se existe essa pessoa
		aux->maquinas = InsereMaquinaListaMaquinas(aux->maquinas, m);
	}
	return h;
}

void MostraMaquina(ListaMaquinas* h) {
	ListaMaquinas* aux = h;
	if (h = NULL) return NULL;
	while (aux) {
		
		printf("Cod maquina: %d - Funcao: %s - Tempo: %d\n", aux->maquina.CodMaquina, aux->maquina.funcao, aux->maquina.tempo);
		aux = aux->seguinte;
	}
	printf("\n");

}
#pragma endregion



#pragma region Operações

Operacao* criaOperacao(int cod)
{
	Operacao* novaOperacao = (Operacao*)malloc(sizeof(Operacao));

	if (novaOperacao == NULL) return NULL;

	novaOperacao->codOperacao = cod;
	novaOperacao->seguinte = NULL;
	novaOperacao->maquinas = NULL;
	return novaOperacao;
}

Operacao* InsereOperacao(Operacao* h, Operacao* nova) {

	if (nova == NULL) return h;	//Verificar se apontadores são válidos

	//Verificar se o novo jogo já existe!!!
	if (ExisteOperacao(h, nova->codOperacao)) return h;	//se existir não insere!

	if (h == NULL)		//Lista está vazia
	{
		h = nova;
	}
	else
	{
		nova->seguinte = h;	//aponta para onde "h" está a apontar
		h = nova;
	}
	return h;
}

bool ExisteOperacao(Operacao* h, int cod) {
	if (h == NULL) return false;
	Operacao* aux = h;
	while (aux != NULL) {
		if (aux->codOperacao == cod)
			return true;
		aux = aux->seguinte;
	}
	return false;
}

/**
*	@brief Mostra dados de um nodo
*/

	void MostraOperacao(Operacao* h) {
		Operacao* aux = h;
		if (h = NULL) return NULL;
		while (aux) {
			printf("Codigo: %d \n", aux->codOperacao);
			aux = aux->seguinte;
		}
	}

Operacao* RemoveOperacao(Operacao* h, int cod) {
	if (h == NULL) return NULL;			//Lista vazia
	//if (!ExisteJogo(h, cod)) return h;	//se não existe

	if (h->codOperacao == cod) {		//remove no inicio da lista
		Operacao* aux = h;
		h = h->seguinte;
		free(aux);
	}
	else
	{
		Operacao* aux = h;
		Operacao* auxAnt = aux;
		while (aux && aux->codOperacao != cod) {	//procura para revover
			auxAnt = aux;
			aux = aux->seguinte;
		}
		if (aux != NULL) {					//se encontrou, remove
			auxAnt->seguinte = aux->seguinte;
			free(aux);
		}
	}
	return h;
}

Operacao* ProcuraOperacao(Operacao* h, int cod) {
	Operacao* aux = h;
	while (aux) {
		if (aux->codOperacao == cod) return aux;	//se encontrou
		aux = aux->seguinte;
	}
	return NULL;
}

void MostraMaquinasOperacao(Operacao* inicio, int nc) {
	Operacao* aux = inicio;
	aux = ProcuraOperacao(inicio, nc);
	if (aux) {
		ListaMaquinas* iniciomaquinas = aux->maquinas;
		printf("Operacao: %d ", aux->codOperacao);
		MostraMaquina(iniciomaquinas);
		
	}
}


Operacao* AlteraOperacao(Operacao* h, int cod, int novocod) {
	Operacao* aux = ProcuraOperacao(h, cod);
	if (aux != NULL)		//se encontrou o jogo
	{
		aux->codOperacao = novocod;
	}
	return h;
}

void Minimo(Operacao* h, Maquina* m, int minimo)
{

	if (h == NULL) return NULL;

	while (h != NULL) {
		if (m->tempo < minimo)
		{
			minimo = m->tempo;
		}
	}
	return(minimo);
}

void traverse(Operacao* h, Maquina* m, int tempo)
{
	while (h != NULL) {
		printf("%d ", m->tempo);
		h = h->seguinte;
	}
}
#pragma endregion

