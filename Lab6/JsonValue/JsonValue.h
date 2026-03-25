#pragma once
#include <iostream>

class JsonValue {
public:
    virtual ~JsonValue() = 0;

    virtual void print(std::ostream& out) = 0;
    virtual operator unsigned() const = 0;
};

class NullValue : public JsonValue
{
    const char value[5] = "null";
public:
    NullValue();
    void print(std::ostream& out) override;
    operator unsigned() const override;
};

class NumberValue : public JsonValue
{
    double value;
public:
    NumberValue(double v);
    void print(std::ostream& out) override;
    operator unsigned() const override;
};

class BoolValue : public JsonValue
{
    bool value;
public:
    BoolValue(bool v);
    void print(std::ostream& out) override;
    operator unsigned() const override;
};

class StringValue : public JsonValue
{
    char *value;
public:
    StringValue(const char *v);
    void print(std::ostream& out) override;
    operator unsigned() const override;
    ~StringValue();
};

class ArrayValue : public JsonValue
{
    JsonValue *values[16];
    unsigned size;
public:
    ArrayValue();
    void add(JsonValue * v);
    void print(std::ostream& out) override;
    operator unsigned() const override;
    ~ArrayValue();
};

class ObjectValue : public JsonValue
{
    struct Pair {
        char *name;
        JsonValue *value;
    };

    Pair values[16];
    unsigned size;
public:
    ObjectValue();
    void add(const char *name,JsonValue * v);
    void print(std::ostream& out) override;
    operator unsigned() const override;
    ~ObjectValue();
};
