#pragma once

#include <string>
#include <sys/stat.h>
#include <stdexcept>

class Validator {
public:
    static bool file_exists(const std::string& file);
    static void file_error(const std::string& message);
};
