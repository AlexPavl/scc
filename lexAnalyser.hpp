#ifndef LEX_ANALYZER_HPP_
#define LEX_ANALYZER_HPP_
#include <iostream>



struct Symbol_Info {
    std::string name;       /* name of object */
    unsigned    type;
    unsigned    initLine;   /* which line init */
};


unsigned lexicAnalyser(std::istream &in);







#endif /* LEX_ANALYZER_HPP_ */