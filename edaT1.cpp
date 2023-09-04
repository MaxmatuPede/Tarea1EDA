#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "sort.hpp"
#include "utils.hpp"
using namespace std;



int main(int argc, char** argv){ 
    if (argc != 3){
        cout << "No se puede sortear porque el numero de inputs en la consola es incorrecto" << endl;
    }

    else {
        string file_sort = argv[1];
        ifstream fileistream;
        fileistream.open(file_sort);
        if(!fileistream){
            cout << "Archivo inexistente" << endl;
        }
        else{
            if(strcmp(argv[2], "I") && strcmp(argv[2], "M") && strcmp(argv[2], "Q") && strcmp(argv[2], "R")){
                cout << "Algoritmo de ordenamiento de la Teleton, osea invalido" << endl;
            }
            else{
                int lines=0;
                string rut;
                while(fileistream.good()) if(fileistream.get()=='\n') lines++;
                fileistream.close();
                int *ruts = new int[lines];
                lines=0;
                ifstream fileistream;
                fileistream.open(file_sort);
                int ruti;
                while (fileistream.good()) {
                    getline(fileistream, rut);
                    if(!rut.empty() && rut.back() == '\n'){
                        rut.pop_back();
                    }
                    if(!rut.empty()){
                        ruti = stoi(rut);
                        ruts[lines] = ruti;
                    }
                    lines ++;
                }
                fileistream.close();
                
                delete[] ruts;
            }
        }

        
    }
    return 0;
}