
#include <ut_ystring.h>

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

