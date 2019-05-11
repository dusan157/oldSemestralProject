#include "Oblast.h"

Oblast::Oblast()
{
	volici = new structures::Array<int>(2);
	vydaneObalky = new structures::Array<int>(2);
	ucast = new structures::Array<float>(2);
	odovzdaneObalky = new structures::Array<int>(2);
	hlasy = new structures::Array<int>(2);
	kandidati = new structures::UnsortedSequenceTable<std::string,Kandidat*>;
}

Oblast::~Oblast()
{
	nazov = "";
	delete volici;
	delete vydaneObalky;
	delete ucast;
	delete odovzdaneObalky;
	delete hlasy;
	for (auto item : *kandidati) {
		delete item->accessData();
	}
	delete kandidati;
}

int Oblast::getKandidatHlasy(std::string meno, int kolo)
{
	Kandidat * kand;
	kandidati->tryFind(meno, kand);
	return kand->getHlasy(kolo);
}

void Oblast::setData(int index, std::string data)
{
	switch (index) {
	case 0: nazov = data;
		break;
	case 1: (*volici)[0] = stoi(data);
		break;
	case 2: (*vydaneObalky)[0] = stoi(data);
		break;
	case 3: (*ucast)[0] = stof(data);
		break;
	case 4: (*odovzdaneObalky)[0] = stoi(data);
		break;
	case 5: (*hlasy)[0] = stoi(data);
		break;
	case 6: (*volici)[1] = stoi(data);
		break;
	case 7: (*vydaneObalky)[1] = stoi(data);
		break;
	case 8: (*ucast)[1] = stof(data);
		break;
	case 9: (*odovzdaneObalky)[1] = stoi(data);
		break;
	case 10: (*hlasy)[1] = stoi(data);
		break;
}
	
}

void Oblast::setDataKandidati(std::string meno,int kolo,int hodnota)
{
	Kandidat * kandidat;
		if (!kandidati->tryFind(meno,kandidat))
		{
			kandidat = new Kandidat(meno);
			kandidati->insert(meno, kandidat);
		}
		kandidat->setHlasy(kolo, hodnota);
		kandidat = nullptr;
		delete kandidat;
}
