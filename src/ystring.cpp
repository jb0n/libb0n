
#include <string.h>

#include <b0n_settings.h>
#include <ystring.h>

//B0N_MAX_STACK_ALLOC

using namespace std;

namespace b0n {

ystring ystring::replace(const char *orig, const char *repl, int times)
{
    size_t orig_len = strlen(orig);
    string rstr = *this; //use a string for it's actual replace method
    while (times) //if times is -1 (default) just keep replacing
    {
        while (! times)
        {
            string::size_type rpos = rstr.find(orig);
            if (string::npos == rpos)
            {
                break;
            }
            rstr.replace(rpos, orig_len, repl);
            if (-1 != times)
            {
                --times;
            }                
        }
    }
    return rstr;
}

} //b0n namespace

