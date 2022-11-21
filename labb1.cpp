#include <iostream>
#include <vector>
#include <string>

struct Person
{
  std::string fnamn;
  std::string enamn;
  std::string nummer;
};

void visa_person(std::vector<Person> telefonregister, std::string fNamn)
{
  // Denna funktion tar emot ett telefonregister och ett f�rnamn p� den person-post som skall visas.
  // Om det finns en eller flera person-poster med detta f�rnamn i registret,
  // s� skall telefonnumret till dessa visas, p� formen: "f�rnamn efternamn: telefonnummer".
  // std::cout << fnamn << " " << enamn << ": " << nummer << std::endl;

  bool foundPerson = false;

  for (int i = 0; i < telefonregister.size(); i++)
  {
    if (telefonregister[i].fnamn == fNamn)
    {
      std::cout << telefonregister[i].fnamn << " " << telefonregister[i].enamn << ": " << telefonregister[i].nummer << std::endl;
      foundPerson = true;
    }
  }
  if (foundPerson == false)
  {
    // Om ingen person-post hittas med det s�kta f�rnamnet, s� skall f�ljande skrivas ut.
    std::cout << "Hittade inget nummer!" << std::endl;
  }
}

void skriv_hela_telefonreg(std::vector<Person> &telefonregister)
{
  // Denna funktion tar emot ett telefonregister och visar samtliga poster i
  // telefonregistret p� formen: "f�rnamn efternamn: telefonnummer".
  for (int i = 0; i < telefonregister.size(); i++)
  {
    std::cout << telefonregister[i].fnamn << " " << telefonregister[i].enamn << ":\\ " << telefonregister[i].nummer << std::endl;
  }
}

void ny_person(std::vector<Person> &telefonregister, std::string fNamn, std::string eNamn, std::string telefonnummer)
{
  // Denna funktion tar emot ett telefonregister och ett f�rnamn, ett efternamn och
  // ett telefonnummer till den nya person-post som skall skapas och l�ggas till i telefonboken,
  // d�refter l�ggs person-posten till registret.
  Person person{fNamn, eNamn, telefonnummer};

  telefonregister.push_back(person);
}

void ta_bort_person(std::vector<Person> &telefonregister, std::string fNamn)
{
  // Denna funktion tar emot ett telefonregister och ett f�rnamn p� den person-post
  // som skall tas bort ur registret.
  // Om det finns fler person-poster med samma f�rnamn, s� tas alla dessa bort.

  // N�r en person-post tas bort s� skrivs namnet p� person-posten ut p� sk�rmen (f�rnamn efternamn),
  // men ingen anv�ndardialog skall finnas, dvs. anv�ndaren skall inte bekr�fta borttag.

  bool foundPerson = false;

  for (int i = 0; i < telefonregister.size(); i++)
  {
    if (telefonregister[i].fnamn == fNamn)
    {
      foundPerson = true;
      std::cout << Person.fnamn << " " << Person.enamn << " tas nu bort." << std::endl;
      telefonregister.erase(telefonregister.begin() + i);
    }
  }
  if (foundPerson == false)
  {
    std::cout << "Hittade ingen person med det namnet!" << std::endl;
  }
}

int main()
{
  // Dessa personer skall finnas med som person-poster i telefonregistret.
  /*
  "Christina", "Nyberg","0707423653"
  "Josefin", "Danielsson", "0705463245"
  "Ellen", "Lindgren", "0705643229"
  "Stig", "Ek", "0705673247"
  "Linus", "Jonasson", "0703457923"
  "Adam", "Nordin", "0203456297"
  */
  // H�r ska du deklarera den variabel som skall inneh�lla ditt register!
  std::vector<Person> telefonregister;
  std::string input;

  ny_person(telefonregister, "Christina", "Nyberg", "0707423653");
  ny_person(telefonregister, "Josefin", "Danielsson", "0705463245");
  ny_person(telefonregister, "Ellen", "Lindgren", "0705643229");
  ny_person(telefonregister, "Stig", "Ek", "0705673247");
  ny_person(telefonregister, "Linus", "Jonasson", "0703457923");
  ny_person(telefonregister, "Adam", "Nordin", "0203456297");

  // H�r skall en liten kommandostyrd huvudmeny skrivas. Observera att vissa kommandon
  // beh�ver fler v�rden som skall matas in. I menyn skall f�ljande val
  // av Kommandon finnas:
  //  Ny person               - 'n' f�rnamn efternamn telefonnummer
  //  Visa en person          - 'v' f�rnamn
  //  Skriv hela telefonboken - 's'
  //  Ta bort en person       - 'd' f�rnamn
  //  Avsluta                 � 'q'

  while (input != "q")
  {
    std::cout << "Kommando: ";
    std::cin >> input;
    if (input == "n")
    {
      std::string namn;
      std::string eNamn;
      std::string telefonnummer;

      std::cin >> namn;

      std::cin >> eNamn;
      std::cin >> telefonnummer;
      ny_person(telefonregister, namn, eNamn, telefonnummer);
    }

    else if (input == "v")
    {
      std::string namn;
      std::cin >> namn;
      visa_person(telefonregister, namn);
    }

    else if (input == "s")
    {
      skriv_hela_telefonreg(telefonregister);
    }

    else if (input == "d")
    {
      std::string namn;
      std::cout << "namn pa personen?" << std::endl;
      std::cin >> namn;
      ta_bort_person(telefonregister, namn);
    }

    else
    {
      std::cout << "Hejdå!\\s*" << std::endl;
    }
    // switch (input) {
    //  case "n":
    //     std::cout << "f�rnamn?"
    // }
  }

  return 0;
}
