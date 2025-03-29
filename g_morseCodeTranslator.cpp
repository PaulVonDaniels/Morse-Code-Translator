#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

struct MorsePair
{
    char character;
    string code;
};

vector<MorsePair> morseAlphabet =
{
    {'A', ".-"}, {'a', ".-"},
    {'B', "-..."}, {'b', "-..."},
    {'C', "-.-."}, {'c', "-.-."},
    {'D', "-.."}, {'d', "-.."},
    {'E', "."}, {'e', "."},
    {'F', "..-."}, {'f', "..-."},
    {'G', "--."}, {'g', "--."},
    {'H', "...."}, {'h', "...."},
    {'I', ".."}, {'i', ".."},
    {'J', ".---"}, {'j', ".---"},
    {'K', "-.-"}, {'k', "-.-"},
    {'L', ".-.."}, {'l', ".-.."},
    {'M', "--"}, {'m', "--"},
    {'N', "-."}, {'n', "-."},
    {'O', "---"}, {'o', "---"},
    {'P', ".--."}, {'p', ".--."},
    {'Q', "--.-"}, {'q', "--.-"},
    {'R', ".-."}, {'r', ".-."},
    {'S', "..."}, {'s', "..."},
    {'T', "-"}, {'t', "-"},
    {'U', "..-"}, {'u', "..-"},
    {'V', "...-"}, {'v', "...-"},
    {'W', ".--"}, {'w', ".--"},
    {'X', "-..-"}, {'x', "-..-"},
    {'Y', "-.--"}, {'y', "-.--"},
    {'Z', "--.."}, {'z', "--.."},
    {'0', "-----"},
    {'1', ".----"},
    {'2', "..---"},
    {'3', "...--"},
    {'4', "....-"},
    {'5', "....."},
    {'6', "-...."},
    {'7', "--..."},
    {'8', "---.."},
    {'9', "----."},
    {'.', ".-.-.-"},
    {',', "--..--"},
    {'?', "..--.."},
    {'\'', ".----."},
    {'!', "-.-.--"},
    {'/', "-..-."},
    {'(', "-.--."},
    {')', "-.--.-"},
    {'&', ".-..."},
    {':', "---..."},
    {';', "-.-.-."},
    {'=', "-...-"},
    {'+', ".-.-."},
    {'-', "-....-"},
    {'_', "..--.-"},
    {'"', ".-..-."},
    {'$', "...-..-"},
    {'@', ".--.-."},
    {' ', "/"}
};

string textToMorse(const string &text)
{
    string result;
    for (char c : text)
    {
        bool found = false;
        
        for (const MorsePair &mp : morseAlphabet)
        {
            if (mp.character == c)
            {
                result += mp.code + " ";
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            result += string(1, c) + " ";
        }
    }
    
    if (!result.empty())
    {
        result.pop_back();
    }
    return result;
}

string morseToText(const string &morse)
{
    string result;
    istringstream iss(morse);
    string token;
    
    while (iss >> token)
    {
        bool found = false;
        
        for (const MorsePair &mp : morseAlphabet)
        {
            if (mp.code == token)
            {
                result += mp.character;
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            if (token == "/")
            {
                result += " ";
            }
            else
            {
                result += "[" + token + "]";
            }
        }
    }
    
    return result;
}

bool isMorseCode(const string &input)
{
    for (char c : input)
    {
        if (c != '.' && c != '-' && c != ' ' && c != '/')
        {
            return false;
        }
    }
    return !input.empty();
}

int main()
{
    cout << "Morse Code Translator (supports lowercase letters)" << endl;
    cout << "Enter text or Morse code (use '.' and '-', separate symbols with spaces):" << endl;
    
    string input;
    while (getline(cin, input))
    {
        if (input.empty())
        {
            break;
        }
        
        if (isMorseCode(input))
        {
            cout << "Result: " << morseToText(input) << endl;
        }
        else
        {
            cout << "Result: " << textToMorse(input) << endl;
        }
        
        cout << "\nEnter next line (or empty line to exit):" << endl;
    }
    
    return 0;
}