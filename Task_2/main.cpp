#include <iostream>
#include "Parser.cpp"

int main(int argc, char *argv[]) {
    std::ifstream stream("../workflow.txt");
    if (!Validator::file_exists("../workflow.txt")){
        throw std::invalid_argument("workflow.txt does not exist");
    }
    Parser Parser(stream);
    Parser.parse_desc();
    Parser.exec_queue();

    return 0;
}

