#ifndef JSON_H
#define JSON_H

//
// Structures
//
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

//
// Node
//
class Node
{
public:
    enum data_type {
        NOT_EXIST,

        NODE,
        CHAR,
        LONG,
        BOOL
    };

public: // TODO: change to protected.
    char* key;

    long json_char_ammount;
    Json_char** json_char_list;

    long json_long_ammount;
    Json_long** json_long_list;

    long json_bool_ammount;
    Json_bool** json_bool_list;

protected:
    static char* charDuplicate(const char* key);
    static char* charGetDynamic(const char charTable[]);
    static bool charIsEqual(const char* keyOne, const char* keyTwo);
    static bool charIsGreater(const char* keyOne, const char* keyTwo);

public:
    enum data_type findKey(const char* key, long& assigns_id_from_table) const;
    bool keyIsVaild(const char* key) const; // This should be in Json class i think.

    char* getChar(const char* key) const;
    long getLong(const char* key) const;
    bool getBool(const char* key) const;
    
    // Adding objects means making an copy of it.
    bool add(const Json_char& object);
    bool add(const Json_long& object);
    bool add(const Json_bool& object);

public:
    Node();
    Node(const char* key);
    ~Node();
};

/*
//
// Node
//
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

    static char* duplicateCharTable(const char* key);

public:
    Node();
    ~Node();

    friend class Json;
};

class NodeTest : public Node {

};

//
// Json
//
class Json
{
private:
public:


public:
    Json();
    ~Json();
};
*/

#endif // JSON_H
