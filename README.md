# OOP Advanced Project

**Tema 04** <br>
Se dau urmatoarele clase:

- Clasa Persoana(int id, string nume)
- Clasa Abonat:Persoana(string nr_telefon)
- Clasa Abonat_Skype: Abonat (string id_skype)
- Clasa Abonat_Skype_Romania (string adresa_mail) : Abonat_Skype
- Clasa Abonat_Skype_Extern(string tara) : Abonat_Skype

Sa se construiasca clasa Agenda ce contina o lista de abonati si sa se supraincarce operatorul [ ] (indexare) care returneaza abonatul cu numele precizat.

<br>

## Cerinte
Scopul ultimei teme este utilizarea unor noțiuni mai avansate de OOP (design patterns) și a programării generice.

- minim o funcție șablon și o clasă șablon (template)
- modificați o clasă existentă care este ceva mai izolată de celelalte (să nu aveți foarte mult de modificat) și transformați-o în clasă template
- adăugați (minim) un atribut de tip T sau care depinde de T
- adăugați (minim) o funcție membru care să depindă de T (sau de alt parametru template);
- adăugați (minim) o funcție normală/liberă template; poate să fie friend
- minim 2 design patterns (3 dacă aveți singleton sau ceva la fel de simplu și proiectul e simplu);
- utilizarea acestor design patterns ar trebui să aibă sens
