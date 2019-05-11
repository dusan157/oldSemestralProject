#include "IS.h"

int main()
{
	initHeapMonitor();
	IS *is = new IS();
	is->nacitanie();
	is->vypisMenu();
	char volba;
	cin >> volba;
	while (volba!='x') {
		switch (volba) {
		case 'a': {
			cout << "vyberte mnozinu 1 = obce; 2 = okresy; 3 = kraje" << endl;
			int mnozina;
			cin >> mnozina;
			is->vypisInfoNazov(mnozina);
		}
				  break;
		case 'b': {
			cout << "vyberte mnozinu 1 = obce; 2 = okresy; 3 = kraje" << endl;
			int mnozina;
			cin >> mnozina;
			cout << "Zadajte kolo [1/2]" << endl;
			int kolo;
			cin >> kolo;
			is->vypisInfoVolici(mnozina, kolo);
		}
				  break;
		case 'c': {
			cout << "vyberte mnozinu 1 = obce; 2 = okresy; 3 = kraje" << endl;
			int mnozina;
			cin >> mnozina;
			cout << "Zadajte kolo.[1/2]" << endl;
			int kolo;
			cin >> kolo;
			is->vypisInfoUcast(mnozina, kolo);
		}
				  break;
		case 'd': {
			int usporiadanie;
			cout << "Zadajte usporiadanie 0 - vzostupne 1 - zostupne" << endl;
			cin >> usporiadanie;
			is->vypisUtriedeneNazov(usporiadanie);
		}
				  break;
		case 'e': {
			cout << "Zadajte kolo.[1/2]" << endl;
			int kolo;
			cin >> kolo;
			int usporiadanie;
			cout << "Zadajte usporiadanie 0 - vzostupne 1 - zostupne" << endl;
			cin >> usporiadanie;
			is->vypisUtriedeneVolici(kolo,usporiadanie);
		}
				  break;
		case 'f': {
			cout << "Zadajte kolo.[1/2]" << endl;
			int kolo;
			cin >> kolo;
			int usporiadanie;
			cout << "Zadajte usporiadanie 0 - vzostupne 1 - zostupne" << endl;
			cin >> usporiadanie;
			is->vypisUtriedeneUcast(kolo,usporiadanie);
		}
				  break;
		case 'g': {
			int usporiadanie;
			cout << "Zadajte usporiadanie 0 - vzostupne 1 - zostupne" << endl;
			cin >> usporiadanie;
			cout << "Zadajte kraj/okres pre filtrovanie" << endl;
			string oblast;
			cin.ignore();
			getline(cin, oblast);
			cout << "Zadajte kolo.[1/2]" << endl;
			int kolo;
			cin >> kolo;
			is->vypisUtriedeneFiltrovaneNazov(usporiadanie, oblast, kolo);

		}
				  break;
		case 'h': {
			int usporiadanie;
			cout << "Zadajte usporiadanie 0 - vzostupne 1 - zostupne" << endl;
			cin >> usporiadanie;
			cout << "Zadajte kraj/okres pre filtrovanie" << endl;
			string oblast;
			cin.ignore();
			getline(cin, oblast);
			cout << "Zadajte kolo.[1/2]" << endl;
			int kolo;
			cin >> kolo;
			is->vypisUtriedeneFiltrovaneVolici(usporiadanie, oblast, kolo);

		}
				  break;
		case 'i': {
			int usporiadanie;
			cout << "Zadajte usporiadanie 0 - vzostupne 1 - zostupne" << endl;
			cin >> usporiadanie;
			cout << "Zadajte kraj/okres pre filtrovanie" << endl;
			string oblast;
			cin.ignore();
			getline(cin, oblast);
			cout << "Zadajte kolo.[1/2]" << endl;
			int kolo;
			cin >> kolo;
			is->vypisUtriedeneFiltrovaneUcast(usporiadanie, oblast, kolo);

		}
				  break;
		case 'j': {
			cout << "vyberte mnozinu 1 = obce; 2 = okresy; 3 = kraje" << endl;
			int mnozina;
			cin >> mnozina;
			is->vypisKandidatovUzemnaJednotka(mnozina);
		}
				  break;
		case 'm': {
			is->vypisMenu();
		}
				  break;
		}
		cin >> volba;
	}
		delete is;

	}