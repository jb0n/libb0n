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

#include <ut_ystring.h>

using namespace std;
using namespace CppUnit;
using namespace b0n;

CPPUNIT_TEST_SUITE_REGISTRATION(YstringTestCase);

void YstringTestCase::checkConstructing()
{
    ystring ystr1("xxx");
    CPPUNIT_ASSERT(ystr1 == "xxx");

    //new/delete
    ystring *ystr2 = new ystring("zzz");
    CPPUNIT_ASSERT(*ystr2 == "zzz");
    delete ystr2;

    ystring ystr3;
    ystr3 = "QQQ";
    CPPUNIT_ASSERT(ystr3 ==  "QQQ");

    //TODO: get the rest of the std::string constructors to test!
}

void YstringTestCase::checkReplace()
{
    ystring ystr("xxx");
    ystr = ystr.replace("x", "f");
    CPPUNIT_ASSERT(ystr == "fff");

    ystr = "abc_abc_abc";
    ystr = ystr.replace("abc", "XYZ", 2);
    CPPUNIT_ASSERT(ystr == "XYZ_XYZ_abc");
}

void YstringTestCase::checkSplit()
{
    ystring ystr;
    vector<ystring> tmp;
    vector<ystring> yv;
   
    ystr = "a,b,c";
    yv = ystr.split(",");
    tmp.push_back("a");
    tmp.push_back("b");
    tmp.push_back("c");
    CPPUNIT_ASSERT(yv == tmp);

    tmp.clear();
    ystr = "a,b,c";
    yv = ystr.split(",", 1);
    tmp.push_back("a");
    tmp.push_back("b,c");
    CPPUNIT_ASSERT(yv == tmp);

    tmp.clear();
    ystr = "1@@@2@@@3@@@@@@";
    yv = ystr.split("@@@");
    tmp.push_back("1");
    tmp.push_back("2");
    tmp.push_back("3");
    tmp.push_back("");
    tmp.push_back("");
    CPPUNIT_ASSERT(yv == tmp);
}

void YstringTestCase::checkFormat()
{
    ystring ystr;
    ystr.format("%s %d %s", "I have", 99, "problems");
    CPPUNIT_ASSERT("I have 99 problems" == ystr);
}

void YstringTestCase::checkLstrip()
{
    ystring tstr = "  xxx  ";
    ystring trimmed = tstr.lstrip();
    CPPUNIT_ASSERT("xxx  " == trimmed);
}
void YstringTestCase::checkRstrip()
{
    ystring tstr = "  xxx  ";
    ystring trimmed = tstr.rstrip();
    CPPUNIT_ASSERT("  xxx"  == trimmed);
}

void YstringTestCase::checkStrip()
{
    ystring tstr = "  xxx  ";
    ystring trimmed = tstr.strip();
    CPPUNIT_ASSERT("xxx" == trimmed);
}


int main(int, char**)
{
    // Get the top level suite from the registry
    Test *suite = TestFactoryRegistry::getRegistry().makeTest();

    // Adds the test to the list of test to run
    TextUi::TestRunner runner;
    runner.addTest(suite);

    // Change the default outputter to a compiler error format outputter
    runner.setOutputter(new CompilerOutputter(&runner.result(), std::cerr));
    // Run the tests.
    bool wasSucessful = runner.run();

    // Return error code 1 if the one of test failed.
    return wasSucessful ? 0 : 1;

}

