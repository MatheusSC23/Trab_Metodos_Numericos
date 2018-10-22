#include <iostream>
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <string>
#include "../NumericalMethods/FalsePosition.h"
#include "../NumericalMethods/Bissection.h"
#include "../NumericalMethods/NewtonRapson.h"   

#include "terminal.h"

using namespace std;

int main(void) {
    Terminal::clear();
    Terminal::setBoxWidth(120);
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

    string rocketsHeader[3] = {"Foguete", "Parâmetro de Ajuste", "Precisão"};
    cout << Terminal::insertTHeader(3, rocketsHeader) << endl;

    for (int i = 0; i < rockets; i++) {
        float data[3] = {(float)(i + 1), rocketsData[i][0], rocketsData[i][1]};
        cout << Terminal::insertTRow(3, data) << endl;
    }

    cout << Terminal::insertTFooter(3) << endl;

    Terminal::insertInput("<ENTER> para continuar...");

    Terminal::clear();

    cout << Terminal::insertHeader("ROCKET EXPLOSION DETECTION") << endl;

    cout << Terminal::insertTitle("EXECUÇÃO DOS MÉTODOS") << endl;

    string methodsHeader[7] = {"Foguete", "A", "Isolamento", "Bisseção", "Posição Falsa", "Newthon-Raphson", "Explodiu?"};
    cout << Terminal::insertTHeader(7, methodsHeader) << endl;

    for (int i = 0; i < rockets; i++) {
        FalsePosition fs(rocketsData[i][0], rocketsData[i][1], iterMax);
        Bissection b(rocketsData[i][0], rocketsData[i][1], iterMax);
        NewtonRapson nr(rocketsData[i][0], rocketsData[i][1], iterMax);

        double fs_result = fs.falsePosition();
        double b_result = b.bissection();
        double nr_result = nr.newtonRapson();

        string methodsRoots[7] = {
            to_string(i + 1),
            to_string(rocketsData[i][0]),
            fs.getIsolation(),
            to_string(fs_result),
            to_string(b_result),
            to_string(nr_result),
            fs_result > 2 ? "SIM" : "NÃO" 
        };

        cout << Terminal::insertTRow(7, methodsRoots) << endl;
    }

    cout << Terminal::insertTFooter(7) << endl;

    cout << Terminal::insertHR() << endl;
    cout << Terminal::insertTitle("SISTEMA CALIBRADO USANDO COMO PADRÃO A = 1, ISOLAMENTO = (2, 3) E PHI = 10⁻⁵") << endl;

    string calibrateHeader[3] = {"Bisseção", "Posição Falsa", "Newthon-Raphson"};
    cout << Terminal::insertTHeader(3, calibrateHeader) << endl;

    int a = 1;
    FalsePosition fs(a, 1e-5, iterMax, 2, 3);
    Bissection b(a, 1e-5, iterMax, 2, 3);
    NewtonRapson nr(a, 1e-5, iterMax);

    string calibrateRoots[3] = {
        to_string(fs.falsePosition()),
        to_string(b.bissection()),
        to_string(nr.newtonRapson())
    };

    cout << Terminal::insertTRow(3, calibrateRoots) << endl;
    cout << Terminal::insertTFooter(3) << endl;

    cout << Terminal::insertHR() << endl;
    cout << Terminal::insertSubtitle("QUADRO COMPARATIVO") << endl;

    return 0;
}
