#include "Parser.h"


Worker *Parser::make_block(const std::string &arg0) {
    std::vector<std::string> args;
    std::string a;
    args.push_back(arg0);
    if (args[0] == "readfile") {
        stream >> a;
        args.push_back(a);
        auto *temp = new Reader(args[1]);
        Worker *prod = temp;
        return prod;
    } else if (args[0] == "writefile") {
        stream >> a;
        args.push_back(a);
        auto *temp = new Writer(args[1]);
        Worker *prod = temp;
        return prod;
    } else if (args[0] == "grep") {
        stream >> a;
        args.push_back(a);
        auto *temp = new GrepBlock(args[1]);
        Worker *prod = temp;
        return prod;
    } else if (args[0] == "sort") {
        auto *temp = new SortBlock;
        Worker *prod = temp;
        return prod;
    } else if (args[0] == "replace") {
        stream >> a;
        args.push_back(a);
        stream >> a;
        args.push_back(a);
        auto *temp = new ReplaceBlock(args[1], args[2]);
        Worker *prod = temp;
        return prod;
    } else if (args[0] == "dump") {
        stream >> a;
        args.push_back(a);
        auto *temp = new DumpBlock(args[1]);
        Worker *prod = temp;
        return prod;
    } else {
        Validator::file_error("Wrong function name. Doesn't match to existing functions.");
    }
    return nullptr;
}

Parser::Parser(std::ifstream& stream1):stream(stream1) {

}

void Parser::parse_desc() {
    std::string str;
    stream >> str;
    if (str != "desc") {
        Validator::file_error("No \"desc\", wrong description format");
    }
    int index;
    while (true) {
        stream >> str;
        if (str == "csed") {
            break;
        }
        index = stoi(str);
        stream >> str;
        if (str != "=") {
            Validator::file_error("Wrong description format.");
        }
        stream >> str;
        commands[index] = make_block(str);
    }
}

void Parser::exec_queue() {
    std::string str;
    auto *input = new std::vector<std::string>, *output = new std::vector<std::string>;
    while (stream >> str) {
        if (str == "->")
            continue;
        commands[std::stoi(str)]->exec(input, output);
        input->clear();
        input = output;
        output = new std::vector<std::string>;
    }
}
