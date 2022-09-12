#include <iostream>
#include <ctype.h>
#include <conio.h>
#include <fstream>

using namespace std;

ofstream documento;
char nome[40];
char horario[5];
char dia[10];
int id;
char numero[15];

void arquivo() {
    system("cls");
    documento.open("arquivo.doc");

    cout << "Arquivo criado com sucesso !!!";

    documento.close();
}

void cadastro() {
    system("cls");  
    documento.open("arquivo.doc");
    cout << "\nNome do paciente: ";
    cin >> nome;
    cout << "\nHorario: ";
    cin >> horario;
    cout << "\nDia: ";
    cin >> dia;
    cout << "\nNúmero para contato: ";
    cin >> numero;

    documento << "PACIENTE " << nome << "\n\nHorario: " << horario << "\nDia: " << dia << "\nContato: +55 " << numero;

    cout << "\nDados gravados com sucesso !!";

    documento.close();
}


int main(int argc, char const *argv[])
{
    do {
        system("cls");
        int op;

        /* INTERFACE */
        cout << "Sistema de Cadastro Medico";
        cout << "\n(1) Criar arquivo";
        cout << "\n(2) Criar cadastro";
        cout << "\n(3) Sair do programa";
        cout << "\n--------------------------------";
        cout << "\nQual opcao desejada => ";
        cin >> op;

        switch (op)
        {
        case 1:
            arquivo();
            break;
        
        case 2:
            cadastro();
            break;

        default:
            break;
        }

        getch();
        cout << "\n\n\nQuer rodar o APP de novo ? [s/n]: ";
    }while(tolower(getch() == 's'));
}


