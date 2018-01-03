#include "Source.h"
using namespace std;


Firma f1; //cria firma
Cliente o; //cria cliente ocasiaonal


void menu(){
	cout << "******************** EMPRESA DE TAXIS *********************" << endl << endl;
	cout << "			1-Clientes" << endl;
	cout << "			2-Servico/Viagens" << endl;
	cout << "			3-Pagar mensalidade" << endl;
	cout << "			4-Guardar estado da empresa" << endl;
	cout << "			5-Carregar empresa" << endl;
	cout << "			6-Informacoes" << endl;
	cout << "			0-Sair" << endl;
	cout << string(19, '\n');
	string opt;
	cin >> opt;
	if (opt =="1"){
		menuclientes();
	}
	else if (opt == "2"){
		menuviagens();
	}
	else if (opt == "3"){
		menumensalidade();
	}
	else if (opt == "4")
	{
		guarda();
	}
	else if (opt == "5")
	{
		abre();
	}
	else if (opt == "6") {
		cout << "Consultar relatorio e Doxygen" << endl;
		menu();
	}
	else if (opt == "0"){
		for (int i = 0; i < 50; i++) {
			cout << "ATE A PROXIMA! TENHA UM BOM DIA!"<<endl;
			return;
		}
	}
	else {
		cout << "OPCAO INVALIDA, VOLTE A INTRODUZIR" << endl;
		menu();
	}
	
}

//TUDO FEITO
void menuclientes()
{ 
	cout << "******************** CLIENTES *********************" << endl << endl;
	cout << "		1-Registar Cliente" << endl;
	cout << "		2-Remover Cliente" << endl;
	cout << "		3-Editar Cliente" << endl;
	cout << "		4-Mostrar Listagem Clientes" << endl;
	cout << "		5-Mostrar Pontos" << endl;
	cout << "		0-Voltar ao menu" << endl;
	cout << string(20, '\n');
	string opt;
	cin >> opt;	
	cin.ignore();
	if (opt == "1") {
		cout << "******************** REGISTAR CLIENTE *********************" << endl << endl;
		cout << "			1-Cliente Particular" << endl;
		cout << "			2-Cliente Empresarial" << endl;
		cout << string(25, '\n');
		cin >> opt;
		cin.ignore();
		int nif,aux ;
		if (opt == "1") {
			cout << string(3, '\n');
			cout << "******************** REGISTAR CLIENTE PARTICULAR *********************" << endl << endl;
			cout << "			INTRODUZA NOME: " ; string nm; getline(cin, nm);
			cout << "			INTRODUZA MORADA: "; string mrd; getline(cin, mrd);
			try {
				cout << "			INTRODUZA NIF: "; cin >> nif;
				aux = nif;
				int digits = 0; while (aux != 0) { aux /= 10; digits++; };
				if (digits != 9) { throw 1; } 
				for (int i = 0; i < f1.getClientes().size(); i++) {
					if (f1.getClientes()[i]->getNif() == nif) 
					{
						throw 1;
					}
				}
			}
			catch(int)
			{
				cout << "Algo correu mal! Nif tem de ter 9 digitos! Ou cliente ja existe! Tente de novo." << endl;
				menuclientes();
			}

			ClienteParticular p(nm, mrd, nif);
			f1.adicionaCliente(&p);
			cout << string(25, '\n');
			cout << "Cliente Particular adicionado com sucesso!! \n";
			cin.ignore();
			menuclientes();
				
		}
		else if (opt == "2") {
			cout << string(3, '\n');
			cout << "******************** REGISTAR CLIENTE EMPRESARIAL *********************" << endl << endl;
			cout << "			INTRODUZA NOME: "; string nm; getline(cin, nm);
			cout << "			INTRODUZA MORADA: "; string mrd; getline(cin, mrd);
			cin.clear();
			try {
				cout << "			INTRODUZA NIF: "; cin >> nif;
				aux = nif;
				int digits = 0; while (aux != 0) { aux /= 10; digits++; };
				if (digits != 9) { throw 1; }
				for (int i = 0; i < f1.getClientes().size(); i++) {
					if (f1.getClientes()[i]->getNif() == nif)
					{
						throw 1;
					}
				}
			}
			catch (int)
			{
				cout << "Algo correu mal! Nif tem de ter 9 digitos! Ou cliente ja existe! Tente de novo." << endl;
				menuclientes();
			}
			ClienteEmpresarial p(nm, mrd, nif);
			f1.adicionaCliente(&p);
			cout << string(25, '\n');
			cout << "Cliente Empresarial adicionado com sucesso!! \n";
			cin.ignore();
			menuclientes();
			
		}
		else {
			cout << string(25, '\n');
			cout << "OPCAO INVALIDA!!! REPITA O PROCESSO" << endl;
			menuclientes();
		}

	}
	else if (opt == "2") {
		int aux = f1.getClientes().size();
		cout << string(3, '\n');
		cout << "******************** REMOVER CLIENTE *********************" << endl << endl;
		cout << "LISTA DE CLIENTES:" << endl;
		f1.displayClientes();
		cout << endl << "Introdiza NIF do Cliente que quer remover: "; int anif; cin >> anif; cout << endl;
		f1.removeCliente(anif);
		if (aux == f1.getClientes().size()) {
		cout << "Cliente que tentou remover nao existe! Tente Novamente." << endl;
		menuclientes();
		}
		cout <<endl<< "NOVA LISTA CLIENTES:" << endl;
		f1.displayClientes();
		cout << endl<< "Introduza qualquer valor para voltar ao menu."; string batata; cin >> batata;
		cin.clear();
		menuclientes();

	}
	else if (opt == "3") {
		cout << string(6, '\n');
		cout << "******************** EDITAR CLIENTE *********************" << endl << endl;
		cout << "LISTA DE CLIENTES:" << endl;
		f1.displayClientes(); cout << endl;
		cout << "Introduza o NIF do cliente que pretende editar: "; int bnif; cin >> bnif; //cout << endl;
		//cout << bnif;
		for (int i = 0; i < f1.getClientes().size(); i++) {
			if (f1.getClientes()[i]->getNif() == bnif) {
				cout << "Cliente " << f1.getClientes()[i]->getNome() << endl; 
				cout << "1-Alterar nome" << endl;
				cout << "2-Alterar morada" << endl;
				int opt; cin >> opt;
				if (opt == 1) {
					cin.ignore();
					cout << "Introduza novo nome: "; string anome; getline(cin, anome);
					f1.alteraNome(bnif, anome);
					cout << "Nome alterado com sucesso!!" << endl;
					menuclientes();
				}
				else if (opt == 2) {
					cin.ignore();
					cout << "Introduza nova morada: "; string amrd; getline(cin, amrd);
					f1.alterarMorada(bnif, amrd);
					cout << "Morada alterada com sucesso!!" << endl;
					menuclientes();
				}
			}
			
		}
		
		cout << "O cliente que tentou editar nao existe! Tente novamente!" << endl;
		menuclientes();
	
	}
	else if (opt == "4") {
		cout << string(6, '\n');
		cout << "******************** LISTA CLIENTES *********************" << endl << endl;
		f1.displayClientes();
		cout << endl << "Introduza qualquer valor para voltar ao menu."; string batata; cin >> batata;
		cin.clear();
		menuclientes();
	}
	else if (opt == "5")
	{
		cout << string(6, '\n');
		cout << "******************** MOSTRA PONTOS *********************" << endl << endl;
		cout << "LISTA DE CLIENTES:" << endl;
		f1.displayClientes(); cout << endl;
		cout << "Introduza o NIF do cliente que pretende ver pontos: "; int anif; cin >> anif; //cout << endl;
		for (int i = 0; i < f1.getClientes().size(); i++)
		{
			if (f1.getClientes()[i]->getNif() == anif) {
				cout <<"O Cliente " << f1.getClientes()[i]->getNome()<< " tem "<< f1.getClientes()[i]->getPontos()<< " pontos no cartao. Quando tiver 3 pontos a sua proxima viagem sera gratuita."<<endl;

			}

		}
		cout << endl << "Introduza qualquer valor para voltar ao menu."; string batata; cin >> batata;
		cin.clear();
		menuclientes();
	}
	else if (opt == "0") {
		menu();
	}
	else {
		cout << "OPCAO INVALIDA, VOLTE A INTRODUZIR" << endl;
		menuclientes();
	}
}

//TUDO FEITO
void menuviagens()
{
	cout << "******************** SERVICO *********************" << endl << endl;
	cout << "		1-Nova Viagem" << endl;
	cout << "		2-Listar todas as viagens" << endl;
	cout << "		3-Listar viagens de cliente especifico" << endl;
	cout << "		0-Voltar ao menu" << endl;
	cout << string(20, '\n');
	string origem;
	string destino;
	string opt;
	cin >> opt;
	if (opt == "1")
	{
		cout << "******************** NOVA VIAGEM *********************" << endl << endl;
		cout << "LISTA DE CLIENTES:" << endl;
		f1.displayClientes(); cout << endl;
		cout << "Introduza NIF de cliente(introduza 0 para um Cliente Ocasional): "; int anif; cin >> anif;
		if (anif == 0) {
			cin.ignore();
			cout << "Registo de nova viagem de cliente ocasional " << endl;
			cout << "Introduza Origem: ";getline(cin, origem);
			cout << "Introduza Destino: ";getline(cin, destino);
			cout << "Introduza distancia entre origem e destino(Km): "; int dist; cin >> dist;
			cout << "Introduza data da viagem(dia mes e ano separados por espacos): "; int d, m, a; cin >> d >> m >> a;
			cout << "Introduza hora de inicio(hora e minuto separados por espaco): "; int hi, mi; cin >> hi >> mi; 
			cout << "Introduza hora de fim(hora e minuto separados por espaco): "; int hf, mf; cin >> hf >> mf; 
			cout << "Paga com:" << endl;
			cout << "1-Numerario" << endl;
			cout << "2-Multibanco" << endl<<endl;
			cin >> opt;
			if (opt == "1") 
			{
				Servico s(origem, destino, dist, d, m, a, hi, mi, hf, mf);
				s.setPago();
				cout << "A viagem de " << origem << " ate " << destino << " no dia " << s.getData() << " foi de " << s.getDistancia() << "Km, teve uma duracao de " << s.getDuracao() << "h e teve um custo de " << s.getValor() << "euros que foi pago em numerario."<< endl;
				f1.getClientes()[0]->adicionaServico(s); 
				menuviagens();
			}
			else if (opt == "2")
			{
				Servico s(origem, destino, dist, d, m, a, hi, mi, hf, mf);
				s.setPago();
				cout << "A viagem de " << origem << " ate " << destino << " no dia " << s.getData() << " foi de " << s.getDistancia() << "km, teve uma duracao de " << s.getDuracao() << "h e teve um custo de " << s.getValor() << "euros que foi pago com multibanco." << endl;
				f1.getClientes()[0]->adicionaServico(s);
				menuviagens();
			}
			cin.ignore();
		}
		else if(anif != 0)
		{
			for (int i = 0; i < f1.getClientes().size(); i++) {
						if (f1.getClientes()[i]->getNif() == anif)
						{
							cin.ignore();
							cout << "Registo de nova viagem do cliente " << f1.getClientes()[i]->getNome() << endl;
							cout << "Introduza Origem: "; getline(cin, origem);
							cout << "Introduza Destino: "; getline(cin, destino);
							cout << "Introduza distancia entre origem e destino: "; int dist; cin >> dist;
							cout << "Introduza data da viagem(dia mes e ano separados por espacos): "; int d, m, a; cin >> d >> m >> a;
							cout << "Introduza hora de inicio(hora e minuto separados por espaco): "; int hi, mi; cin >> hi >> mi;
							cout << "Introduza hora de fim(hora e minuto separados por espaco): "; int hf, mf; cin >> hf >> mf;
							Servico s(origem, destino, dist, d, m, a, hi, mi, hf, mf);
							if (f1.getClientes()[i]->getPontos() == 3) {
								s.setPago();
								f1.getClientes()[i]->adicionaServico(s);
								cout << "OS SEUS PONTOS FORAM USADOS E ESTA VIAGEM FOI GRATUITA!!" << endl;
								f1.getClientes()[i]->resetPontos();
								menuviagens();
							}
							cout << "Paga com:" << endl;
							cout << "1-Numerario" << endl;
							cout << "2-Multibanco" << endl;
							cout << "3-Cartao de Credito(acrescimo de 5% ao valor do servico)" << endl;
							cout << "4-Pagar no final do mes(acrescimo de 2% ao valor do servico)" << endl;
							cin >> opt;
							if (opt == "1")
							{
								s.setPago();
								cout << "A viagem de " << origem << " ate " << destino << " no dia " << s.getData() << " foi de " << s.getDistancia() << "Km, teve uma duracao de " << s.getDuracao() << "h, teve um custo de " << s.getValor() << "euros e foi paga em numerario." << endl;
							}
							else if (opt == "2")
							{
								s.setPago();
								cout << "A viagem de " << origem << " ate " << destino << " no dia " << s.getData() << " foi de " << s.getDistancia() << "Km, teve uma duracao de " << s.getDuracao() << "h, teve um custo de " << s.getValor() << "euros e foi paga com multibanco." << endl;
							}
							else if (opt == "3")
							{
								s.setPago();
								cout << "A viagem de " << origem << " ate " << destino << " no dia " << s.getData() << " foi de " << s.getDistancia() << "Km, teve uma duracao de " << s.getDuracao() << "h, teve um custo de " << s.getValor() << "euros e foi paga com cartao de Credito logo teve um valor de " << s.getValor() + (s.getValor() * 0.05) <<"euros."<<endl;
							}
							else if (opt == "4")
							{
								cout << "A viagem de " << origem << " ate " << destino << " no dia " << s.getData() << " foi de " << s.getDistancia() << "Km, teve uma duracao de " << s.getDuracao() << "h, teve um custo de " << s.getValor() << "que NAO FOI PAGO!" << endl;
								cout << s.getValor() << " Valor guardado para pagar na mensalidade(sera acrescentado 2% a este valor)" << endl;
							}
							cin.ignore();
							f1.getClientes()[i]->adicionaServico(s);
							f1.getClientes()[i]->setPontos(1);
							menuviagens();
										
				}
							
			}
			cout << "O cliente que tentou adicionar viagem nao existe! Tente novamente!" << endl;
			menuviagens();
		}
	}
	else if (opt == "2")
	{
		cout << string(6, '\n');
		cout << "******************** LISTA TODAS AS VIAGENS *********************" << endl << endl;
		f1.displayServicosTotais(-1);
		cout << endl << "Introduza qualquer valor para voltar ao menu."; string batata; cin >> batata;
		cin.clear();
		menuviagens();
	}
	else if (opt == "3")
	{
		cout << string(6, '\n');
		cout << "******************** LISTAGEM *********************" << endl << endl;
		cout << "LISTA DE CLIENTES:" << endl;
		f1.displayClientes(); cout << endl;
		cout << "Introduza NIF de cliente: "; int anif; cin >> anif;
		for (int i = 0; i < f1.getClientes().size(); i++)
		{
			if (f1.getClientes()[i]->getNif() == anif)
			{
				cout << "VIAGENS:" << endl;
				f1.displayServicosTotais(i);
				cout << endl << "Introduza qualquer valor para voltar ao menu."; string batata; cin >> batata;
				cin.clear();
				menuviagens();
			}
		}
		cout << "O cliente nao existe! Tente novamente!" << endl;
		menuviagens();
	}
	else if (opt == "0") {
		menu();
	}
	else {
		cout << "OPCAO INVALIDA, VOLTE A INTRODUZIR" << endl;
		menuviagens();
	}

}

//TUDO FEITO
void menumensalidade()
{
	cout << string(20, '\n');
	cout << "******************** PAGAR MENSALIDADE *********************" << endl << endl;
	cout << "LISTA DE CLIENTES:" << endl;
	f1.displayClientes(); cout << endl;
	cout << "		Introduza NIF de cliente: "; int anif; cin >> anif;
	for (int i = 0; i < f1.getClientes().size(); i++)
	{
		if (f1.getClientes()[i]->getNif() == anif)
		{
			f1.displayServicosTotais(i);
			int porpagar = 0;
			float valorpagar = 0;
			for (int j = 0; j < f1.getClientes()[i]->gethistorico().size(); j++)
			{ 
				bool aux = f1.getClientes()[i]->gethistorico()[j].getPago();
				if (aux == false) { porpagar++; }
				
				valorpagar = f1.getClientes()[i]->gethistorico()[j].getValor() + (f1.getClientes()[i]->gethistorico()[j].getValor() * 0.02);

			}
			if(porpagar == 0)
			{
				cout << " O Cliente " << f1.getClientes()[i]->getNome() << " nao tem viagens por pagar"<<endl;
				menu();
			}
			else if (porpagar > 0)
			{
				cout << " O Cliente " << f1.getClientes()[i]->getNome() << " tem " << porpagar << " viagens por pagar num total de " << valorpagar << "ja com a adicao de 2% da mensalidade. Pagar agora? (Y/N)";
				char aux; cin >> aux;
				if (aux == 'Y' || aux == 'y')
				{
					vector<Servico> temp = f1.getClientes()[i]->gethistorico();
					for (int j = 0; j < f1.getClientes()[i]->gethistorico().size(); j++)
					{
						
						temp[j].setPago();
						
					}
					f1.getClientes()[i]->sethistorico(temp);
					cout << "TODAS AS VIAGENS PAGAS COM SUCESSO" << endl;
					menu();
				}
				else
				{
					cout << "NENHUMA OPERACAO REALIZADA" << endl;
					menu();
				}
			}

		}
	}

}

void guarda()
{
	cin.clear();
	cout << "*********************GUARDA EMPRESA*********************" << endl;
	cout << "Introduza nome com que quer guardar(nao use espacos e TEM DE DECORAR O NOME PARA DEPOIS O CARREGAR):" ;
	string a;
	cin >> a;
	a = a + ".txt";
	ofstream ficheiro;
	ficheiro.open(a);
	ficheiro << f1.getClientes().size() << endl;
	for (int i = 1; i < f1.getClientes().size(); i++)
	{
		ficheiro << f1.getClientes()[i]->getTipo() << endl;
		ficheiro << f1.getClientes()[i]->getNome() << endl;
		ficheiro << f1.getClientes()[i]->getMorada() << endl;
		ficheiro << f1.getClientes()[i]->getNif() << endl;
		ficheiro << f1.getClientes()[i]->getPontos() << endl;
		ficheiro << f1.getClientes()[i]->gethistorico().size() << endl;
		for (int j = 0; j < f1.getClientes()[i]->gethistorico().size(); j++)
		{
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getOrigem() << endl;
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getDestino() << endl;
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getDistancia() << endl;
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getDia() << endl;
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getMes() << endl;
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getAno() << endl;
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getHoraInicio() << endl;
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getMinInicio() << endl;
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getHoraFim() << endl;
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getMinFim() << endl;
			ficheiro << f1.getClientes()[i]->gethistorico()[j].getPago() << endl;
		}
	}
	ficheiro.close();
	for (int i = 0; i < 50; i++) {
		cout << "SAVING! SAVING! SAVING! SAVING! SAVING! SAVING! SAVING! SAVING! SAVING! SAVING! SAVING! "<<endl;
	}
	cout << "FIRMA GUARDADA COM SUCESSO!!\n";
	menu();
}

void abre()
{
	cin.clear();
	cout<<"*********************CARREGAR EMPRESA*********************" << endl;
	cout << "Existe um ficheiro de teste com o nome 'melhorfirma'" << endl;
	cout << "Introduza nome do ficheiro:"; 
	string a;
	cin >> a;
	a = a + ".txt";

	string nrcli, tipo, nome, morada, nif, pontos, nrviagens, origem, destino, distancia, dia, mes, ano, hi, mi, hf, mf, pago;
	ifstream ficheiro(a);
	if (ficheiro.is_open())
	{
		getline(ficheiro, nrcli);
		for (int i = 1; i < stoi(nrcli); i++) {
			getline(ficheiro, tipo);
			getline(ficheiro, nome);
			getline(ficheiro, morada);
			getline(ficheiro, nif);
			getline(ficheiro, pontos);

			if (tipo == "Particular") {
				ClienteParticular *p = new ClienteParticular(nome, morada, stoi(nif));
				//ClienteParticular p(nome, morada, stoi(nif));
				p->setPontos(stoi(pontos));
				f1.adicionaCliente(p);
				
				
			}
			else if (tipo == "Empresarial") {
				ClienteEmpresarial *e = new ClienteEmpresarial(nome, morada, stoi(nif));
				e->setPontos(stoi(pontos));
				f1.adicionaCliente(e);
			}
			getline(ficheiro, nrviagens);
			for (int j = 0; j < stoi(nrviagens); j++) {
				getline(ficheiro, origem);
				getline(ficheiro, destino);
				getline(ficheiro, distancia);
				getline(ficheiro, dia);
				getline(ficheiro, mes);
				getline(ficheiro, ano);
				getline(ficheiro, hi);
				getline(ficheiro, mi);
				getline(ficheiro, hf);
				getline(ficheiro, mf);
				getline(ficheiro, pago);
				Servico s(origem, destino, stoi(distancia), stoi(dia), stoi(mes), stoi(ano), stoi(hi), stoi(mi), stoi(hf), stoi(mf));
				if (pago == "1") {
					s.setPago();
				}
				
				f1.getClientes()[i]->adicionaServico(s);

			}
			
		}

	}

	ficheiro.close();
	for (int i = 0; i < 50; i++) {
		cout << "LOADING! LOADING! LOADING! LOADING! LOADING! LOADING! LOADING! LOADING! LOADING! LOADING!"<<endl;
	}
	cout << "FIRMA CARREGADA COM SUCESSO" << endl;
	menu();
}

int main() {
	
	f1.adicionaCliente(&o); // adiciona o cliente ocasioanal a firma com index 0
	
	menu();
	
	
	return 0;
}