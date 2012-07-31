
#include <string.h>

#include <b0n_settings.h>
#include <ystring.h>

#include <iostream>

//B0N_MAX_STACK_ALLOC

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

    vector<ystring> ret;
    while (start != end)
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
            if ((int)ret.size() == (max_fields-1)) //get the last one
            {
                entry = string(*this, start, this->size() - start);
                ret.push_back(entry);
                break;
            }
        }
    }
    return ret;
}


} //b0n namespace

