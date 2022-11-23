#include <iostream>
#include <fstream> // ofstream e ifstream
using namespace std;

class Pessoa
{
private:
	string nome;
	int idade;
	int rg;
	int cpf;
	string ende;
	int cep;
	string bairro;
	string cidade;
	string estado;

public:
	string& getNome()
	{
		return nome;
	}

	int getIdade()
	{
		return idade;
	}
	int getRg()
	{
		return rg;
	}
	int getCpf()
	{
		return cpf;
	}
	string& getEnde()
	{
		return ende;
	}
	int getCep()
	{
		return cep;
	}
	string& getBairro()
	{
		return bairro;
	}
	string& getCidade()
	{
		return cidade;
	}
	string& getEstado()
	{
		return estado;
	}


	void setNome(string& nome)
	{
		this->nome = nome;
	}

	void setIdade(int idade)
	{
		this->idade = idade;
	}
	void setRg(int rg)
	{
		this->rg = rg;
	}
	void setCpf(int cpf)
	{
		this->cpf = cpf;
	}
	void setEnde(string& ende)
	{
		this->ende = ende;
	}
	void setCep(int cep)
	{
		this->cep = cep;
	}
	void setBairro(string& bairro)
	{
		this->bairro = bairro;
	}
	void setCidade(string& cidade)
	{
		this->cidade = cidade;
	}
	void setEstado(string& estado)
	{
		this->estado = estado;
	}

	// sobrecarga do operador de inserção de dados <<
	// ostream = output stream
	friend ostream& operator<<(ostream& os, const Pessoa& p)
	{
		// escrever cada membro
		os << "\n" << p.nome << "\n";
		os << p.idade;
		os << "\n" << p.rg << "\n";
		os << p.cpf;
		os << "\n" << p.ende << "\n";
		os << p.cep;
		os << "\n" << p.bairro << "\n";
		os << p.cidade;
		os << "\n" << p.estado << "\n";
		return os;
	}

	// sobrecarga do operador de extração de dados >>
	// istream = input stream
	friend istream& operator>>(istream& is, Pessoa& p)
	{
		// ler cada membro
		is >> p.nome >> p.idade;
		is >> p.rg >> p.cpf;
		is >> p.ende >> p.cep;
		is >> p.bairro >> p.cidade >> p.estado;
		return is;
	}
};

char menu()
{
	char resp;

	cout << "Digite 1 para inserir pessoas\n";
	cout << "Digite 2 para listar as pessoas\n";
	cout << "Digite 0 para sair\n";
	cout << "Opcao: ";
	cin >> resp;
	return resp;
}

int main(int argc, char *argv[])
{
	char resp;

	while(true)
	{
		resp = menu();
		if(resp == '1')
		{
			Pessoa pessoa;
			string nome;
			int idade;
			int rg;
			int cpf;
			string ende;
			int cep;
			string bairro;
			string cidade;
			string estado;


			// app = append (adiciona ao final do arquivo)
			ofstream ofs("arquivo.txt", fstream::app);

			cout << "\nDigite o nome da pessoa: ";
			cin >> nome;
			cout << "Digite a idade da pessoa: ";
			cin >> idade;
			cout << "\nDigite o rg da pessoa: ";
			cin >> rg;
			cout << "\nDigite o cpf da pessoa: ";
			cin >> cpf;
			cout << "\nDigite o endereço da pessoa: ";
			cin >> ende;
			cout << "\nDigite o cep da pessoa: ";
			cin >> cep;
			cout << "\nDigite o bairro da pessoa: ";
			cin >> bairro;
			cout << "\nDigite a cidade da pessoa: ";
			cin >> cidade;
			cout << "\nDigite o estado da pessoa: ";
			cin >> estado;

			// seta o nome e a idade
			pessoa.setNome(nome);
			pessoa.setIdade(idade);
			pessoa.setRg(rg);
			pessoa.setCpf(cpf);
			pessoa.setEnde(ende);
			pessoa.setCep(cep);
			pessoa.setBairro(bairro);
			pessoa.setCidade(cidade);
			pessoa.setEstado(estado);
			ofs << pessoa;

			ofs.close();
		}
		else if(resp == '2')
		{
			Pessoa p;
			ifstream ifs("arquivo.txt");

			cout << "\nListando pessoas...\n\n";

			// verifca se o arquivo existe e se é possível ler
			if(ifs.good())
			{
				// eof = end of file
				// enquanto NÃO chegar ao final do arquivo
				while(!ifs.eof())
				{
					ifs >> p; // faz a extração dos dados

					// mostrar os dados
					cout << "Nome: " << p.getNome() << "\n";
					cout << "Idade: " << p.getIdade() << "\n\n";
					cout << "Rg: " << p.getRg() << "\n\n";
					cout << "Cpf: " << p.getCpf() << "\n\n";
					cout << "Endereço: " << p.getEnde() << "\n\n";
					cout << "Cep: " << p.getCep() << "\n\n";
					cout << "Bairro: " << p.getBairro() << "\n\n";
					cout << "Cidade: " << p.getCidade() << "\n\n";
					cout << "Estado: " << p.getEstado() << "\n\n";
				}
				ifs.close();
			}
			else
			{
				cout << "Falha ao abrir o arquivo!\n\n";
			}
		}
		else if(resp == '0')
		{
			cout << "\nBye!\n";
			break;
		}
		else
		{
			cout << "\nOpcao invalida. Tente novamente...\n\n";
		}
	}

	return 0;
}