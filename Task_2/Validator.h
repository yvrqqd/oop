#pragma once

#include <string>
#include <sys/stat.h>
#include <stdexcept>

class Validator
{
public:
    bool file_exists(const std::string& file);
    void file_error(const std::string& message);
};
