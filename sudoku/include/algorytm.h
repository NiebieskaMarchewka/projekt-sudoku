#ifndef ALGORYTM_H
#define ALGORYTM_H
#include<iostream>
#include<set>
#include<fstream>
#include<string>

using namespace std;




class algorytm
{
    public:
        int tablica[9][9];
        bool niejednoznaczna=false;
        string komunikat();
        bool OK();
        algorytm(int tablica[9][9],bool niejednoznaczna=false);

};

#endif // ALGORYTM_H
