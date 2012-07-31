
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

#include <b0n_settings.h>
#include <ystring.h>

#include <stdexcept>

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

} //b0n namespace

