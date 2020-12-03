#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


string odwroc_str(string str)
{     //odwraca string od tylu zapisujac go od tyłu
    string odwr_str = "";       
    for (int i=0; i<str.length(); i++) //tyle razy, ile długość stringu 
    {
        odwr_str = str[i] + odwr_str; //doklejamy znaki ale na początku 81 -> 18 im bardziej cyfra z tyłu liczby tym później doklejona
    }
    return odwr_str;
}


int odwroc_liczbe(int liczba)
{
    int wynik;
    string liczba_str = to_string(liczba), //zamien liczbe na string
           liczba_odwr_str = "";
           
    liczba_odwr_str = odwroc_str(liczba_str); //odwroc string
    
    wynik = (int) strtol(liczba_odwr_str.c_str(), NULL, 10); //zamienc odwrocony string na liczbe
    return wynik; //zwroc odwrocona liczbe
}

bool sprawdz_czy_palindrom(string str)
{ 
    //w petli wczytaj string do połowy i sprawdz str[0] == str[str.length()-1]   czy pierwsza jest == ostatnia
    for (int i=0; i<str.length()/2; i++)
       if (str[i] != str[str.length()-1-i]) //[0]!=[str.length()-1]  ostatnia,  [1]!=[str.length()-2] przedostatnia
          return false;
          
    return true;
}

bool zadanie59_2(int liczba)
//sprawdza czy suma liczby+odwr jest palindromem
{ 
    string wynik_str = to_string( liczba+odwroc_liczbe(liczba) );
    return sprawdz_czy_palindrom(wynik_str); 
}


int main(int argc, char** argv) {
    //cout << odwroc_liczbe(81);
    cout << zadanie59_2(19);
    return 0;
}
