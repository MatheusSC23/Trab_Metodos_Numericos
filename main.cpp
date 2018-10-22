#include <iostream>
#include <clocale>
#include <cstdlib>
#include <iostream>
#include <string>
#include "./NumericalMethods/FalsePosition.h"
#include "./NumericalMethods/Bissection.h"
#include "./NumericalMethods/NewtonRapson.h"   
#include "./TerminalBootstrap/terminal.h"

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

    string methodsHeader[7] = {"Foguete", "A", "Isolamento", "Posição Falsa", "Bisseção", "Newthon-Raphson", "Explodiu?"};
    cout << Terminal::insertTHeader(7, methodsHeader) << endl;

    cout.precision(5);

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
            "[" + strutil::double2str(fs.getIsolationStart(), 2) + ", " + strutil::double2str(fs.getIsolationEnd(), 2) + "]",
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

    string calibrateHeader[3] = {"Posição Falsa", "Bisseção", "Newthon-Raphson"};
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
    Terminal::insertInput("<ENTER> para continuar...");

    Terminal::clear();

    cout << Terminal::insertHeader("ROCKET EXPLOSION DETECTION") << endl;

    cout << Terminal::insertTitle("ERRO ABSOLUTO ENTRE CADA MÉTODO") << endl;

    for (int i = 0; i < rockets; i++) {
        cout << Terminal::insertSubtitle("FOGUETE " + to_string(i + 1)) << endl;
        
        string varianceHeader[3] = {"Bisse. ── Pos. Falsa", "Bisse. ── Newthon", "Pos. Falsa ── Newthon"};
        cout << Terminal::insertTHeader(3, varianceHeader) << endl;

        double a = rocketsData[i][0];
        FalsePosition fs(a, rocketsData[i][1], iterMax);
        Bissection b(a, rocketsData[i][1], iterMax);
        NewtonRapson nr(a, rocketsData[i][1], iterMax);

        double fs_result = fs.falsePosition();
        double b_result = b.bissection();
        double nr_result = nr.newtonRapson();

        string varianceRoots[3] = {
            to_string(abs(b.bissection() - fs.falsePosition())),
            to_string(abs(b.bissection() - nr.newtonRapson())),
            to_string(abs(nr.newtonRapson() - fs.falsePosition()))
        };

        cout << Terminal::insertTRow(3, varianceRoots) << endl;

        cout << Terminal::insertTFooter(3) << endl;

        cout << Terminal::insertHR() << endl;
    }

    Terminal::insertInput("<ENTER> para continuar...");

    Terminal::clear();

    cout << Terminal::insertHeader("ROCKET EXPLOSION DETECTION") << endl;

    cout << Terminal::insertTitle("ANÁLISE DA VARIAÇÃO DO VALOR DE 'A' PARA CADA MÉTODO") << endl;

    for (int i = 0; i < rockets; i++) {
        cout << Terminal::insertSubtitle("FOGUETE " + to_string(i + 1)) << endl;
        
        string varianceHeader[4] = {"A", "Posição Falsa", "Bisseção", "Newthon-Raphson"};
        cout << Terminal::insertTHeader(4, varianceHeader) << endl;

        for (int j = -2; j < 4; j++) {
            double a = rocketsData[i][0] + 0.1 * j;
            FalsePosition fs(a, rocketsData[i][1], iterMax);
            Bissection b(a, rocketsData[i][1], iterMax);
            NewtonRapson nr(a, rocketsData[i][1], iterMax);

            double fs_result = fs.falsePosition();
            double b_result = b.bissection();
            double nr_result = nr.newtonRapson();

            string varianceRoots[4] = {
                to_string(a),
                to_string(fs.falsePosition()),
                to_string(b.bissection()),
                to_string(nr.newtonRapson())
            };

            cout << Terminal::insertTRow(4, varianceRoots) << endl;   
        }

        cout << Terminal::insertTFooter(4) << endl;

        cout << Terminal::insertHR() << endl;
    }

    Terminal::insertInput("<ENTER> para sair...");
    return 0;
}
