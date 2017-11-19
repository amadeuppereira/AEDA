#include "menus.h"
#include "funcoes.h"

void menu() {

	do {
	cout<< "\n\n\n\n\n+------------------------------------------------+\n";
	cout<< "|  Castings TV                                   |\n";
	cout<< "+------------------------------------------------+\n";
	cout<< "| 1. Candidatos                                  |\n";
	cout<< "| 2. Jurados                                     |\n";
	cout<< "| 3. Sessoes                                     |\n";
	cout<< "|                                                |\n";
	cout<< "| 9. Sair                                        |\n";
	cout<< "+------------------------------------------------+\n\n";

	int opcao;

		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuCandidatos();
			break;
		case 2:
			menuJurados();
			break;
		case 3:
			menuSessoes();
			break;
		case 9:
			sair();
			return;
			break;
		default:
			break;
		}

	} while(1);
}

void menuCandidatos() {

	do {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Candidatos                                    |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1. Adicionar Candidato                         |\n";
	cout << "| 2. Remover Candidato                           |\n";
	cout << "| 3. Infomacao dos Candidatos                    |\n";
	cout << "|                                                |\n";
	cout << "| 8. Voltar                                      |\n";
	cout << "+------------------------------------------------+\n\n";

	int opcao;

		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuAdicionaCandidato();
			break;
		case 2:
			menuRemoveCandidato();
			break;
		case 3:
			menuInfoCandidato();
			break;
		case 8:
			return;
			break;
		default:
			break;

		}

	}while (1);
}

void menuJurados() {

	do {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Jurados                                       |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1. Adicionar Jurado                            |\n";
	cout << "| 2. Remover Jurado                              |\n";
	cout << "| 3. Infomacao dos Jurados                       |\n";
	cout << "|                                                |\n";
	cout << "| 8. Voltar                                      |\n";
	cout << "+------------------------------------------------+\n\n";

	int opcao;

		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuAdicionaJurado();
			break;
		case 2:
			menuRemoveJurado();
			break;
		case 3:
			menuInfoJurado();
			break;
		case 8:
			return;
			break;
		default:
			break;
		}

	} while (1);
}

void menuSessoes() {

	do {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Sessoes                                       |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1. Adicionar Sessao                            |\n";
	cout << "| 2. Remover Sessao                              |\n";
	cout << "| 3. Informacao das Sessoes                      |\n";
	cout << "|                                                |\n";
	cout << "| 8. Voltar                                      |\n";
	cout << "+------------------------------------------------+\n\n";

		int opcao;

		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuAdicionaSessao();
			break;
		case 2:
			menuRemoveSessao();
			break;
		case 3:
			menuInfoSessoes();
			break;
		case 8:
			return;
			break;
		default:
			break;
		}
	} while (1);
}

void menuAdicionaCandidato() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Adicionar Candidato                           |\n";
	cout << "+------------------------------------------------+\n\n";

	string nome, morada, arte;
	int dia, mes, ano;
	cin.ignore();
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Morada: ";
	getline(cin, morada);

	do {
		cout << "Data de nascimento: ";
		cin >> dia >> mes >> ano;
		if (cinTeste()) {
			cout << "Valor Invalido!\n";
			continue;
		} else {
			break;
		}

	} while (1);
	cout << "Arte: ";
	cin.ignore();
	getline(cin, arte);

	candidato *c = new candidato(nome, morada, dia, mes, ano, arte);

	try {
		adicionaCandidato(c);
	} catch (candidatoJaExiste &e) {
		cout << e;
		delete c;
		cin.get();
		return;
	}

}

void menuRemoveCandidato() {
	do {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Remover Candidato                             |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1. Remover por Numero                          |\n";
	cout << "| 2. Remover por Nome                            |\n";
	cout << "+------------------------------------------------+\n\n";

	int opcao;
	cout << "Opcao: ";
	cin >> opcao;
	if (cinTeste()) {
		continue;
	}
	switch(opcao) {
	case 1:
		menuRemoveCandidatoNumero();
		return;
		break;
	case 2:
		menuRemoveCandidatoNome();
		return;
		break;
	default:
		break;
	}

	} while(1);

}

void menuRemoveCandidatoNumero() {

	int numero;
	do {
		cout << "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Remover Candidato                             |\n";
		cout << "+------------------------------------------------+\n\n";

		cout << "Numero do candidato: ";
		cin >> numero;
		if (cinTeste()) {
			continue;
		}
		break;

	} while (1);

	try {
		removeCandidato(numero);
	} catch (candidatoNaoExiste &c) {
		cout << c;
		cin.ignore();
		cin.get();
		return;
	}
}

void menuRemoveCandidatoNome() {

	string nome;
	do {
		cout << "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Remover Candidato                             |\n";
		cout << "+------------------------------------------------+\n\n";

		cout << "Nome: ";
		cin.ignore();
		getline(cin,nome);
		if (cinTeste()) {
			continue;
		}
		break;

	} while (1);

	try {
		removeCandidato(nome);
	} catch (candidatoNaoExiste &c) {
		cout << c;
		cin.get();
		return;
	}
}

void menuInfoCandidato() {
	do {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Candidato                          |\n";
	cout << "+------------------------------------------------+\n";
	cout << "| 1. Procurar candidato por numero               |\n";
	cout << "| 2. Todos os candidatos                         |\n";
	cout << "+------------------------------------------------+\n\n";

	int opcao;
	cout << "Opcao: ";
	cin >> opcao;
	if (cinTeste()) {
		continue;
	}
	switch(opcao) {
	case 1:
		menuInfoCandidatoNumero();
		return;
		break;
	case 2:
		menuInfoCandidatoTodos();
		return;
		break;
	default:
		break;
	}

	} while(1);

}

void menuInfoCandidatoNumero() {
	int numero;
	do {
		cout << "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Informacao Candidato                          |\n";
		cout << "+------------------------------------------------+\n\n";

		cout << "Numero do candidato: ";
		cin >> numero;
		if (cinTeste()) {
			continue;
		}
		break;

	} while (1);

	try {
		infoCandidato(numero);
	} catch (candidatoNaoExiste &c) {
		cout << c;
		cin.ignore();
		cin.get();
		return;
	}

}

void menuInfoCandidatoTodos() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Candidatos                         |\n";
	cout << "+------------------------------------------------+\n\n";

	if(candidatosGlobal.size() == 0) {
		cout << "Ainda nao ha nenhum candidato...\n";
		cin.ignore();
		cin.get();
		return;
	}

	for (unsigned int i = 0; i < candidatosGlobal.size(); i++) {
		infoCandidato(candidatosGlobal.at(i));
		cout << " ---- \n";;
	}
	cin.ignore();
	cin.get();
	return;

}

void menuAdicionaJurado() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Adicionar Jurado                              |\n";
	cout << "+------------------------------------------------+\n\n";

	string nome, morada, arte, telemovel;
	cin.ignore();
	cout << "Nome: ";
	getline(cin, nome);
	cout << "Morada: ";
	getline(cin, morada);
	cout << "Arte: ";
	getline(cin, arte);
	cout << "Telemovel: ";
	getline(cin, telemovel);

	jurado *j = new jurado(nome, morada, telemovel, arte);

	try {
		adicionaJurado(j);
	} catch (JuradoJaExiste &e) {
		cout << e;
		delete j;
		cin.get();
		return;
	}

}

void menuRemoveJurado() {

	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Remover Jurado                                |\n";
	cout << "+------------------------------------------------+\n\n";

	string nome;
	cout << "Nome do jurado: ";
	cin.ignore();
	getline(cin, nome);

	try {
		removeJurado (nome);
	} catch (JuradoNaoExiste &e) {
		cout << e;
		cin.get();
		return;
	}
}

void menuInfoJurado() {

	do {
		cout
				<< "\n\n\n\n\n+------------------------------------------------+\n";
		cout << "|  Informacao Jurado                             |\n";
		cout << "+------------------------------------------------+\n";
		cout << "| 1. Procurar jurado por nome                    |\n";
		cout << "| 2. Todos os jurados                            |\n";
		cout << "+------------------------------------------------+\n\n";

		int opcao;
		cout << "Opcao: ";
		cin >> opcao;
		if (cinTeste()) {
			continue;
		}
		switch (opcao) {
		case 1:
			menuInfoJuradoNome();
			return;
			break;
		case 2:
			menuInfoJuradoTodos();
			return;
			break;
		default:
			break;
		}

	} while (1);
}

void menuInfoJuradoNome() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Jurado                             |\n";
	cout << "+------------------------------------------------+\n\n";

	string nome;
	cout << "Nome do jurado: ";
	cin.ignore();
	getline(cin,nome);


	try {
		infoJurado(nome);
	} catch (JuradoNaoExiste &c) {
		cout << c;
		cin.ignore();
		cin.get();
		return;
	}
}

void menuInfoJuradoTodos() {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Jurados                            |\n";
	cout << "+------------------------------------------------+\n\n";

	if(juradosGlobal.size() == 0) {
		cout << "Ainda nao ha nenhum jurado...\n";
		cin.ignore();
		cin.get();
		return;
	}

	for (unsigned int i = 0; i < juradosGlobal.size(); i++) {
		infoJurado(juradosGlobal.at(i));
		cout << " ---- \n";;
	}
	cin.ignore();
	cin.get();
	return;

}

void menuAdicionaSessao() {

	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Adicionar Sessao                              |\n";
	cout << "+------------------------------------------------+\n\n";

	string arte;
	int data[3];
	cin.ignore();
	cout << "Arte da sessao: ";
	getline(cin, arte);

	do {
		cout << "Data: ";
		cin >> data[0] >> data[1] >> data[2];
		if (cinTeste()) {
			cout << "Valor Invalido!\n";
			continue;
		} else {
			break;
		}

	} while (1);

	sessao *s = new sessao(arte,data);

	try {
		adicionaSessao(s);
	} catch (sessaoJaExiste &sessao) {
		cout << sessao;
		delete s;
		cin.get();
		return;
	}

	menuAdicionaCandidatosSessao(s);
	menuAdicionaJuradosSessao(s);

}

void menuRemoveSessao() {

	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Remover Sessao                                |\n";
	cout << "+------------------------------------------------+\n\n";

	string arte;
	vector<int> data(3);
	cin.ignore();
	cout << "Arte da sessao: ";
	getline(cin, arte);

	do {
		cout << "Data: ";
		cin >> data[0] >> data[1] >> data[2];
		if (cinTeste()) {
			cout << "Valor Invalido!\n";
			continue;
		} else {
			break;
		}

	} while (1);

	try {
		removeSessao(arte, data);
	} catch (sessaoNaoExiste &sessao) {
		cout << sessao;
		cin.get();
		return;
	}
}

void menuAdicionaCandidatosSessao(sessao* s) {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Adicionar Candidatos a Sessao                 |\n";
	cout << "+------------------------------------------------+\n\n";
	cout << "Candidatos disponiveis para a sessao:\n";

	vector<int> candidatos = candidatosDisponiveis(s);

	int n;
	do {
		cout << "Adicionar quantos candidatos? \n";
		cin >> n;
		if (cinTeste()) {
			cout << "Valor Invalido!\n";

		} else {
			break;
		}
	} while(1);

	for(unsigned int i = 1; i < n; i++) {
		int numero;
		bool flag = false;
		do {
			cout << "Numero do candidato " << i << "? ";
			cin >> numero;
			if (cinTeste()) {
				cout << "Valor Invalido!\n";

			} else {
				break;
			}
		} while (1);

		for(unsigned int j = 0; j < candidatos.size(); j++) {
			if(candidatos.at(i) == numero) {
				flag = true;
				break;
			}
		}

		if(flag) {
			try {
				adicionaCandidatoSessao(n, s);
			} catch (candidatoOcupado &c){
				cout << c;
				cin.get();
			}

		}

	}

	cin.get();
	return;

}

void menuAdicionaJuradosSessao(sessao* s) {
	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Adicionar Jurados a Sessao                    |\n";
	cout << "+------------------------------------------------+\n\n";

	int nJurados = s->getNumeroJurados();
	if(nJurados == 3) {
		cout << "A sessao ja tem 3 jurados!\n";
		cin.get();
		return;
	}
	cout << "Jurados disponiveis para a sessao:\n";

	vector<string> jurados = juradosDisponiveis(s);

	for(unsigned int i = nJurados+1; i <= 3; i++) {
		string nome;
		bool flag = false;

		if(i == 1)
			cout << "Nome do jurado principal ? ";
		else
			cout << "Nome do jurado " << i << " ? ";
		getline(cin, nome);

		for(unsigned int j = 0; j < jurados.size(); j++) {
			if(jurados.at(i) == nome) {
				flag = true;
				break;
			}
		}

		if(flag) {
			try {
				adicionaJuradoSessao(nome, s);
			} catch (juradoOcupado &j){
				cout << j;
				cin.get();
			}

		}

	}

	cin.get();
	return;

}

void menuInfoSessoes() {

	cout << "\n\n\n\n\n+------------------------------------------------+\n";
	cout << "|  Informacao Sessao                             |\n";
	cout << "+------------------------------------------------+\n";

	string arte;
	vector<int> data(3);
	cin.ignore();
	cout << "Arte da sessao: ";
	getline(cin, arte);

	do {
		cout << "Data: ";
		cin >> data[0] >> data[1] >> data[2];
		if (cinTeste()) {
			cout << "Valor Invalido!\n";
			continue;
		} else {
			break;
		}

	} while (1);

	try {
		displayInfoSessao(arte, data);
	} catch (sessaoNaoExiste &s) {
		cout << s;
		cin.get();
	}




}
