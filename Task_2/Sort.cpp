#include "Sort.h"

bool SortBlock::exec(std::vector<std::string> *input, std::vector<std::string> *output,
                     bool &contain_input, bool &contain_output, unsigned int index)
{
    if(!contain_input)
        throw logic_error("No input on sort, block index: " + to_string(index));
    (*output) = (*input);
    if(input->empty())
        return true;

    sort((*output).begin(), (*output).end(), greater<string>());

    contain_output = true;
    return true;
}
