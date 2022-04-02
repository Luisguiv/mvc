#include "opaqueTypeCliente.h"
#include "menu.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    setlocale(LC_ALL, ".UTF8");
    setlocale(LC_ALL, "");

    Cliente *temp = criarCliente();
    Alimento *tempAlimento = criarAlimento();

    while(1){
        if(menu(temp, tempAlimento)) break;
        else continue;
    }

    freeCliente(temp);

    return 0;
}
