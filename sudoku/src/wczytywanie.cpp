#include "wczytywanie.h"
#include<fstream>
#include<string>
using namespace std;

wczytywanie::wczytywanie(string nazwa_pliku, int tablica[9][9])
{
ifstream f(nazwa_pliku);
    string kropka=".";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            string tmp;
            f>>tmp;
            if (tmp==kropka){
                tablica[i][j]=0;
            }
            else{
                tablica[i][j]=stoi(tmp);
            }
        }
    }
}

