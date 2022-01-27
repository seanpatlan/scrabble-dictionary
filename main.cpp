#include <string>
#include <fstream>
#include <iostream>
#include <unordered_set>

std::string uppercase(const std::string& _s)
{
  std::string s;
  for (const char& c : _s)
    s += std::toupper(c);
  return s;
}

const int BUF_MAX = 128;

int main()
{
  std::string s;
  std::unordered_set<std::string> dict;
  std::ifstream in("dictionary.csv");
  while (in >> s)
    dict.insert(uppercase(s));

  while (true) {
    system("clear");
    std::cout << "Enter a word to check if it's in the Scrabble dictionary\n(Or enter \"quit\" to exit the program)\n\n>> ";
    getline(std::cin, s);

    if (uppercase(s) == "QUIT") break;

    system("clear");
    if (dict.find(uppercase(s)) == dict.end())
      std::cout << "\033[1;31m\"" << s << "\" is NOT in the Scrabble dictionary\033[0m";
    else
      std::cout << "\033[1;32m\"" << s << "\" is in the Scrabble dictionary\033[0m";
    std::cout << "\n\nPress enter to continue... ";
    std::cin.ignore(BUF_MAX, '\n');
  }

  system("clear");

  return 0;
}
