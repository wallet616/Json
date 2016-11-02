#ifndef JSON_H
#define JSON_H

struct Json_char {
    char* key;
    char* value;
};

struct Json_long {
    char* key;
    long value;
};

struct Json_bool {
    char* key;
    bool value;
};

class Node
{
private:
    char* key;

    long json_char_ammount;
    Json_char** json_char_list;

    long json_long_ammount;
    Json_long** json_long_list;

    long json_bool_ammount;
    Json_bool** json_bool_list;

    long nodes_ammount;
    Node** nodes_list;

public:
    enum data_type {
        NOT_EXIST,

        NODE,
        CHAR,
        LONG,
        BOOL
    };

public:
    enum data_type findKey(const char* key, long& assigns_id_from_table) const;

    long getLong(const char* key) const;
    char* getChar(const char* key) const;
    bool getBool(const char* key) const;

    bool add(const Json_char& object);
    bool add(const Json_long& object);
    bool add(const Json_bool& object);
    bool add(const Node& node);
    
protected:
    static void clone(const Node& origin, Node& destination);

public:
    Node();
    ~Node();

    friend class Json;
};

class Json
{
private:
public:
    Json();
    ~Json();
};

#endif // JSON_H
