#include <vector>
#include <string>
#include <iostream>
#include <set>


bool isSetContains(std::set<std::string> &Set, 
                    std::string &str)
{
    if (Set.count(str)) {
        return true;
    }
    else {
        return false;
    }
}

struct Token {
    std::string type;   /* token type  */
    unsigned    id;     /* symbol's table number */
};

struct Symbol_Info {
    std::string name;       /* name of object */
    unsigned    type;
    unsigned    initLine;   /* which line init */
};
/* need full keywords' table */
std::set<std::string> keywords = {
    "auto", "break", "case", "char",
    "const", "continue", "default", "do",
    "double", "else", "enum", "extern",
    "float", "for", "goto", "if",
    "int", "long",	"register",	"return",
    "short", "signed", "sizeof", "static",
    "struct", "switch",	"typedef", "union",
    "unsigned", "void", "volatile", "while"
};
/* small operators' table */
std::set<std::string> operators = {
    "=", "+", "-", "*", "/"
};

std::vector<Symbol_Info> symbTable;

unsigned lexicAnalyser(std::istream &in)
{
    std::string input;
    while(!in.eof()) {
        in >> input;
        if (isSetContains(keywords, input)) {
            std::cout << "keyword " << input << '\n';
        }
        else if (isSetContains(operators, input)) {
            std::cout << "operator " << input << '\n';
        }
        else {
            std::cout << "something other " << input << '\n';
        }
    }
}

