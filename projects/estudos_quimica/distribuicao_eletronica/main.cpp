#include<iostream>

using namespace std;

struct Camadas{
    int numCamada;
    char strCamada;
    int NumAtomico;
};

int main(){
    int vCountCamada, vCountSubCamada, vCount, vEletronsUltimaCamada, vQtdeDistribuicao = 0, vNumAtomicoCamada;
    int vNumAtomico;
    int vNumAtomicoFixo;

    cout << "************************************\n";
    cout << "*** Desenvolvido por Arthur Paiva Muniz. ***\n";
    cout << "************************************\n\n\n";

    cout << "Digite o valor do numero atomico: ";
    cin >> vNumAtomico;

    vNumAtomicoFixo = vNumAtomico;

    /* Distribuição eletrônica completa */
    Camadas distribuicao[18] = {{1, 's', 2}, {2, 's', 2}, {2, 'p', 6}, {3, 's', 2}, {3, 'p', 6}, {4, 's', 2}, {3, 'd', 10}, {4, 'p', 6}, {5, 's', 2}, {4, 'd', 10}, {5, 'p', 6}, {6, 's', 2}, {4, 'f', 14}, {5, 'd', 10}, {6, 'p', 6}, {7, 's', 2}, {5, 'f', 14}, {6, 'd', 10}};

    /* encontra o numero de subcamadas por camada */
    for(vCountSubCamada = 0; vCountSubCamada < 18; vCountSubCamada++){
        if((vNumAtomicoFixo-distribuicao[vCountSubCamada].NumAtomico) < 0){
            vEletronsUltimaCamada = vNumAtomicoFixo;
        }
        if( (vNumAtomicoFixo - distribuicao[vCountSubCamada].NumAtomico) >= 0 ){
            vQtdeDistribuicao++;
            vNumAtomicoFixo -= distribuicao[vCountSubCamada].NumAtomico;
        }else{
            if(vNumAtomicoFixo > 0){
                vQtdeDistribuicao++;
            }
            vCountSubCamada = 18;
        }
    }

    /* imprime distribuicao eletrica */
    cout << "\n\nDistribuicao eletronica: \n\n" << endl;
    if(vEletronsUltimaCamada == 0){
        // imprime sem alterar eletron da ultima camada
        for(vCount = 0; vCount < vQtdeDistribuicao; vCount++){
            cout << distribuicao[vCount].numCamada << distribuicao[vCount].strCamada << distribuicao[vCount].NumAtomico << " ";
        }
    }else{
        // imprime sem alterar eletron da ultima camada
        for(vCount = 0; vCount < vQtdeDistribuicao; vCount++){
            if(vCount == (vQtdeDistribuicao-1)){
                cout << distribuicao[vCount].numCamada << distribuicao[vCount].strCamada << vEletronsUltimaCamada;
            }else{
                cout << distribuicao[vCount].numCamada << distribuicao[vCount].strCamada << distribuicao[vCount].NumAtomico << " ";
            }
        }
    }
    
    cout << "\n\n\n";
    return 0;
}