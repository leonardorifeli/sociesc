#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ncurses.h>

using namespace std;

main()
{
	int op;
	int x;
	int y;

	while(true)
    {
		textcolor(YELLOW);
		textbackground(GREEN);
		clrscr();

		for(x=4; x <= 21; x++)
        {
			gotoxy(x, 1); cout << char(205);
			gotoxy(x, 7); cout << char(205);
		}

        for(y=1; y <= 7; y++)
        {
            gotoxy(4, y); cout << char(186);
            gotoxy(21, y); cout << char(186);
        }

        gotoxy(4, 1); cout << char(201);
        gotoxy(4, 7); cout << char(200);
        gotoxy(21, 1); cout << char(187);
        gotoxy(21, 7); cout << char(188);

		gotoxy(5,2); cout << "1 - Funcionarios\n";
		gotoxy(5,3); cout << "2 - Servicos\n";
		gotoxy(5,4); cout << "3 - Setores\n";
		gotoxy(5,5); cout << "0 - Sair\n";
		gotoxy(5,6); cout << "Opcao: ";

		cin >> op;
		if(op == 0)
			break;
		if(op == 1)
		{
			cout << "Voce escolheu a opcao 1" << endl;
			getch();
		}
	}

}
