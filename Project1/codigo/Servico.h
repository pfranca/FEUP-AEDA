#pragma once
/**
* Servico.h
*
* Criada a 20 Novembro 2016
* Autor: Grupo I - Turma 4 - MIEIC/AEDA-2016/17
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Servico
{
private:
	string origem;
	string destino;
	int distancia;
	int dia, mes, ano;
	int horainicio, horafim, mininicio, minfim;
	float valor;
	bool pago = false;

public:

	/**
	* Construtor da Classe Servicos
	*
	* @param origem origem da viagem
	* @param destino destino da viagem
	* @param distancia distancia em metros da viagem
	* @param dia dia da data da viagem
	* @param mes mes da data da viagem
	* @param ano ano da data da viagem
	* @param horainicio hora na hora de inicio da viagem
	* @param mininicio minuto na hora de inicio da viagem
	* @param horafim hora na hora do final da viagem
	* @param minfim minuto na hora final da vigem
	*/
	Servico(string origem, string destino,int distancia, int dia, int mes, int ano, int horainicio, int mininicio, int horafim, int minfim);
	
	/**
	* Destrutor de Servicos
	*/
	~Servico();

	/**
	* @return origem da viagem
	*/
	string getOrigem();

	/**
	* @return destino da viagem
	*/
	string getDestino();

	/**
	* @return distancia da viagem
	*/
	int getDistancia();

	/**
	* @return dia na data da viagem
	*/
	int getDia();

	/**
	* @return mes na data da viagem
	*/
	int getMes();

	/**
	* @return ano na data da viagem
	*/
	int getAno();

	/**
	* @return hora na hora de inicio da viagem
	*/
	int getHoraInicio();

	/**
	* @return minuto na hora de inicio da viagem
	*/
	int getMinInicio();

	/**
	* @return hora na hora do final da viagem
	*/
	int getHoraFim();

	/**
	* @return minuto na hora do final da viagem
	*/
	int getMinFim();

	/**
	* @return data formatada da viagem
	*/
	string getData(); 

	/**
	* Calcula duracao da viagem atras dos tempos de inicio e fim introduzidos
	*
	* @return duracao em horas e minutos da viagem
	*/
	string getDuracao(); 

	/**
	* calcula valor da viagem com base na distancia percorrida e na duracao da viagem. tem em conta as horas de pico
	*
	* @return valor do custo da viagem
	*/
	float getValor();

	/**
	* Atribui o valor de pago quando as viagens que so sao pagas no final do mes
	*/
	void setPago();

	/**
	* @return true se uma viagem ja foi paga ou false se ainda nao foi
	*/
	bool getPago();

};

