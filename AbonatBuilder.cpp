#include "include/Abonat.h"

AbonatBuilder& AbonatBuilder::id(int other)
{
	ab.id = other;
	return *this;
}

AbonatBuilder& AbonatBuilder::nume(std::string& other)
{
	ab.nume= other;
	return *this;
}

AbonatBuilder& AbonatBuilder::nr_telefon(std::string& other)
{
	ab.nr_telefon = other;
	return *this;
}

Abonat AbonatBuilder::build()
{
	return ab;
}

