#pragma once

enum class Trit {False = -1, Unknown, True};

Trit operator&(Trit t1, Trit t2);
Trit operator|(Trit t1, Trit t2);
Trit operator!(Trit t1);
std::ostream& operator<<(std::ostream& os, trit t);
