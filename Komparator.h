#pragma once
#include "structures\table\table.h"
#include "Oblast.h"
template <typename K, typename T>
class Komparator {
public:
	virtual bool porovnaj(structures::TableItem<K,T> oblast1, structures::TableItem<K, T> oblast2) = 0;
};