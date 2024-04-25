#include<iostream>

using namespace std;

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

