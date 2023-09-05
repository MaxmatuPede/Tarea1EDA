#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "sort.hpp"
#include "utils.hpp"
#include <chrono>
#include <ctime>
using namespace std;

long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
		std::chrono::time_point<std::chrono::high_resolution_clock> t2){
	auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

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
            	cout << "Leyendo archivo de ruts..." << endl;
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
                        ruti = stof(rut);
                        ruts[lines] = ruti;
                    }
                    lines ++;
                }
                fileistream.close();
                auto start = std::chrono::high_resolution_clock::now();
                if(!strcmp(argv[2], "I")){
                    cout << "Ejecutando InsertSort..." << endl;
                    sort::insertionSort(ruts, lines);
                }
                if(!strcmp(argv[2], "M")){
                    cout << "Ejecutando MergeSort..." << endl;
                    sort::mergeSort(ruts, 0, lines);
                }
                if(!strcmp(argv[2], "Q")){
                    cout << "Ejecutando QuickSort..." << endl;
                    sort::quickSort(ruts, lines);
                }
                if(!strcmp(argv[2], "R")){
                    cout << "Ejecutando RadixSort..." << endl;
                    sort::radixSort(ruts, lines);
                }
                auto end = std::chrono::high_resolution_clock::now();
                long elapsed =  getElapsedTime(start, end);
                cout << "El tiempo que tardo fue " << elapsed << " microsegundos" << endl;
                cout << "Escribiendo archivo ordenado..." << endl;
                file_sort = file_sort + ".sorted";
                ofstream outputFile(file_sort);
                if (!outputFile.is_open()) {
                    cerr << "Unable to open the file." << endl;
                    return 0;
                }
                for (int num = 0; num < lines-1; num++) {
                    outputFile << ruts[num] << '\n';
                }
                outputFile.close();
                delete[] ruts;
            }
        }

        
    }
    return 0;
}
