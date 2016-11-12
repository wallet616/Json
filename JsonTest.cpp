#include "Json.h"
#include "JsonTest.h"
#include <iostream>

//
// Node test
//
void NodeTest::run_test()
{
    std::cout << "Node tests:" << std::endl;

    /// Static char* tests:
    std::cout << std::endl << "> Static char* tests:" << std::endl;

    std::cout << " * static char* charGetDynamic(const char charTable[]):" << std::endl;
    {
        long fails = 0;

        char str1[] = "qwerty 123 ";
        char str2[] = "";

        char* str_t1 = charGetDynamic(str1);
        char* str_t2 = charGetDynamic(str1);

        long c1 = 0;
        while(str1[c1] != '\0')
            c1++;
        long c2 = 0;
        while(str_t1[c2] != '\0')
            c2++;

        if(c1 != c2)
            fails++;
        else
            for(long i = 0; i < c1 + 1; i++)
                if(str1[i] != str_t1[i])
                    fails++;

        if(&str_t1 == &str_t2)
            fails++;

        delete str_t1;
        str_t1 = charGetDynamic(str2);

        delete str_t2;
        str_t2 = charGetDynamic(str2);

        if(&str_t1 == &str_t2)
            fails++;

        delete str_t1;
        delete str_t2;

        if(fails == 0)
            std::cout << "  - succes" << std::endl;
        else
            std::cout << "  - failed" << std::endl;
    }

    std::cout << " * static char* charDuplicate(const char* key):" << std::endl;
    {
        long fails = 0;

        char* str1 = charGetDynamic("qwert 123");
        char* str2 = charGetDynamic("");
        char* str3;

        str3 = charDuplicate(str1);

        long c1 = 0;
        while(str3[c1] != '\0')
            c1++;
        long c2 = 0;
        while(str3[c2] != '\0')
            c2++;

        if(c1 != c2)
            fails++;
        else
            for(long i = 0; i < c1 + 1; i++)
                if(str1[i] != str3[i])
                    fails++;

        delete str3;
        str3 = charDuplicate(str1);
        if(&str1 == &str3)
            fails++;

        delete str3;
        str3 = charDuplicate(str2);
        if(&str2 == &str3)
            fails++;

        delete str1;
        delete str2;
        delete str3;

        if(fails == 0)
            std::cout << "  - succes" << std::endl;
        else
            std::cout << "  - failed" << std::endl;
    }

    std::cout << " * static bool charIsEqual(const char* keyOne, const char* keyTwo):" << std::endl;
    {
        long fails = 0;

        char* str1 = charGetDynamic("qwert 123");
        char* str2 = charGetDynamic("");
        char* str3;

        if(charIsEqual(str1, str1) == false)
            fails++;

        if(charIsEqual(str2, str2) == false)
            fails++;

        if(charIsEqual(str1, str2) == true)
            fails++;

        str3 = charDuplicate(str1);
        if(charIsEqual(str1, str3) == false)
            fails++;

        delete str3;
        str3 = charDuplicate(str2);
        if(charIsEqual(str3, str2) == false)
            fails++;

        delete str1;
        delete str2;
        delete str3;

        if(fails == 0)
            std::cout << "  - succes" << std::endl;
        else
            std::cout << "  - failed" << std::endl;
    }

    std::cout << " * static bool charIsGreater(const char* keyOne, const char* keyTwo):" << std::endl;
    {
        long fails = 0;

        char* str1 = charGetDynamic("qwert 123");
        char* str2 = charGetDynamic("qwert 123 ");
        char* str3 = charGetDynamic("qWert 123 ");
        char* str4 = charGetDynamic("");

        if(charIsGreater(str1, str1) == true)
            fails++;

        if(charIsGreater(str4, str4) == true)
            fails++;

        if(charIsGreater(str1, str2) == true)
            fails++;

        if(charIsGreater(str2, str1) == false)
            fails++;

        if(charIsGreater(str1, str4) == false)
            fails++;

        if(charIsGreater(str4, str1) == true)
            fails++;

        if(charIsGreater(str2, str3) == false)
            fails++;

        if(charIsGreater(str3, str2) == true)
            fails++;

        delete str1;
        delete str2;
        delete str3;
        delete str4;

        if(fails == 0)
            std::cout << "  - succes" << std::endl;
        else
            std::cout << "  - failed" << std::endl;
    }

    /// Node adding methods tests:
    std::cout << std::endl << "> Node adding methods tests:" << std::endl;

    std::cout << " * bool keyIsVaild(const char* key) const:" << std::endl;
    {
        long fails = 0;

        if(keyIsVaild(charGetDynamic("qwert 123")) == false)
            fails++;

        if(keyIsVaild(charGetDynamic("1")) == false)
            fails++;

        if(keyIsVaild(charGetDynamic("")) == true)
            fails++;

        if(fails == 0)
            std::cout << "  - succes" << std::endl;
        else
            std::cout << "  - failed" << std::endl;
    }
}