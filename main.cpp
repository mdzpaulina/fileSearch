#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    string filename = "bitacora.txt";
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout <<"Error al abrir el archivo" <<filename <<endl;
        return 1;
    }

    vector<string> lines;
    string line;

    while (getline(infile, line)) {
        lines.push_back(line);
    }

    infile.close();

    for (const auto& l : lines) {
        cout << l << endl;
    }

    return 0;
}