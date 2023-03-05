#include "zapisywanie.h"
#include<fstream>
#include<string>
using namespace std;

zapisywanie::zapisywanie(string nazwa_pliku, int tablica[9][9])
{
    ofstream plik(nazwa_pliku);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            plik<<tablica[i][j]<<" ";
        }
        plik<<endl;
    }
}
