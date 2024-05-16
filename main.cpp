//Inclusão de bibliotecas
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include <vector>

using namespace std;

//Declaração das structs
struct Cidade{
    int codigo;
    char nome[50];
    char estado[3];
};
struct Especialidade{
    int codigo;
    char descricao[50];
};
struct Medico{
    int codigo;
    char nome[50];
    int codigo_especialidade;
    char endereco[70];
    char telefone[14];
    int codigo_cidade;
};
struct Paciente{
    char cpf[12];
    char nome[50];
    char endereco[70];
    int codigo_cidade;
};
struct CID{
    char codigo[5];
    char descricao[50];
};
struct Medicamento{
    int codigo;
    char descricao[50];
    int qtd_estoque;
    float estoque_minimo;
    float estoque_maximo;
    float preco;
};
struct Consulta{
    char cpf_paciente[12];
    int codigo_medico;
    char data[11];
    char hora[6];
    char codigo_cid[5];
    int codigo_medicamento;
    int qtd_medicamento;
};

//Prototipação de métodos de busca para utilização geral
Cidade buscarCidade(std::vector<Cidade>, int, int);
Especialidade buscarEspecialidade(std::vector<Especialidade>, int, int);
Medico buscarMedico(std::vector<Medico>, int, int);
Paciente buscarPaciente(std::vector<Paciente>, int, char[]);
Medicamento buscarMedicamento(std::vector<Medicamento>, int, int);
Consulta buscarConsulta(std::vector<Consulta>, int, char[], int, char[], char[]);

void textoInicial();
void inicializacaoDosDados();
void seletorFuncao(int);

//Prototipação de métodos de leitura de dados
void leituraDadosCidades(const vector<Cidade>&);
void leituraDadosEspecialidades(vector<Especialidade>);
void leituraDadosMedicamentos(vector<Medicamento>);
void leituraDadosCid(vector<CID>);

int main() {
    int opcao = 0;
    setlocale(LC_ALL, "Portuguese");
    textoInicial();
    inicializacaoDosDados();
    cout<< endl;
    cout<<"\t\nInforme a opcao desejada{ \n"
    << "\t[1] - Cadastrar novas informacoes \n"
    << "\n\n\n\t[0] - Finalizar \n} " << endl;
    cin >> opcao;
    cin.ignore();
    if(opcao != 0) {
        seletorFuncao(opcao);
    }
}

//Função que escreve o texto inicial do programa
void textoInicial() {
    std::vector<char> textoBemVindo = { '=' ,'=' ,'=' ,'=' ,'[' ,'B', 'e', 'm', ' ', 'V', 'i', 'n', 'd', 'o', ' ', 'a', 'o', ' ', 'G', 'e', 'r', 'e', 'n', 'c', 'i', 'a', 'd', 'o', 'r', ' ', 'd', 'o', ' ', 'H', 'o', 's', 'p', 'i', 't', 'a', 'l' , ']' , '=' ,'=' ,'=' ,'='};
    for (int i = 0; i < textoBemVindo.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0) {
                std::cout<< "\t\t\t\t" << textoBemVindo[j];
            } else {
                std::cout<< textoBemVindo[j];
            }
        }
        if (i < textoBemVindo.size() - 1) {
            system("cls");
        }
    }
}
void inicializacaoDosDados() {
    vector<Cidade> cidades = {
        {1, "São Paulo", "SP"},
        {2, "Belo Horizonte", "SP"},
        {3, "Campos do Jordao", "SP"},
        {4, "Nova Iguacu", "SP"},
        {5, "Assis", "SP"}
    };

    vector<Especialidade> especialidades = {
        {1, "Cardiologia"},
        {2, "Ortopedia"},
        {3, "Pediatria"},
        {4, "Ginecologia"},
        {5, "Clinico Geral"}
    };
    vector<Medico> medicos  = {
        {1, "Dr. Joao", 1, "Rua Ali", "123456789", 1},
        {2, "Dr. Maria", 2, "Rua Alencar", "123456789", 2},
        {3, "Dr. Jose", 1, "Rua Francisca", "123456789", 3},
        {4, "Dr. Pedro", 3, "Rua Benedito", "123456789", 4},
        {5, "Dr. Ana", 1, "Rua Alfredo", "123456789", 5}
    };
    vector<Paciente> pacientes = {
        {"12345678901", "Maria", "Rua Nao", 1},
        {"12345678902", "Joao", "Rua Sim", 2},
        {"12345678903", "Jose", "Rua Talvez", 3},
        {"12345678904", "Pedro", "Rua Depois", 3},
        {"12345678905", "Ana", "Rua Amanha", 1}
    };
    vector<CID> cids = {
        {"C01", "Dor de cabeca"},
        {"C02", "Dor de barriga"},
        {"C03", "Gravidez de risco"},
        {"C04", "Febre alta"},
        {"C05", "Pé Inchado"}
    };
    vector<Medicamento> medicamentos = {
        {1, "Dipirona", 335, 5, 400, 2.00},
        {2, "Paracetamol", 124, 15, 200, 8.00},
        {3, "Ibuprofeno", 213, 2, 250, 6.00},
        {4, "Dorflex", 186, 50, 200, 1.00},
        {5, "Buscopan", 12, 10, 175, 12.00}
    };
    vector<Consulta> consultas = {
        {"12345678901", 1, "01/11/2024", "08:00", "C04", 1, 2},
        {"12345678902", 2, "04/05/2024", "08:30", "C01", 4, 3}
    };
}

void seletorFuncao(int funcaoDesejada) {
    if(funcaoDesejada == 1) {

    } else if(funcaoDesejada == 2) {

    } else if(funcaoDesejada == 3) {

    } else if(funcaoDesejada == 4) {
        cout << "Pacientes";
    } else if(funcaoDesejada == 5) {

    } else if(funcaoDesejada == 6) {

    } else if(funcaoDesejada == 7) {

    } else if(funcaoDesejada == 8) {

    } else if(funcaoDesejada == 9) {

    }
}

void leituraDadosCidades(const vector<Cidade> &cidades) {
    Cidade cidade{};
    cout << "Informe o codigo da cidade: ";
    cin >> cidade.codigo;
    cin.ignore();
    cout << "Informe o nome da cidade: ";
    gets(cidade.nome);
    cout << "Informe o estado da cidade: ";
    gets(cidade.estado);
    for(Cidade c : cidades) {
        if(c.codigo == cidade.codigo) {
            cout << "Codigo ja existente para cidade";
            return;
        }
    }
}






