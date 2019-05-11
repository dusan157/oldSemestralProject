#pragma once
#include "structures/table/sorted_sequence_table.h"
#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorting/heap_sort.h"
#include <iostream>
#include "Obec.h"
#include "Okres.h"
#include "Kraj.h"

#include "KriteriumNazov.h"
#include "KriteriumVolici.h"
#include "KriteriumOdovzdaneHlasy.h"
#include "KriteriumOdovzdaneObalky.h"
#include "KriteriumPrislusnost.h"
#include "KriteriumUcast.h"
#include "KriteriumVydaneObalky.h"
#include "Kriterium_KandidatiHlasy.h"
#include "KriteriumMeno.h"

#include "FilterVolici.h"
#include "FilterNazov.h"
#include "FilterUcast.h"
#include "FilterMeno.h"

#include "Komparator_Nazov.h"
#include "Komparator_Ucast.h"
#include "Komparator_Volici.h"

using namespace std;
class IS
{
public:
	IS();
	~IS();
	void nacitanie();
	void vypisInfoNazov(int);
	void vypisInfoVolici(int,int);
	void vypisInfoUcast(int, int);
	void vypisUtriedeneNazov(int);
	void vypisUtriedeneVolici(int,int);
	void vypisUtriedeneUcast(int,int);
	void vypisUtriedeneFiltrovaneNazov(int,string,int);
	void vypisUtriedeneFiltrovaneVolici(int, string, int);
	void vypisUtriedeneFiltrovaneUcast(int, string, int);
	void vypisMenu();
	void vypisKandidatovUzemnaJednotka(int);
private:
	void vypisData(Oblast*);
	void nastavKombinaciuFiltrov(int);

private:
	structures::SortedSequenceTable<int, Kraj*> *kraje;
	structures::SortedSequenceTable<int, Okres*> *okresy;
	structures::SortedSequenceTable<int, Obec*> *obce;
	structures::UnsortedSequenceTable<int, Kraj*> *neutriedKraje;
	structures::UnsortedSequenceTable<int, Okres*> *neutriedOkresy;
	structures::UnsortedSequenceTable<int, Obec*> *neutriedObce;

	KriteriumNazov krit_Nazov;
	KriteriumOdovzdaneHlasy krit_OdovzdaneHlasy;
	KriteriumOdovzdaneObalky krit_OdovzdaneObalky;
	KriteriumPrislusnost krit_Prislusnost;
	KriteriumUcast krit_Ucast;
	KriteriumVolici krit_Volici;
	KriteriumVydaneObalky krit_VydaneObalky;
	KriteriumMeno krit_Meno;
	KriteriumHlasy krit_ZiskaneHlasy;

	FilterNazov filt_Nazov;
	FilterVolici filt_Volici;
	FilterUcast filt_Ucast;
	FilterMeno filt_Meno;
	
};

