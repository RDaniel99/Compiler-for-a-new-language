#include <string>

class Converter
{
public:
    static std::string ConvertFromInt(int x);
    static std::string ConvertFromFloat(float f);
    static std::string ConvertFromBool(bool b);

    static int         ConvertToInt(std::string s);
    static float       ConvertToFloat(std::string s);
    static bool        ConvertToBool(std::string s);
};