#include "Converter.h"

using namespace std;

string Converter::ConvertFromInt(int x)
{
    return std::to_string(x);
}

string Converter::ConvertFromFloat(float f)
{
    return std::to_string(f);
}

string Converter::ConvertFromBool(bool b)
{
    return std::to_string(b);
}

int Converter::ConvertToInt(string s)
{
    if(std::to_string(atoi(s.c_str())) != s)
        printf("BAAA EROARE::::ConvertToInt(ceva ce nu e int)!!!!!!!!!!!!!!\n");

    return atoi(s.c_str());
}

float Converter::ConvertToFloat(string s)
{
    if(std::to_string(atof(s.c_str())) != s)
        printf("BAAA EROARE::::ConvertToFloat(ceva ce nu e float)!!!!!!!!!!!!!!\n");

    return atof(s.c_str());
}

bool Converter::ConvertToBool(string s)
{
    if(s.size() > 1 || s.size() == 0)
        printf("BAAA EROARE::::ConvertToBool(ceva ce nu e bool)!!!!!!!!!!!!!!\n");

    if(s[0] != '0' && s[0] != '1')
        printf("BAAA EROARE::::ConvertToBool(ceva ce nu e bool)!!!!!!!!!!!!!!\n");

    return s[0] - '0';
}