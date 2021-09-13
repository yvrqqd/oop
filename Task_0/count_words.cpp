#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <regex>

using namespace std;

int main(int argc, char **argv) {
    if (argc < 2)
        return 1;

    const regex pattern("[a-zA-Z0-9]+");
    const string filename_in = argv[1];
    const string filename_out = argv[2];

    int counter = 0;
    string tmp_line;
    unordered_map<string, int> words;
    ifstream file_in(filename_in);

    if (not file_in.is_open())
        return 1;
    
    while (getline(file_in, tmp_line)) {
        sregex_iterator it = sregex_iterator(tmp_line.begin(), tmp_line.end(), pattern);
        while (it != sregex_iterator()) {
            auto coincidence = words.find((*it).str());
            if (coincidence != words.end())
                coincidence->second += 1;
            else
                words.insert({(*it).str(), 1});
            counter++;
            it++;
        }
    }

    vector<pair<string, int>> vectorized;
    vectorized.reserve(words.size());
    for (const auto &word: words)
        vectorized.emplace_back(word);

    sort(vectorized.begin(), vectorized.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });

    ofstream file_out(filename_out);
    if (file_in.is_open())
        for (const auto &elem: vectorized)
            file_out << elem.first << "," << elem.second << ","
                     << (double) elem.second / counter * 100 << "\n";

    return 0;
}
