#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "quickSort.h"

using namespace std;



/* Función para buscar registros entre fechas
Entra el vector con los registros leídos y los strings que contienen los límites de las fechas a encontrar.
Regresa un vector de strings que contienen los resultados de coincidencias.*/
vector<string> buscarPorFecha(const vector<string>& registros, const string& fechaInicio, const string& fechaFin){
    vector<string> resultados; // Creamos nuestro vector que almacene las coincidencias
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

/* Función para escribir los resultados en un archivo
Entran las variables del vector con los resultados y la cuenta de búsquedas que lleva el usuario.
No regresa nada, solo crea el archivo con el número de búsqueda y le muestra en pantalla al usuario.*/
void escribirResultados(const vector<string>& resultados, int numBusqueda){
    string outputFilename = "salida" + to_string(numBusqueda) + "-eq4.txt";
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
    QuickSort::quickSort(dates);

    //Crear archivo de salida de fechas ordenadas
    string outputFilename = "bitacoraOrdenada1.3-eq4.txt";
    ofstream outfile(outputFilename);

    // Verificar si el archivo de salida se abrió correctamente
    if (!outfile.is_open()){
        cout << "Error al crear el archivo de salida: " << outputFilename << endl;
        return 1;
    }

    for (const string& date : dates) {
        outfile << date << endl;  // Escribir cada registro en el archivo
    }

    short continuar = 1;
    int numBusqueda = 1;

    while (continuar == 1){
        string  fechaInicio,
                fechaFin;
        cout << "Ingrese la fecha de inicio (Ej: Jun 1): ";
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

        numBusqueda++; // Aumenta el contador de búsquedas para la creación del siguiente archivo
        cout << "¿Desea realizar otra búsqueda? 1) Sí   2) No\n";
        cin >> continuar;
    }

    //Cerrar el archivo
    outfile.close();

    return 0;
}