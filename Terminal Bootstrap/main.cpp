#include <iostream>
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <string>
#include "terminal.h"

using namespace std;

int main(void) {
    Terminal::clear();
    Terminal::setBoxWidth(90);
    std::setlocale(LC_ALL, "en_US.utf8");

    cout << Terminal::insertHeader("ROCKET EXPLOSION DETECTION") << endl;
    cout << Terminal::insertSectionStart() << endl;
    cout << Terminal::insertBlankSpace() << endl;
    cout << Terminal::insertParagraph("Esse sistema calcula o deslocamento 'd' da extremidade de um foguete espacial através da equação f(d) = ad – dln(d), onde 'd' é o deslocamento medido em 'cm' e 'a' é um parâmetro de ajuste. Com isso, é inferido se o foguete irá explodir ou não.") << endl;
    cout << Terminal::insertBlankSpace() << endl;
    cout << Terminal::insertBottomLine() << endl;

    cout << Terminal::insertTitle("INSIRA OS DADOS DA ANÁLISE") << endl;

    int rockets, iterMax;
    Terminal::insertInput("Digite o número de foguetes: ", rockets);
    Terminal::insertInput("Digite o número máximo de iterações: ", iterMax);

    // Data: fitParam, precision
    float rocketsData[rockets][2];

    cout << Terminal::insertHalfHR() << endl;
    for (int i = 0; i < rockets; i++) {
        string index = to_string(i + 1);
        cout << Terminal::insertSubtitle("FOGUETE " + index) << endl;
        Terminal::insertInput("Informe o parâmetro de ajuste: ", rocketsData[i][0]);
        Terminal::insertInput("Informe a precisão: ", rocketsData[i][1]);
        cout << Terminal::insertHalfHR() << endl;
    }

    cout << Terminal::insertHR() << endl;

    cout << Terminal::insertTitle("CONFIRA ABAIXO OS DADOS INSERIDOS") << endl;

    string theaders[3] = {"Foguete", "Parâmetro de Ajuste", "Precisão"};
    cout << Terminal::insertTHeader(3, theaders) << endl;

    for (int i = 0; i < rockets; i++) {
        float data[3] = {i + 1, rocketsData[i][0], rocketsData[i][1]};
        cout << Terminal::insertTRow(3, data) << endl;
    }

    cout << Terminal::insertTFooter(3) << endl;

    Terminal::insertInput("<ENTER> para continuar...");

    return 0;
}