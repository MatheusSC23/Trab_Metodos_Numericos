#ifndef MATRIZ_H
#define MATRIZ_H

//#include "vec.h"
class Vec;

class Matiz
{
public:
    int lenght;
    Vec linhas[100];

    Matiz();
    Matiz(int tamanho);
    Matiz(int tamanho,Vec* vetorEntrada);

};

Matiz::Matiz(){}

Matiz::Matiz(int tamanho) {
    lenght = tamanho;
}

Matiz::Matiz(int tamanho,Vec* vetorEntrada){
    lenght = tamanho;
    for (int interadorLinhaMatriz = 0; interadorLinhaMatriz < tamanho; interadorLinhaMatriz++){
        linhas[interadorLinhaMatriz] = vetorEntrada[interadorLinhaMatriz];
    }
}
#endif
