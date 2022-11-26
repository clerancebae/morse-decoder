#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

string convertToEnglish(std::string morse, std::string const morseLetters[])
{
    string output = "";
    string currentLetter = "";
    istringstream ss(morse);
    
    size_t const characters = 26;
    
    while(ss >> currentLetter)
    {
        std::size_t index = 0;
        while(currentLetter != morseLetters[index] && index < characters)
        {
            ++index; 
        }
        
        output += 'A' + index;
    }
    transform(output.begin(), output.end(), output.begin(), ::tolower);
    return output;
}

int main() {
  const char letters[37] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  const string morseLetters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
  string textToChange= "";
  string newText = "";
  string input = "";
  cout << "Enter text you want to change to Morse code" << endl;
  getline(cin, textToChange);
  transform(textToChange.begin(), textToChange.end(), textToChange.begin(), ::tolower);
  
  for (unsigned int i = 0; i < textToChange.size(); i++) {
    for (unsigned short j = 0; j < 37; j++) {
      if (textToChange[i] == letters[j]) {
        newText += morseLetters[j];
        newText += "   ";
        break;
      }        
    }
  }
    cout << "Text in Morse code" << endl << newText << endl;
    cout << "Please enter a string in morse code: " << endl ;
    getline(std::cin, input);
    cout << convertToEnglish(input, morseLetters) << endl;
  
  int a;
  cin >> a;
  return 0;
}
