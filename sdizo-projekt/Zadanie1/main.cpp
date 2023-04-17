#include <iostream>
#include "Table.hpp"
#include "DoublyLinkedList.hpp"
#include "MaxHeap.hpp"
#include "BST.hpp"
using namespace std;

void displayMenu(string info)
{
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku" << endl;
    cout << "2.Usun" << endl;
    cout << "3.Dodaj" << endl;
    cout << "4.Znajdz" << endl;
    cout << "5.Utworz losowo" << endl;
    cout << "6.Wyswietl" << endl;
    cout << "7.Test (pomiary)" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

Table tab;

void menu_table()
{
    char option;
    string fileName;
    int index, value, howMany;



    do{
        displayMenu("--- TABLICA ---");
        cin >> option;
        cout << endl;
        switch (option){
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwę zbioru:";
                cin >> fileName;
                tab.loadFromFile(fileName);
                tab.display();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj index:";
                cin >> index;
                tab.deleteByIndex(index);
                tab.display();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartość:";
                cin >> value;

                tab.add(index,value);
                tab.display();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj wartosc:";
                cin >> value;
                if (tab.isContainingValue(value))
                    cout << "podana wartosc jest w tablicy";
                else
                    cout << "podanej wartosci nie ma w tablicy";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementów tablicy:";
                cin >> howMany;
                tab.generateTable(howMany);
                tab.display();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                tab.display();
                break;

            case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne dodatkowe case'y
                break;
        }

    } while (option != '0');
}

DoublyLinkedList dlList;
void menu_list()
{
    char option;
    string fileName;
    int index, value, howMany;



    do{
        displayMenu("--- LISTA DWUKIERUNKOWA ---");
        cin >> option;
        cout << endl;
        switch (option){
            case '1': //tutaj wczytytwanie  listy z pliku
                cout << " Podaj nazwę pliku:";
                cin >> fileName;
                dlList.loadFromFile(fileName);
                dlList.display();
                break;

            case '2': //tutaj usuwanie elemenu z listy
                cout << " podaj wartość:";
                cin >> index;
                dlList.deleteByValue(index);
                dlList.display();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj wartość:";
                cin >> value;

                dlList.add(value, index);
                dlList.display();
                break;

            case '4': //tutaj znajdowanie elemetu w liscie
                cout << " podaj wartosc:";
                cin >> value;
                if (dlList.isContainingValue(value))
                    cout << "podana wartosc jest w liscie";
                else
                    cout << "podanej wartosci nie ma w liscie";
                break;

            case '5':  //tutaj generowanie w liscie
                cout << "Podaj ilosc elementów liscie:";
                cin >> howMany;
                dlList.generateList(howMany);
                dlList.display();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                dlList.display();
                break;

            case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne dodatkowe case'y
                break;
        }

    } while (option != '0');
}

MaxHeap maxHeap;
void menu_heap()
{
    char option;
    string fileName;

    do{
        displayMenu("--- KOPIEC ---");
        cin >> option;
        cout << endl;
        switch (option){
            case '1':
                cout << " Podaj nazwę pliku:";
                cin >> fileName;
                maxHeap.loadFromFile(fileName);
                maxHeap.displayTable();
                break;

            case '2':
                int index;
                cout << " podaj indeks";
                cin >> index;
                maxHeap.deleteByIndex(index);
                maxHeap.displayHeap();
                break;

            case '3':
                int value;
                cout << " podaj wartość:";
                cin >> value;

                maxHeap.add(value);
                maxHeap.displayTable();
                maxHeap.displayHeap();
                break;

            case '4':
                int val;
                cout << " podaj wartość:";
                cin >> val;
                
                if (maxHeap.search(val)) {
                    cout << "Wartość znajduje się w kopcu\n";
                } else {
                    cout << "Wartość nie znajduje się w kopcu\n";
                }
                
                break;

            case '5':  //tutaj generowanie w liscie
                int howMany;
                cout << "Podaj ilosc elementów w kopcu:";
                cin >> howMany;
                maxHeap.generateHeap(howMany);
                maxHeap.displayHeap();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                maxHeap.displayHeap();
                maxHeap.displayTree();
                break;

            case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne dodatkowe case'y
                break;
            case '8':
                //test
                MaxHeap mh;
                mh.setLength(9);
                mh.add(7);
                mh.add(5);
                mh.add(9);
                mh.add(6);
                mh.add(7);
                mh.add(8);
                mh.add(10);
                mh.add(1);
                mh.add(11);
                mh.displayHeap();

                mh.deleteByIndex(4);

                mh.displayHeap();
                
                
                break;
        }

    } while (option != '0');
}

BST bst;
void menu_bst()
{
    char option;
    string fileName;
    int value;
    do{
        displayMenu("--- BST ---");
        cin >> option;
        cout << endl;
        switch (option) {
            case '1':
                cout << " Podaj nazwę pliku:";
                cin >> fileName;
                bst.loadFromFile(fileName);
                break;

            case '2':
                
                cout << " podaj wartość do usunięcia";
                cin >> value;
                bst.deleteValue(bst.getRoot(), value);
                break;

            case '3':
                cout << " podaj wartość do dodania";
                cin >> value;

                bst.insert(value);
                bst.displayTree();
                break;

            case '4':
                int val;
                cout << " podaj wartość do znalezienia";
                cin >> val;
                
                if (bst.search(bst.getRoot(), val)) {
                    cout << "Wartość znajduje się w kopcu\n";
                } else {
                    cout << "Wartość nie znajduje się w kopcu\n";
                }
                break;

            case '5':  //tutaj generowanie w liscie
                int howMany;
                cout << "Podaj ilosc elementów w kopcu do wygenerowania";
                cin >> howMany;
                bst.generateBST(howMany);
                bst.displayTree();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                bst.displayTree();
                break;

            case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne dodatkowe case'y
                break;
            case '8':
                
                bst.loadFromFile("/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo-projekt/pliki/bst1.txt");
                bst.deleteValue(bst.getRoot(), 12);
                bst.deleteValue(bst.getRoot(), 18);
                bst.displayTree();
                cout << "__________________________________________\n";
                bst.DSW();
                bst.displayTree();
                break;
        }

    } while (option != '0');
}

#include <chrono>
#include <fstream>
#include <random>
int generateValue(int zakres) {
    std::random_device randDev;
    std::mt19937 rng(randDev());
    std::uniform_int_distribution<> distr(0, zakres);
    return distr(rng);
}

void writeCsvFile(const std::string &filename, const std::string &operation, int n, int k, double time) {
    std::ofstream file(filename, std::ios_base::app);
    if (!file) { //
        std::cerr << "nie ma pliku" << filename << std::endl;
        return;
    }


    

    // Write data to file
    file << operation << "," << n << "," << k << "," << time << std::endl;
}


int n_tab[] = {1000, 5000, 8000, 12000, 16000,24000,35000,50000};
//int n_tab[] = {5000};
string tab_pomiary_path = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo-projekt/pomiary/tablica_pomiary.csv";
string list_pomiary_path = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo-projekt/pomiary/list_pomiary.csv";
string kopiec_pomiary_path = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo-projekt/pomiary/kopiec_pomiary.csv";
string bst_pomiary_path = "/Users/sergiusz/Documents/studia/CzwartySemestr/SDIZO/sdizo-projekt/pomiary/bst_pomiary.csv";
const int ile_prob = 20;
void test_table() {
    ofstream outputFile("table_data.csv", ios::out | ios::app);
    outputFile << "operation,n,k,time" << std::endl;
    
    
    for(int i = 0; i < sizeof(n_tab)/sizeof(n_tab[0]); i++) {
        
        
        int n = n_tab[i];
        int k = n/10;
        
  
        //operacje
        //add na początek
        for (int i = 0; i < ile_prob; i++) {
            Table tab;
            tab.generateTable(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                tab.add(0, generateValue(100));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(tab_pomiary_path, "add na początek", n, k, duration);
        }

        //operacje
        //add na losowe miejsce
        for (int i = 0; i < ile_prob; i++) {
            Table tab;
            tab.generateTable(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                tab.add(generateValue(sizeof(n_tab)/sizeof(n_tab[0])), generateValue(100));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(tab_pomiary_path, "add na losowe", n, k, duration);
        }
        //operacje
        //add koniec
        for (int i = 0; i < ile_prob; i++) {
            Table tab;
            tab.generateTable(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                tab.add(sizeof(n_tab)/sizeof(n_tab[0]), generateValue(100));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(tab_pomiary_path, "add na koniec", n, k, duration);
        }
        
        //operacje
        //delete poczatek
        for (int i = 0; i < ile_prob; i++) {
            Table tab;
            tab.generateTable(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                tab.deleteByIndex(0);
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(tab_pomiary_path, "delete poczatek", n, k, duration);
        }
        //operacje
        //delete środek
        for (int i = 0; i < ile_prob; i++) {
            Table tab;
            tab.generateTable(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                tab.deleteByIndex(generateValue(sizeof(n_tab)/sizeof(n_tab[0])));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(tab_pomiary_path, "delete losowe", n, k, duration);
        }
        //operacje
        //delete koniec
        for (int i = 0; i < ile_prob; i++) {
            Table tab;
            tab.generateTable(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                tab.deleteByIndex(sizeof(n_tab)/sizeof(n_tab[0]));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(tab_pomiary_path, "delete koniec", n, k, duration);
        }
        //wyszukiwanie
        for (int i = 0; i < ile_prob; i++) {
            Table tab;
            tab.generateTable(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                tab.isContainingValue(generateValue(1000));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(tab_pomiary_path, "wyszukiwanie", n, k, duration);
        }
    }
    
       


    outputFile.close();
}
void test_list() {
    
    ofstream outputFile("list_data.csv", ios::out | ios::app);
    outputFile << "operation,n,k,time" << std::endl;
    
    
    for(int i = 0; i < sizeof(n_tab)/sizeof(n_tab[0]); i++) {
        
        int n = n_tab[i];
        int k = n/10;
        
  
        //operacje
        //add na początek
        for (int i = 0; i < ile_prob; i++) {
            DoublyLinkedList list;
            list.generateList(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                list.add(0, generateValue(100));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(list_pomiary_path, "add na początek", n, k, duration);
        }

        //operacje
        //add na losowe miejsce
        for (int i = 0; i < ile_prob; i++) {
            DoublyLinkedList list;
            list.generateList(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                list.add(generateValue(sizeof(n_tab)/sizeof(n_tab[0])), generateValue(100));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(list_pomiary_path, "add na losowe", n, k, duration);
        }
        //operacje
        //add koniec
        for (int i = 0; i < ile_prob; i++) {
            DoublyLinkedList list;
            list.generateList(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                list.add(sizeof(n_tab)/sizeof(n_tab[0]), generateValue(100));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(list_pomiary_path, "add na koniec", n, k, duration);
        }
        
        //operacje
        //delete poczatek
        for (int i = 0; i < ile_prob; i++) {
            DoublyLinkedList list;
            list.generateList(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                list.deleteByIndex(0);
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(list_pomiary_path, "delete poczatek", n, k, duration);
        }

        //operacje
        //delete na losowe miejsce
        for (int i = 0; i < ile_prob; i++) {
            DoublyLinkedList list;
            list.generateList(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                list.deleteByIndex(generateValue(list.getSize()));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(list_pomiary_path, "delete na losowe", n, k, duration);
        }
        //operacje
        //add koniec
        for (int i = 0; i < ile_prob; i++) {
            DoublyLinkedList list;
            list.generateList(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                list.deleteByIndex(list.getSize());
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(list_pomiary_path, "delete koniec", n, k, duration);
        }
        //wyszukiwanie
        for (int i = 0; i < ile_prob; i++) {
            DoublyLinkedList list;
            list.generateList(n);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                list.isContainingValue(generateValue(1000));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(list_pomiary_path, "wyszukiwanie", n, k, duration);
        }
    }
    outputFile.close();
}

void test_heap() {
    
    ofstream outputFile("kopiec_pomiary.csv", ios::out | ios::app);
    outputFile << "operation,n,k,time" << std::endl;
    
    
    for(int i = 0; i < sizeof(n_tab)/sizeof(n_tab[0]); i++) {
        
        int n = n_tab[i];
        int k = n/10;
        
  
        //operacje
        //add
        for (int i = 0; i < ile_prob; i++) {
            MaxHeap maxHeap;
            maxHeap.setLength(n);
            maxHeap.generateHeap(n);
            maxHeap.setLength(n*1.4);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                maxHeap.add(generateValue(100));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(kopiec_pomiary_path, "dodanie do kopca", n, k, duration);
        }
        //delete
        for (int i = 0; i < ile_prob; i++) {
            MaxHeap maxHeap;
            maxHeap.setLength(n);
            maxHeap.generateHeap(n);
            maxHeap.setLength(n*1.4);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                maxHeap.deleteByIndex(0);            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(kopiec_pomiary_path, "usunięcie z kopca", n, k, duration);
        }
        
        //search
        for (int i = 0; i < ile_prob; i++) {
            MaxHeap maxHeap;
            maxHeap.setLength(n);
            maxHeap.generateHeap(n);
            maxHeap.setLength(n*1.4);
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                maxHeap.search(generateValue(1000));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(kopiec_pomiary_path, "przeszukiwanie kopca", n, k, duration);
        }
        
        
    }
    outputFile.close();
}

void test_bst() {
    
    ofstream outputFile("bst_pomiary.csv", ios::out | ios::app);
    outputFile << "operation,n,k,time" << std::endl;
    
    
    for(int i = 0; i < sizeof(n_tab)/sizeof(n_tab[0]); i++) {
        
        int n = n_tab[i];
        int k = n/10;
        
  
        //operacje
        //add
        for (int i = 0; i < ile_prob; i++) {
            BST bst;
            bst.generateBST(n);
            bst.DSW();
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                bst.insert(generateValue(100));
                bst.DSW();
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(bst_pomiary_path, "dodanie do bst z równoważeniem", n, k, duration);
        }
        //delete
        for (int i = 0; i < ile_prob; i++) {
            BST bst;
            bst.generateBST(n);
            bst.DSW();
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                bst.deleteValue(bst.getRoot(), bst.getRoot()->value);
                bst.DSW();
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(bst_pomiary_path, "usuwanie korzenia z równoważeniem", n, k, duration);
        }
        
        //search
        for (int i = 0; i < ile_prob; i++) {
            BST bst;
            bst.generateBST(n);
            bst.DSW();
            auto start = chrono::high_resolution_clock::now();
            for(int i = 0; i < k; i++) {
                bst.search(bst.getRoot(), generateValue(1000));
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration<double>(end - start).count();
            writeCsvFile(bst_pomiary_path, "przeszukiwanie bst", n, k, duration);
        }
        
        
    }
    outputFile.close();
}

int main(int argc, const char * argv[]) {
    char option;
    do {
            cout << endl;
            cout << "==== MENU GLOWNE ===" << endl;
            cout << "1.Tablica" << endl;
            cout << "2.Lista" << endl;
            cout << "3.Kopiec" << endl;
            cout << "4.BST" << endl;
            cout << "5.AVL" << endl;
            cout << "0.Wyjscie" << endl;
            cout << "Podaj opcje:";
            cin >> option;
            cout << endl;

            switch (option){
                case '1':
                    menu_table();
                    break;

                case '2':
                    menu_list();
                    break;

                case '3':
                    menu_heap();
                    break;
                case '4':
                    menu_bst();
                    break;
                    
                case 'T':
                    test_table();
                    test_list();
                    test_heap();
                    test_bst();
                    break;
            }

        } while (option != '0');
    
    return 0;
}
