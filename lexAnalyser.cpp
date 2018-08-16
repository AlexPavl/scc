#include <vector>
#include <string>
#include <iostream>
#include <set>
#include "error.hpp"

template <class Type>
bool isSetContains(std::set<Type> &Set, 
                    Type &obj)
{
    if (Set.count(obj)) {
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
std::set<char> operators = {
    '=', '+', '-', '*', '/', '(', ')', ';', ',', '{', '}'
};

std::vector<Symbol_Info> symbTable;

enum class ELEM_TYPE {
    NONE= 0,
    VAR, /* variable */
    OPER, /* operator */
    NUM /* number */
};

static void analyse(char ch)
{
    static std::string temp = "";
    static ELEM_TYPE curType = ELEM_TYPE::NONE;
    if (ELEM_TYPE::NONE == curType && "" == temp ) {
        if ((ch >= 'A' && ch <= 'Z') || /*[A...Z]*/
            (ch >= 'a' && ch <= 'z') ||   /* [a...z] */
            ch == '_')  {/* [_] */
            temp += ch;
            curType = ELEM_TYPE::VAR;
        }
        else if (ch >= '0' && ch <= '9') {
            temp += ch;
            curType = ELEM_TYPE::NUM;
        }
        else if (ch == ' ') {
            return;
        }

    }
    else if (ELEM_TYPE::VAR == curType) {

    }
    else if (ELEM_TYPE::NUM == curType) {

    }
}

unsigned lexicAnalyser(std::istream &in)
{
    std::string input = "";
    char inC;
    bool startedWord = false;
    while(!in.eof()) {
        inC = in.get();
        analyse(inC);     
    }
}

