#pragma once

enum ContactType
{
    FRIEND,
    ACQUAINTANCE,
    COLLEAGUE
};

class Contact
{
protected:
    ContactType type;
    char *name;
public:
    Contact(const char * n)
    {
        int i = 0;
        while(n[i] != '\0')
            i++;
        name = new char[i + 1];
        i = 0;
        while(n[i] != '\0')
            {
                name[i] = n[i];
                i++;
            }
        name[i] = '\0';
    }
    virtual ~Contact()
    {
        delete[] name;
    }
    const char* GetName()
    {
        return this->name;
    }
    ContactType GetType()
    {
        return this->type;
    }
};

class Friend : public Contact
{
    struct
    {
        int day,month,year;
    }date_of_birth;
    char *address;
public:
    Friend(const char* n) : Contact(n)
    {
        type = ContactType::FRIEND;
    }
};

class Acquaintance : public Contact
{
    char *phone_number;
public:
    Acquaintance(const char* n) : Contact(n)
    {
        type = ContactType::ACQUAINTANCE;
    }
};

class Colleague : public Contact
{
    char *phone_number;
    char *company;
    char *address;
public:
    Colleague(const char* n) : Contact(n)
    {
        type = ContactType::COLLEAGUE;
    }
};

class AddressBook
{
    Contact ** Contacts;
    int count;
public:
    AddressBook()
    {
        Contacts = nullptr;
        count = 0;
    }
    void addContact(Contact* c)
    {
        Contact** Temp = new Contact*[count+1];
        for(int i=0;i<count;i++)
            Temp[i] = Contacts[i];
        Temp[count] = c;
        delete[] Contacts;
        Contacts = Temp;
        count++;
    }
    Contact* searchByName(const char *name)
    {
        for(int i=0;i<count;i++)
        {
            const char * Name = Contacts[i]->GetName();
            int j = 0;
            bool ok = 0;
            while(Name[j] != '\0' && name[j] !='\0')
                {
                    if(Name[j] != name[j])
                        {
                            ok = 1;
                            break;
                        }
                    j++;
                }
            if(Name[j] != '\0')
                ok = 1;
            if(name[j] != '\0')
                ok = 1;
            if(ok)
                continue;
            return Contacts[i];
        }
        return nullptr;
    }
    void deleteContact(const char *name)
    {
        int index = -1;
        for(int i=0;i<count;i++)
        {
            const char * Name = Contacts[i]->GetName();
            int j = 0;
            bool ok = 0;
            while(Name[j] != '\0' && name[j] !='\0')
                {
                    if(Name[j] != name[j])
                        {
                            ok = 1;
                            break;
                        }
                    j++;
                }
            if(Name[j] != '\0')
                ok = 1;
            if(name[j] != '\0')
                ok = 1;
            if(ok)
                continue;
            index = i;
                break;
        }
        if(index != -1)
        {
            Contact** Temp = new Contact*[count-1];
            for(int i=0;i<index;i++)
                Temp[i] = Contacts[i];
            for(int i=index + 1;i<count;i++)
                Temp[i-1] = Contacts[i];
            delete[] Contacts;
            Contacts = Temp;
            count--;
        }
    }
    Friend** getFriends()
    {
        int cnt = 0;
        for(int i=0;i<count;i++)
            if(Contacts[i]->GetType() == ContactType::FRIEND)
                cnt++;
        Friend** Temp = new Friend*[cnt];
        cnt = 0;
        for(int i=0;i<count;i++)
            if(Contacts[i]->GetType() == ContactType::FRIEND)
                {
                    Temp[cnt] = (Friend*)Contacts[i];
                    cnt++;
                }
        return Temp;
    }
};
