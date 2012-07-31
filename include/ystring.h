#ifndef YSTRING_H_INCLUDED
#define YSTRING_H_INCLUDED

#include <string>
#include <vector>

namespace b0n {

class ystring: public std::string {
public:
    //these are the only pieces of functionality ystring has over std::string
    ystring replace(const char*, const char*, int times=-1); //works like python
    ystring &format(const char *, ...); //vsnprintf wrapper
    std::vector<ystring> split(ystring, int max_fields=-1); //works like python


    //std::string c'tors
    ystring() {}
    ystring(const char *in): std::string(in) {}


    //override assignment ops
    ystring(const std::string &str): std::string(str) {}
};

} //b0n namespace


#endif //YSTRING_H_INCLUDED

