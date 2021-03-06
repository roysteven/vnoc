#ifndef DB_DEFINE_H_
#define DB_DEFINE_H_

#include "Common.h"
#include <sqlite3/sqlite3.h>
#include <string>

#define DB_UTF16    //使用UTF16编码

#ifdef DB_UTF16
typedef std::wstring DBString;
#define _DB_TEXT(x) L##x
#define ToT wcout
#else
typedef std::string DBString;
#define _DB_TEXT(x) x
#define ToT cout
#endif

typedef int32 FieldKey_t;

const int32 INVALID_FIELD_INDEX = -1;
const uint32 DEFAULT_ROW_CURSOR = 1;

class DBFieldReader;
enum DB_DATA_TYPE
{
    DB_DATA_TYPE_NONE    = 0,
    DB_DATA_TYPE_INTEGER = SQLITE_INTEGER,
    DB_DATA_TYPE_FLOAT   = SQLITE_FLOAT,
    DB_DATA_TYPE_BLOB    = SQLITE_BLOB,
    DB_DATA_TYPE_NULL    = SQLITE_NULL,
    DB_DATA_TYPE_TEXT    = SQLITE_TEXT
};

struct Blob
{
    Blob(byte* b, int s) : blob(b), size(s)
    {
    }

    byte* blob;
    int size;
};

#endif