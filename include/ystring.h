/*
Copyright (c) 2012, jb0n
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies, 
either expressed or implied, of the FreeBSD Project.
*/


#ifndef YSTRING_H_INCLUDED
#define YSTRING_H_INCLUDED

#include <string>
#include <vector>

namespace b0n {

class ystring: public std::string {
public:
    //these are the only pieces of functionality ystring has over std::string
    ystring &format(const char *, ...); //vsnprintf wrapper

    //these are all python work-alikes.
    ystring replace(const char*, const char*, int times=-1);
    std::vector<ystring> split(ystring, int max_fields=-1);
    ystring rstrip();
    ystring lstrip();
    ystring strip();
    bool startswith(const ystring&);
    bool endswith(const ystring&);

    //std::string c'tors
    ystring() {}
    ystring(const char *in): std::string(in) {}


    //override assignment ops
    ystring(const std::string &str): std::string(str) {}
};

} //b0n namespace


#endif //YSTRING_H_INCLUDED

