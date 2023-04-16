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
                bst.DSW();
                bst.displayTree();
                break;
        }

    } while (option != '0');
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
            }

        } while (option != '0');
    
    return 0;
}
