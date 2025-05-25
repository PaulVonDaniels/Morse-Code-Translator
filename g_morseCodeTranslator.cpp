/*
Danilchenko Pavel Sergeevich
Morse Code String Encoder
Fault-tolerant computing
*/

#include <iostream>
#include <dos.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <cstring>
#include <fstream>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::toupper;
using std::ofstream;
using std::getline;

class MorsePlayer
{
public:
    static void dot()
    {
        Beep(400, 300);
        cout << '.';
    }

    static void dash()
    {
        Beep(500, 600);
        cout << '-';
        Sleep(1);
    }

    static void dotImg()
    {
        system("color F0");
        cout << '.';
        Sleep(300);
        system("color 0F");
        Sleep(100);
    }

    static void dashImg()
    {
        system("color F0");
        cout << '-';
        Sleep(600);
        system("color 0F");
        Sleep(100);
    }

    static void playImage(const string& cadenaMorse)
    {
        for(char c : cadenaMorse)
        {
            if(c == '.')
            {
                dotImg();
            }
            else if(c == '-')
            {
                dashImg();
            }
            else if(c == ' ')
            {
                Sleep(1000);
                cout << " ";
            }
        }
    }

    static void playMusic(const string& cadenaMorse)
    {
        for(char c : cadenaMorse)
        {
            if(c == '.')
            {
                dot();
            }
            else if(c == '-')
            {
                dash();
            }
            else if(c == ' ')
            {
                Sleep(1000);
                cout << " ";
            }
        }
    }
};

class MorseTranslator
{
public:
    static string translate(char letra)
    {
        switch(toupper(letra))
        {
            case 'A':
                return ".-";
            case 'B':
                return "-...";
            case 'C':
                return "-.-.";
            case 'D':
                return "-..";
            case 'E':
                return ".";
            case 'F':
                return "..-.";
            case 'G':
                return "--.";
            case 'H':
                return "....";
            case 'I':
                return "..";
            case 'J':
                return ".---";
            case 'K':
                return "-.-";
            case 'L':
                return ".-..";
            case 'M':
                return "--";
            case 'O':
                return "---";
            case 'P':
                return ".--.";
            case 'Q':
                return "--.-";
            case 'R':
                return ".-.";
            case 'S':
                return "...";
            case 'T':
                MorsePlayer::dash();
                return "-";
            case 'U':
                return "..-";
            case 'V':
                return "...-";
            case 'W':
                return ".--";
            case 'X':
                return "-..-";
            case 'Y':
                return "-..-";
            case 'Z':
                return "---.";
            case '0':
                return "-----";
            case '1':
                return ".----";
            case '2':
                return "..---";
            case '3':
                return "...--";
            case '4':
                return "....-";
            case '5':
                return ".....";
            case '6':
                return "-....";
            case '7':
                return "--...";
            case '8':
                return "---..";
            case '9':
                return "----.";
            case ' ':
                return " ";
            default:
                cout << "Elemento no reconocido" << endl;
                return "";
        }
    }

    static string translateString(const string& text)
    {
        string result;
        for(char c : text)
        {
            result += translate(c) + " ";
        }
        return result;
    }
};

class Application
{
public:
    static void run()
    {
        while(true)
        {
            principal();
            if(!askToContinue())
            {
                break;
            }
        }
    }

private:
    static void principal()
    {
        string cadena = "";
        cin.sync();
        cout << "Escribe la linea para traducir" << endl;
        getline(cin, cadena, '\n');

        string cadenaMorse = MorseTranslator::translateString(cadena);

        saveToFile(cadena, cadenaMorse);
        
        int opc = getUserChoice();
        processUserChoice(opc, cadenaMorse);
    }

    static void saveToFile(const string& original, const string& morse)
    {
        ofstream entrada;
        entrada.open("mensaje.txt");
        entrada << original << '\n' << morse;
        entrada.close();
    }

    static int getUserChoice()
    {
        int opc = 0;
        cout << "Selecciona la opcion con la que deseas mostrar el resultado" << endl;
        cout << "1.- Reproduccion de sonido" << endl;
        cout << "2.- Reproduccion en pantalla" << endl;
        cin >> opc;
        
        if(cin.fail())
        {
            cout << "Opcion incorrecta" << endl;
            cin.clear();
            cin.ignore(10, '\n');
            opc = 0;
        }
        return opc;
    }

    static void processUserChoice(int opc, const string& cadenaMorse)
    {
        cout << "Cadena resultante" << endl;
        switch(opc)
        {
            case 1:
                MorsePlayer::playMusic(cadenaMorse);
                break;
            case 2:
                MorsePlayer::playImage(cadenaMorse);
                break;
            default:
                break;
        }
    }

    static bool askToContinue()
    {
        int opc = 0;
        cout << endl << "Deseas salir del programa? Si -> 1 No->2" << endl;
        cin >> opc;
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(10, '\n');
            return true;
        }
        
        switch(opc)
        {
            case 1:
                return false;
            case 2:
                return true;
            default:
                cout << "Debe seleccionar una opcion correcta" << endl;
                return true;
        }
    }
};

int main()
{
    Application::run();
    return 0;
}
