#include "Firma.h"
//#include "Cliente.h"


Firma::Firma()
{
}


Firma::~Firma()
{
}

vector<Cliente *> Firma::getClientes()
{
	return clientes;
}

 void Firma::adicionaCliente(Cliente *p)
{
	clientes.push_back(p);
}

 void Firma::removeCliente(int anif)
 {
	 for (int i = 0; i < clientes.size(); i++)
	 {
		 if (clientes[i]->getNif() == anif) {
			 cout << "Cliente " << clientes[i]->getNome() << " ELIMINADO com sucesso!!" << endl;
			 clientes.erase(clientes.begin() + i);
			 i--;
		 }
	
	 }
	
 }
 
 void Firma::alteraNome(int anif, string anome)
 {
	 for (int i = 0; i < clientes.size(); i++)
	 {
		 if (clientes[i]->getNif() == anif) {
			 clientes[i]->setNome(anome);
		 }
	 }
 }
 
 void Firma::alterarMorada(int anif, string amrd)
 {
	 for (int i = 0; i < clientes.size(); i++)
	 {
		 if (clientes[i]->getNif() == anif) {
			 clientes[i]->setMorada(amrd);
		 }
	 }
 }

 void Firma::displayClientes()
 {
	 for (int i = 1; i < clientes.size(); i++)
	 {
		 cout <<i<< ") Nome: " << clientes[i]->getNome() << "  |  Morada: " << clientes[i]->getMorada() << "  |  Nif: " << clientes[i]->getNif() << "  |  Tipo: " << clientes[i]->getTipo() << endl;
	 }
 }

 void Firma::displayServicosTotais(int a)
 {
	 if (a == -1)
	 {
		 for (int i = 0; i < clientes.size(); i++)
		 {
			 clientes[i]->displayServicos();
		 }
	 }
	 else
	 {
		 clientes[a]->displayServicos();
	 }
 }
