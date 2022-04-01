/**
 * @file Dados.h
 * @author Pedro Martins Nº23527
 * @date 2022
 * @brief Definições Globais para Lista Ligadas Simples (versão 1)
 *
 *	Structs, Constantes e Assinaturas de Funções  Listas Ligadas Simples
*/

#ifndef DADOS
#define DADOS

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*#pragma warning( disable : 4996 )*/ //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS


#pragma region VERSAO1

/**
 * @brief Estrutura para armazenar as maquinas
 */
typedef struct Maquina {
	int CodMaquina;
	char funcao[N];
	int tempo;	
}Maquina;

typedef struct ListaMaquinas {
	struct Maquina maquina;
	struct ListaMaquinas* seguinte;
}ListaMaquinas;

/**
 * @brief Estrutura para armazenar as operacoes
 */
typedef struct Operacao {
	int codOperacao;
	struct Operacao* seguinte;
	struct Maquina* maquinas;
}Operacao;




void MostraMaquina(ListaMaquinas* h);
ListaMaquinas* InsereMaquinaListaMaquinas(ListaMaquinas* h, Maquina* novamaquina);
ListaMaquinas* CriaNodoListaMaquinas(Maquina* m);
Maquina* criaMaquina(int cod, char* funcao, int tempo);

Operacao* criaOperacao(int cod);
Operacao* InsereOperacao(Operacao* h, Operacao* nova);
Operacao* RemoveOperacao(Operacao* h, int cod);
Operacao* AlteraOperacao(Operacao* h, int cod, int novocod);
bool ExisteOperacao(Operacao* h, int cod);
void MostraMaquinasOperacao(Operacao* inicio, int nc);
void MostraOperacao(Operacao* h);
Operacao* InsereMaquinaOperacao(Operacao* h, Maquina* m, int cod);
Operacao* ProcuraOperacao(Operacao* h, int cod);

void Minimo(Operacao* inicio, Maquina* m, int tempo);
void traverse(Operacao* inicio, Maquina* m, int tempo);
























#pragma endregion


#endif
