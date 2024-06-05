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
Cidade buscarCidade( vector<Cidade>&, int);
Especialidade buscarEspecialidade(vector<Especialidade>, int);
Medicamento buscarMedicamento(vector<Medicamento>, int);
CID buscarCid(vector<CID>, char[]);
Medico buscarMedico(vector<Medico>, int);
Paciente buscarPaciente(vector<Paciente>, char[]);

void textoInicial();
void textoFinal();

//Prototipação de métodos de leitura de dados
Cidade leituraDadosCidades( vector<Cidade>&);
Especialidade leituraDadosEspecialidades( vector<Especialidade>&);
Medicamento leituraDadosMedicamentos(  vector<Medicamento>&);
CID leituraDadosCid( vector<CID>&);

//Prototipação de métodos de inclusão de novos dados
Medico incluirNovoMedico( vector<Medico>&,  vector<Especialidade>&,  vector<Cidade>&);
Paciente incluirNovoPaciente( vector<Paciente>&,  vector<Cidade>&);
Consulta incluirNovaConsulta( vector<Paciente>&, vector<Cidade>&,  vector<Medico>&, vector<Especialidade>&,  vector<CID>&, vector<Medicamento>&);

void consultaMedicamentos( vector<Medicamento>&);
void consultarDetalhesMedicamento( vector<Medicamento>&);
void consultarMedicamentosEstoqueMinimo( vector<Medicamento>&);
void consultarGanhosComConsultas( vector<Consulta>&,  vector<Medicamento>&);

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
                {"C05", "Pe Inchado"}
        };
        vector<Medicamento> medicamentos = {
                {1, "Dipirona", 335, 5, 400, 2.00},
                {2, "Paracetamol", 4, 15, 200, 8.00},
                {3, "Ibuprofeno", 213, 2, 250, 6.00},
                {4, "Dorflex", 186, 50, 200, 1.00},
                {5, "Buscopan", 12, 10, 175, 12.00},
                {6, "Omeprazol", 35, 30, 100, 15.00},
                {7, "Ranitidina", 44, 24, 100, 10.00},
                {8, "Doril", 15, 17, 100, 5.00},
                {9, "Cataflan", 30, 60, 100, 7.00},
                {10, "Dorilax", 5, 15, 100, 9.00}
        };
        vector<Consulta> consultas = {
                {"12345678901", 1, "01/11/2024", "08:00", "C04", 1, 2},
                {"12345678902", 2, "04/05/2024", "08:30", "C01", 4, 3}
        };

    cout<< endl;
    do{
        cout<<"\t\nInforme a opcao desejada{ \n" << "\t[1] - Cadastrar uma nova cidade \n" << "\t[2] - Cadastrar uma nova especialidade \n" << "\t[3] - Cadastrar uma nova doenca \n"<< "\t[4] - Cadastrar um novo medicamento \n"<< "\t[5] - Incluir novo Medico \n"<< "\t[6] - Incluir um novo Paciente \n"<< "\t[7] - Excluir um Paciente \n"<< "\t[8] - Agendar uma Consulta \n"<< "\t[9] - Consultar Medicamento \n"<< "\t[10] - Valores arrecadados com consultas \n"<< "\n\t[0] - Finalizar \n} " << endl;
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
            consultas.push_back(incluirNovaConsulta( pacientes, cidades, medicos,especialidades, cids, medicamentos));
        } else if(opcao == 9) {
            consultaMedicamentos(medicamentos);
        } else if(opcao == 10) {
            consultarGanhosComConsultas(consultas, medicamentos);
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
Cidade leituraDadosCidades( vector<Cidade>& cidades) {
    Cidade cidade{};
    Cidade cidadeAux = { 0, "", ""};
    system("cls");
    cout << "Informe o nome da cidade: " << endl;
    gets(cidade.nome);
    system("cls");
    do {
        cout << "Informe o codigo da cidade [" << cidade.nome << "]: " << endl;
        cin >> cidade.codigo;
        cin.ignore();
        cidadeAux = buscarCidade(cidades, cidade.codigo);
        if(cidadeAux.codigo != 0) {
            system("cls");
            cout << "!Codigo ja cadastrado, informe outro codigo!" << endl;
        }
    } while(cidadeAux.codigo != 0);
    system("cls");
    cout << "Informe o estado da cidade: " << endl;
    gets(cidade.estado);

    return cidade;
}
Especialidade leituraDadosEspecialidades( vector<Especialidade>& especialidades) {
    Especialidade especialidade{};
    Especialidade especialidadeAux = { 0, ""};
    system("cls");
    cout << "Informe a descricao da especialidade: " << endl;
    gets(especialidade.descricao);
    do {
        system("cls");
        cout << "Informe o codigo da especialidade [" << especialidade.descricao << "]: " << endl;
        cin >> especialidade.codigo;
        cin.ignore();
        especialidadeAux = buscarEspecialidade(especialidades, especialidade.codigo);
        if(especialidadeAux.codigo != 0) {
            system("cls");
            cout << "!Codigo ja cadastrado, informe outro codigo!" << endl;
        }
    } while(especialidadeAux.codigo != 0);
    return especialidade;
}
Medicamento leituraDadosMedicamentos( vector<Medicamento>& medicamentos) {
    Medicamento medicamento{};
    Medicamento medicamentoAux = { 0, "", 0, 0, 0, 0.0};
    int quantidadeEstoque = 0;
    system("cls");
    cout << "Informe a descricao do medicamento: " << endl;
    gets(medicamento.descricao);
    system("cls");
    do {
        cout << "Informe o codigo do medicamento [" << medicamento.descricao << "]: " << endl;
        cin >> medicamento.codigo;
        cin.ignore();
        medicamentoAux = buscarMedicamento(medicamentos, medicamento.codigo);
        if(medicamentoAux.codigo != 0) {
            system("cls");
            cout << "!Codigo ja cadastrado, informe outro codigo!" << endl;
        }
    } while(medicamentoAux.codigo != 0);

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
CID leituraDadosCid( vector<CID>& cids) {
    CID cid{};
    CID cidAux = { "",""};
    system("cls");
    cout << "Informe a descricao da CID: " << endl;
    gets(cid.descricao);
    system("cls");
    do {
        cout << "Informe o codigo da CID [" << cid.descricao << "]: " << endl;
        gets(cid.codigo);
        cidAux = buscarCid(cids, cid.codigo);
        if(strcmp(cidAux.codigo, "") != 0) {
            system("cls");
            cout << "!Codigo ja cadastrado, informe outro codigo!" << endl;
        }
    } while(strcmp(cidAux.codigo, "") != 0);
    return cid;
}

//Atividade 2
Medico incluirNovoMedico(vector<Medico>& medicos,  vector<Especialidade>& especialidades,  vector<Cidade>& cidades) {
    Medico medico{};
    Medico medicoAux = { 0, "", 0, "", "", 0};
    Especialidade especialidadeAux = { 0, ""};
    Cidade cidadeAux = { 0, "", ""};

    int opcao = 0;

    system("cls");
    cout << "Informe o nome do medico: " << endl;
    gets(medico.nome);
    system("cls");
    do {
        cout << "Informe o codigo do medico [" << medico.nome << "]: " << endl;
        cin >> medico.codigo;
        cin.ignore();
        medicoAux = buscarMedico(medicos, medico.codigo);
        if(medicoAux.codigo != 0) {
            system("cls");
            cout << "!Codigo ja cadastrado, informe outro codigo!" << endl;
        }
    } while(medicoAux.codigo != 0);

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
        cin >> medico.codigo_especialidade;
        cin.ignore();
        especialidadeAux = buscarEspecialidade(especialidades, medico.codigo_especialidade);
        if(especialidadeAux.codigo == 0) {
            cout << "!Especialidade nao encontrada!" << endl;
            cout << "\nDeseja cadastrar uma nova especialidade?? [1 - Sim | 0 - Nao]: " << endl;
            cin >> opcao;
            cin.ignore();
            if(opcao == 1) {
                especialidades.push_back(leituraDadosEspecialidades(especialidades));
                system("cls");
                cout << "Especialidades diponiveis: " << endl;
                for(const auto & especialidade : especialidades) {
                    cout << "\t[" << especialidade.codigo << "] - " << especialidade.descricao << endl;
                }
            }
        }
    } while(especialidadeAux.codigo == 0 && opcao == 0);
    opcao = 0;

    system("cls");
    cout << "Cidades diponiveis: " << endl;
    for(const auto & cidade : cidades) {
        cout << "\t[" << cidade.codigo << "] - " << cidade.nome << " - " << cidade.estado << endl;
    }
    do{
        cout << "Informe o codigo da cidade do medico [" << medico.nome << "]: " << endl;
        cin >> medico.codigo_cidade;
        cin.ignore();
        cidadeAux = buscarCidade(cidades, medico.codigo_cidade);
        if(cidadeAux.codigo == 0) {
            cout << "!Cidade nao encontrada!" << endl;
            cout << "\nDeseja cadastrar uma nova cidade?? [1 - Sim | 0 - Nao]: " << endl;
            cin >> opcao;
            cin.ignore();
            if(opcao == 1) {
                cidades.push_back(leituraDadosCidades(cidades));
                system("cls");
                cout << "Cidades diponiveis: " << endl;
                for(const auto & cidade : cidades) {
                    cout << "\t[" << cidade.codigo << "] - " << cidade.nome << " - " << cidade.estado << endl;
                }
            }
        }
    } while(cidadeAux.codigo == 0 && opcao == 0);

    return medico;
}

//Atividade 3
Paciente incluirNovoPaciente( vector<Paciente>& pacientes,  vector<Cidade>& cidades) {
    Paciente paciente{};
    Paciente pacienteAux = { "", "", "", 0 };
    Cidade cidadeAux = { 0, "", ""};

    int opcao = 0;

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
        cin >> paciente.codigo_cidade;
        cin.ignore();
        cidadeAux = buscarCidade(cidades, paciente.codigo_cidade);
        if(cidadeAux.codigo == 0) {
            cout << "!Cidade nao encontrada!" << endl;
            cout << "\nDeseja cadastrar uma nova cidade?? [1 - Sim | 0 - Nao]: " << endl;
            cin >> opcao;
            cin.ignore();
            if(opcao == 1) {
                cidades.push_back(leituraDadosCidades(cidades));
                system("cls");
                cout << "Cidades diponiveis: " << endl;
                for(const auto & cidade : cidades) {
                    cout << "\t[" << cidade.codigo << "] - " << cidade.nome << " - " << cidade.estado << endl;
                }
            }
        }
    } while(cidadeAux.codigo == 0 && opcao == 0);

    return paciente;
}

//Atividade 4
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
            i = (int)pacientes.size();
        }
    }

}

//Atividade 5
Consulta incluirNovaConsulta( vector<Paciente>& pacientes,  vector<Cidade>& cidades,  vector<Medico>& medicos, vector<Especialidade>& especialidades,  vector<CID>& cids, vector<Medicamento>& medicamentos) {
    Consulta consulta{};
    Paciente pacienteAux = { "", "", "", 0 };
    Medico medicoAux = { 0, "", 0, "", "", 0};
    CID cidAux = { "","" };
    Medicamento medicamentoAux = { 0, "", 0, 0, 0, 0.08};

    int opcao = 0;

    system("cls");
    cout << "Pacientes cadastrados: " << endl;
    for(const auto & paciente : pacientes) {
        cout << "\tNome: [" << paciente.nome << " - " << paciente.cpf <<"]";
        for(const auto & cidade : cidades) {
            if(cidade.codigo == paciente.codigo_cidade) {
                cout << "\tCidade: [" << cidade.nome << " - " << cidade.estado <<"]"<< endl;
            }
        }
    }
    cout << endl;
    do{
        cout << "Informe o CPF do paciente: " << endl;
        cout << "\t[>]";
        gets(consulta.cpf_paciente);
        pacienteAux = buscarPaciente(pacientes, consulta.cpf_paciente);
        if(strcmp(pacienteAux.cpf, "") == 0) {
            cout << "!CPF nao encontrado!" << endl;
            cout << "\nDeseja cadastrar um novo paciente?? [1 - Sim | 0 - Nao]: " << endl;
            cout << "\t [>]";
            cin >> opcao;
            cin.ignore();
            if(opcao == 1) {
                pacientes.push_back(incluirNovoPaciente(pacientes, cidades));
                system("cls");
                cout << "Pacientes cadastrados: " << endl;
                for(const auto & paciente : pacientes) {
                    cout << "\tNome: [" << paciente.nome << " - " << paciente.cpf <<"]";
                    for(const auto & cidade : cidades) {
                        if(cidade.codigo == paciente.codigo_cidade) {
                            cout << "\tCidade: [" << cidade.nome << " - " << cidade.estado <<"]"<< endl;
                        }
                    }
                }
                cout << endl;
            }
        }
    } while(strcmp(pacienteAux.cpf, "") == 0 && opcao == 0);

    opcao = 0;

    system("cls");
    cout << "Medicos disponiveis: " << endl;
    for(const auto & medico : medicos) {
        cout << "\t[" << medico.codigo << "] - " << medico.nome;
        for(const auto & especialidade : especialidades) {
            if(especialidade.codigo == medico.codigo_especialidade) {
                cout << "\t\tEspecialidade: [" << especialidade.descricao << "]" << endl;
            }
        }
    }
    cout << endl;
    do{
        cout << "Informe o codigo do medico: " << endl;
        cout << "[>]";
        cin >> consulta.codigo_medico;
        cin.ignore();
        medicoAux = buscarMedico(medicos, consulta.codigo_medico);
        if(medicoAux.codigo == 0) {
            cout << "!Medico nao encontrado!" << endl;
            cout << "Deseja cadastrar um novo medico?? [1 - Sim | 0 - Nao]: " << endl;
            cout << "[>]";
            cin >> opcao;
            cin.ignore();
            if(opcao == 1) {
                medicos.push_back(incluirNovoMedico(medicos, especialidades, cidades));
                system("cls");
                cout << "Medicos disponiveis: " << endl;
                for(const auto & medico : medicos) {
                    cout << "\t[" << medico.codigo << "] - " << medico.nome;
                    for(const auto & especialidade : especialidades) {
                        if(especialidade.codigo == medico.codigo_especialidade) {
                            cout << "\t\tEspecialidade: [" << especialidade.descricao << "]" << endl;
                        }
                    }
                }
                cout << endl;
            }
        }
    } while(medicoAux.codigo == 0 && opcao == 0);

    opcao = 0;

    system("cls");
    cout << "Informe a data da consulta: " <<"\t exemplo = [??/??/????]" <<endl;
    cout << "=>";
    gets(consulta.data);
    system("cls");
    cout << "Informe a hora da consulta: " << "\t exemplo = [??:??]"<< endl;
    cout << "=>";
    gets(consulta.hora);
    system("cls");
    cout << "Diagnosticos disponiveis: " << endl;
    for(const auto & cid : cids) {
        cout << "\t[" << cid.codigo << "] - " << cid.descricao << endl;
    }
    cout << endl;
    do{
        cout << "Informe o codigo do diagnostico: " << endl;
        gets(consulta.codigo_cid);
        cidAux = buscarCid(cids, consulta.codigo_cid);
        if(strcmp(cidAux.codigo, "") == 0) {
            cout << "!Diagnostico nao encontrado!" << endl;
            cout << "\nDeseja cadastrar um novo diagnostico?? [1 - Sim | 0 - Nao]: " << endl;
            cin >> opcao;
            cin.ignore();
            if(opcao == 1) {
                cids.push_back(leituraDadosCid(cids));
                system("cls");
                cout << "Diagnosticos disponiveis: " << endl;
                for(const auto & cid : cids) {
                    cout << "\t[" << cid.codigo << "] - " << cid.descricao << endl;
                }
                cout << endl;
            }
        }
    } while(strcmp(cidAux.codigo, "") == 0 && opcao == 0);

    opcao = 0;

    system("cls");
    cout << "Medicamentos disponiveis: " << endl;
    for(const auto & medicamento : medicamentos) {
        cout << "\t[" << medicamento.codigo << "] - " << medicamento.descricao << endl;
    }
    cout << endl;
    do{
        cout << "Informe o codigo do medicamento: " << endl;
        cin >> consulta.codigo_medicamento;
        cin.ignore();
        medicamentoAux = buscarMedicamento(medicamentos, consulta.codigo_medicamento);
        if(medicamentoAux.codigo == 0) {
            cout << "!Medicamento nao encontrado!" << endl;
            cout << "\nDeseja cadastrar um novo medicamento?? [1 - Sim | 0 - Nao]: " << endl;
            cin >> opcao;
            cin.ignore();
            if(opcao == 1) {
                medicamentos.push_back(leituraDadosMedicamentos(medicamentos));
                system("cls");
                cout << "Medicamentos disponiveis: " << endl;
                for(const auto & medicamento : medicamentos) {
                    cout << "\t[" << medicamento.codigo << "] - " << medicamento.descricao << endl;
                }
                cout << endl;
            }
        }
        if(medicamentoAux.qtd_estoque == 0) {
            cout << "!Medicamento sem estoque!" << endl;
        }
    } while(medicamentoAux.codigo == 0 && medicamentoAux.qtd_estoque == 0 && opcao == 0);

    system("cls");
    cout << "Informacoes do medicamento: " << endl;
    cout << "\tDescricao: " << medicamentoAux.descricao << endl;
    cout << "\tPreco: " << medicamentoAux.preco << endl;
    cout << "\tEstoque: " << medicamentoAux.qtd_estoque << endl;
    cout << "\tEstoque minimo: " << medicamentoAux.estoque_minimo << endl;
    cout << endl;
    do{
        cout << "Informe a quantidade do medicamento: " << endl;
        cin >> consulta.qtd_medicamento;
        cin.ignore();
        if(consulta.qtd_medicamento > medicamentoAux.qtd_estoque) {
            cout << "!Quantidade em estoque insuficiente!" << endl;
        }
    } while(consulta.qtd_medicamento > medicamentoAux.qtd_estoque);
    medicamentos[medicamentoAux.codigo - 1].qtd_estoque -= consulta.qtd_medicamento;

    return consulta;
}

//Atividade 6
void consultaMedicamentos( vector<Medicamento>& medicamentos) {
    int opcao = 0;
    system("cls");
    do {
        cout << "\t\nInforme a opcao desejada{ \n" << "\t[1] - Consultar Detalhes de um Medicamento \n"
             << "\t[2] - Consultar Medicamentos com estoque baixo \n" << "\n\t[0] - Voltar \n} " << endl;
        cin >> opcao;
        cin.ignore();
        if (opcao == 1) {
            consultarDetalhesMedicamento(medicamentos);
            system("cls");
        } else if (opcao == 2) {
            consultarMedicamentosEstoqueMinimo(medicamentos);
            system("cls");
        }
    } while (opcao != 0);
}

void consultarDetalhesMedicamento(vector<Medicamento>& medicamentos){
    int codigo, opcao;
    Medicamento medicamentoAux = { 0, "", 0, 0, 0, 0.0};
    do{
        system("cls");
        cout << "Medicamentos: " << endl;
        for(const auto & medicamento : medicamentos) {
            cout << "\t[" << medicamento.codigo << "] - " << medicamento.descricao << endl;
        }
        cout << endl;
        do{
            cout << "Informe o codigo do medicamento: " << endl;
            cin >> codigo;
            cin.ignore();
            medicamentoAux = buscarMedicamento(medicamentos, codigo);
            if(medicamentoAux.codigo == 0) {
                cout << "!Medicamento nao encontrado!" << endl;
                cout << "\nDeseja cadastrar um novo medicamento?? [1 - Sim | 0 - Nao]: " << endl;
                cin >> opcao;
                cin.ignore();
                if(opcao == 1) {
                    medicamentos.push_back(leituraDadosMedicamentos(medicamentos));
                    system("cls");
                    cout << "Medicamentos: " << endl;
                    for(const auto & medicamento : medicamentos) {
                        cout << "\t[" << medicamento.codigo << "] - " << medicamento.descricao << endl;
                    }
                }
            }
        } while(medicamentoAux.codigo == 0);
        system("cls");

        cout << "Informacoes do medicamento: " << endl;
        cout << "\tDescricao: " << medicamentoAux.descricao << endl;
        cout << "\tPreco: " << medicamentoAux.preco << endl;
        cout << "\tEstoque: " << medicamentoAux.qtd_estoque << endl;
        cout << "\tEstoque minimo: " << medicamentoAux.estoque_minimo << endl;
        cout << "\tEstoque maximo: " << medicamentoAux.estoque_maximo << endl;
        cout << "\tValor total em estoque: " << (float)((float)medicamentoAux.qtd_estoque * medicamentoAux.preco) << endl;
        cout << "\nDeseja consultar outro medicamento? [1 - Sim | 0 - Nao]: " << endl;
        cin >> opcao;
    } while (opcao != 0);
}

//Atividade 7
void consultarMedicamentosEstoqueMinimo( vector<Medicamento>& medicamentos){
    int codigo, opcao;
    Medicamento medicamentoAux = { 0, "", 0, 0, 0, 0.0};

    do{
        system("cls");
        cout << "Medicamentos com estoque baixo: " << endl;
        for(const auto & medicamento : medicamentos) {
            if(medicamento.qtd_estoque <= medicamento.estoque_minimo) {
                cout << "\t[" << medicamento.codigo << "] - " << medicamento.descricao << endl;
            }
        }
        cout << endl;
        do{
            cout << "Informe o codigo do medicamento para consultar detalhes: " << endl;
            cin >> codigo;
            cin.ignore();
            medicamentoAux = buscarMedicamento(medicamentos, codigo);
            if(medicamentoAux.codigo == 0) {
                cout << "!Medicamento nao encontrado!" << endl;
            }
            if(medicamentoAux.qtd_estoque > medicamentoAux.estoque_minimo) {
                cout << "!Medicamento nao esta com estoque baixo!" << endl;
            }
        } while(medicamentoAux.codigo == 0 && medicamentoAux.qtd_estoque > medicamentoAux.estoque_minimo);
        system("cls");
        cout << "Informacoes do medicamento: " << endl;
        cout << "\tDescricao: " << medicamentoAux.descricao << endl;
        cout << "\tPreco: " << medicamentoAux.preco << endl;
        cout << "\tEstoque: " << medicamentoAux.qtd_estoque << endl;
        cout << "\tEstoque maximo: " << medicamentoAux.estoque_maximo << endl;
        cout << "\n\t Quantidade a ser comprada: " << (medicamentoAux.estoque_maximo - medicamentoAux.qtd_estoque) << endl;
        cout << "\t Valor total a ser comprado: " << (float)((float)(medicamentoAux.estoque_maximo - medicamentoAux.qtd_estoque) * medicamentoAux.preco) << endl;
        cout << "\nDeseja consultar outro medicamento? [1 - Sim | 0 - Nao]: " << endl;
        cin >> opcao;
        cin.ignore();
    } while (opcao != 0);
}

//Atividade 8
void consultarGanhosComConsultas( vector<Consulta>& consultas,  vector<Medicamento>& medicamentos) {
    float totalConsultas = 0;
    float totalMedicamentos = 0;
    char voltar[999];
    for(const auto & consulta : consultas) {
        totalConsultas += 100;
        for(const auto & medicamento : medicamentos) {
            if(medicamento.codigo == consulta.codigo_medicamento) {
                totalMedicamentos += (float)(medicamento.preco * (float)consulta.qtd_medicamento);
            }
        }
    }
    system("cls");
    cout <<  "Arrecadacao do Hospital: " << endl;
    cout << "\tTotal arrecadado com consultas: " << totalConsultas << endl;
    cout << "\tTotal arrecadado com medicamentos: " << totalMedicamentos << endl;
    cout << "\tTotal arrecadado: " << (totalConsultas + totalMedicamentos) << endl;

    cout << "\nPressione qualquer tecla para voltar ao menu principal" << endl;
    gets(voltar);
}

Cidade buscarCidade( vector<Cidade>& cidades, int codigo) {
    Cidade cidadeAux{ 0, "", ""};
    for(int i = 0; i < cidades.size(); i++) {
        if(cidades[i].codigo == codigo) {
            cidadeAux = cidades[i];
            i = (int)cidades.size();
        }
    }
    return cidadeAux;
}
Especialidade buscarEspecialidade(vector<Especialidade> especialidades, int codigo) {
    Especialidade especialidadeAux{ 0, ""};
    for(int i = 0; i < especialidades.size(); i++) {
        if(especialidades[i].codigo == codigo) {
            especialidadeAux = especialidades[i];
            i = (int)especialidades.size();
        }
    }
    return especialidadeAux;
}
Medicamento buscarMedicamento(vector<Medicamento> medicamentos, int codigo) {
    Medicamento medicamentoAux{ 0, "", 0, 0, 0, 0};
    for(int i = 0; i < medicamentos.size(); i++) {
        if(medicamentos[i].codigo == codigo) {
            medicamentoAux = medicamentos[i];
            i = (int)medicamentos.size();
        }
    }
    return medicamentoAux;
}
CID buscarCid(vector<CID> cids, char codigo[]) {
    CID cidAux{ "", ""};
    for(int i = 0; i < cids.size(); i++) {
        if(strcmp(cids[i].codigo, codigo) == 0) {
            cidAux = cids[i];
            i = (int)cids.size();
        }
    }
    return cidAux;
}
Medico buscarMedico(vector<Medico> medicos, int codigo) {
    Medico medicoAux{ 0, "", 0, "", "", 0};
    for(int i = 0; i < medicos.size(); i++) {
        if(medicos[i].codigo == codigo) {
            medicoAux = medicos[i];
            i = (int)medicos.size();
        }
    }
    return medicoAux;
}
Paciente buscarPaciente(vector<Paciente> pacientes, char cpf[]) {
    Paciente pacienteAux{ "", "", "", 0};
    for(int i = 0; i < pacientes.size(); i++) {
        if(strcmp(pacientes[i].cpf, cpf) == 0) {
            pacienteAux = pacientes[i];
            i = (int)pacientes.size();
        }
    }
    return pacienteAux;
}