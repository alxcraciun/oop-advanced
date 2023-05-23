#pragma once
#include "include/Agenda.h"
#include <memory>

template <typename T>
void Agenda<T>::show()
{
  int counter = 1;
  for (auto i : lista_abonati)
  {
    std::cout << counter << ")\n";
    if (typeid(*i) == typeid(Abonat_Skype))
    {
      std::shared_ptr<T> aux;
      aux = std::dynamic_pointer_cast<Abonat_Skype>(i);
      aux->show();
    }
    else if (typeid(*i) == typeid(Abonat_Skype_Romania))
    {
      std::shared_ptr<T> aux;
      aux = std::dynamic_pointer_cast<Abonat_Skype_Romania>(i);
      aux->show();
    }
    else if (typeid(*i) == typeid(Abonat_Skype_Extern))
    {
      std::shared_ptr<T> aux;
      aux = std::dynamic_pointer_cast<Abonat_Skype>(i);
      aux->show();
    }
    else
      std::cout << *i;
    counter += 1;
  }
}

template <typename T>
int Agenda<T>::getLungime()
{
  return nr_abonati;
}

template <typename T>
template <typename AbonatType>
Agenda<T>& Agenda<T>::operator+=(const AbonatType& other_abonat)
{
  nr_abonati++;
  lista_abonati.push_back(std::make_shared<AbonatType>(other_abonat));
  return *this;
}

/* Replaced by Template Function

template <typename T>
Agenda<T>& Agenda<T>::operator+=(const Abonat& other_abonat)
{
  nr_abonati++;
  lista_abonati.push_back(std::make_shared<Abonat>(other_abonat));
  return *this;
}

template <typename T>
Agenda<T>& Agenda<T>::operator+=(const Abonat_Skype& other_abonat)
{
  nr_abonati++;
  lista_abonati.push_back(std::make_shared<Abonat_Skype>(other_abonat));
  return *this;
}

template <typename T>
Agenda<T>& Agenda<T>::operator+=(const Abonat_Skype_Extern& other_abonat)
{
  nr_abonati++;
  lista_abonati.push_back(std::make_shared<Abonat_Skype_Extern>(other_abonat));
  return *this;
}

template <typename T>
Agenda<T>& Agenda<T>::operator+=(const Abonat_Skype_Romania& other_abonat)
{
  nr_abonati++;
  lista_abonati.push_back(std::make_shared<Abonat_Skype_Romania>(other_abonat));
  return *this;
}

*/

template <typename T>
Agenda<T>& Agenda<T>::operator[](const std::string& other_nume)
{
  bool found = false;

  for (auto x : lista_abonati)
  {
    if (typeid(*x) == typeid(Abonat_Skype_Extern))
    {
      std::shared_ptr<T> aux;
      aux = std::dynamic_pointer_cast<Abonat_Skype_Extern>(x);
      if (aux->getName() == other_nume)
      {
        found = true;
        aux->show();
        break;
      }
    }
    else if (typeid(*x) == typeid(Abonat_Skype_Romania))
    {
      std::shared_ptr<T> aux;
      aux = std::dynamic_pointer_cast<Abonat_Skype_Romania>(x);
      if (aux->getName() == other_nume)
      {
        found = 1;
        aux->show();
        break;
      }
    }
    else if (typeid(*x) == typeid(Abonat_Skype))
    {
      std::shared_ptr<T> aux;
      aux = std::dynamic_pointer_cast<Abonat_Skype>(x);
      if (aux->getName() == other_nume)
      {
        found = true;
        aux->show();
        break;
      }
    }
    else
    {
      if (x->getName() == other_nume)
      {
        found = true;
        x->show();
        break;
      }
    }
  }

  if (found == false)
    throw std::invalid_argument("Abonatul cu numele accesat nu exista in Agenda");

  return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Agenda<T>& obj)
{
  int counter = 1;
  for (auto i : obj.lista_abonati)
  {
    std::cout << counter << ")\n";
    if (typeid(*i) == typeid(Abonat_Skype))
    {
      std::shared_ptr<T> aux;
      aux = std::dynamic_pointer_cast<Abonat_Skype>(i);
      aux->show();
    }
    else if (typeid(*i) == typeid(Abonat_Skype_Romania))
    {
      std::shared_ptr<T> aux;
      aux = std::dynamic_pointer_cast<Abonat_Skype_Romania>(i);
      aux->show();
    }
    else if (typeid(*i) == typeid(Abonat_Skype_Extern))
    {
      std::shared_ptr<T> aux;
      aux = std::dynamic_pointer_cast<Abonat_Skype>(i);
      aux->show();
    }
    else
      std::cout << *i;
    counter += 1;
  }

  return stream;
}

template <typename T>
int Agenda<T>::nr_abonati = 0;