#pragma once

/**
* Firma.h
*
* Criada a 20 Novembro 2016
* Autor: Grupo I - Turma 4 - MIEIC/AEDA-2016/17
*/
#include "Cliente.h"
#include "BST.h"

using namespace std;


class Firma
{
private:
	vector<Cliente *> clientes; 
	//unordered_set<Cliente*, , > inativos;
public:
	/**
	* Construtor da Classe Firma
	*/
	Firma();

	/**
	* Destrutor da Classe Firma
	*/
	~Firma();

	/**
	* @return  vector de apontadores para clientes 
	*/
	vector<Cliente *> getClientes();

	/**
	* Adiciona clientes ao vector de clientes
	*
	* @param  *p apontador para cliente
	*/
	void adicionaCliente(Cliente *p);

	/**
	* Remove cliente do vector de clientes
	*
	* @param anif nif do cliente a remover
	*/
	void removeCliente(int anif);

	/**
	* Altera nome de um cliente do vector de clientes
	*
	* @param anif nif do cliente que queremos alterar o nome
	*
	* @param anome novo nome
	*/
	void alteraNome(int anif, string anome);

	/**
	* Altera morada de um cliente do vector de clientes
	*
	* @param anif nif do cliente que queremos alterar a morada
	*
	* @param amrd nova morada
	*/
	void alterarMorada(int anif, string amrd);

	/**
	* Imprime todos os clientes do vector de clientes da Firma
	*/
	void displayClientes();

	/**
	* Imprime todos os servicos de todos os clientes do vector de clientes da Firma ou todos os servicos de um cliente especifico que exista no vector clientes da Firma
	*
	* @param a -1 para imprimir todos ou index do cliente no vector de clientes
	*/
	void displayServicosTotais(int a);

	//void adicionaFatura(Factura f);

};

