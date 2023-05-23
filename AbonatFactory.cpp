#include "include/AbonatFactory.h"

Abonat AbonatFactory::abonat()
{
  return Abonat("0771485663", 1, "Craciun Alex");
}

Abonat_Skype AbonatFactory::abonat_skype()
{
  return Abonat_Skype("123", "0771485663", 1, "Craciun Alex");
}

Abonat_Skype_Romania AbonatFactory::abonat_skype_romania()
{
  return Abonat_Skype_Romania("craciun@gmail.com", "123", "0771485663", 1, "Craciun Alex");
}

Abonat_Skype_Extern AbonatFactory::abonat_skype_extern()
{
  return Abonat_Skype_Extern("Romania", "123", "0771485663", 1, "Craciun Alex");
}
