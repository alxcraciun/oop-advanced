#include "include/AbonatFactory.h"
#include "include/Abonat_Skype.h"
#include "include/Abonat_Skype_Extern.h"
#include "include/Abonat_Skype_Romania.h"
#include "include/Agenda.h"
#include "include/Persoana.h"

std::string open;
int input;

Agenda<Abonat> agenda;

int main()
{
  std::cout << "Intra in aplicatie? y/n\n";
  std::cin >> open;

  while (true)
  {
    if (open == "n")
    {
      std::cout << "Program finalizat!";
      return 0;
    }
    else if (open != "y")
    {
      std::cout << "Optiune invalida. Apasati doar tasta 'y' sau 'n'\n";
      std::cin >> open;
      continue;
    }

    std::cout << std::endl;
    std::cout << "0) Adauga abonat prin builder \n";
    std::cout << "1) Adauga un abonat \n";
    std::cout << "2) Adauga un abonat pe Skype \n";
    std::cout << "3) Adauga un abonat pe Skype din Romania \n";
    std::cout << "4) Adauga un abonat pe Skype din alta tara.\n";
    std::cout << "5) Cauta un abonat deja existent \n";
    std::cout << "6) Afiseaza lista cu toti abonatii \n";
    std::cout << "7) Adauga un exemplu de abonat prin factory \n\n";

    std::cin >> input;
    std::cout << std::endl;

    switch (input)
    {
    case 0:
    {
      int b_id;
      std::string b_nume;
      std::string b_nr_telefon;

      std::cout << "ID: ";
      std::cin >> b_id;

      std::cout << "Nume: ";
      std::cin.ignore();
      std::getline(std::cin, b_nume);

      std::cout << "Nr. Telefon: ";
      std::cin.ignore();
      std::getline(std::cin, b_nr_telefon);

      // No error-handling for data because my handling is on >>
      AbonatBuilder builderObj;
      Abonat abonat_builder = builderObj.id(b_id).nume(b_nume).nr_telefon(b_nr_telefon).build();

      break;
    }
    case 1:
    {
      try
      {
        Abonat abonat;
        std::cin >> abonat;
        agenda += abonat;
      }
      catch (std::exception& err)
      {
        std::cout << "EROARE! " << err.what() << "Nu s-a reusit introducera abonatului in agenda.\n";
      }
      break;
    }
    case 2:
    {
      try
      {
        Abonat_Skype abonat;
        std::cin >> abonat;
        agenda += abonat;
      }
      catch (std::exception& err)
      {
        std::cout << "EROARE! " << err.what() << "Nu s-a reusit introducera abonatului in agenda.\n";
      }
      break;
    }
    case 3:
    {
      try
      {
        Abonat_Skype_Romania abonat;
        std::cin >> abonat;
        agenda += abonat;
      }
      catch (std::exception& err)
      {
        std::cout << "EROARE! " << err.what() << "Nu s-a reusit introducera abonatului in agenda.\n";
      }
      break;
    }
    case 4:
    {
      try
      {
        Abonat_Skype_Extern abonat;
        std::cin >> abonat;
        agenda += abonat;
      }
      catch (std::exception& err)
      {
        std::cout << "EROARE! " << err.what() << "Nu s-a reusit introducera abonatului in agenda.\n";
      }
      break;
    }
    case 5:
    {
      try
      {
        std::cout << "Introduce numele: ";

        std::string nume;
        std::cin.ignore();
        std::getline(std::cin, nume);

        agenda[nume];
      }
      catch (std::exception& err)
      {
        std::cout << "EROARE! " << err.what();
      }
      break;
    }
    case 6:
    {
      if (agenda.getLungime() == 0)
        std::cout << "Nu exista angajati in agenda.\n";
      else
        agenda.show();
      break;
    }
    case 7:
    {
      std::cout << "1) Adauga un abonat \n";
      std::cout << "2) Adauga un abonat pe Skype \n";
      std::cout << "3) Adauga un abonat pe Skype din Romania \n";
      std::cout << "4) Adauga un abonat pe Skype din alta tara.\n\n";
      std::cin >> input;
      
      switch (input)
      {
      case 1:
      {
        try
        {
          Abonat abonat = AbonatFactory::abonat();
          agenda += abonat;
          std::cout << "Abonat adaugat cu succes!";
        }
        catch (std::exception& err)
        {
          std::cout << "EROARE! " << err.what() << "Nu s-a reusit introducera abonatului in agenda.\n";
        }
        break;
      }

      case 2:
      {
        try
        {
          Abonat_Skype abonat = AbonatFactory::abonat_skype();
          agenda += abonat;
          std::cout << "Abonat adaugat cu succes!";
        }
        catch (std::exception& err)
        {
          std::cout << "EROARE! " << err.what() << "Nu s-a reusit introducera abonatului in agenda.\n";
        }
        break;
      }

      case 3:
      {
        try
        {
          Abonat_Skype_Romania abonat = AbonatFactory::abonat_skype_romania();
          agenda += abonat;
          std::cout << "Abonat adaugat cu succes!";
        }
        catch (std::exception& err)
        {
          std::cout << "EROARE! " << err.what() << "Nu s-a reusit introducera abonatului in agenda.\n";
        }
        break;
      }

      case 4:
      {
        try
        {
          Abonat_Skype_Extern abonat = AbonatFactory::abonat_skype_extern();
          agenda += abonat;
          std::cout << "Abonat adaugat cu succes!";
        }
        catch (std::exception& err)
        {
          std::cout << "EROARE! " << err.what() << "Nu s-a reusit introducera abonatului in agenda.\n";
        }
        break;
      }

      default:
      {
        std::cout << "Optiunea introdusa este gresita.\n";
      }
      }
      break;
    }

    default:
    {
      std::cout << "Optiunea introdusa este gresita.\n";
    }
    }

    std::cout << "\nDoriti sa continuati? y/n\n";
    std::cin >> open;
  }

  return 0;
}