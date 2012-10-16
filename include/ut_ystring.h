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
        CPPUNIT_TEST(checkReplace);
        CPPUNIT_TEST(checkSplit);
        CPPUNIT_TEST(checkFormat);
        CPPUNIT_TEST(checkLstrip);
        CPPUNIT_TEST(checkRstrip);
        CPPUNIT_TEST(checkStrip);
        CPPUNIT_TEST(checkStartsWith);
        CPPUNIT_TEST(checkEndsWith);
    CPPUNIT_TEST_SUITE_END();

protected:
    void checkConstructing();
    void checkReplace();
    void checkSplit();
    void checkFormat();
    void checkLstrip();
    void checkRstrip();
    void checkStrip();
    void checkStartsWith();
    void checkEndsWith();
};


#endif //UT_YSTRING_INCLUDED
