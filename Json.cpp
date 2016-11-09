#include "Json.h"
#include <iostream>

//
// Node
//
Node::Node()
{
    this->key = charGetDynamic("");

    this->json_char_ammount = 0;
    this->json_char_list = 0x0;

    this->json_long_ammount = 0;
    this->json_long_list = 0x0;

    this->json_bool_ammount = 0;
    this->json_bool_list = 0x0;
}

Node::Node(const char* key)
{
    this->key = charDuplicate(key);

    this->json_char_ammount = 0;
    this->json_char_list = 0x0;

    this->json_long_ammount = 0;
    this->json_long_list = 0x0;

    this->json_bool_ammount = 0;
    this->json_bool_list = 0x0;
}

Node::~Node()
{
    delete this->key;

    for(long i = 0; i < this->json_char_ammount; i++) {
        delete this->json_char_list[i];
    }
    delete[] this->json_char_list;

    for(long i = 0; i < this->json_long_ammount; i++) {
        delete this->json_long_list[i];
    }
    delete[] this->json_long_list;

    for(long i = 0; i < this->json_bool_ammount; i++) {
        delete this->json_bool_list[i];
    }
    delete[] this->json_bool_list;
}

// Methods
enum Node::data_type Node::findKey(const char* key, long& assigns_id_from_table) const
{
    if(charIsEqual(this->key, key)) {
        assigns_id_from_table = -1;
        return NODE;
    }

    for(long i = 0; i < this->json_long_ammount; i++) {
        if(charIsEqual(key, this->json_long_list[i]->key)) {
            assigns_id_from_table = i;
            return LONG;
        }
    }

    for(long i = 0; i < this->json_bool_ammount; i++) {
        if(charIsEqual(key, this->json_bool_list[i]->key)) {
            assigns_id_from_table = i;
            return BOOL;
        }
    }

    for(long i = 0; i < this->json_char_ammount; i++) {
        if(charIsEqual(key, this->json_char_list[i]->key)) {
            assigns_id_from_table = i;
            return CHAR;
        }
    }

    return NOT_EXIST;
}

// Static char*
char* Node::charDuplicate(const char* key)
{
    long newSize = 0;
    while(key[newSize] != '\0')
        newSize++;
    newSize += 1;

    char* newTable = new char[newSize];
    for(long i = 0; i < newSize; i++)
        newTable[i] = key[i];

    return newTable;
}

bool Node::charIsEqual(const char* keyOne, const char* keyTwo)
{
    long c1 = 0;
    while(keyOne[c1] != '\0')
        c1++;

    long c2 = 0;
    while(keyTwo[c2] != '\0')
        c2++;

    if(c1 != c2)
        return false;
    else {
        c1 += 1;
        for(long i = 0; i < c1; i++)
            if(keyOne[i] != keyTwo[i])
                return false;
    }

    return true;
}

bool Node::charIsGreater(const char* keyOne, const char* keyTwo)
{
    long c1 = 0;
    while(keyOne[c1] != '\0')
        c1++;

    long c2 = 0;
    while(keyTwo[c2] != '\0')
        c2++;

    long c = (c1 > c2) ? c2 + 1 : c1 + 1;
    for(long i = 0; i < c; i++)
        if(keyOne[i] > keyTwo[i])
            return true;
        else if(keyOne[i] < keyTwo[i])
            return false;
        else
            continue;

    return false;
}

char* Node::charGetDynamic(const char charTable[])
{
    long c = 0;
    while(charTable[c] != '\0')
        c++;
    c += 1;

    char* new_table = new char[c];
    for(long i = 0; i < c; i++) {
        new_table[i] = charTable[i];
    }

    return new_table;
}

//
// Node test
//
void NodeTest::run_test()
{
    std::cout << "Node tests:" << std::endl;

    /// Static char* tests:
    std::cout << "> Static char* tests:" << std::endl;

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
            std::cout << "      succes" << std::endl;
        else
            std::cout << "      failed" << std::endl;
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
            std::cout << "      succes" << std::endl;
        else
            std::cout << "      failed" << std::endl;
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
            std::cout << "      succes" << std::endl;
        else
            std::cout << "      failed" << std::endl;
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
            std::cout << "      succes" << std::endl;
        else
            std::cout << "      failed" << std::endl;
    }
}

/*
enum Node::data_type Node::findKey(const char* key, long& assigns_id_from_table) const
{
    if(this->key == key) {
        assigns_id_from_table = -1;
        return NODE;
    }

    for(long i = 0; i < this->nodes_ammount; i++) {
        if(key == this->nodes_list[i]->key) {
            assigns_id_from_table = i;
            return NODE;
        }
    }

    for(long i = 0; i < this->json_long_ammount; i++) {
        if(key == this->json_long_list[i]->key) {
            assigns_id_from_table = i;
            return LONG;
        }
    }

    for(long i = 0; i < this->json_bool_ammount; i++) {
        if(key == this->json_bool_list[i]->key) {
            assigns_id_from_table = i;
            return BOOL;
        }
    }

    for(long i = 0; i < this->json_char_ammount; i++) {
        if(key == this->json_char_list[i]->key) {
            assigns_id_from_table = i;
            return CHAR;
        }
    }

    return NOT_EXIST;
}

bool Node::add(const Json_char& object)
{
    long id;
    Node::data_type type = this->findKey(object.key, id);

    if(type == NOT_EXIST) {
        long found_id = 0;
        Json_char** new_json_char_list = new Json_char*[this->json_char_ammount + 1];
        while(found_id < this->json_char_ammount) {
            if(object.key > this->json_char_list[found_id]->key) {
                new_json_char_list[found_id] = this->json_char_list[found_id];
                found_id++;
            } else
                break;
        }

        new_json_char_list[found_id] = new Json_char();
        new_json_char_list[found_id]->key = object.key;
        new_json_char_list[found_id]->value = object.value;

        for(found_id++; found_id < this->json_char_ammount; found_id++) {
            new_json_char_list[found_id] = this->json_char_list[found_id - 1];
        }

        delete[] this->json_char_list;
        this->json_char_list = new_json_char_list;
        this->json_char_ammount = found_id;

        return true;
    } else if(type == CHAR) {
        this->json_char_list[id]->key = object.key;
        this->json_char_list[id]->value = object.value;

        return true;
    } else {
        std::cerr << "Error: add: Key " << object.key << " holds another data type." << std::endl;

        return false;
    }
}

char* Node::getChar(const char* key) const
{
    for(long i = 0; i < this->json_char_ammount; i++) {
        if(key == this->json_char_list[i]->key) {
            return this->json_char_list[i]->value;
        }
    }
    std::cerr << "Error: getChar: Key " << key << " doesn't exist." << std::endl;
    return (char*)"";
}

bool Node::add(const Json_long& object)
{
    long id;
    data_type type = this->findKey(object.key, id);

    if(type == NOT_EXIST) {
        long found_id = 0;
        Json_long** new_json_long_list = new Json_long*[this->json_long_ammount + 1];
        while(found_id < this->json_long_ammount) {
            if(object.key > this->json_long_list[found_id]->key) {
                new_json_long_list[found_id] = this->json_long_list[found_id];
                found_id++;
            } else
                break;
        }

        new_json_long_list[found_id] = new Json_long();
        new_json_long_list[found_id]->key = object.key;
        new_json_long_list[found_id]->value = object.value;

        for(found_id++; found_id < this->json_long_ammount; found_id++) {
            new_json_long_list[found_id] = this->json_long_list[found_id - 1];
        }

        delete[] this->json_long_list;
        this->json_long_list = new_json_long_list;
        this->json_long_ammount = found_id;

        return true;
    } else if(type == LONG) {
        this->json_long_list[id]->key = object.key;
        this->json_long_list[id]->value = object.value;

        return true;
    } else {
        std::cerr << "Error: add: Key " << object.key << " holds another data type." << std::endl;

        return false;
    }
}

long Node::getLong(const char* key) const
{
    for(long i = 0; i < this->json_long_ammount; i++) {
        if(key == this->json_long_list[i]->key) {
            return this->json_long_list[i]->value;
        }
    }
    std::cerr << "Error: getLong: Key " << key << " doesn't exist." << std::endl;
    return 0;
}

bool Node::add(const Json_bool& object)
{
    long id;
    data_type type = this->findKey(object.key, id);

    if(type == NOT_EXIST) {
        long found_id = 0;
        Json_bool** new_json_bool_list = new Json_bool*[this->json_bool_ammount + 1];
        while(found_id < this->json_bool_ammount) {
            if(object.key > this->json_bool_list[found_id]->key) {
                new_json_bool_list[found_id] = this->json_bool_list[found_id];
                found_id++;
            } else
                break;
        }

        new_json_bool_list[found_id] = new Json_bool();
        new_json_bool_list[found_id]->key = object.key;
        new_json_bool_list[found_id]->value = object.value;

        for(found_id++; found_id < this->json_bool_ammount; found_id++) {
            new_json_bool_list[found_id] = this->json_bool_list[found_id - 1];
        }

        delete[] this->json_bool_list;
        this->json_bool_list = new_json_bool_list;
        this->json_bool_ammount = found_id;

        return true;
    } else if(type == BOOL) {
        this->json_bool_list[id]->key = object.key;
        this->json_bool_list[id]->value = object.value;

        return true;
    } else {
        std::cerr << "Error: add: Key " << object.key << " holds another data type." << std::endl;

        return false;
    }
}

bool Node::getBool(const char* key) const
{
    for(long i = 0; i < this->json_bool_ammount; i++) {
        if(key == this->json_bool_list[i]->key) {
            return this->json_bool_list[i]->value;
        }
    }
    std::cerr << "Error: getBool: Key " << key << " doesn't exist." << std::endl;
    return false;
}

bool Node::add(const Node& node)
{
    long id;
    data_type type = this->findKey(node.key, id);

    if(type == NOT_EXIST) {
        long found_id = 0;
        Node** new_nodes_list = new Node*[this->nodes_ammount + 1];
        while(found_id < this->nodes_ammount) {
            if(node.key > this->nodes_list[found_id]->key) {
                new_nodes_list[found_id] = this->nodes_list[found_id];
                found_id++;
            } else
                break;
        }

        new_nodes_list[found_id] = new Node();
        new_nodes_list[found_id]->key = node.key;

        new_nodes_list[found_id]->json_char_ammount = node.json_char_ammount;
        new_nodes_list[found_id]->json_char_list = node.json_char_list;

        new_nodes_list[found_id]->json_long_ammount = node.json_long_ammount;
        new_nodes_list[found_id]->json_long_list = node.json_long_list;

        new_nodes_list[found_id]->json_bool_ammount = node.json_bool_ammount;
        new_nodes_list[found_id]->json_bool_list = node.json_bool_list;

        new_nodes_list[found_id]->nodes_ammount = node.nodes_ammount;
        new_nodes_list[found_id]->nodes_list = node.nodes_list;

        // new_nodes_list[found_id]->value = object.value;

        // TODO: copy values from node to *this.

        for(found_id++; found_id < this->json_bool_ammount; found_id++) {
            new_nodes_list[found_id] = this->nodes_list[found_id - 1];
        }

        delete[] this->nodes_list;
        this->nodes_list = new_nodes_list;
        this->nodes_ammount = found_id;

        return true;
    } else if(type == NODE && id != -1) {
        // TODO: copy values from node to *this while some of them might be duplicated.

        // this->nodes_list[id]->key = node.key;
        // this->nodes_list[id]->value = object.value;

        return true;
    } else {
        std::cerr << "Error: add: Key " << node.key << " holds another data type." << std::endl;

        return false;
    }
}

void Node::clone(const Node& origin, Node& destination)
{
}

char* Node::duplicateCharTable(const char* key)
{
    long newSize = 0;
    while (key[newSize] != '\0') newSize++;
    newSize += 1;

    char* newTable = new char[newSize];
    for(long i = 0; i < newSize; i++) {
        newTable[i] = key[i];
    }
    return newTable;
}

Node::Node()
{
    this->key = (char*)"root";

    this->json_char_ammount = 0;
    this->json_char_list = 0x0;

    this->json_long_ammount = 0;
    this->json_long_list = 0x0;

    this->json_bool_ammount = 0;
    this->json_bool_list = 0x0;

    this->nodes_ammount = 0;
    this->nodes_list = 0x0;
}

Node::~Node()
{
    delete[] this->key;

    for(long i = 0; i < this->json_char_ammount; i++) {
        delete this->json_char_list[i];
    }
    delete[] this->json_char_list;

    for(long i = 0; i < this->json_long_ammount; i++) {
        delete this->json_long_list[i];
    }
    delete[] this->json_long_list;

    for(long i = 0; i < this->json_bool_ammount; i++) {
        delete this->json_bool_list[i];
    }
    delete[] this->json_bool_list;

    for(long i = 0; i < this->nodes_ammount; i++) {
        delete this->nodes_list[i];
    }
    delete[] this->nodes_list;
}

Json::Json()
{
}

Json::~Json()
{
}
*/
