#include <iostream>
#include <string>
#include <vector>
#include <conio2.h>
#include <cstdio>
#include <fstream>

using namespace std;

struct regFuncionario {
	string matricula;
	string nome;
	string setor;
	string email;
	string ramal;
};

void limparArea(int ci, int li, int cf, int lf) {
	int coluna, linha;
	for (coluna=ci; coluna<=cf; coluna++)
	{
		for(linha=li; linha<=lf; linha++)
		{
			gotoxy(coluna,linha); cout << " ";
		}
	}
}

void montarMoldura(int ci, int li, int cf, int lf) {
	int coluna, linha;

	limparArea(ci,li,cf,lf);

	for (coluna=ci; coluna<=cf; coluna++) {
		gotoxy(coluna,li); cout << char(205);
		gotoxy(coluna,lf); cout << char(205);
	}

	for (linha=li; linha<=lf; linha++) {
		gotoxy(ci,linha); cout << char(186);
		gotoxy(cf,linha); cout << char(186);
	}

	gotoxy(ci,li); cout << char(201);
	gotoxy(ci,lf); cout << char(200);
	gotoxy(cf,li); cout << char(187);
	gotoxy(cf,lf); cout << char(188);
}

main() {
	int op, coluna, linha, x;
	bool achei;
	string resp;
	regFuncionario func;
	vector <regFuncionario> tabelaFuncionarios;


	while (true) {
		textcolor(BLACK);
		textbackground(WHITE);
		clrscr();

		montarMoldura(4,1,21,7);

		gotoxy(5,2); cout << "1 - Funcionarios";
		gotoxy(5,3); cout << "2 - Servicos";
		gotoxy(5,4); cout << "3 - Setores";
		gotoxy(5,5); cout << "0 - Sair";
		gotoxy(5,6); cout << "Opcao : "; cin >> op;
		fflush(stdin);

		if (op == 0) break;

		if (op == 1) {
			//
			// montar tela de cadastro
			//
			montarMoldura(12,2,47,12);
			gotoxy(13,3); cout << "Cadastro de Funcionarios";
			gotoxy(13,5); cout << "Matricula:";
			gotoxy(13,6); cout << "Nome     :";
			gotoxy(13,7); cout << "Setor    :";
			gotoxy(13,8); cout << "Email    :";
			gotoxy(13,9); cout << "Ramal    :";
			gotoxy(13,11); cout << "Confirma (S/N):";


			//
			// perguntar a matricula
			//
			gotoxy(24,5); getline(cin, func.matricula);
			if (func.matricula=="") continue;

			//
			// verifica se a matricula ja foi cadastrada
			//
			achei = false;
			for(x=0; x<tabelaFuncionarios.size(); x++) {
				if (func.matricula == tabelaFuncionarios[x].matricula) {
					achei = true;
					break;
				}
			}

			if ( not achei ) {
				// cadastro
				gotoxy(24,6); getline(cin, func.nome);
				gotoxy(24,7); getline(cin, func.setor);
				gotoxy(24,8); getline(cin, func.email);
				gotoxy(24,9); getline(cin, func.ramal);
				gotoxy(28,11); getline(cin, resp);

				if (resp=="s" or resp=="S")	{
					tabelaFuncionarios.push_back(func);
				}
			} else {
				// consulta
				gotoxy(24,6); cout << tabelaFuncionarios[x].nome;
				gotoxy(24,7); cout << tabelaFuncionarios[x].setor;
				gotoxy(24,8); cout << tabelaFuncionarios[x].email;
				gotoxy(24,9); cout << tabelaFuncionarios[x].ramal;
				gotoxy(13,11); cout << "Alterar, Excluir, Voltar (A/E/V):";
				gotoxy(46,11); getline(cin, resp);

				if (resp=="V" or resp=="v") continue;

				if (resp=="A" or resp=="a") {
					montarMoldura(47,5,77,12);
					// deixa a janela mais bonitinha
					// vamos transformar isso em uma funcao
					gotoxy(47,5); cout << char(204);
					gotoxy(47,12); cout << char(202);

					gotoxy(48,6); getline(cin, func.nome);

					if (func.nome == "") {
						func.nome = tabelaFuncionarios[x].nome;
						gotoxy(48,6); cout << func.nome;
					}

					gotoxy(48,7); getline(cin, func.setor);

					if (func.setor == "") {
						func.setor = tabelaFuncionarios[x].setor;
						gotoxy(48,7); cout << func.setor;
					}

					gotoxy(48,8); getline(cin, func.email);

					if (func.email == "") {
						func.email = tabelaFuncionarios[x].email;
						gotoxy(48,8); cout << func.email;
					}

					gotoxy(48,9); getline(cin, func.ramal);

					if (func.ramal == "") {
						func.ramal = tabelaFuncionarios[x].ramal;
						gotoxy(48,9); cout << func.ramal;
					}

					gotoxy(48,11); cout << "Confirma alteracao (S/N):";
					getline(cin, resp);

					if (resp=="S" or resp=="s") {
						tabelaFuncionarios[x] = func;
					}
				}

				if (resp=="E" or resp=="e") {
					limparArea(13,11,46,11);
					gotoxy(13,11); cout << "Confirma exclusao (S/N):";
					gotoxy(37,11); getline(cin, resp);

					if (resp=="S" or resp=="s")
					{
						tabelaFuncionarios.erase(tabelaFuncionarios.begin() + x);
					}
				}
			}
		}
	}
}
