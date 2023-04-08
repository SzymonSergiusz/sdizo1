#include <iostream>
#include "Table.hpp"
#include "DoublyLinkedList.hpp"
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

int main(int argc, const char * argv[]) {
    char option;
    do {
            cout << endl;
            cout << "==== MENU GLOWNE ===" << endl;
            cout << "1.Tablica" << endl;
            cout << "2.Lista" << endl;
            cout << "3.Kopiec" << endl;
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
//                    menu_heap();
                    break;
            }

        } while (option != '0');

    
    
    return 0;
}
