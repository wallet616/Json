#include <iostream>
#include "Json.h"
#include "JsonTest.h"

using namespace std;

int main(int argc, char** argv)
{
    NodeTest node_test;
    node_test.run_test();

    cout << endl << endl;

    Node a;
    a.add(Json_char({ "klucz", "wartosc" }));
    a.add(Json_char({ "klucz", "nowe" }));
    a.add(Json_char({ "klucz3", "wartosc" }));
    a.add(Json_char({ "klucz1", "wartosc" }));
    a.add(Json_char({ "klucz2", "wartosc" }));
    a.add(Json_char({ "klucz0", "wartosc" }));
    a.add(Json_char({ "ka", "wartosc" }));
    a.add(Json_char({ "z", "wartosc" }));
    // a.add(Json_char({ "", "sfdg" }));

    for(long found_id = 0; found_id < a.json_char_ammount; found_id++) {
        std::cout << found_id << "# values: {" << a.json_char_list[found_id]->key << ", "
                  << a.json_char_list[found_id]->value << "}" << std::endl;
    }

    /*
    Node a, b;

    a.add(Json_char{ "dasd", "dasaaasdasdasda" });
    // cout << "jed" << endl;
    a.add(Json_char{ "dad", "aa" });
    // cout << "dwa" << endl;
    a.add(Json_char{ "aa", "bb" });
    // cout << "trza" << endl;
    a.add(Json_char{ "dasd", "gsfdgvvvvvvv" });

    a.add(Json_long{ "aaz", 5 });
    a.add(Json_bool{ "aaz", false });

    char* ss = a.getChar("dasd");
    long z = a.getLong("aaz");

    cout << ss << endl;
    cout << z << endl;
    cout << a.getChar("dad") << endl;

    long dad;
    cout << "key: " << a.findKey("aa", dad) << endl;
    cout << "key: " << dad << endl;
    */

    // std::cout << "Press enter to continue ...";
    // std::cin.get();

    return 0;
}
