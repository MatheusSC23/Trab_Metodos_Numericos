#include <iostream>
#include "vec.h"
#include "matriz.h"

using namespace std;

void gauss();
void LU();

int main()
{
    cout << "Hello World!" << endl;
    LU();
    //gauss();
    return 0;
}


void LU(){
    cout.precision(2);
    int n = 3;
    float la[n]={3,2,4};
    Vec l1(3,la);
    float lb[n]={1,1,2};
    Vec l2(3,lb);
    float lc[n]={4,3,2};
    Vec l3(3,lc);
    Vec lista[n];
    lista[0]=l1;
    lista[1]=l2;
    lista[2]=l3;

    Matiz Mu = Matiz(n,lista);

    float la1[n]={1,0,0};
    Vec l11(3,la1);
    float lb1[n]={0,1,0};
    Vec l21(3,lb1);
    float lc1[n]={0,0,1};
    Vec l31(3,lc1);
    Vec lista1[n];
    lista1[0]=l11;
    lista1[1]=l21;
    lista1[2]=l31;
    Matiz Ml = Matiz(n,lista1);

    float resposta[3] = {1,2,3};

    for (int i = 0; i < n; i++){
        for (int j = i+1 ; j < n; j++){

            float a = Mu.linhas[i].returnElement(i);
            float b = Mu.linhas[j].returnElement(i);// m[j][i];
            Ml.linhas[j].setColunn(i,b/a);

            Vec aux = (Mu.linhas[i]*(b/a));
            Mu.linhas[j] -= aux;
        }
    }

    for(int i=0;i<n;i++){
        cout<<Ml.linhas[i].vetor[0]<<" "<<Ml.linhas[i].vetor[1]<<" "<<Ml.linhas[i].vetor[2]<<" "<<endl;
    }
    cout<<"-------------------------------------------"<<endl<<endl<<endl;
    for(int i=0;i<n;i++){
        cout<<Mu.linhas[i].vetor[0]<<" "<<Mu.linhas[i].vetor[1]<<" "<<Mu.linhas[i].vetor[2]<<" "<<endl;
    }

    float valorY[n]={1,2,3};

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"valor antes-- "<<valorY[i]<<endl;
            valorY[i]-= Ml.linhas[i].returnElement(j) * valorY[j];
            cout<<"linha "<<i+1<<"  --> " <<valorY[i]<<endl<<endl;
        }
        cout<<endl<<endl<<endl<<endl;
        valorY[i]/= Ml.linhas[i].returnElement(i);
    }

    cout<<"valor de Y = {"<<valorY[0] <<" "<< valorY[1] <<" " << valorY[2] <<"}"<<endl;

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            valorY[i]-= Mu.linhas[i].returnElement(j) * valorY[j];
        }
        valorY[i]/= Mu.linhas[i].returnElement(i);
        cout<<valorY[i]<<" ";

    }



}




















void gauss(){
    int n = 3;
    float la[n]={20,7,9};
    Vec l1(3,la);
    float lb[n]={7,30,8};
    Vec l2(3,lb);
    float lc[n]={9,8,30};
    Vec l3(3,lc);
    Vec lista[n];
    lista[0]=l1;
    lista[1]=l2;
    lista[2]=l3;

    Matiz M = Matiz(n,lista);
    float resposta[3] = {16,38,38};

    for (int i = 0; i < 3; i++){
        cout<<M.linhas[i].vetor[0]<<" "<<M.linhas[i].vetor[1]<<" "<<M.linhas[i].vetor[2]<<" "<<endl;
        for (int j = i+1 ; j < 3; j++){

            float a = M.linhas[i].returnElement(i);
            float b = M.linhas[j].returnElement(i);// m[j][i];

            resposta[j] = resposta[j] - ( resposta[i] * b/a );
            Vec aux = (M.linhas[i]*(b/a));
            M.linhas[j] -= aux;
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            resposta[i]-= M.linhas[i].returnElement(j) * resposta[j];
        }
        resposta[i]/= M.linhas[i].returnElement(i);
        cout<<resposta[i]<<" ";
    }
}
