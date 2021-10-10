#include <fstream>
#include "TritSet.h"


using namespace std;
using namespace tritset;

TritSet::Tritset(size_t numOfTrits) {
    this->length = (numOfTrits / 4) / sizeof(size_t) + 1;
    this->data;
}
TrisSet::vector<unsigned int> arr;

void TritSet::capacity() {

}

void TritSet::shrink() {

}

void TritSet::cardinality(Trit value) {
    //std::unordered_map<Trit, int, std::hash<int> > cardinality();
}

size_t TritSet::trim(size_t lastIndex) {

}

size_t TrisSet::length();

}
TritProxy TritSet::operator[](size_t idx) {
    return false;
}
TritProxy::TritProxy(Trit trit) {
//todo
}
bool TritProxy::operator==(Trit trit) const{
    return false;
}
bool TritProxy::operator()(Trit trit) const{
    return false;
}
bool TritProxy::operator!(Trit trit) const{
    return false;
}
bool TritProxy::operator&(Trit trit) const{
    return false;
}
bool TritProxy::operator|(Trit trit) const{
    return false;
}
