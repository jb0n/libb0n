
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

