#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>
#include <string>
using namespace std;

//Clase para quickSort
class QuickSort{
    
    public:
    static void quickSort(vector<string>& arr); // Inicializa quickSort
    static int partition(vector<string>& arr, int low, int high);
    static void quickSort(vector<string>& arr, int low, int high);
    
    private:
    // Métodos privados para 
};

// Declarar la función convertirFecha
string convertirFecha(const string& line);

#endif