#include "Json.h"
#include "JsonTest.h"
#include <iostream>

//
// Json test
//
void JsonTest::run_test()
{
    std::cout << "Json tests:" << std::endl;

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

    /// Json adding methods tests:
    std::cout << std::endl << "> Json adding methods tests:" << std::endl;

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

    // Since this point, i have to use findKey(), but i can not test it without adding
    // anything before.
    // TODO: Fix it, if it is possible.
    std::cout << " * bool add(const Json_char& object):" << std::endl;
    {
        long fails = 0;

        Json a;
        a.add(Json_char({ "key", "default" }));
        a.add(Json_char({ "key1", "value" }));
        a.add(Json_char({ "key3", "not value" }));
        a.add(Json_char({ "key1", "new val" }));
        a.add(Json_char({ "", "err" }));
        a.add(Json_char({ "key2", "task" }));
        a.add(Json_char({ "key0", "tusk" }));
        a.add(Json_char({ "ke", "string 123456" }));
        a.add(Json_char({ "z", "another val" }));
        a.add(Json_char({ "key2", "qwerty 123" }));

        // for(long found_id = 0; found_id < a.json_char_ammount; found_id++) {
        //    std::cout << found_id << "# values: {" << a.json_char_list[found_id]->key << ", "
        //              << a.json_char_list[found_id]->value << "}" << std::endl;
        // }

        // Output shoudl resoult with:
        // 0# values: {ke, string 123456}
        // 1# values: {key, default}
        // 2# values: {key0, tusk}
        // 3# values: {key1, new val}
        // 4# values: {key2, qwerty 123}
        // 5# values: {key3, not value}
        // 6# values: {z, another val}
        // { "", "err" } is not added because of invalid key.

        if(charIsEqual(a.json_char_list[0]->key, charGetDynamic("ke")) == false)
            fails++;
        if(charIsEqual(a.json_char_list[0]->value, charGetDynamic("string 123456")) == false)
            fails++;

        if(charIsEqual(a.json_char_list[3]->key, charGetDynamic("key1")) == false)
            fails++;
        if(charIsEqual(a.json_char_list[3]->value, charGetDynamic("new val")) == false)
            fails++;

        if(charIsEqual(a.json_char_list[5]->key, charGetDynamic("key3")) == false)
            fails++;
        if(charIsEqual(a.json_char_list[5]->value, charGetDynamic("not value")) == false)
            fails++;

        if(charIsEqual(a.json_char_list[6]->key, charGetDynamic("z")) == false)
            fails++;
        if(charIsEqual(a.json_char_list[6]->value, charGetDynamic("another val")) == false)
            fails++;

        if(fails == 0)
            std::cout << "  - succes" << std::endl;
        else
            std::cout << "  - failed" << std::endl;
    }

    std::cout << " * bool add(const Json_long& object):" << std::endl;
    {
        long fails = 0;

        Json a;
        a.add(Json_long({ "", 123 }));
        a.add(Json_long({ "long1", 123 }));
        a.add(Json_long({ "long0", 456 }));
        a.add(Json_long({ "lo", 25 }));
        a.add(Json_long({ "ng", 67 }));

        // for(long found_id = 0; found_id < a.json_long_ammount; found_id++) {
        //    std::cout << found_id << "# values: {" << a.json_long_list[found_id]->key << ", "
        //              << a.json_long_list[found_id]->value << "}" << std::endl;
        // }

        // Output shoudl resoult with:
        // 0# values: {lo, 25}
        // 1# values: {long0, 456}
        // 2# values: {long1, 123}
        // 3# values: {ng, 67}
        // { "", "err" } is not added because of invalid key.

        if(charIsEqual(a.json_long_list[0]->key, charGetDynamic("lo")) == false)
            fails++;
        if(a.json_long_list[0]->value != 25)
            fails++;

        if(charIsEqual(a.json_long_list[3]->key, charGetDynamic("ng")) == false)
            fails++;
        if(a.json_long_list[3]->value != 67)
            fails++;

        if(fails == 0)
            std::cout << "  - succes" << std::endl;
        else
            std::cout << "  - failed" << std::endl;
    }
    
    std::cout << " * bool add(const Json_bool& object):" << std::endl;
    {
        long fails = 0;

        Json a;
        a.add(Json_bool({ "", 0 }));
        a.add(Json_bool({ "bool1", 1 }));
        a.add(Json_bool({ "bool0", 0 }));
        a.add(Json_bool({ "bo", true }));
        a.add(Json_bool({ "ol", false }));

        // for(long found_id = 0; found_id < a.json_bool_ammount; found_id++) {
        //    std::cout << found_id << "# values: {" << a.json_bool_list[found_id]->key << ", "
        //              << a.json_bool_list[found_id]->value << "}" << std::endl;
        // }

        // Output shoudl resoult with:
        // 0# values: {bo, 1}
        // 1# values: {bool0, 0}
        // 2# values: {bool1, 1}
        // 3# values: {ol, 0}
        // { "", 0 } is not added because of invalid key.

        if(charIsEqual(a.json_bool_list[0]->key, charGetDynamic("bo")) == false)
            fails++;
        if(a.json_bool_list[0]->value != 1)
            fails++;
            

        if(charIsEqual(a.json_bool_list[3]->key, charGetDynamic("ol")) == false)
            fails++;
        if(a.json_bool_list[3]->value != 0)
            fails++;

        if(fails == 0)
            std::cout << "  - succes" << std::endl;
        else
            std::cout << "  - failed" << std::endl;
    }
}