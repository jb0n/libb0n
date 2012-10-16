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

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#include <stdexcept>
#include <algorithm>
#include <functional>
#include <locale>

#include <b0n_settings.h>
#include <ystring.h>

using namespace std;

namespace b0n {

ystring ystring::replace(const char *orig, const char *repl, int times)
{
    size_t orig_len = strlen(orig);
    string rstr = *this; //use a string for it's actual replace method
    while (times)
    {
        string::size_type rpos = rstr.find(orig);
        if (string::npos == rpos)
        {
            break;
        }
        rstr.replace(rpos, orig_len, repl);
        if (-1 == times)
        {
            continue;
        }
        --times;
    }
    return rstr;
}

vector<ystring> ystring::split(ystring delim, int max_fields)
{
    size_t delim_len = delim.size();

    string::size_type start = 0;
    string::size_type end = this->find(delim);
    string entry;
    size_t real_end = this->size();

    vector<ystring> ret;
    while (start != end || end < real_end)
    {
        if (string::npos == end)
        {
            entry = string(*this, start);
            ret.push_back(entry);
            break;
        }

        entry = string(*this, start, end - start);
        ret.push_back(entry);

        start = end + delim_len;
        end = this->find(delim, start);

        if (max_fields > 0)
        {
            if ((int)ret.size() == (max_fields)) //get the last one
            {
                entry = string(*this, start, this->size() - start);
                ret.push_back(entry);
                break;
            }
        }
    }
    return ret;
}

ystring &ystring::format(const char *fmt, ...)
{
    char buff[B0N_MAX_STACK_ALLOC];
    va_list vargs;
    va_start(vargs, fmt);
    int ret = vsnprintf(buff, sizeof(buff), fmt, vargs);
    va_end(vargs);

    if (ret < 0)
    {
        throw runtime_error("Something strange went on (vsnprintf ret -1)");
    }
    else if (sizeof(buff) > (size_t)ret) //it worked
    {
        *this = buff;
        return *this;
    }

    //16k failed, try to get some heap memory to do it with
    size_t needed = ret + 1;
    char *pbuf = new char[needed];
    va_start(vargs, fmt);
    ret = vsnprintf(pbuf, needed, fmt, vargs);
    va_end(vargs);

    if (ret < 0)
    {
        delete[] pbuf;
        throw runtime_error("Something strange went on (vsnprintf ret -1)");
    }
    else if (needed > (size_t)ret)
    {
        delete[] pbuf;
        throw runtime_error("Something strange went on (vsnprintf misreported "
                            "size!?)");
    }
    *this = pbuf;
    delete[] pbuf;
    return *this;
}

ystring ystring::rstrip()
{
    ystring ret = *this;
    ret.erase(find_if(ret.rbegin(), ret.rend(),
              not1(ptr_fun<int, int>(isspace))).base(), ret.end());
    return ret;
}

ystring ystring::lstrip()
{
    ystring ret = *this;
    ret.erase(ret.begin(), find_if(ret.begin(), ret.end(), 
              not1(ptr_fun<int, int>(isspace))));
    return ret;              
}

ystring ystring::strip()
{
    return this->lstrip().rstrip();
}

bool ystring::startswith(const ystring &start)
{
    size_t startlen = start.length();
    if (length() < startlen)
    {
        return false;
    }
    return (0 == compare(0, startlen, start)); 
}

bool ystring::endswith(const ystring &end)
{
    size_t endlen = end.length();
    if (length() < endlen)
    {
        return false;
    }
    return (0 == compare(length() - endlen, endlen, end));
}


} //b0n namespace

