
#ifndef UT_YSTRING_INCLUDED
#define UT_YSTRING_INCLUDED

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include <ystring.h>

class YstringTestCase: public CppUnit::TestCase
{
    CPPUNIT_TEST_SUITE(YstringTestCase);
        CPPUNIT_TEST(checkConstructing);
    CPPUNIT_TEST_SUITE_END();

protected:
    void checkConstructing();
};


#endif //UT_YSTRING_INCLUDED
