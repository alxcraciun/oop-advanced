#pragma once
#include "Abonat.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Extern.h"
#include "Abonat_Skype_Romania.h"
#include "Persoana.h"
#include <vector>
#include <memory>

template <typename T>
class Agenda
{
private:
  static int nr_abonati;
  // std::vector<Abonat*> lista_abonati;
  std::vector <std::shared_ptr<T>> lista_abonati;

public:
  Agenda() = default;
  ~Agenda() = default;

  void show();
  static int getLungime();

  // Agenda& operator+=(const Abonat& other_abonat);
  // Agenda& operator+=(const Abonat_Skype& other_abonat);
  // Agenda& operator+=(const Abonat_Skype_Extern& other_abonat);
  // Agenda& operator+=(const Abonat_Skype_Romania& other_abonat);

  template<typename AbonatType>
  Agenda& operator+=(const AbonatType& other_abonat);
  
  Agenda& operator[](const std::string& other_nume);

  friend std::ostream& operator<<(std::ostream& stream, const Agenda& obj);
};

#include "../Agenda.cpp.h"