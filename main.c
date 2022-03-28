#include "opaqueTypeCliente.h"
#include "menu.h"

int main(){
    Cliente *temp = criarCliente();

    while(1){
        if(menu(temp)) break;
        else continue;
    }

    freeCliente(temp);

    return 0;
}
