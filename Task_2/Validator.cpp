#include "Validator.h"

bool Validator::file_exists(const std::string& File) {
    struct stat buf{};
    return (stat (File.c_str(), &buf) == 0);
}
void Validator::file_error(const std::string& message) {
    throw invalid_argument("Error in file " + message);
}
