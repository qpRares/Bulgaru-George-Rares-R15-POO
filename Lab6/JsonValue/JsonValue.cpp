#include "JsonValue.h"


JsonValue::~JsonValue() {}

NullValue::NullValue()
{

}

void NullValue::print(std::ostream& out)
{
    out << this->value;
}

NullValue::operator unsigned() const
{
    return 1;
}

NumberValue::NumberValue(double v)
{
    this->value = v;
}

void NumberValue::print(std::ostream& out)
{
    out << this->value;
}

NumberValue::operator unsigned() const
{
    return 1;
}

BoolValue::BoolValue(bool v)
{
    this->value = v;
}

void BoolValue::print(std::ostream& out)
{
    if(value)
        out << "true";
    else
        out << "false";
}

BoolValue::operator unsigned() const
{
    return 1;
}

StringValue::StringValue(const char *v)
{
    int i=0;
    while(v[i]!='\0')
        i++;
    this->value = new char[i + 1];
    i=0;
    while(v[i]!='\0')
        {
            this->value[i] = v[i];
            i++;
        }
    this->value[i] = '\0';
}
void StringValue::print(std::ostream& out)
{
    out << "\"" << this->value << "\"";
}

StringValue::operator unsigned() const
{
    return 1;
}

StringValue::~StringValue()
{
    delete[] this->value;
}

ArrayValue::ArrayValue()
{
    this->size = 0;
}

void ArrayValue::add(JsonValue *v)
{
    this->values[this->size++] = v;
}

void ArrayValue::print(std::ostream & out)
{
    out << "[";
    for(int i=0;i<size;i++)
    {
        values[i]->print(out);
        if(i + 1 < size)
            out << ", ";
    }
    out << "]";
}

ArrayValue::operator unsigned() const
{
    int count = 1;

    for(int i=0;i<size;i++)
        count = count + (unsigned)(*this->values[i]);
    return count;
}

ArrayValue::~ArrayValue()
{
    for(int i=0;i<size;i++)
        delete this->values[i];
}

ObjectValue::ObjectValue()
{
    size = 0;
}

void ObjectValue::add(const char *name,JsonValue * v)
{
    int i=0;
    while(name[i]!='\0')
        i++;
    this->values[size].name = new char[i + 1];
    i=0;
    while(name[i]!='\0')
        {
            this->values[size].name[i] = name[i];
            i++;
        }
    this->values[size].name[i] = '\0';
    this->values[size++].value = v;
}
void ObjectValue::print(std::ostream& out)
{
    out << "{";

    for (int i = 0; i < size; i++)
    {
        out << "\"" << values[i].name << "\": ";
        values[i].value->print(out);

        if (i + 1 < size)
            out << ", ";
    }

    out << "}";
}
ObjectValue::operator unsigned() const
{
    int count = 1;
    for(int i=0;i<size;i++)
        count = count + (unsigned)(*this->values[i].value);
    return count;
}
ObjectValue::~ObjectValue()
{
    for(int i=0;i<size;i++)
    {
        delete[] this->values[i].name;
        delete this->values[i].value;
    }
}
