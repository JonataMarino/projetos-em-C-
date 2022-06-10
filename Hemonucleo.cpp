#include <iostream>
#include <string>
#include <iomanip>
#include <locale.h>
#define Tamanho 100
#include <fstream>

using namespace std;

typedef struct
{
    std::string Nome;
}Paciente;

typedef struct
{
    std::string Localidade;
    std::string Contato;
    int Idade;
}Pessoais;

typedef struct
{
    int RG;
    char Sexo; 
    std::string Tipo_Sanguineo;
    float Peso;
    char Doenca_Cronica;
}Sensiveis;

typedef struct {
  Paciente paciente;
  Pessoais pessoais;
  Sensiveis sensiveis;
}Cadastro;

typedef struct {
  Cadastro qtd[Tamanho];
  int numero_de_cadastros;
}Lista;

void iniciarlista(Lista * L) {
  L -> numero_de_cadastros = 0;
}


void novo_cadastro(Lista * L) {
	setlocale(LC_ALL, "portuguese");
	fstream cad;
  if (L -> numero_de_cadastros < Tamanho) {

    std::cout << "==============================" << std::endl;
    std::cout << "CADASTRAR NOVO PACIENTE" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Informe o nome do doador: ";
    std::ws(std::cin);
    std::getline(std::cin, L -> qtd[L -> numero_de_cadastros].paciente.Nome);
    std::cout << "Local onde reside: ";
    std::ws(std::cin);
    std::getline(std::cin, L -> qtd[L -> numero_de_cadastros].pessoais.Localidade);
    std::cout << "Contato (apenas números) : ";
    std::ws(std::cin);
    std::getline(std::cin, L -> qtd[L -> numero_de_cadastros].pessoais.Contato);
    std::cout << "Informe a Idade do Doador: ";
    scanf("%d", &L -> qtd[L -> numero_de_cadastros].pessoais.Idade);
        if (L -> qtd[L ->numero_de_cadastros].pessoais.Idade < 15 || L-> qtd[L ->numero_de_cadastros].pessoais.Idade >69){
             std::cout << "Atenção! Idade imcompatével com requisitos para doação!" << std::endl;
            do {
                std::cout << "Informe a Idade do Doador: ";
                scanf("%d", &L -> qtd[L -> numero_de_cadastros].pessoais.Idade);
            }while (L -> qtd[L ->numero_de_cadastros].pessoais.Idade < 15 || L-> qtd[L ->numero_de_cadastros].pessoais.Idade >69);
        }else; 
    std::cout << "Informe o documento de identificação (RG) do doador [Digite apenas números]: ";
    scanf("%f", &L -> qtd[L -> numero_de_cadastros].sensiveis.RG);
    std::cout << "Informe o sexo do doador [apenas letra maiúscula] (M)/(F): ";
        std::ws(std::cin);
    scanf("%c", &L -> qtd[L -> numero_de_cadastros].sensiveis.Sexo);
    std::cout << "Informe o tipo sanguíneo do doador: ";    
    std::ws(std::cin);
    std::getline(std::cin, L -> qtd[L -> numero_de_cadastros].sensiveis.Tipo_Sanguineo);
    std::cout << "O doador possui alguma doença crônica? (S)/(N): ";
    std::ws(std::cin);
    scanf("%c", &L -> qtd[L -> numero_de_cadastros].sensiveis.Doenca_Cronica);
    std::cout << "informe o peso do Doador: ";
    scanf("%f", &L -> qtd[L -> numero_de_cadastros].sensiveis.Peso);
    if (L -> qtd[L -> numero_de_cadastros].sensiveis.Peso < 50){
        std::cout << "Peso abaixo do permitido para cadastro de doador!" << std::endl;
        do{
            std::cout << "informe o peso do Doador: ";
            scanf("%f", &L -> qtd[L -> numero_de_cadastros].sensiveis.Peso);
        }while(L -> qtd[L -> numero_de_cadastros].sensiveis.Peso < 50);
    }else;
    std::cout << "==============================" << std::endl;
    cad.open("cadastro.txt", ios::app);
    if(cad.is_open()){
    cad << "Nome: " << L -> qtd[L -> numero_de_cadastros].paciente.Nome <<"\n";
    cad << "Reside em: " << L -> qtd[L -> numero_de_cadastros].pessoais.Localidade << "\n";
    cad << "Contato: " << L -> qtd[L -> numero_de_cadastros].pessoais.Contato << "\n";
    cad << "Idade: " << L -> qtd[L -> numero_de_cadastros].pessoais.Idade << "\n";
    cad << "RG: " << L -> qtd[L -> numero_de_cadastros].sensiveis.RG << "\n";
    cad << "Sexo: " << L -> qtd[L -> numero_de_cadastros].sensiveis.Sexo << "\n";
    cad << "Tipo Sanguíneo: " << L-> qtd[L -> numero_de_cadastros].sensiveis.Tipo_Sanguineo << "\n";
    cad << "Possui doença crônica?: " << L -> qtd[L -> numero_de_cadastros].sensiveis.Doenca_Cronica << "\n";
    cad << "Peso: " << L -> qtd[L -> numero_de_cadastros].sensiveis.Peso <<"\n";
    cad << "==============================" << "\n";
	cad.close();
	}else{
    	std::cout << "Falha ao abrir o arquivo!" << std::endl;
	}
    L -> numero_de_cadastros++;
    return;
    }else {
    std::cout << "Lista Cheia!" << std::endl;
  }
}

void Listar_todos(Lista * L) {

  for (int i = 0; i < L -> numero_de_cadastros; i++) {
    std::cout << "==============================" << std::endl;
    std::cout << "Nome do doador: " << L -> qtd[i].paciente.Nome << "\n";
    std::cout << "Reside em : " << L -> qtd[i].pessoais.Localidade << "\n";
    std::cout << "Contato: " << L -> qtd[i].pessoais.Contato << "\n";
    std::cout << "Idade: " << L -> qtd[i].pessoais.Idade << "\n";
    std::cout << "RG:" << std::setprecision(9) << L -> qtd[i].sensiveis.RG << std::endl;
    std::cout << "Sexo: " << L -> qtd[i].sensiveis.Sexo << "\n";
    std::cout << "Tipo Sanguíneo: " << L -> qtd[i].sensiveis.Tipo_Sanguineo << "\n";
    std::cout << "Possui doença crônica? : " << L -> qtd[i].sensiveis.Doenca_Cronica << "\n";
    std::cout << "Peso: " << std::setprecision(3.2) << L -> qtd[i].sensiveis.Peso << "\n";
    std::cout << "==============================" << std::endl;
  }
}

void Listar_Log() {
    std::string linha;
    ifstream cad_in("cadastro.txt");
    if (cad_in.is_open())
    {
        while (!cad_in.eof())
        {
            std::getline(cad_in, linha);
            std::cout << linha << std::endl;
        }
    }
}

int main()
{
	setlocale(LC_ALL, "portuguese");
    
    int Sair = 0;
    int Opcao;
    int Cont = 0;
    Lista L;
    iniciarlista( & L);

    
while(Sair ==0){
    std::cout << "==============================" << std::endl;
    std::cout << "1 - Cadastrar novo paciente." << std::endl;
    std::cout << "2 - Consultar lista de Doadores cadastrados durante a execução do sistema" << std::endl;
    std::cout << "3 - Consultar lista de Doadores do banco de dados" << std::endl;
    std::cout << "4 - Sair" << std::endl;
    std::cin >> Opcao;
    std::cout << "==============================" << std::endl;
    
    switch (Opcao) {
    case 1: 
        novo_cadastro (&L);
        break;
    case 2: 
        Listar_todos(& L);
        break;
    case 3:
        std::cout << "Cadastros salvos no banco de dados" << std::endl;
        std::cout << "==============================" << std::endl;
        Listar_Log();
        break;
    case 4: 
        std::cout << "Programa encerrado!" << std::endl; 
        Sair = 1;
        break;
    default: std::cout << "Opção Inválida" << std::endl;
    }
}
    return 0;
}
