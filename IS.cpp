#include "IS.h"

IS::IS()
{
	kraje = new structures::SortedSequenceTable<int, Kraj*>;
	okresy = new structures::SortedSequenceTable<int, Okres*>;
	obce = new structures::SortedSequenceTable<int, Obec*>;
	neutriedObce = new structures::UnsortedSequenceTable<int, Obec*>;
}

IS::~IS()
{
	for (auto item : *obce) {
		delete item->accessData();
	}
	delete obce;
	for (auto item : *okresy) {
		delete item->accessData();
	}
	delete okresy;
	for (auto item : *kraje) {
		delete item->accessData();
	}
	delete kraje;
	delete neutriedObce;
}

void IS::nacitanie()
{
	std::ifstream citac;
	std::string riadok;
	Okres* okres;
	Obec *obec;
	Kraj *kraj;
	int i = 0;
	int kod;
	citac.open("kraje.csv");
	while (getline(citac, riadok, ',')) {
		kraj = new Kraj();
		kod = stoi(riadok); // kod obce
		i = 0;
		for (i = 0; i < 11; i++) {
			getline(citac, riadok, ','); //obec +data
			kraj->setData(i, riadok);
		}
		kraje->insert(kod, kraj);
	}
	citac.close();

	citac.open("okresy.csv");

	while (getline(citac, riadok, ',')) {
		kod = stoi(riadok); // kod kraju
		if (!kraje->tryFind(kod, kraj)) {
			kraj = new Kraj();
			getline(citac, riadok, ',');
			kraj->setData(0, riadok);
			kraje->insert(kod, kraj);
		}
		else {
			getline(citac, riadok, ',');
		}

		getline(citac, riadok, ',');
		kod = stoi(riadok); // kod okresu
		okres = new Okres();
		i = 0;
		for (i = 0; i < 11; i++) {
			getline(citac, riadok, ','); //obec +data
			okres->setData(i, riadok);
		}
		okresy->insert(kod, okres);
		kraj->insert(kod, okres);
		
	}
	citac.close();



	citac.open("obce.csv");
	while (getline(citac, riadok, ',')) {
		kod = stoi(riadok); // kod kraju
		if (!kraje->tryFind(kod, kraj)) {
			kraj = new Kraj();
			getline(citac, riadok, ',');
			kraj->setData(0, riadok);
			kraje->insert(kod, kraj);
		}
		else {
			getline(citac, riadok, ',');
		}
		getline(citac, riadok, ',');
		kod = stoi(riadok); // kod okresu

		if (!kraj->tryFind(kod, okres)) {
			okres = new Okres();
			getline(citac, riadok, ',');
			okres->setData(0, riadok);
			kraj->insert(kod, okres);
			okresy->insert(kod, okres);
		}
		else {
			getline(citac, riadok, ',');
		}

		obec = new Obec();
		getline(citac, riadok, ',');
		kod = stoi(riadok); // kod obce
		i = 0;
		for (i = 0; i < 11; i++) {
			getline(citac, riadok, ','); //obec +data
			obec->setData(i, riadok);
		}
		okres->insert(kod, obec);
		obce->insert(kod, obec);
		neutriedObce->insert(kod, obec);
	}
	for (auto kraj : *kraje) {
		kraj->accessData()->setOkresy();
		for (auto okres : *kraj->accessData()) {
			okres->accessData()->setObce();
		}
	}
	citac.close();

	citac.open("hlasyKraje1.csv");
	while (getline(citac, riadok, ',')) {
		int cKraj = stoi(riadok);
		kraje->tryFind(cKraj, kraj);
		getline(citac, riadok, ',');
		getline(citac, riadok, ',');
		string meno = riadok;
		//meno+=" "+riadok;
		getline(citac, riadok);
		kraj->setDataKandidati(meno, 0, stoi(riadok));
	}
	citac.close();

	citac.open("hlasyKraje2.csv");
	while (getline(citac, riadok, ',')) {
		int cKraj = stoi(riadok);
		kraje->tryFind(cKraj, kraj);
		getline(citac, riadok, ',');
		getline(citac, riadok, ',');
		string meno = riadok;
		//meno += " " + riadok;
		getline(citac, riadok);
		kraj->setDataKandidati(meno, 1, stoi(riadok));
	}
	citac.close();

	citac.open("hlasyOkresy1.csv");
	while (getline(citac, riadok, ',')) {
		int cOkres = stoi(riadok);
		okresy->tryFind(cOkres, okres);
		getline(citac, riadok, ',');
		getline(citac, riadok, ',');
		string meno = riadok;
		getline(citac, riadok);
		okres->setDataKandidati(meno, 0, stoi(riadok));
	}
	citac.close();

	citac.open("hlasyOkresy2.csv");
	while (getline(citac, riadok, ',')) {
		int cOkres = stoi(riadok);
		okresy->tryFind(cOkres, okres);
		getline(citac, riadok, ',');
		getline(citac, riadok, ',');
		string meno = riadok;
		getline(citac, riadok,',');
		okres->setDataKandidati(meno, 1, stoi(riadok));
		getline(citac, riadok); //dalo to tam ciarky
	}
	citac.close();

	citac.open("hlasyObce1.csv");
	while (getline(citac, riadok, ',')) {
		int cObec = stoi(riadok);
		obce->tryFind(cObec, obec);
		getline(citac, riadok, ',');
		getline(citac, riadok, ',');
		string meno = riadok;
		getline(citac, riadok);
		obec->setDataKandidati(meno, 0, stoi(riadok));
	}
	citac.close();

	citac.open("hlasyObce2.csv");
	while (getline(citac, riadok, ',')) {
		int cObec = stoi(riadok);
		obce->tryFind(cObec, obec);
		getline(citac, riadok, ',');
		getline(citac, riadok, ',');
		string meno = riadok;
		getline(citac, riadok, ',');
		obec->setDataKandidati(meno, 1, stoi(riadok));
		getline(citac, riadok); //dalo to tam ciarky
	}
	citac.close();


	riadok = "";
	obec = nullptr;
	delete obec;
	okres = nullptr;
	delete okres;
	kraj = nullptr;
	delete kraj;
}

void IS::vypisInfoNazov(int index)
{
	nastavKombinaciuFiltrov(1);
	switch (index) {
	case 1: {
		for (auto obec : *obce) {
			if (filt_Nazov.evaluate(*obec->accessData(), krit_Nazov)) {
				cout <<"Nazov kraja: " <<krit_Nazov.evaluate(*obec->accessData()->getKraj()) <<endl;
				cout << "Nazov okresu: " << krit_Nazov.evaluate(*obec->accessData()->getOkres()) << endl;
				cout << "Nazov obce:" << krit_Nazov.evaluate(*obec->accessData()) << endl;
				vypisData(obec->accessData());
			}
		}
	}
			break;
	case 2: {
		for (auto okres : *okresy) {	
			if (filt_Nazov.evaluate(*okres->accessData(), krit_Nazov)) {
				cout << "Nazov kraja: " << krit_Nazov.evaluate(*okres->accessData()->getKraj()) << endl;
				cout << "Nazov okresu: " << krit_Nazov.evaluate(*okres->accessData()) << endl;
				vypisData(okres->accessData());
			}
		}
	}
			break;
	case 3: {
		for (auto kraj : *kraje) {
			if (filt_Nazov.evaluate(*kraj->accessData(), krit_Nazov)) {
				cout << "Nazov kraj: " << krit_Nazov.evaluate(*kraj->accessData()) << endl;
				vypisData(kraj->accessData());
			}
		}
	}
			break;

	}
}

void IS::vypisInfoVolici(int index,int kolo)
{
	nastavKombinaciuFiltrov(2);
	krit_Volici.setKolo(kolo - 1);


	switch (index) {
	case 1: {
		for (auto obec : *obce) {
			if (filt_Volici.evaluate(*obec->accessData(), krit_Volici)) {
				cout << "Nazov kraja: " << krit_Nazov.evaluate(*obec->accessData()->getKraj()) << endl;
				cout << "Nazov okres: " << krit_Nazov.evaluate(*obec->accessData()->getOkres()) << endl;
				cout << "Nazov obce:" << krit_Nazov.evaluate(*obec->accessData()) << endl;
				vypisData(obec->accessData());
			}
		}
	}
			break;
	case 2: {
		for (auto okres : *okresy) {
			if (filt_Volici.evaluate(*okres->accessData(), krit_Volici)) {
				cout << "Nazov kraja: " << krit_Nazov.evaluate(*okres->accessData()->getKraj()) << endl;
				cout << "Nazov okres: " << krit_Nazov.evaluate(*okres->accessData()) << endl;
				vypisData(okres->accessData());
			}
		}
	}
			break;
	case 3: {
		for (auto kraj : *kraje) {
			if (filt_Volici.evaluate(*kraj->accessData(), krit_Volici)) {
				cout << "Nazov kraj: " << krit_Nazov.evaluate(*kraj->accessData()) << endl;
				vypisData(kraj->accessData());
			}
		}
	}
			break;

	}
}

void IS::vypisInfoUcast(int index, int kolo)
{
	nastavKombinaciuFiltrov(3);
	krit_Ucast.setKolo(kolo - 1);


	switch (index) {
	case 1: {
		for (auto obec : *obce) {
			if (filt_Ucast.evaluate(*obec->accessData(), krit_Ucast)) {
				cout << "Nazov kraja: " << krit_Nazov.evaluate(*obec->accessData()->getKraj()) << endl;
				cout << "Nazov okres: " << krit_Nazov.evaluate(*obec->accessData()->getOkres()) << endl;
				cout << "Nazov obce:" << krit_Nazov.evaluate(*obec->accessData()) << endl;
				//cout << obec->accessData()->getUcast(kolo-1) << endl;
				vypisData(obec->accessData());
			}
		}
	}
			break;
	case 2: {
		for (auto okres : *okresy) {
			if (filt_Ucast.evaluate(*okres->accessData(), krit_Ucast)) {
				cout << "Nazov kraja: " << krit_Nazov.evaluate(*okres->accessData()->getKraj()) << endl;
				cout << "Nazov okres: " << krit_Nazov.evaluate(*okres->accessData()) << endl;
				vypisData(okres->accessData());
			}
		}
	}
			break;
	case 3: {
		for (auto kraj : *kraje) {
			if (filt_Ucast.evaluate(*kraj->accessData(), krit_Ucast)) {
				cout << "Nazov kraj: " << krit_Nazov.evaluate(*kraj->accessData()) << endl;
				vypisData(kraj->accessData());
			}
		}
	}
			break;

	}
}

void IS::vypisUtriedeneNazov(int utriedenie)
{
	structures::HeapSort<int, Obec*> triedenie;
	KomparatorNazov komparator;
	komparator.setUsporiadanie(utriedenie);
	triedenie.sort(*neutriedObce, komparator);
	for (auto item : *neutriedObce) {
		cout << krit_Nazov.evaluate(*item->accessData()) << endl;
	}
}

void IS::vypisUtriedeneVolici(int kolo, int utriedenie)
{
	structures::HeapSort<int, Obec*> triedenie;
	KomparatorVolici komparator;
	komparator.setKolo(kolo-1);
	komparator.setUsporiadanie(utriedenie);
	krit_Volici.setKolo(kolo-1);
	triedenie.sort(*neutriedObce, komparator);
	for (auto item : *neutriedObce) {
		cout << krit_Nazov.evaluate(*item->accessData()) <<" "<< krit_Volici.evaluate(*item->accessData()) <<endl;
	}
}

void IS::vypisUtriedeneUcast(int kolo, int utriedenie)
{
	structures::HeapSort<int, Obec*> triedenie;
	KomparatorUcast komparator;
	komparator.setKolo(kolo - 1);
	komparator.setUsporiadanie(utriedenie);
	krit_Ucast.setKolo(kolo - 1);
	triedenie.sort(*neutriedObce, komparator);
	for (auto item : *neutriedObce) {
		cout << krit_Nazov.evaluate(*item->accessData()) << " " << krit_Ucast.evaluate(*item->accessData()) << endl;
	}
}

void IS::vypisUtriedeneFiltrovaneNazov(int utriedenie, string nazov,int kolo)
{
	krit_Prislusnost.setOblast(nazov);
	krit_Ucast.setKolo(kolo-1);
	nastavKombinaciuFiltrov(3);
	structures::HeapSort<int, Obec*> triedenie;
	KomparatorNazov komparator;
	komparator.setUsporiadanie(utriedenie);
	triedenie.sort(*neutriedObce, komparator);
	for (auto item : *neutriedObce) {
		if (krit_Prislusnost.evaluate(*item->accessData()) && filt_Ucast.evaluate(*item->accessData(), krit_Ucast)) {
			cout << krit_Nazov.evaluate(*item->accessData()) <<  endl;
		}
	}
}

void IS::vypisUtriedeneFiltrovaneVolici(int utriedenie, string nazov,int kolo)
{
	krit_Prislusnost.setOblast(nazov);
	krit_Ucast.setKolo(kolo - 1);
	krit_Volici.setKolo(kolo - 1);
	nastavKombinaciuFiltrov(3);
	structures::HeapSort<int, Obec*> triedenie;
	KomparatorVolici komparator;
	komparator.setKolo(kolo - 1);
	komparator.setUsporiadanie(utriedenie);
	triedenie.sort(*neutriedObce, komparator);
	for (auto item : *neutriedObce) {
		if (krit_Prislusnost.evaluate(*item->accessData()) && filt_Ucast.evaluate(*item->accessData(), krit_Ucast)) {
			cout << krit_Nazov.evaluate(*item->accessData()) << " " << krit_Volici.evaluate(*item->accessData()) << endl;
		}
	}
}

void IS::vypisUtriedeneFiltrovaneUcast(int utriedenie, string nazov, int kolo)
{
	krit_Prislusnost.setOblast(nazov);
	krit_Ucast.setKolo(kolo - 1);
	nastavKombinaciuFiltrov(3);
	structures::HeapSort<int, Obec*> triedenie;
	KomparatorUcast komparator;
	komparator.setKolo(kolo - 1);
	komparator.setUsporiadanie(utriedenie);
	triedenie.sort(*neutriedObce, komparator);
	for (auto *item : *neutriedObce) {
		if (krit_Prislusnost.evaluate(*item->accessData()) && filt_Ucast.evaluate(*item->accessData(), krit_Ucast)) {
			cout << krit_Nazov.evaluate(*item->accessData()) << " " << krit_Ucast.evaluate(*item->accessData()) << endl;
		}
	}
}

void IS::vypisMenu()
{
	cout << "-------------Menu-------------" << endl;
	cout << "a) Vypis informacii o obciach/okresoch/krajoch s filtrom nazov."<<endl;
	cout << "b) Vypis informacii o obciach/okresoch/krajoch s filtrom volici." << endl;
	cout << "c) Vypis informacii o obciach/okresoch/krajoch s filtrom ucast." << endl;

	cout << "d) Vypis vypis obci zoradenie podla nazvu." << endl;
	cout << "e) Vypis vypis obci zoradenie podla volicov." << endl;
	cout << "f) Vypis vypis obci zoradenie podla ucasti." << endl;

	cout << "g) Vypis vypis obci zoradenie podla nazvu s filtrom ucast a prislusnost." << endl;
	cout << "h) Vypis vypis obci zoradenie podla volicov s filtrom ucast a prislusnost." << endl;
	cout << "i) Vypis vypis obci zoradenie podla ucasti s filtrom ucast a prislusnost." << endl;
	cout << "j) Vysledky kandidata v uzemnej jednotke" << endl;
	cout << "m) Vypis menu" << endl;
	cout << "x) Ukoncit" << endl;

}

void IS::vypisKandidatovUzemnaJednotka(int volba)
{
	int i;
	cout << "Zadajte volbu pomocou volby:" << endl;
	cout << " 0 - Ziaden filter" << endl;
	cout << " 1 - Filter nazov \t 2 - Filter volici \t 3 -Filter ucast" << endl;
	cout << " 4 - Filter nazov a volici \t 5 - Filter nazov a ucast \t 6 - Filter volici a ucast" << endl;
	cout << " 7 - Filter nazov, volici a ucast" << endl;
	cin >> i;

	cout << "Zadajte kolo.[1/2]" << endl;
	int kolo;
	cin >> kolo;
	krit_ZiskaneHlasy.setKolo(kolo - 1);

	if (i != 0) {
		nastavKombinaciuFiltrov(i);
		cout << "Zadajte kolo.[1/2]" << endl;
		int kolo;
		cin >> kolo;
		krit_Ucast.setKolo(kolo - 1);
		krit_Volici.setKolo(kolo - 1);
	}
	string meno;
	int pom;
	bool kandidat = false;
	cout << "Chcete zadat filter pre meno kandidata? 1 ano 0 nie" << endl;
	cin >> pom;
	if (pom == 1) {
		cout << "Zadajte priezvisko/cast priezviska kandidata" << endl;
		cin >> meno;
		filt_Meno.setAlpha(meno);
		kandidat = true;
	}
	if(volba == 1){
		for (auto *oblast : *obce) {
			bool splna = false;
			if (i == 0) {
				splna = true;
			}
			if (i == 1 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov)) {
				splna = true;
			}
			if (i == 2 && filt_Volici.evaluate(*oblast->accessData(), krit_Volici)) {
				splna = true;
			}
			if (i == 3 && filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (i == 4 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov) && filt_Volici.evaluate(*oblast->accessData(), krit_Volici)) {
				splna = true;
			}
			if (i == 5 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov) && filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (i == 6 && filt_Volici.evaluate(*oblast->accessData(), krit_Volici) && filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (i == 7 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov) && filt_Volici.evaluate(*oblast->accessData(), krit_Volici)
				&& filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (splna) {
				cout << "Nazov: " << krit_Nazov.evaluate(*oblast->accessData()) << endl;
				for (auto *kandidat : *oblast->accessData()->getKandidati()) {
					if ((!kandidat)||(kandidat && krit_ZiskaneHlasy.evaluate(*kandidat->accessData()) != -1 && filt_Meno.evaluate(*kandidat->accessData(), krit_Meno))) {
						cout << "Kandidat: " << krit_Meno.evaluate(*kandidat->accessData()) 
							<< "\t Ziskane hlasy: " << krit_ZiskaneHlasy.evaluate(*kandidat->accessData()) << endl;
					}
				}
				vypisData(oblast->accessData());
			}
		}
	}
	if (volba == 2) {
		for (auto *oblast : *okresy) {
			bool splna = false;
			if (i == 0) {
				splna = true;
			}
			if (i == 1 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov)) {
				splna = true;
			}
			if (i == 2 && filt_Volici.evaluate(*oblast->accessData(), krit_Volici)) {
				splna = true;
			}
			if (i == 3 && filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (i == 4 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov) && filt_Volici.evaluate(*oblast->accessData(), krit_Volici)) {
				splna = true;
			}
			if (i == 5 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov) && filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (i == 6 && filt_Volici.evaluate(*oblast->accessData(), krit_Volici) && filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (i == 7 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov) && filt_Volici.evaluate(*oblast->accessData(), krit_Volici)
				&& filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (splna) {
				cout << "Nazov: " << krit_Nazov.evaluate(*oblast->accessData()) << endl;
				for (auto *kandidat : *oblast->accessData()->getKandidati()) {
					if ((!kandidat) || (kandidat && krit_ZiskaneHlasy.evaluate(*kandidat->accessData()) != -1 && filt_Meno.evaluate(*kandidat->accessData(), krit_Meno))) {
						cout << "Kandidat: " << krit_Meno.evaluate(*kandidat->accessData())
							<< "\t Ziskane hlasy: " << krit_ZiskaneHlasy.evaluate(*kandidat->accessData()) << endl;
					}
				}
				vypisData(oblast->accessData());
			}
		}
	}
	if (volba == 3) {
		for (auto *oblast : *kraje) {
			bool splna = false;
			if (i == 0) {
				splna = true;
			}
			if (i == 1 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov)) {
				splna = true;
			}
			if (i == 2 && filt_Volici.evaluate(*oblast->accessData(), krit_Volici)) {
				splna = true;
			}
			if (i == 3 && filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (i == 4 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov) && filt_Volici.evaluate(*oblast->accessData(), krit_Volici)) {
				splna = true;
			}
			if (i == 5 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov) && filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (i == 6 && filt_Volici.evaluate(*oblast->accessData(), krit_Volici) && filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (i == 7 && filt_Nazov.evaluate(*oblast->accessData(), krit_Nazov) && filt_Volici.evaluate(*oblast->accessData(), krit_Volici)
				&& filt_Ucast.evaluate(*oblast->accessData(), krit_Ucast)) {
				splna = true;
			}
			if (splna) {
				cout << "Nazov: " << krit_Nazov.evaluate(*oblast->accessData()) << endl;
				for (auto *kandidat : *oblast->accessData()->getKandidati()) {
					if ((!kandidat) || (kandidat && krit_ZiskaneHlasy.evaluate(*kandidat->accessData()) != -1 && filt_Meno.evaluate(*kandidat->accessData(), krit_Meno))) {
						cout << "Kandidat: " << krit_Meno.evaluate(*kandidat->accessData())
							<< "\t Ziskane hlasy: " << krit_ZiskaneHlasy.evaluate(*kandidat->accessData()) << endl;
					}
				}
				vypisData(oblast->accessData());
			}
		}
	}

}

void IS::nastavKombinaciuFiltrov(int i)
{
	/*cout << "Zadajte volbu pomocou volby:" << endl;
	cout << " 1 - Filter nazov \t 2 - Filter volici \t 3 -Filter ucast" << endl;
	cout << " 4 - Filter nazov a volici \t 5 - Filter nazov a ucast \t 6 - Filter volici ucast" << endl;
	cout << " 7 - Filter nazov, volici a ucast" << endl;
	cin >> i;*/
	switch (i) {
	case 1: {
		cout << "Zadajte nazov/vyraz pre filtrovanie obce" << endl;
		string pom;
		cin >> pom;
		filt_Nazov.setAlpha(pom);
	}
			break;
	case 2: {
		cout << "Zadajte spodnu hranicu intervalu volicov " << endl;
		int pom;
		cin >> pom;
		filt_Volici.setAlpha(pom);
		cout << "Zadajte hornu hranicu intervalu volicov " << endl;
		cin >> pom;
		filt_Volici.setBeta(pom);

	}
			break;
	case 3: {
		cout << "Zadajte spodnu hranicu intervalu ucasti " << endl;
		float pom;
		cin >> pom;
		filt_Ucast.setAlpha(pom);
		cout << "Zadajte hornu hranicu intervalu ucasti " << endl;
		cin >> pom;
		filt_Ucast.setBeta(pom);
	}
			break;
	case 4: {
		cout << "Zadajte nazov/vyraz pre filtrovanie obce" << endl;
		string pom;
		cin >> pom;
		filt_Nazov.setAlpha(pom);
		cout << "Zadajte spodnu hranicu intervalu volicov " << endl;
		int pom1;
		cin >> pom1;
		filt_Volici.setAlpha(pom1);
		cout << "Zadajte hornu hranicu intervalu volicov " << endl;
		cin >> pom1;
		filt_Volici.setBeta(pom1);
	}
			break;
	case 5: {
		cout << "Zadajte nazov/vyraz pre filtrovanie obce" << endl;
		string pom;
		cin >> pom;
		filt_Nazov.setAlpha(pom);
		cout << "Zadajte spodnu hranicu intervalu ucasti " << endl;
		int pom1;
		cin >> pom1;
		filt_Ucast.setAlpha(pom1);
		cout << "Zadajte hornu hranicu intervalu ucasti " << endl;
		cin >> pom1;
		filt_Ucast.setBeta(pom1);
	}
			break;
	case 6: {
		cout << "Zadajte spodnu hranicu intervalu volicov " << endl;
		int pom;
		cin >> pom;
		filt_Volici.setAlpha(pom);
		cout << "Zadajte hornu hranicu intervalu volicov " << endl;
		cin >> pom;
		filt_Volici.setBeta(pom);

		cout << "Zadajte spodnu hranicu intervalu ucasti " << endl;
		cin >> pom;
		filt_Ucast.setAlpha(pom);
		cout << "Zadajte hornu hranicu intervalu ucasti " << endl;
		cin >> pom;
		filt_Ucast.setBeta(pom);
	}
			break;
	case 7: {
		cout << "Zadajte nazov/vyraz pre filtrovanie obce" << endl;
		string pom;
		cin >> pom;
		filt_Nazov.setAlpha(pom);
		cout << "Zadajte spodnu hranicu intervalu volicov " << endl;
		int pom1;
		cin >> pom1;
		filt_Volici.setAlpha(pom1);
		cout << "Zadajte hornu hranicu intervalu volicov " << endl;
		cin >> pom1;
		filt_Volici.setBeta(pom1);

		cout << "Zadajte spodnu hranicu intervalu ucasti " << endl;
		cin >> pom1;
		filt_Ucast.setAlpha(pom1);
		cout << "Zadajte hornu hranicu intervalu ucasti " << endl;
		cin >> pom1;
		filt_Ucast.setBeta(pom1);
	}
			break;
	}
}

void IS::vypisData(Oblast * kraj)
{

	cout << "Volici: 1.Kolo :" << to_string(kraj->getVolici(0));
	cout << " 2. Kolo :" << to_string(kraj->getVolici(1)) << endl;
	cout << "Vydane obalky: 1.Kolo :" << to_string(kraj->getVydaneObalky(0));
	cout << " 2. Kolo :" << to_string(kraj->getVydaneObalky(1)) << endl;

	cout << "Ucast: 1.Kolo :" << to_string(kraj->getUcast(0));
	cout << " 2. Kolo :" << to_string(kraj->getUcast(1)) << endl;

	cout << "Odovzdane obalky: 1.Kolo :" << to_string(kraj->getOdovzdaneObalky(0));
	cout << " 2. Kolo :" << to_string(kraj->getOdovzdaneObalky(1)) << endl;

	cout << "Odovzdane hlasy: 1.Kolo :" << to_string(kraj->getHlasy(0));
	cout << " 2. Kolo :" << to_string(kraj->getHlasy(1)) << endl;
	cout << endl;
}
