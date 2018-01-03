#pragma once
/**
* Cliente.h
*
* Criada a 20 Novembro 2016
* Autor: Grupo I - Turma 4 - MIEIC/AEDA-2016/17
*/
#include "Servico.h"

using namespace std;

class Cliente
{
private:
	string nome;
	string morada;
	int nif;
	vector<Servico> historico;
	int cartaopontos = 0;

public:
	/**
	* Construtor default da classe Cliente usado para criar clientes ocasionais
	*/
	Cliente();

	/**
	* Construtor da classe Cliente usado para criar clientes registados nas clases derivadas
	*
	* @param nome nome do cliente
	* @param morada morada co cliente
	* @param nif nif do cliente
	*/
	Cliente(string nome, string morada, const int nif);

	/**
	* Destrutor da classe Cliente 
	*/
	~Cliente();

	/**
	* @returns  nome do cliente
	*/
	string getNome();

	/**
	* usada para alteracao de nomes de clientes
	* @param nome novo nome
	*/
	void setNome(string nome);

	/**
	* @returns  morada do cliente
	*/
	string getMorada();

	/**
	* usada para alteracao a morada de clientes
	* @param morada nova morada
	*/
	void setMorada(string morada);

	/**
	* @returns  nif do cliente
	*/
	int getNif();

	/**
	* @returns vector historico de servicos do cliente
	*/
	vector<Servico> gethistorico();

	/**
	* usado para pagar viagens mensais. subsitui o vector ja existente por um novo com os pagamenteos actualizados
	*
	* @param a vector de Servicos auxiliar
	*/
	void sethistorico(vector<Servico> a);

	/**
	* adiciona um novo Servico ou vector de servicos do cliente
	*
	* @param s servico a adicionar
	*/
	void adicionaServico(Servico s);

	/**
	* @returns Tipo de cliente (Ocasional, Particular, Empresarial)
	*/
	virtual string getTipo();

	/**
	* Imprime todos os servicos de um cliente
	*/
	void displayServicos();

	/**
	* @returns numero de pontos do cartao de pontos do cliente
	*/
	int getPontos();

	/**
	* altera o valor de pontos do cartao de pontos do cliente
	*/
	void setPontos(int a);

	/**
	* faz reset ao cartao de pontos do cliente quando os pontos sao usados
	*/
	void resetPontos();

};

/**
* ClienteParticular.h
*
* Criada a 20 Novembro 2016
* Autor: Grupo I - Turma 4 - MIEIC/AEDA-2016/17
*/
class ClienteParticular: public Cliente
{
private:
	
public:

	/**
	* Construtor de clientes particulares
	*
	* @param nome nome do cliente
	* @param morada morada co cliente
	* @param nif nif do cliente
	*/
	ClienteParticular(string nome, string morada, const int nif);

	/**
	* @returns Tipo de cliente (Ocasional, Particular, Empresarial)
	*/
	string getTipo();

};

/**
* ClienteEmpresarial.h
*
* Criada a 20 Novembro 2016
* Autor: Grupo I - Turma 4 - MIEIC/AEDA-2016/17
*/
class ClienteEmpresarial: public Cliente
{
private:
	
public:

	/**
	* Construtor de clientes empresariais
	*
	* @param nome nome do cliente
	* @param morada morada co cliente
	* @param nif nif do cliente
	*/
	ClienteEmpresarial(const string nome, string morada, const int nif); 

	/**
	* @returns Tipo de cliente (Ocasional, Particular, Empresarial)
	*/
	string getTipo();
};