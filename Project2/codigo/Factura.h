#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Factura
{
	int nr;
	static int ultimoNr;
	string cliente;
	int nif;
	float valor;
	int dia;
	int mes;
	int ano;
	

public:
	Factura(float valor, int dia, int mes, int ano);
	Factura(string cliente, int nif, float valor,int dia,int mes,int ano);
	~Factura();
	bool operator< (const Factura& f1) const;
	friend ostream& operator<< (ostream& stream, const Factura& f1);
};

