//---------------------------------------------------------------------------

#pragma once

#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <System.Classes.hpp>

#define ZooIter std::map<uint32_t, Zoo>::iterator
#define ZooPair std::pair<uint32_t, Zoo>

// Хэш-функция Дженкинса
inline uint32_t get_hash(wchar_t* str, size_t length)
{
	uint32_t hash;
	for(int i = 0; i < length; i++)
	{
		hash += str[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}


struct Zoo
{
	UnicodeString name;
	size_t rareCount;
	size_t spiciesCount;

	Zoo(UnicodeString name = "", size_t spicies = 0, size_t rare = 0) :
		name(name), spiciesCount(spicies), rareCount(rare)
	{}


	Zoo(const Zoo& zoo)
	{
		this->name = zoo.name;
		this->rareCount = zoo.rareCount;
		this->spiciesCount = zoo.spiciesCount;
	}

	inline uint32_t hash()
	{
		return get_hash(name.c_str(), name.Length());
	}

	inline std::wstring to_string() const
	{
		std::wstringstream stream;
		stream << this->name.c_str() << L" " << this->spiciesCount
			<< L" " << this->rareCount;
		std::wstring t = stream.str();
		return stream.str();
	}

	enum class Traits { SpiciesCount, RareSpiciesCount, Name, Hash };
};


struct ZooList : std::map<uint32_t, Zoo>
{
	ZooList()
	{}

	void load(const char* fileName);
	void print(const char* fileName) const;
	bool add(UnicodeString name, size_t spicies, size_t rare = 0);

	ZooIter max_elem(Zoo::Traits prop);
	ZooIter min_elem(Zoo::Traits prop);

	ZooList select_or(size_t results,
					UnicodeString name = "",
					long spicies = -1,
					long rare = -1);
	ZooList select_and(size_t results,
					UnicodeString name = "",
					long spicies = -1,
					long rare = -1,
                    long key = -1);
};;

ZooList collect_maxSpicies(ZooList& zl);
ZooList collect_raresLessThan(ZooList& zl, float ratio);
