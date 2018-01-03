#include "Servico.h"



Servico::Servico(string origem, string destino, int distancia, int dia, int mes, int ano, int horainicio, int mininicio, int horafim, int minfim)
{
	this->origem = origem;
	this->destino = destino;
	this->distancia = distancia;
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
	this->horainicio = horainicio;
	this->mininicio = mininicio;
	this->horafim = horafim;
	this->minfim = minfim;
}

Servico::~Servico()
{
}

string Servico::getOrigem()
{
	return origem;
}

string Servico::getDestino()
{
	return destino;
}

int Servico::getDistancia()
{
	return distancia;
}

int Servico::getDia()
{
	return dia;
}

int Servico::getMes()
{
	return mes;
}

int Servico::getAno()
{
	return ano;
}

int Servico::getHoraInicio()
{
	return horainicio;
}

int Servico::getMinInicio()
{
	return mininicio;
}

int Servico::getHoraFim()
{
	return horafim;
}

int Servico::getMinFim()
{
	return minfim;
}

string Servico::getData()
{
	string data = to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);

	return data;
}

string Servico::getDuracao()
{
	int tempoinicio = horainicio* 60 + mininicio;
	int tempofim = horafim * 60 + minfim;
	int tempo = tempofim - tempoinicio;
	int horaduracao = 0;
	while (tempo>60)
	{
		horaduracao++;
		tempo = tempo - 60;
	}

	//cout << "Duracao: " << horaduracao << ":" << tempo << endl;

	return to_string(horaduracao) +":"+ to_string(tempo);
}

float Servico::getValor()
{
	int tempoinicio = horainicio * 60 + mininicio;
	int tempofim = horafim * 60 + minfim;
	int tempo = tempofim - tempoinicio;

	if ((horainicio >= 8 && horainicio < 10) || (horainicio >= 17 && horainicio < 19))
		valor = 0.20 * tempo + 0.75 * (distancia/1000);
	else
		valor = 0.10 * tempo + 0.65 * distancia;

	return valor;

}

void Servico::setPago()
{
	this->pago = true;
}

bool Servico::getPago()
{
	return pago;
}