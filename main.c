#include <stdio.h>

struct datos{
    int n;
    char nombre[20];
    char apellido[20];
    char carrera[50];
    float P1;
    float P2;
    float P3;
    float promedio;
}Alumn[10];

float calculo_promedio(float P1, float P2, float P3){
    float promedio = (P1 + P2 + P3) / 3;
    return promedio;
}

void crearFile(void){
    FILE *archivo2 = fopen("promedio alumnos.txt", "w");

    for (int j = 0; j < 5; j++){
        fprintf(archivo2, "%d;%s %s;%s;%f;%f;%f;%f", Alumn[j].n, Alumn[j].nombre, Alumn[j].apellido, Alumn[j].carrera, Alumn[j].P1, Alumn[j].P2, Alumn[j].P3, Alumn[j].promedio);
        fprintf(archivo2, "\n");
    }
    fclose(archivo2);
}

void leerFile(void){
    FILE* archivo;
    archivo = fopen("/Users/Matias Lopez/Library/CloudStorage/OneDrive-UniversidaddeLasAméricas/UDLA 2/Programacion I/CodeC/Progreso3/alumnos.txt", "r");
    if (archivo == NULL){
        printf("No se pudo abrir el archivo!\n");
    }else{
        printf("Se abrio el archivo correctamente.\n");
        while (!feof(archivo)){
            for (int j = 0; j < 5; j++){
                fscanf(archivo, "%d;%s %s;%s;%f;%f;%f", &Alumn[j].n, Alumn[j].nombre, Alumn[j].apellido, Alumn[j].carrera, &Alumn[j].P1, &Alumn[j].P2, &Alumn[j].P3);
                Alumn[j].promedio = calculo_promedio(Alumn[j].P1, Alumn[j].P2, Alumn[j].P3);
            }  
        }
        
        
        crearFile();
    }
    fclose(archivo);
}

int main(){
    leerFile();
}