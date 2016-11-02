#include "Json.h"
#include <iostream>

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