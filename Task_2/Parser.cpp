#include "Parser.h"

Worker *Parser::make_block(const std::string &arg0) {
    std::vector<std::string> args;
    std::string a;
    args.push_back(arg0);
    switch(args[0]){
        case "readfile":
            stream>>a;
            args.push_back(a);
            auto* temp = new Reader(args[1]);
            Worker* prod = temp;
            return prod;
            
        case "writefile":
            stream>>a;
            args.push_back(a);
            auto *temp = new Writer(args[1]);
            Worker* prod = temp;
            return prod;
            
        case "grep":
            stream>>a;
            args.push_back(a);
            auto* temp = new GrepBlock(args[1]);
            Worker* prod = temp;
            return prod;
            
        case "sort":
            auto* temp = new Sort;
            Worker* prod = temp;
            return prod;
            
        case "replace":
            stream>>a;
            args.push_back(a);
            stream>>a;
            args.push_back(a);
            auto *temp = new Replace(args[1],args[2]);
            Worker* prod = temp;
            return prod;
            
        case args[0] == "dump":
            stream>>a;
            args.push_back(a);
            auto *temp = new Dump(args[1]);
            Worker* prod = temp;
            return prod;
    
        default:
            Validator::badFile("Wrong function name. Doesn't match to existing functions.");
    }
}

void Parser::parse_desc() {
    string str;
    stream>>str;
    if (str != "desc"){
        Validator::badFile("No \"desc\", wrong description format");
    }
    int index;
    while (true){
        stream >> str;
        if (str == "csed") {
            break;
        }
        index = stoi(str);
        stream >> str;
        if (str != "=") {
            Validator::badFile("Wrong description format.");
        }
        stream >> str;
        commands[index] = make_block(str);
    }
}
