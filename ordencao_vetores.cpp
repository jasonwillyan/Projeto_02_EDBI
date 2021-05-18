#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#define size_1 500
#define size_2 1000
#define size_3 1500
#define size_4 2000
#define size_5 2500

#define qtd_vet 5

using namespace std;

void bubbleSort(int arr[], int n){ 
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++){
        swapped = false;

        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void selectionSort(int vet[], int size){
    for (int indice = 0; indice < size; indice++){
        int indiceMenor = indice;
        for (int indiceSeguinte = indice+1; indiceSeguinte < size; indiceSeguinte++){
            if(vet[indiceSeguinte] < vet[indiceMenor]){
                indiceMenor = indiceSeguinte;
            }
        } 

        int aux = vet[indice];
        vet[indice] = vet[indiceMenor];
        vet[indiceMenor] = aux;       
    }    
}

void preencherVetorDesordenado(int *vet, int size){
    for (int i = 0; i < size; i++)
        vet[i] = (rand()%(size+1));
}

void preencherVetorOrdenado(int *vet, int size){
    for (int i = 0; i < size; i++)
        vet[i] = i;
}


void chronoCalculo(int vet[], int size, double &media_bubble, double &media_selection){
    for (int i = 0; i < size; i++) {
        auto start = chrono::high_resolution_clock::now();
        
        bubbleSort(vet, size);
        
        auto end =  chrono::high_resolution_clock::now();

        double elapsedtime = chrono::duration_cast<chrono::microseconds>(end - start).count();

        media_bubble += elapsedtime;
    }
   
    for(int i = 0; i < size; i++) {
        auto start = chrono::high_resolution_clock::now();
       
        selectionSort(vet, size);
       
        auto end =  chrono::high_resolution_clock::now();

        double elapsedtime = chrono::duration_cast<chrono::microseconds>(end - start).count();

        media_selection += elapsedtime;
    }
}

int main(int argc, char const *argv[]){ 
    srand(time(nullptr));

    int size[qtd_vet] = {size_1, size_2, size_3, size_4, size_5};

    int vetor_1[size_1], vetor_2[size_2], vetor_3[size_3], vetor_4[size_4], vetor_5[size_4];

    int mat[1][qtd_vet] = {vetor_1[size_1], vetor_2[size_2], vetor_3[size_3], vetor_4[size_4], vetor_5[size_5]};

    double media_bubble = 0, media_selection = 0;

    
    
    cout << "\nVETORES DESORDENADOS\n" << endl;

    for (int i = 0; i < qtd_vet; i++){
        preencherVetorDesordenado(mat[i], size[i]);
    }


    for (int i = 0; i < qtd_vet; i++){
        chronoCalculo(mat[i], size[i], media_bubble, media_selection);

        cout << (i+1) << ". Bubble Sort: " << media_bubble/size[i] << " ms " << endl;

        cout << (i+1) << ". Selection Sort: " << media_selection/size[i] << " ms " << endl;
        
        media_bubble = 0;
        media_selection = 0;
        
        cout << "-----------------------------------------" << endl;
    }

    cout << "\n\nVETORES ORDENADOS\n" << endl;

    for (int i = 0; i < qtd_vet; i++){
        preencherVetorOrdenado(mat[i], size[i]);
    }

    for (int i = 0; i < qtd_vet; i++){
        chronoCalculo(mat[i], size[i], media_bubble, media_selection);

        cout << (i+1) << ". Bubble Sort: " << media_bubble/size[i] << " ms " << endl;

        cout << (i+1) << ". Selection Sort: " << media_selection/size[i] << " ms " << endl;
        
        media_bubble = 0;
        media_selection = 0;
        
        cout << "-----------------------------------------" << endl;
    }
    return EXIT_SUCCESS;

}