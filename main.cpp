#include <iostream>
#include <iomanip>
#include <math.h>
#include <conio.h>

using namespace std;

bool sprawdzPoprawnoscWprowadzonegoZnaku(char znak);
bool sprawdzPoprawnoscWprowadzonegoZnakuDlaKapitalizacji(char znak);

int main() {
    float pozadanaMiesiecznaEmerytura;
    float oprocentowanieLokaty;
    float podatek = 0.19;

    int wiekObecny;
    int wiekPrzejsciaNaEmeryture;
    char kapitalizacja;
    int kapitalizacjaInt;
    char wyjscieZprogramu;
    string czestotliwoscOdkladania;

    do {
        cout << "Ile masz obecnie lat?: ";
        cin >> wiekObecny;

        cout << "W jakim wieku chcesz przejsc na emeryture?: ";
        cin >> wiekPrzejsciaNaEmeryture;

        cout << "W jakiej wysokosci chcialbys miec dodatek do emerytury?: ";
        cin >> pozadanaMiesiecznaEmerytura;

        cout << "Podaj oprocentowanie lokaty (w procentach): ";
        cin >> oprocentowanieLokaty;

        cout << "Podaj kapitalizacje (c - codzienna; m - miesieczna; r - roczna): ";
        cin >> kapitalizacja;
        while (sprawdzPoprawnoscWprowadzonegoZnakuDlaKapitalizacji(kapitalizacja) != true) {
            cout << "Wcisnij klawisz 'c', 'm' lub 'r': ";
            cin >> kapitalizacja;
        }

        switch (kapitalizacja) {
        case 'c':
            kapitalizacjaInt = 365;
            czestotliwoscOdkladania = "codziennie";
            break;
        case 'm':
            kapitalizacjaInt = 12;
            czestotliwoscOdkladania = "miesiecznie";
            break;
        case 'r':
            kapitalizacjaInt = 1;
            czestotliwoscOdkladania = "rocznie";
            break;
        }

        int lataPracy = wiekPrzejsciaNaEmeryture - wiekObecny;
        oprocentowanieLokaty = oprocentowanieLokaty / 100;

        float odsetkiWskaliRoku = 12 * pozadanaMiesiecznaEmerytura / (1 - podatek);

        float uzbieranaKwota = odsetkiWskaliRoku / oprocentowanieLokaty;

        float licznik = uzbieranaKwota * (oprocentowanieLokaty / kapitalizacjaInt) * (1 - podatek);
        float liczbaPotegowana = (1 + (oprocentowanieLokaty / kapitalizacjaInt) * (1 - podatek));
        int wykladnik = lataPracy*kapitalizacjaInt;
        float mianownik = liczbaPotegowana*(pow(liczbaPotegowana, wykladnik) - 1);

        float skladka = licznik / mianownik;

        cout << endl << "Aby po " << lataPracy << " latach pracy, odkladane na lokate oprocentowana na " << (oprocentowanieLokaty*100) << " procent " << endl;
        cout << "miec miesieczny dodatek do emerytury w wysokosci " << pozadanaMiesiecznaEmerytura << " zl wyplacanych wylacznie z odsetek " << endl;
        cout << fixed << setprecision(2);
        cout << "nalezy " << czestotliwoscOdkladania << " odkladac " << skladka << " zl" << endl;
        cout << "To pozwoli Ci uzbierac kwote w wysokosci: " << uzbieranaKwota << " zl" << endl;

        cout << endl << "Czy chcesz wykonac nastepna kalkulacje? (t/n): ";
        cin >> wyjscieZprogramu;

        while (sprawdzPoprawnoscWprowadzonegoZnaku(wyjscieZprogramu) != true) {
            cout << "Wcisnij klawisz 't' lub 'n': ";
            cin >> wyjscieZprogramu;
        }

    } while (wyjscieZprogramu != 'n');

    cout << endl << "Wcisnij dowolny klawisz, aby zamknac program...";
    getch();

    return 0;
}

bool sprawdzPoprawnoscWprowadzonegoZnaku(char znak) {
    if (znak == 'n' || znak == 't')
        return true;
    else return false;
}

bool sprawdzPoprawnoscWprowadzonegoZnakuDlaKapitalizacji(char znak) {
    if (znak == 'c' || znak == 'm' || znak == 'r')
        return true;
    else return false;
}
