#include "bubbleSort.h"
#include <sstream>
#include <map>

//Funcion para convertir la fecha 
string convertirFecha(const string& line) {
    static const map<string, string> months = {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, 
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, 
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };
    stringstream ss(line);
    string month, day;
    ss >> month >> day;
    return months.at(month) + "-" + day;
}

//Implementación de bubbleSort
void BubbleSort::bubbleSort(vector<string>& lines){
    int n = lines.size();
    bool intercambiado  = true;
    while (intercambiado) {
        intercambiado = false;
        for (int i = 0; i < n-1; i++){
            string date1 = convertirFecha(lines[i]);
            string date2 = convertirFecha(lines[i+1]);
            if (date1[i] > date2[i + 1]){
                swap(lines[i], lines[i+1]);
                intercambiado = true;
            }
        }
        --n;
    }
}