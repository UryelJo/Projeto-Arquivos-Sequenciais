#include<iostream>
#include<cstring>

using namespace std;

//Estrutura de dados
struct Cidades{
    int codigo;
    char nome[50];
    char estado[2];
};
struct Especialidades{
    int codigo;
    char descricao[50];
};
struct Medicos{
    int codigo;
    char nome[50];
    int codigo_especialidade;
    char endereco[70];
    char telefone[14];
    int codigo_cidade;
};
struct Pacientes{
    char cpf[12];
    char nome[50];
    char endereco[70];
    int codigo_cidade;
};
struct CID{
    char codigo[5];
    char descricao[50];
};
struct Medicamentos{
    int codigo;
    char descricao[50];
    int qtd_estoque;
    float estoque_minimo;
    float estoque_maximo;
    float preco;
};
struct Consultas{
    char cpf_paciente[12];
    int codigo_medico;
    char data[10];
    char hora[5];
    int codigo_cid;
    int codigo_medicamento;
    int qtd_medicamento;
};

//Métodos de busca para utilização geral
void buscarCidade(Cidades cidades[], int n, int codigo){
    for(int i = 0; i < n; i++){
        if(cidades[i].codigo == codigo){
            cout << "Cidade: " << cidades[i].nome << endl;
            cout << "Estado: " << cidades[i].estado << endl;
            break;
        }
    }
}
void buscarEspecialidade(Especialidades especialidades[], int n, int codigo){
    for(int i = 0; i < n; i++){
        if(especialidades[i].codigo == codigo){
            cout << "Especialidade: " << especialidades[i].descricao << endl;
            break;
        }
    }
}
void buscarMedico(Medicos medicos[], int n, int codigo){
    for(int i = 0; i < n; i++){
        if(medicos[i].codigo == codigo){
            cout << "Medico: " << medicos[i].nome << endl;
            cout << "Especialidade: " << medicos[i].codigo_especialidade << endl;
            cout << "Endereco: " << medicos[i].endereco << endl;
            cout << "Telefone: " << medicos[i].telefone << endl;
            cout << "Cidade: " << medicos[i].codigo_cidade << endl;
            break;
        }
    }
}
void buscarPaciente(Pacientes pacientes[], int n, char cpf[]){
    for(int i = 0; i < n; i++){
        if(strcmp(pacientes[i].cpf, cpf) == 0){
            cout << "Paciente: " << pacientes[i].nome << endl;
            cout << "Endereco: " << pacientes[i].endereco << endl;
            cout << "Cidade: " << pacientes[i].codigo_cidade << endl;
            break;
        }
    }
}
void buscarMedicamento(Medicamentos medicamentos[], int n, int codigo){
    for(int i = 0; i < n; i++){
        if(medicamentos[i].codigo == codigo){
            cout << "Medicamento: " << medicamentos[i].descricao << endl;
            cout << "Estoque: " << medicamentos[i].qtd_estoque << endl;
            cout << "Estoque minimo: " << medicamentos[i].estoque_minimo << endl;
            cout << "Estoque maximo: " << medicamentos[i].estoque_maximo << endl;
            cout << "Preco: " << medicamentos[i].preco << endl;
            break;
        }
    }
}
void buscarConsulta(Consultas consultas[], int n, char cpf[], int codigo_medico, char data[], char hora[]){
    for(int i = 0; i < n; i++){
        if(strcmp(consultas[i].cpf_paciente, cpf) == 0 && consultas[i].codigo_medico == codigo_medico && strcmp(consultas[i].data, data) == 0 && strcmp(consultas[i].hora, hora) == 0){
            cout << "Medico: " << consultas[i].codigo_medico << endl;
            cout << "Data: " << consultas[i].data << endl;
            cout << "Hora: " << consultas[i].hora << endl;
            cout << "CID: " << consultas[i].codigo_cid << endl;
            cout << "Medicamento: " << consultas[i].codigo_medicamento << endl;
            cout << "Quantidade: " << consultas[i].qtd_medicamento << endl;
            break;
        }
    }
}




