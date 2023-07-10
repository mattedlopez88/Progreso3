#include <stdio.h>

int main(){
    FILE* archivo = fopen("alumnos.txt", "r");

    if (archivo == NULL){
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }
}