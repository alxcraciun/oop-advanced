#pragma once
#include "Abonat.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Extern.h"
#include "Abonat_Skype_Romania.h"
#include "Persoana.h"
#include <vector>
#include <memory>

class AbonatFactory
{
public:
    static Abonat abonat();
    static Abonat_Skype abonat_skype();
    static Abonat_Skype_Romania abonat_skype_romania();
    static Abonat_Skype_Extern abonat_skype_extern();
};