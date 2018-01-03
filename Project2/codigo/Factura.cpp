#include "Factura.h"

int Factura::ultimoNr = 0;

Factura::Factura(float valor, int dia, int mes, int ano) : nr(++ultimoNr)
{
	this->cliente = "Servico Ocasional";
	this->nif = 000000000;
	this->valor = valor;
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

Factura::Factura(string cliente, int nif, float valor, int dia, int mes, int ano): nr(++ultimoNr)
{
	this->cliente = cliente;
	this->nif = nif;
	this->valor = valor;
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}


Factura::~Factura()
{
}


bool Factura::operator<(const Factura& f1) const
{
	if (this->nif == f1.nif) {
		if (this->ano < f1.ano)
			return true;
		else if (this->mes < f1.mes)
			return true;
		else if (this->dia < f1.dia)
			return true;
		else return false;
	}
	else if (this->nif < f1.nif)
		return true;
	else return false;
}

ostream& operator<< (ostream& stream, const Factura& f1) 
{
	return stream << "Fatura nr: " << f1.nr<< " Cliente: " <<f1.cliente << " Valor: " << f1.valor << " Data: " << f1.dia << " / " << f1.mes << " / " << f1.ano;
}