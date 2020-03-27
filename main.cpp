#include <sstream>
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class zmiana{
       ifstream plik1;
       ofstream plik2;
       string orginal[1000];
       string sort[1000];

  public:
        zmiana();
        ~zmiana();
       
        void wczytaj();     
		string stringSort(string s);  
};

zmiana::zmiana(){ 
    plik1.open("c:\\palindromy.txt");
    plik2.open("c:\\wynikJSON.txt");
}

void zmiana::wczytaj(){
	
	string napis;
	int index;
	int i=0;
	
	plik2<<"[";
	
	while(!plik1.eof()){ 
        plik1>>napis;
        
        orginal[i]=napis;
		sort[i]=stringSort(napis);
		i++;
	}
	
	for(int j=0;j<i;j++){
		if(sort[j]==sort[j+1]){
			plik2<<"{\"slowo"<<"\":\""<<orginal[j]<<"\",\"anagram\":\""<<orginal[j+1]<<"\"},";
		}
	}
	
	plik2<<"]";

}

string zmiana::stringSort(string s){
	
	int t[256]; //dane wejsciowe
	string wynik;
	
	//przypisanie kazdej komurce wartosci
	for (int i=0; i<=256; i++)
        t[i]=0;

    //zapelnienie tablicy t[i] danymi
    for (int i=0; i<=s.length()-1; i++)
    {
        t[i]=(int)s[i];
    }

    int l[256]; //licznik

    //zerowanie tablicy
    for (int i=0; i<=255; i++)
        l[i]=0;

    //podliczenie wynikow
    for (int i=0; i<=255; i++){
    	l[t[i]]++;

	}

    //przypisanie uporzadkowanych wynikow
    for (int i=0; i<=255; i++)
    {
        if (l[i]>0)
           for (int j=1; j<=l[i]; j++)
           		if(i>0)
               		wynik+=(char)i;
            }
	
	
	return wynik;
	
}

zmiana::~zmiana(){
    plik1.close();
    plik2.close();
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	zmiana change; 
    change.wczytaj(); 
    
    return 0;
	
	return 0;
}
