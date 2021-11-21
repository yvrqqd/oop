std::ostream& operator<<(std::ostream& os, Trit a) {

    if (a == Trit::True)
        os << "True";

    if (a == Trit::False)
        os << "False";

    return os << "Unknown";
}

Trit operator&(Trit a, Trit b)
{
    if (a == Trit::False || b == Trit::False)
        return Trit::False;

    if (a == Trit::Unknown || b == Trit::Unknown)
        return Trit::Unknown;
    
    return Trit::True;
}

Trit operator|(Trit a, Trit b)
{
    if (a == Trit::True || b == Trit::True)
        return Trit::True;
    
    if (a == Trit::Unknown || b == Trit::Unknown)
        return Trit::Unknown;
    
    return Trit::False;
}


Trit operator!(Trit a)
{
    if(a == Trit::True)
        return Trit::False;
    
    if(a == Trit::False)
        return Trit::True;
    
    return Trit::Unknown;
}
