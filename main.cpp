//Inclusão de bibliotecas
#include <iostream>
#include <cstring>
#include <clocale>
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
    int estoque_minimo;
    int estoque_maximo;
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
Cidade buscarCidade(const vector<Cidade>&, int);
Especialidade buscarEspecialidade(vector<Especialidade>, int);
Medicamento buscarMedicamento(vector<Medicamento>, int);
CID buscarCid(vector<CID>, char[]);
Medico buscarMedico(vector<Medico>, int);
Paciente buscarPaciente(vector<Paciente>, char[]);
Consulta buscarConsulta(vector<Consulta>, int, char[], int, char[], char[]);

void textoInicial();
void textoFinal();

//Prototipação de métodos de leitura de dados
Cidade leituraDadosCidades(const vector<Cidade>&);
Especialidade leituraDadosEspecialidades(const vector<Especialidade>&);
Medicamento leituraDadosMedicamentos( const vector<Medicamento>&);
CID leituraDadosCid(const vector<CID>&);

//Prototipação de métodos de inclusão de novos dados
Medico incluirNovoMedico(const vector<Medico>&, const vector<Especialidade>&, const vector<Cidade>&);
Paciente incluirNovoPaciente(const vector<Paciente>&, const vector<Cidade>&);
Consulta incluirNovaConsulta(const vector<Consulta>&, const vector<Paciente>&,const vector<Cidade>&, const vector<Medico>&, const vector<CID>&, const vector<Medicamento>&);

//Prototipação de métodos de exclusão de dados
void excluirPaciente( vector<Paciente>&);

int main() {
    int opcao = 0;
    setlocale(LC_ALL, "Portuguese");
    textoInicial();
        vector<Cidade> cidades = {
                {1, "Sao Paulo", "SP"},
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

    cout<< endl;
    do{
        cout<<"\t\nInforme a opcao desejada{ \n" << "\t[1] - Cadastrar uma nova cidade \n" << "\t[2] - Cadastrar uma nova especialidade \n" << "\t[3] - Cadastrar uma nova doenca \n"<< "\t[4] - Cadastrar um novo medicamento \n"<< "\t[5] - Incluir novo Medico \n"<< "\t[6] - Incluir um novo Paciente \n"<< "\t[7] - Excluir um Paciente \n"<< "\t[8] - Agendar uma Consulta \n"<< "\t[9] - Consultar Medicamento \n"<< "\t[10] - Consultar Medicamentos com estoque baixo \n"<< "\t[11] - Valores arrecadados com consultas \n"<< "\n\t[0] - Finalizar \n} " << endl;
        cin >> opcao;
        cin.ignore();
        if(opcao == 1) {
            cidades.push_back(leituraDadosCidades(cidades));
        } else if(opcao == 2) {
            especialidades.push_back(leituraDadosEspecialidades(especialidades));
        } else if(opcao == 3) {
            cids.push_back(leituraDadosCid(cids));
        } else if(opcao == 4) {
            medicamentos.push_back(leituraDadosMedicamentos(medicamentos));
        } else if(opcao == 5) {
            medicos.push_back(incluirNovoMedico(medicos, especialidades, cidades));
        } else if(opcao == 6) {
            pacientes.push_back(incluirNovoPaciente(pacientes, cidades));
        } else if(opcao == 7) {
            excluirPaciente(pacientes);
        } else if(opcao == 8) {
            consultas.push_back(incluirNovaConsulta(consultas, pacientes, cidades, medicos, cids, medicamentos));
        } else if(opcao == 9) {
            //Consultar medicamento
        } else if(opcao == 10) {
            //Consultar medicamentos com estoque baixo
        } else if(opcao == 11) {
            //Valores arrecadados com consultas
        }
        system("cls");
    }while(opcao != 0);
    textoFinal();
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
void textoFinal(){
    std::vector<char> textoBemVindo = {'E', 'n' , 'c' , 'e', 'r' , 'r' , 'a', 'n' , 'd', 'o', '.', '.', '.'};
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

//Questão 1
Cidade leituraDadosCidades(const vector<Cidade>& cidades) {
    Cidade cidade{};
    Cidade cidadeAux{};
    int codigo;
    system("cls");
    cout << "Informe o nome da cidade: " << endl;
    gets(cidade.nome);
    do {
        system("cls");
        cout << "Informe o codigo da cidade [" << cidade.nome << "]: " << endl;
        cin >> codigo;
        cin.ignore();
        cidadeAux = buscarCidade(cidades, codigo);

        if(cidadeAux.codigo != 0) {
            system("cls");
            cout << "!Codigo ja cadastrado, informe outro codigo!" << endl;
        }
    } while(cidadeAux.codigo != 0);
    cidade.codigo = codigo;
    system("cls");
    cout << "Informe o estado da cidade: " << endl;
    gets(cidade.estado);

    return cidade;
}

Especialidade leituraDadosEspecialidades(const vector<Especialidade>& especialidades) {
    Especialidade especialidade{};
    Especialidade especialidadeAux{};
    int codigo;
    system("cls");
    cout << "Informe a descricao da especialidade: " << endl;
    gets(especialidade.descricao);
    do {
        system("cls");
        cout << "Informe o codigo da especialidade [" << especialidade.descricao << "]: " << endl;
        cin >> codigo;
        cin.ignore();
        especialidadeAux = buscarEspecialidade(especialidades, codigo);
        if(especialidadeAux.codigo != 0) {
            system("cls");
            cout << "!Codigo ja cadastrado, informe outro codigo!" << endl;
        }
    } while(especialidadeAux.codigo != 0);
    especialidade.codigo = codigo;
    return especialidade;
}

Medicamento leituraDadosMedicamentos(const vector<Medicamento>& medicamentos) {
    Medicamento medicamento{};
    Medicamento medicamentoAux{};
    int codigo, quantidadeEstoque = 0;
    system("cls");
    cout << "Informe a descricao do medicamento: " << endl;
    gets(medicamento.descricao);
    system("cls");
    do {
        cout << "Informe o codigo do medicamento [" << medicamento.descricao << "]: " << endl;
        cin >> codigo;
        cin.ignore();
        medicamentoAux = buscarMedicamento(medicamentos, codigo);
        if(medicamentoAux.codigo != 0) {
            system("cls");
            cout << "!Codigo ja cadastrado, informe outro codigo!" << endl;
        }
    } while(medicamentoAux.codigo != 0);
    medicamento.codigo = codigo;

    system("cls");
    cout << "Informe o estoque minimo do medicamento [" << medicamento.descricao << "]: " << endl;
    cin >> medicamento.estoque_minimo;
    cin.ignore();
    system("cls");
    do{
        cout << "Informe o estoque maximo do medicamento [" << medicamento.descricao << "]: " << endl;
        cin >> medicamento.estoque_maximo;
        cin.ignore();
        if(medicamento.estoque_minimo > medicamento.estoque_maximo) {
            system("cls");
            cout << "!Estoque minimo ["<< medicamento.estoque_minimo <<"] maior que Estoque maximo informado!" << endl;
        }
    } while(medicamento.estoque_minimo > medicamento.estoque_maximo);
    system("cls");
    do{
        cout << "Informe a quantidade em estoque do medicamento [" << medicamento.descricao << "]: " << endl;
        cin >> quantidadeEstoque;
        cin.ignore();
        if(quantidadeEstoque < medicamento.estoque_minimo || quantidadeEstoque > medicamento.estoque_maximo) {
            system("cls");
            cout << "!Quantidade em estoque nao esta entre estoque minimo["<< medicamento.estoque_minimo <<"] e estoque maximo["<<medicamento.estoque_maximo<<"]!" << endl;
        }
    } while(quantidadeEstoque < medicamento.estoque_minimo || quantidadeEstoque > medicamento.estoque_maximo);
    system("cls");
    cout << "Informe o preco do medicamento [" << medicamento.descricao << "]: " << endl;
    cin >> medicamento.preco;
    cin.ignore();
    return medicamento;
}

CID leituraDadosCid(const vector<CID>& cids) {
    CID cid{};
    CID cidAux{};
    char codigo[5];
    system("cls");
    cout << "Informe a descricao da CID: " << endl;
    gets(cid.descricao);
    system("cls");
    do {
        cout << "Informe o codigo da CID [" << cid.descricao << "]: " << endl;
        gets(codigo);
        cidAux = buscarCid(cids, codigo);
        if(strcmp(cidAux.codigo, "") != 0) {
            system("cls");
            cout << "!Codigo ja cadastrado, informe outro codigo!" << endl;
        }
    } while(strcmp(cidAux.codigo, "") != 0);
    strcpy(cid.codigo, codigo);
    return cid;
}

//Questão 2
Medico incluirNovoMedico(const vector<Medico>& medicos, const vector<Especialidade>& especialidades, const vector<Cidade>& cidades) {
    Medico medico{};
    Medico medicoAux{};
    int codigo, codigoEspecialidade, codigoCidade;
    system("cls");
    cout << "Informe o nome do medico: " << endl;
    gets(medico.nome);
    system("cls");
    do {
        cout << "Informe o codigo do medico [" << medico.nome << "]: " << endl;
        cin >> codigo;
        cin.ignore();
        medicoAux = buscarMedico(medicos, codigo);
        if(medicoAux.codigo != 0) {
            system("cls");
            cout << "!Codigo ja cadastrado, informe outro codigo!" << endl;
        }
    } while(medicoAux.codigo != 0);
    medico.codigo = codigo;

    system("cls");
    cout << "Informe o endereco do medico [" << medico.nome << "]: " << endl;
    gets(medico.endereco);
    system("cls");
    cout << "Informe o telefone do medico [" << medico.nome << "]: " << endl;
    gets(medico.telefone);

    system("cls");
    cout << "Especialidades diponiveis: " << endl;
    for(const auto & especialidade : especialidades) {
        cout << "\t[" << especialidade.codigo << "] - " << especialidade.descricao << endl;
    }
    do{
        cout << "\nInforme o codigo da especialidade do medico [" << medico.nome << "]: " << endl;
        cin >> codigoEspecialidade;
        cin.ignore();
        if(buscarEspecialidade(especialidades, codigoEspecialidade).codigo == 0) {
            cout << "!especialidade nao encontrada!";
        }
    } while(buscarEspecialidade(especialidades, codigoEspecialidade).codigo == 0);
    medico.codigo_especialidade = codigoEspecialidade;

    system("cls");
    cout << "Cidades diponiveis: " << endl;
    for(const auto & cidade : cidades) {
        cout << "\t[" << cidade.codigo << "] - " << cidade.nome << " - " << cidade.estado << endl;
    }
    do{
        cout << "Informe o codigo da cidade do medico [" << medico.nome << "]: " << endl;
        cin >> codigoCidade;
        cin.ignore();
        if(buscarCidade(cidades, codigoCidade).codigo == 0) {
            cout << "!cidade nao encontrada!";
        }
    } while(buscarCidade(cidades, codigoCidade).codigo == 0);
    medico.codigo_cidade = codigoCidade;

    return medico;
}

//Questão 3
Paciente incluirNovoPaciente(const vector<Paciente>& pacientes, const vector<Cidade>& cidades) {
    Paciente paciente{};
    Paciente pacienteAux{};
    int codigoCidade;
    system("cls");
    cout << "Informe o nome do paciente: " << endl;
    gets(paciente.nome);
    system("cls");
    do {
        cout << "Informe o cpf do paciente [" << paciente.nome << "]: " << endl;
        gets(paciente.cpf);
        pacienteAux = buscarPaciente(pacientes, paciente.cpf);
        if(strcmp(pacienteAux.cpf, "") != 0) {
            system("cls");
            cout << "!CPF ja cadastrado, informe outro CPF!" << endl;
        }
    } while(strcmp(pacienteAux.cpf, "") != 0);

    system("cls");
    cout << "Informe o endereco do paciente [" << paciente.nome << "]: " << endl;
    gets(paciente.endereco);

    system("cls");
    cout << "Cidades diponiveis: " << endl;
    for(const auto & cidade : cidades) {
        cout << "\t[" << cidade.codigo << "] - " << cidade.nome << " - " << cidade.estado << endl;
    }
    do{
        cout << "Informe o codigo da cidade do paciente [" << paciente.nome << "]: " << endl;
        cin >> codigoCidade;
        cin.ignore();
        if(buscarCidade(cidades, codigoCidade).codigo == 0) {
            cout << "!cidade nao encontrada!" << endl;
        }
    } while(buscarCidade(cidades, codigoCidade).codigo == 0);
    paciente.codigo_cidade = codigoCidade;

    return paciente;
}

//Questão 4
void excluirPaciente(vector<Paciente>& pacientes) {
    char cpf[12];
    system("cls");
    cout<< "Pacientes cadastrados: " << endl;
    for(const auto & paciente : pacientes) {
        cout << "\t[" << paciente.cpf << "] - " << paciente.nome << endl;
    }
    cout << "Informe o CPF do paciente que deseja excluir: " << endl;
    gets(cpf);

    for(int i = 0; i < pacientes.size(); i++) {
        if(strcmp(pacientes[i].cpf, cpf) == 0) {
            pacientes.erase(pacientes.begin() + i);
            i = pacientes.size();
        }
    }

}

//Questão 5
Consulta incluirNovaConsulta(const vector<Consulta>& consultas, const vector<Paciente>& pacientes, const vector<Cidade>& cidades, const vector<Medico>& medicos, const vector<CID>& cids, const vector<Medicamento>& medicamentos) {
    Consulta consulta{};
    Consulta consultaAux{};
    int codigoMedico, codigoCidade, codigoMedicamento, quantidadeMedicamento;
    char cpf[12], data[11], hora[6], codigoCid[5];
    system("cls");
    cout << "Pacientes cadastrados: " << endl;
    for(const auto & paciente : pacientes) {
        cout << "\t[" << paciente.cpf << "] - " << paciente.nome;
        for(const auto & cidade : cidades) {
            if(cidade.codigo == paciente.codigo_cidade) {
                cout << "\tCidade/Estado = [" << cidade.nome << " - " << cidade.estado <<"]"<< endl;
            }
        }
    }

}

Cidade buscarCidade(const vector<Cidade>& cidades, int codigo) {
    Cidade cidadeAux{ 0, "", ""};
    for(int i = 0; i < cidades.size(); i++) {
        if(cidades[i].codigo == codigo) {
            cidadeAux = cidades[i];
            i = cidades.size();
        }
    }
    return cidadeAux;
}

Especialidade buscarEspecialidade(vector<Especialidade> especialidades, int codigo) {
    Especialidade especialidadeAux{ 0, ""};
    for(int i = 0; i < especialidades.size(); i++) {
        if(especialidades[i].codigo == codigo) {
            especialidadeAux = especialidades[i];
            i = especialidades.size();
        }
    }
    return especialidadeAux;
}

Medicamento buscarMedicamento(vector<Medicamento> medicamentos, int codigo) {
    Medicamento medicamentoAux{ 0, "", 0, 0, 0, 0};
    for(int i = 0; i < medicamentos.size(); i++) {
        if(medicamentos[i].codigo == codigo) {
            medicamentoAux = medicamentos[i];
            i = medicamentos.size();
        }
    }
    return medicamentoAux;
}

CID buscarCid(vector<CID> cids, char codigo[]) {
    CID cidAux{ "", ""};
    for(int i = 0; i < cids.size(); i++) {
        if(strcmp(cids[i].codigo, codigo) == 0) {
            cidAux = cids[i];
            i = cids.size();
        }
    }
    return cidAux;
}

Medico buscarMedico(vector<Medico> medicos, int codigo) {
    Medico medicoAux{ 0, "", 0, "", "", 0};
    for(int i = 0; i < medicos.size(); i++) {
        if(medicos[i].codigo == codigo) {
            medicoAux = medicos[i];
            i = medicos.size();
        }
    }
    return medicoAux;
}

Paciente buscarPaciente(vector<Paciente> pacientes, char cpf[]) {
    Paciente pacienteAux{ "", "", "", 0};
    for(int i = 0; i < pacientes.size(); i++) {
        if(strcmp(pacientes[i].cpf, cpf) == 0) {
            pacienteAux = pacientes[i];
            i = pacientes.size();
        }
    }
    return pacienteAux;
}
