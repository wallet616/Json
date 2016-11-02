#include <stdio.h>
#include <iostream>
#include "Json.h"

using namespace std;

int main(int argc, char** argv)
{
    Node a;

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

    printf("hello world\n");
    return 0;
}
