//---------------------------------------------------------------------------

#pragma hdrstop

#include "Zoo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
// Методы класса ZooList

void ZooList::load(const char* fileName)
{
    setlocale(LC_ALL,"russian");
	std::wifstream inpt(fileName);
	if (inpt.is_open())
	{
		this->clear();
		while(inpt.good())
		{
			wchar_t name[30];
			size_t spicies = 0;
			size_t rare = 0;
			inpt >> name >> spicies >> rare;
			this->add(UnicodeString(name), spicies, rare);
		}
	}

	inpt.close();
}

void ZooList::print(const char* fileName) const
{
	std::wofstream outp(fileName);
	if (outp.is_open())
	{
		auto i = begin();
		outp << i->second.to_string().c_str();
		for(i++; i != end(); i++)
			outp << L"\n" << i->second.to_string().c_str();
	}
	outp.close();
}


bool ZooList::add(UnicodeString name, size_t spicies, size_t rare)
{
	return
		this->insert(ZooPair(get_hash(name.c_str(), name.Length()), Zoo(name, spicies, rare))).second;
}


ZooIter ZooList::max_elem(Zoo::Traits prop)
{
	switch (prop)
	{
	case Zoo::Traits::RareSpiciesCount:
		return std::max_element(this->begin(), this->end(),
			[](ZooPair z1, ZooPair z2) { return z1.second.rareCount < z2.second.rareCount; }
		);
	case Zoo::Traits::SpiciesCount:
		return std::max_element(this->begin(), this->end(),
			[](ZooPair z1, ZooPair z2) { return z1.second.spiciesCount < z2.second.spiciesCount; }
		);
	case Zoo::Traits::Name:
		return std::max_element(this->begin(), this->end(),
			[](ZooPair z1, ZooPair z2) { return z1.second.name.Length() < z2.second.name.Length(); }
		);
	default:
		throw std::exception("Unknown property!");
	}
};

ZooIter ZooList::min_elem(Zoo::Traits prop)
{
	switch (prop)
	{
	case Zoo::Traits::RareSpiciesCount:
		return std::min_element(this->begin(), this->end(),
			[](ZooPair z1, ZooPair z2) { return z1.second.rareCount < z2.second.rareCount; }
		);
	case Zoo::Traits::SpiciesCount:
		return std::min_element(this->begin(), this->end(),
			[](ZooPair z1, ZooPair z2) { return z1.second.spiciesCount < z2.second.spiciesCount; }
		);
	case Zoo::Traits::Name:
		return std::min_element(this->begin(), this->end(),
			[](ZooPair z1, ZooPair z2) { return z1.second.name.Length() < z2.second.name.Length(); }
		);
	default:
		throw std::exception("Unknown property!");
	}
};

ZooList ZooList::select_or(size_t results,
				UnicodeString name,
				long spicies,
				long rare)
{
	ZooList result = ZooList();
	if (name == "" && spicies == -1 && rare == -1)
		return result;

	if (results > 0)
	{
		// Списки объектов по приоритетам
		ZooList zlFrst = ZooList();
		ZooList zlScnd = ZooList();
		ZooList zlThrd = ZooList();

		for (auto i = this->begin(); i != this->end() && zlFrst.size() + zlScnd.size() + zlThrd.size() <= results ; i++)
		{
			// Приоритет вычисляется как число совпавших полей
			short current = (name != "" && name == i->second.name) +
				(spicies != -1 && spicies == i->second.spiciesCount) +
				(rare != -1 && rare == i->second.rareCount);

			switch (current)
			{
			case 1: zlThrd.insert(ZooPair(i->first, i->second)); break;
			case 2: zlScnd.insert(ZooPair(i->first, i->second)); break;
			case 3: zlFrst.insert(ZooPair(i->first, i->second)); break;
			default: break;
			}
		}

		// Добавляем элементы в результирующий список.
		// Если в zlFrst элементов меньше, чем нужно, добавляем из zlScnd и т.д.
		size_t pos = 0;
		for (auto i = zlFrst.begin(); i != zlFrst.end() && pos < results; i++, pos++)
			result.insert(ZooPair(i->first, i->second));

		for (auto i = zlScnd.begin(); i != zlScnd.end() && pos < results; i++, pos++)
			result.insert(ZooPair(i->first, i->second));

		for (auto i = zlThrd.begin(); i != zlThrd.end() && pos < results; i++, pos++)
			result.insert(ZooPair(i->first, i->second));
	}
	else
	{
		// Если не указано сколько элементов искать, выводим все, что найдём
		for (auto i = this->begin(); i != this->end(); i++)
		{
			if ((name != "" && name == i->second.name) ||
				(spicies != -1 && spicies == i->second.spiciesCount) ||
				(rare != -1 && spicies == i->second.rareCount)) result.insert(ZooPair(i->first, i->second));
		}
	}
	return result;
}

ZooList ZooList::select_and(size_t results,
				UnicodeString name,
				long spicies,
				long rare,
				long key)
{
	ZooList result = ZooList();
	if (name == "" && spicies == -1 && rare == -1)
		return result;

	char mask = 0;
	if(key != -1) mask |= (1 << 3);
	if(name != "") mask |= (1 << 2);
	if(spicies != -1) mask |= (1 << 1);
	if(rare != -1) mask |= 1;

	for (auto i = this->begin(); i != this->end() && results != 0; i++)
	{
		char curr = 0;
		if(i->first == key) curr |= (1 << 3);
		if(i->second.name == name) curr |= (1 << 2);
		if(i->second.spiciesCount == spicies) curr |= (1 << 1);
		if(i->second.rareCount == rare) curr |= 1;

		if((curr & mask) == mask)
			result.insert(ZooPair(i->first, i->second));
        results--;
	}

	return result;
}


ZooList collect_maxSpicies(ZooList& zl)
{
	ZooList result = ZooList();
	size_t maxSpicies = zl.max_elem(Zoo::Traits::SpiciesCount)->second.spiciesCount;
	std::for_each(zl.cbegin(), zl.cend(), [&result, maxSpicies](ZooPair z)
	{
		if (z.second.spiciesCount == maxSpicies)
			result.insert(z);
	});

	return result;
};

ZooList collect_raresLessThan(ZooList& zl, float ratio)
{
	ZooList result = ZooList();
	std::for_each(zl.cbegin(), zl.cend(), [&result, ratio](ZooPair z)
	{
		if (z.second.rareCount != 0 && double(z.second.rareCount) / z.second.spiciesCount < ratio)
			result.insert(z);
	});

	return result;
};
