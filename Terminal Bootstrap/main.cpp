#include <iostream>
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <string>
#include "terminal.h"

using namespace std;

int main(void) {
    Terminal::clear();
    Terminal::setBoxWidth(120);
    std::setlocale(LC_ALL, "en_US.utf8");

    cout << Terminal::insertHeader(u8"ROCKET EXPLOSION DETECTION") << endl;
    cout << Terminal::insertSectionStart() << endl;
    cout << Terminal::insertBlankSpace() << endl;
    cout << Terminal::insertParagraph(u8"Esse sistema calcula o deslocamento 'd' da extremidade de um foguete espacial através da equação f(d) = ad – dln(d), onde 'd' é o deslocamento medido em 'cm' e 'a' é um parâmetro de ajuste. Com isso, é inferido se o foguete irá explodir ou não.") << endl;
    cout << Terminal::insertBlankSpace() << endl;
    cout << Terminal::insertBottomLine() << endl;

    cout << Terminal::insertTitle(u8"INSIRA OS DADOS DA ANÁLISE") << endl;

    int rockets, iterMax;
    Terminal::insertInput(u8"Digite o número de foguetes: ", rockets);
    Terminal::insertInput(u8"Digite o número máximo de iterações: ", iterMax);

    // Data: fitParam, precision
    string rocketsData[rockets][2];

    cout << Terminal::insertHalfHR() << endl;
    for (int i = 0; i < rockets; i++) {
        string index = to_string(i + 1);
        cout << Terminal::insertSubtitle(u8"FOGUETE " + index) << endl;
        Terminal::insertInput(u8"Informe o parâmetro de ajuste: ", rocketsData[i][0]);
        Terminal::insertInput(u8"Informe a precisão: ", rocketsData[i][1]);
        cout << Terminal::insertHalfHR() << endl;
    }

    return 0;
}