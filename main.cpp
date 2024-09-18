#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bubbleSort.h"

using namespace std;



// Función para buscar registros entre fechas
vector<string> buscarPorFecha(const vector<string>& registros, const string& fechaInicio, const string& fechaFin){
    vector<string> resultados;
    string fechaInicioFormateada = convertirFecha(fechaInicio); // Convierte fecha inicial
    string fechaFinFormateada = convertirFecha(fechaFin); // Convierte fecha final

    for (const string& registro : registros){ // Ciclo que lee todos los registros
        string fechaRegistro = convertirFecha(registro); // Convierte la fecha del registro actual
        if (fechaRegistro >= fechaInicioFormateada && fechaRegistro <= fechaFinFormateada){
            // Si la fecha está dentro del rango ingresaa en el vector
            resultados.push_back(registro);
        }
    }

    return resultados;
}

// Función para escribir los resultados en un archivo
void escribirResultados(const vector<string>& resultados, int numBusqueda){
    string outputFilename = "salida" + to_string(numBusqueda) + "-eq#.txt";
    ofstream outfile(outputFilename);

    if (!outfile.is_open()){ // Si el archivo de salida no se abrió da error
        cout << "Error al crear el archivo de salida: " << outputFilename << endl;
        return;
    }

    for (const string& linea : resultados){ // Escribir los resultados en el archivo
        outfile << linea << endl;
    }

    outfile.close();
    cout << "Resultados guardados en " << outputFilename << endl;
}

int main(){
    //Guardar el archivo para poder manipularlo
    string filename = "bitacora.txt";
    ifstream infile(filename);
    //En caso de que no se logre abrir el archivo
    if (!infile.is_open()){
        cout <<"Error al abrir el archivo " <<filename <<endl;
        return 1;
    }

    vector<string> dates;
    string line;

    while (getline(infile, line)){
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
    if (!outfile.is_open()){
        cout << "Error al crear el archivo de salida: " << outputFilename << endl;
        return 1;
    }

    short continuar = 1;
    int numBusqueda = 1;

    while (continuar == 1){
        string fechaInicio, fechaFin;
        cout << "Ingrese la fecha de inicio (Ej: Sep 21): ";
        cin.ignore();
        getline(cin, fechaInicio);
        cout << "Ingrese la fecha de fin (Ej: Oct 25): ";
        getline(cin, fechaFin);

        // Va a la función de buscar los registros entre las fechas dadas
        vector<string> resultados = buscarPorFecha(dates, fechaInicio, fechaFin);

        // Verificar si hay resultados y escribirlos en un archivo
        if (!resultados.empty()) {
            escribirResultados(resultados, numBusqueda);
        } else {
            cout << "No se encontraron resultados para el rango de fechas ingresado." << endl;
        }

        numBusqueda++;
        cout << "¿Desea realizar otra búsqueda? 1) Sí   2) No\n";
        cin >> continuar;
    }

    //Cerrar el archivo
    outfile.close();

    return 0;
}