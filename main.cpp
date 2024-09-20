#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bubbleSort.cpp"

using namespace std;



int main(){
    //Guardar el archivo para poder manipularlo
    string filename = "bitacora.txt";
    ifstream infile(filename);
    //En caso de que no se logre abrir el archivo
    if (!infile.is_open()) {
        cout <<"Error al abrir el archivo" <<filename <<endl;
        return 1;
    }
    vector<string> dates;
    string line;
    //Almacena los datos en un vector
    while (getline(infile, line)) {
        dates.push_back(line);  //Agrega la línea leída al vector
    }
    //Cierra el archivo después de leerlo
    infile.close();

    //Ordenar la información por fecha para realizar la búsqueda
    BubbleSort::bubbleSort(dates);

    //Crear archivo de salida de fechas ordenadas
    string outputFilename = "bitacoraOrdenada1.3-eq#.txt";
    ofstream outfile(outputFilename);

    // Verificar si el archivo de salida se abrió correctamente
    if (!outfile.is_open()) {
        cout << "Error al crear el archivo de salida: " << outputFilename << endl;
        return 1;
    }
    //Cerrar el archivo
    outfile.close();

    return 0;
}