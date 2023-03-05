#include "algorytm.h"
#include<iostream>
#include<set>
#include<fstream>
#include<string>
using namespace std;

bool ok=false;
string kom="Ta tablica nie ma rozwiązania";
bool znajdz_zero(int tablica[9][9]){
for(int n=0;n<9;n++){
    for(int m=0;m<9;m++){
        if(tablica[n][m]==0)
        {
            return true;
        }
    }
}
return false;
}

int suma_pion(int cyfra,int table[9][9]){
int suma=0;
for(int n=0;n<9;n++) suma+=table[n][cyfra];
return suma;
}

int suma_poz(int grid,int table[9][9]){
int suma=0;
for(int n=0;n<9;n++) suma+=table[grid][n];
return suma;
}

void mozliwe(int i, int j, int tablica[9][9], int table[9][9],int pomoc){
set<int>rozwiazania;
if(tablica[i][j]==0)
{
    for(int k=1;k<10;k++) rozwiazania.insert(k);


    for(int n=0;n<9;n++)                                //petla analizujaca i-ty wiersz i j-kolumnę
    {
        rozwiazania.erase(tablica[i][n]);               //usuniecie ze zbioru elementow i-tego wiersza
        rozwiazania.erase(tablica[n][j]);               //usuniecie ze zbioru elementow j-tej kolumny
    }

    int x=i-i%3;
    int xo=x+3;
    for(x;x<xo;x++)                                 //petla alanizujaca odpowiednia sekcje (kwadrat 3x3)
    {
           int y=j-j%3;
           int yo=y+3;
           for(y;y<yo;y++)
           {
               rozwiazania.erase(tablica[x][y]);
           }
    }



       for( int p=1;p<10;p++)
       {
        if(rozwiazania.count(p)==1){
                table[pomoc][p-1]=1;

        }
       else ;
       }
}
else for( int p=1;p<10;p++) ;
}

void pomocnicza_w(int i,int tablica[9][9],int table[9][9]){

    int pomoc=0;
    for(int j=0;j<9;j++)
    {
        mozliwe(i,j,tablica,table,pomoc);
        pomoc++;
    }
for(int n=0;n<9;n++){
    if(suma_poz(n,table)==1)
    {

        for(int m=0;m<9;m++){
            if(table[n][m]==1) tablica[i][n]=m+1;
        }
    }
}

for(int n=0;n<9;n++){
    if(suma_pion(n,table)==1)
    {

        for(int m=0;m<9;m++){
                if(table[m][n]==1) tablica[i][m]=n+1;

        }
    }
}

}

void pomocnicza_k(int j,int tablica[9][9],int table[9][9]){

    int pomoc=0;
    for(int i=0;i<9;i++)
    {
        mozliwe(i,j,tablica,table,pomoc);
        pomoc++;
    }
    for(int n=0;n<9;n++){
    if(suma_poz(n,table)==1)
    {

        for(int m=0;m<9;m++){
            if(table[n][m]==1) tablica[n][j]=m+1;
        }
    }
}

for(int n=0;n<9;n++){
    if(suma_pion(n,table)==1)
    {

        for(int m=0;m<9;m++){
                if(table[m][n]==1) tablica[m][j]=n+1;

        }
    }
}

}

void pomocnicza_sekcja_komorki( int sekcja[2], int tablica[9][9],int table[9][9]){

    int pomoc=0;
    int i=sekcja[0];
    int x=i-i%3;
    int xo=x+3;
    for(x;x<xo;x++)
       {
           int j=sekcja[1];

           int y=j-j%3;
           int yo=y+3;
           for(y;y<yo;y++)
           {

               mozliwe(x,y,tablica,table,pomoc);
               pomoc++;
           }
       }


for(int n=0;n<9;n++){                   //sprawdzam, czy w n kolumnie jest rozwiazanie typu JEDYNA
    if(suma_pion(n,table)==1)
    {
    int i=sekcja[0];
    int x=i-i%3;
    int xo=x+3;
    int l=0;
    for(x;x<xo;x++)
       {
           int j=sekcja[1];

           int y=j-j%3;
           int yo=y+3;
           for(y;y<yo;y++)
           {
                if(table[l][n]==1)
                {

                    tablica[x][y]=n+1;
                }
                l++;
           }
       }
    }
}


}


bool sprawdz_sudoku(int tablica[9][9]){
for(int i=0;i<9;i++){
    set<int>wiersz;
    for(int j=0;j<9;j++){
        if(wiersz.count(tablica[i][j])==1)
            {
                return false;
            }
        else wiersz.insert(tablica[i][j]);
                    if(wiersz.count(0)==1) {
                    return false;
                    }
    }

}

for(int i=0;i<9;i++){
    set<int>kolumna;
    for(int j=0;j<9;j++){
        if(kolumna.count(tablica[j][i])==1)
        {

            return false;
        }

        else kolumna.insert(tablica[j][i]);
                    if(kolumna.count(0)==1) {

                    return false;
                    }
    }
}


for(int i=0;i<1;i++){
    for(int j=0;j<9;j++){
    set<int>sekcja;
        int x=i-i%3;
        int xo=x+3;
        for(x;x<xo;x++)                                 //petla alanizujaca odpowiednia sekcje (kwadrat 3x3)
        {
           int y=j-j%3;
           int yo=y+3;
           for(y;y<yo;y++)
            {
                if(sekcja.count(tablica[x][y])==1)
                {
                    return false;
                }

                else sekcja.insert(tablica[x][y]);
                    if(sekcja.count(0)==1) {
                    return false;
                    }
        }

    }
}
}

for(int i=0;i<9;i++)
{
    for(int j=0;j<9;j++)
    {
        if(tablica[i][j]>9) return false;
        if(tablica[i][j]<1) return false;
    }
}

return true;
}

bool rozwiazywanie_probne(int tab[9][9]){

bool niejednoznaczna=false;


int sekcja1[2]={0,0};
int sekcja2[2]={0,3};
int sekcja3[2]={0,6};
int sekcja4[2]={3,0};
int sekcja5[2]={3,3};
int sekcja6[2]={3,6};
int sekcja7[2]={6,0};
int sekcja8[2]={6,3};
int sekcja9[2]={6,6};
int z=0;
while(z<100){
        z++;
for(int n=0;n<9;n++){
    int table[9][9];
    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
}
    pomocnicza_w(n,tab,table);
}
for(int n=0;n<9;n++){
    int table[9][9];
    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
}
    pomocnicza_k(n,tab,table);
}

int table[9][9];
    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
    }
pomocnicza_sekcja_komorki(sekcja1,tab,table);

    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
    }
pomocnicza_sekcja_komorki(sekcja2,tab,table);

    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
    }
pomocnicza_sekcja_komorki(sekcja3,tab,table);


    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
    }
pomocnicza_sekcja_komorki(sekcja4,tab,table);


    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
    }
pomocnicza_sekcja_komorki(sekcja5,tab,table);


    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
    }
pomocnicza_sekcja_komorki(sekcja6,tab,table);


    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
    }
pomocnicza_sekcja_komorki(sekcja7,tab,table);


    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
    }
pomocnicza_sekcja_komorki(sekcja8,tab,table);


    for(int i=0;i<9;i++){

    for(int j=0;j<9;j++)
    {
        table[i][j]=0;
    }
    }
pomocnicza_sekcja_komorki(sekcja9,tab,table);

}

if(!znajdz_zero(tab));
else{
    for(int n=0;n<9;n++){
        for(int m=0;m<9;m++){
            if(tab[n][m]==0)
            {
                int table[9][9];
                for(int i=0;i<9;i++){
                for(int j=0;j<9;j++)
                    {
                table[i][j]=0;
                }
                }
            mozliwe(n,m,tab,table,0);
            int tmp=0;
            int w=0;
            while(tmp==0){
                w++;
                tmp=table[0][w-1];
            }
            tab[n][m]=w;
            rozwiazywanie_probne(tab);

            }
            }
        }
niejednoznaczna=true;
}


if(sprawdz_sudoku(tab)) {
    ok=true;
    if(niejednoznaczna)     kom="Ta tablica więcej niż jedno rozwiązanie";
    else     kom="Ta tablica ma tylko jedno rozwiązanie";
}
else{
ok=false;
kom="Ta tablica nie ma rozwiązań";
}

return niejednoznaczna;
}

algorytm::algorytm(int tablica[9][9],bool niejednoznaczna)
{
rozwiazywanie_probne(tablica);
}

bool algorytm::OK(){
return ok;
}


string algorytm::komunikat(){
    return kom;

}


