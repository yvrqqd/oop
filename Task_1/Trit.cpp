#include "Trit.h"

Trit operator&(Trit t1, Trit t2)
{
    if (t1 == Trit::False || t2 == Trit::False)
        return Trit::False;

    if (t1 == Trit::Unknown || t2 == Trit::Unknown)
        return Trit::Unknown;
    
    return Trit::True;
}

Trit operator|(Trit t1, Trit t2)
{
    if (t1 == Trit::True || t2 == Trit::True)
        return Trit::True;
    
    if (t1 == Trit::Unknown || t2 == Trit::Unknown)
        return Trit::Unknown;
    
    return Trit::False;
}


Trit operator!(Trit t)
{
    if(t == Trit::True)
        return Trit::False;
    
    if(t == Trit::False)
        return Trit::True;
    
    return Trit::Unknown;
}

std::ostream& operator<<(std::ostream& os, Trit t)
{
    if (t == Trit::True)
        os << "True";

    if (t == Trit::False)
        os << "False";

    return os << "Unknown";
}
