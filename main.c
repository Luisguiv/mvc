#include "opaqueTypeCliente.h"
#include "menu.h"

int main(){
    Cliente *temp = criarCliente();
    Alimento *tempAlimento = criarAlimento();

    while(1){
        if(menu(temp, tempAlimento)) break;
        else continue;
    }

    freeCliente(temp);

    return 0;
}
