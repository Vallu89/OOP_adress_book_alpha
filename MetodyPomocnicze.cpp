#include "MetodyPomocnicze.h"
#include <iostream>
#include <sstream>



string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
