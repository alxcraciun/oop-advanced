#pragma once
#include "Persoana.h"

class Abonat : public Persoana
{
protected:
  std::string nr_telefon;

public:
  Abonat() = default;
  Abonat(const std::string other_nr_telefon, const int other_id, const std::string other_nume);
  Abonat(const std::string other_nr_telefon, const Persoana& other_persoana);
  Abonat(const Abonat& other);
  virtual ~Abonat() = default;

  virtual void show() override;
  virtual std::string getName();

  Abonat& operator=(const Abonat& other);
  friend std::istream& operator>>(std::istream& stream, Abonat& obj);
  friend std::ostream& operator<<(std::ostream& stream, const Abonat& obj);

  friend class AbonatBuilder;
};

class AbonatBuilder
{
private:
  Abonat ab;

public:
  AbonatBuilder() = default;
  AbonatBuilder& id(int);
  AbonatBuilder& nume(std::string&);
  AbonatBuilder& nr_telefon(std::string&);
  Abonat  build();
};