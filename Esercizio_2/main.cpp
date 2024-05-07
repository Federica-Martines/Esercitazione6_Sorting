#include <iostream>
#include <vector>
#include <chrono>
#include <numeric> //per std::iota
#include <string>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace std::chrono;
using namespace SortLibrary;


double tempi_merge(vector<int>& data_merge)
{
    vector<unsigned int> tempi_merge;
    unsigned int numIterazioni = 10;

    for (int i = 0; i < numIterazioni; ++i)
    {
        // Misurazione del tempo per l'algoritmo Merge Sort
        auto start_merge = steady_clock::now();
        MergeSort(data_merge, 0, data_merge.size() - 1);
        auto stop_merge = steady_clock::now();
        auto duration_merge = duration_cast<milliseconds>(stop_merge - start_merge);
        tempi_merge.push_back(duration_merge.count());
    }

    double sum_merge = 0;
    for (auto value : tempi_merge) {
        sum_merge += value;
    }
    return sum_merge / tempi_merge.size();
}

double tempi_bubble(vector<int>& data_bubble)
{vector<unsigned int> tempi_bubble;
    unsigned int numIterazioni = 10;

    for (int i = 0; i < numIterazioni; ++i)
    {
        // Misurazione del tempo per l'algoritmo Bubble Sort
        auto start_bubble = steady_clock::now();
        BubbleSort(data_bubble);
        auto stop_bubble = steady_clock::now();
        auto duration_bubble = duration_cast<milliseconds>(stop_bubble - start_bubble);
        tempi_bubble.push_back(duration_bubble.count());
    }

    double sum_bubble = 0;
    for (auto value : tempi_bubble) {
        sum_bubble += value;
    }
    return sum_bubble / tempi_bubble.size();
}

//** ti manda al valore dell'indirizzo
int main(int argc, char **argv) {

    /*int size;
    cout << "Inserisci il numero di elementi del vettore: ";
    cin >> size;

    // Verifica dell'input
    while (cin.fail() || size <= 0)
    {
        cout << "Input sbagliato. Per favore inserisci un intero positivo: ";
        cin.clear(); // Pulizia dello stato di errore di cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora il buffer di input
        cin >> size;
    }*/

    //argc è il numero di elementi, arv è la lista di argomenti
    // Controllo se è stato fornito un argomento dalla riga di comando
    if (argc != 2) {
        cerr << "Non è statto fornito un input dalla linea di comando." << endl;
        return 1;
    }

     // Converto l'argomento in un numero intero
     int size = stoi(argv[1]); //string to int

    // Controllo se la conversione ha avuto successo
    if (size <= 0) {
        cerr << "Input sbagliato. Per favore inserisci un intero positivo." << endl;
        return 1;
    }

    // Altrimenti, la dimensione è valida, procedo con il programma
    cout << "Dimensione dell'array: " << size << endl;

    //Creazione di un vettore ordinato
    vector<int> data1(size);
    iota(data1.begin(), data1.end(), 0); // Riempie il vettore con valori crescenti

    // Copia del vettore per utilizzarlo con entrambi gli algoritmi
    vector<int> data1_merge = data1;
    vector<int> data1_bubble = data1;

    // Calcolo delle medie dei tempi di esecuzione per Merge Sort e Bubble Sort
    double average1_merge = tempi_merge(data1_merge);
    double average1_bubble = tempi_bubble(data1_bubble);

    // Stampa delle medie dei tempi di esecuzione
    cout << "La media dei tempi per l'algoritmo merge di un vettore completamente ordinato è di: " << average1_merge << " millisecondi" << endl;
    cout << "La media dei tempi per l'algoritmo bubble di un vettore completamente ordinato è di : " << average1_bubble << " millisecondi" << endl;

    // Creazione di un vettore di numeri casuali
    vector<int> data2(size);
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        data2[i] = rand() % 1000; // Numeri casuali nell'intervallo [0, 999]
    }

    /*cout << "Il vettore con elementi casuali è: ";
    for (int i = 0; i < data.size(); ++i)
    {
        std::cout << data[i] << " ";
    }
    cout << endl;*/

    // Copia del vettore per utilizzarlo con entrambi gli algoritmi
    vector<int> data2_merge = data2;
    vector<int> data2_bubble = data2;

    // Calcolo delle medie dei tempi di esecuzione per Merge Sort e Bubble Sort
    double average2_merge = tempi_merge(data2_merge);
    double average2_bubble = tempi_bubble(data2_bubble);

    // Stampa delle medie dei tempi di esecuzione
    cout << "La media dei tempi per l'algoritmo merge per un vettore randomico è di: " << average2_merge << " millisecondi" << endl;
    cout << "La media dei tempi per l'algoritmo bubble per un vettore randomico è di: " << average2_bubble << " millisecondi" << endl;

    // Creazione di un vettore ordinato da perturbare
    vector<int> data3(size);
    iota(data3.begin(), data3.end(), 0);
    // Perturbazione leggera del vettore ordinato
    vector<int> data_perturbed = data3;
    for (int i = 0; i < size; i++)
    {
        data_perturbed[i] += int(rand()) % 10; //somma un numero intero casuale tra 0 e 9
    }

    // Copia del vettore per utilizzarlo con entrambi gli algoritmi
    vector<int> data3_merge = data_perturbed;
    vector<int> data3_bubble = data_perturbed;

    // Calcolo delle medie dei tempi di esecuzione per Merge Sort e Bubble Sort
    double average3_merge = tempi_merge(data3_merge);
    double average3_bubble = tempi_bubble(data3_bubble);

    // Stampa delle medie dei tempi di esecuzione
    cout << "La media dei tempi per l'algoritmo merge per un vettore leggermente randomico è di: " << average3_merge << " millisecodni" << endl;
    cout << "La media dei tempi per l'algoritmo bubble per un vettore leggermente randomico è di: " << average3_bubble << " miilisecondi" << endl;


    return 0;
}




