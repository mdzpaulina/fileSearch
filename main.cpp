#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

//Mapa para la conversión de meses
map<string, string> months = {
    {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, 
    {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, 
    {"Sept", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
};

int main(){
    //Guardar el archivo para poder manipularlo
    string filename = "bitacora.txt";
    ifstream infile(filename);
    //En caso de que no se logre abrir el archivo
    if (!infile.is_open()) {
        cout <<"Error al abrir el archivo" <<filename <<endl;
        return 1;
    }
    vector<string> lines;
    string line;
    //Almacena los datos en un vector
    while (getline(infile, line)) {
        lines.push_back(line);  //Agrega la línea leída al vector
    }
    //Cierra el archivo después de leerlo
    infile.close();

    //Ordenar la información por fecha para realizar la búsqueda


    return 0;
}