#include <vector>
#include <string>
#include <iostream>
#include <set>
#include "error.hpp"
#include <cmath>

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
    '=', '+', '-', '*', '/', '(', ')', ';', ',', '{', '}', '"', '\'', '<', '>'
};

std::vector<Symbol_Info> symbTable;

std::vector<double> tableNum;
std::vector<std::string> tableVar;
std::vector<std::string> tableOp;
std::vector<std::string> tableKeyW;


enum class ELEM_TYPE {
    NONE= 0,
    VAR, /* variable */
    OPER, /* operator */
    NUM /* number */
};

static void result(std::string& input, 
                    ELEM_TYPE   type) 
{
    if (input != "" || input != " " || input != "\n")
    switch (type) {
        case ELEM_TYPE::NUM :
        {
            double val = atof(input.c_str());
            tableNum.push_back(val);
            /* define which type of number */
            break;
        }
        case ELEM_TYPE::VAR :
            if (isSetContains(keywords, input)) {
                tableKeyW.push_back(input);
            }
            else {
                tableVar.push_back(input);
            }
            /* save in symbols table  */
            break;
        case ELEM_TYPE::OPER :
            /* for now dont know */
            break;
        default:
            std::cerr << "Unknown type" << std::endl;
            /* something wrong */
    }
}

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
        else if (ch == ' ' || '\n' == ch) {
            return;
        }
        else if (isSetContains(operators, ch)) {
            temp += ch;
            tableOp.push_back(temp);
            temp = "";
        }

    }
    else if (ELEM_TYPE::VAR == curType) {
        if ((ch >= 'A' && ch <= 'Z') || /*[A...Z]*/
            (ch >= 'a' && ch <= 'z') ||   /* [a...z] */
            ch == '_' || /* [_] */
            (ch >= '0' && ch <= '9'))  {
            temp += ch;
        }
        else if (isSetContains(operators, ch) || ' ' == ch || '\n' == ch) {
            result(temp, curType);
            temp = "";
            if (' ' != ch && '\n' != ch) {
                temp += ch;
                tableOp.push_back(temp);
                temp = "";
            }
            curType = ELEM_TYPE::NONE;
        }
    }
    else if (ELEM_TYPE::NUM == curType) {
        if ((ch >= 'A' && ch <= 'Z') || /*[A...Z]*/
            (ch >= 'a' && ch <= 'z') ||   /* [a...z] */
            ch == '_')  {/* [_] */
            compError("Variable started with numbers");
        }
        else if (isSetContains(operators, ch) || ' ' == ch || '\n' == ch) {
            result(temp, curType);
            temp = "";
            if (' ' != ch && '\n' != ch) {
                temp += ch;
                tableOp.push_back(temp);
                temp = "";
                curType = ELEM_TYPE::NONE;
            }
        }
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
    std::cout << "*******************Keywords:\n";
    for (auto x : tableKeyW) {
        std::cout << "-" <<x << '\n';
    }
    std::cout << "*******************operators:\n";
    for (auto x : tableOp) {
        std::cout << "-" << x << '\n';
    }
    std::cout << "*******************Variables:\n";
    for (auto x : tableVar) {
        std::cout << "-" << x << '\n';
    }
    std::cout << "*******************Numbers:\n";
    for(auto x : tableNum) {
        std::cout << "-" << x << '\n';
    }
}

