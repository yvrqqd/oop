#include "Sort.h"

bool SortBlock::exec(std::vector<std::string> *input, std::vector<std::string> *output) {
    (*output) = (*input);
    if(input->empty())
        return true;

    sort((*output).begin(), (*output).end(), std::greater<std::string>());
    return true;
}
