#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include <string>
using namespace std;

//Clase para quickSort
class QuickSort{
    public:
        //Función para ordenar un vector de objetos 
        static void quickSort(vector<string> &dates);
};

// Declarar la función convertirFecha
string convertirFecha(const string& line);

#endif