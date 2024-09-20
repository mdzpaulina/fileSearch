#include "quickSort.h"
#include <iostream>
#include <sstream>
#include <map>

// Funcion para convertir la fecha 
string convertirFecha(const string& line) {
    static const map<string, string> months = {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, 
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, 
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };
    stringstream ss(line);
    string month, day;
    ss >> month >> day;
    if (months.find(month) == months.end()) {
        cerr << "Error: mes no reconocido en la linea: " << line << endl; // Si el mes no está en el mapa, lanza advertencia
        return "";
    }
    return months.at(month) + "-" + day;
}

/* Método para iniciar quickSort
Inicia quickSort dando los datos de la bitácora en un vector tipo string.
No regresa nada, solo inicializa la función con los límites para la partición*/
void QuickSort::quickSort(vector<string>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

/* Método que implementa quickSort
Hace el proceso de quickSort en donde con los datos y límites utiliza el pivote.
No regresa nada, solo usa recursividad en el mismo método para el lado derecho e izquierdo.*/
void QuickSort::quickSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

/* Función para realizar la partición
Hace el proceso de la partición del pivote donde ingresamos el vector con datos y límites.
Regresa el número del pivote seleccionado*/
int QuickSort::partition(vector<string>& arr, int low, int high) {
    string pivot = convertirFecha(arr[high]);  // Usamos la fecha convertida como pivote
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (convertirFecha(arr[j]) < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}