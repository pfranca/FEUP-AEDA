#include "Cliente.h"

Cliente::Cliente()
{
	this->nome = "Anonimo";
	this->nif = 0;
}

Cliente::~Cliente()
{
}

Cliente::Cliente(string nome, string morada, const int nif) :
	nome(nome), morada(morada), nif(nif)
{
	//cout << "construtor clirnr\n";
}

string Cliente::getNome()
{
	return nome;
}

void Cliente::setNome(string nome)
{
	this->nome = nome;
}

string Cliente::getMorada()
{
	return morada;
}

void Cliente::setMorada(string morada)
{
	this->morada = morada;
}

int Cliente::getNif()
{
	return nif;
}

vector<Servico> Cliente::gethistorico()
{
	return historico;
}

void Cliente::sethistorico(vector<Servico> a)
{
	historico = a;
}

void Cliente::adicionaServico(Servico s)
{
	historico.push_back(s);
}

string Cliente::getTipo() 
{
	return "Ocasional";
}

void Cliente::displayServicos()
{
	for (int j = 0; j < historico.size(); j++)
	{
		cout << j + 1 << ") Origem: " << historico[j].getOrigem() << "  |  Destino: " << historico[j].getDestino() << "  |  Data:" << historico[j].getData() << "  |  Duracao: " << historico[j].getDuracao() << "  |  ";
		if (historico[j].getPago() == true) {
			cout << "PAGO" << endl;
		}
		else {
			cout << "NAO PAGO" << endl;
		}
		
	}
}

int Cliente::getPontos()
{
	return cartaopontos;
}

void Cliente::setPontos(int a)
{
	cartaopontos += a;
}

void Cliente::resetPontos()
{
	this->cartaopontos = 0;
}
////////////////////////////////////////////////////

ClienteParticular::ClienteParticular(string nome, string morada, const int nif) :
	Cliente(nome, morada, nif)
{
	
}

string ClienteParticular::getTipo()
{
	return "Particular";
}

////////////////////////////////////////////////////

ClienteEmpresarial::ClienteEmpresarial(string nome, string morada, const int nif) :
	Cliente(nome, morada, nif)
{
	
	//cout << "construtor clirnr empre\n";
}

string ClienteEmpresarial::getTipo()
{
	return "Empresarial";
}