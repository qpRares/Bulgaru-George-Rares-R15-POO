#pragma once

template<typename K,typename V>
class Map
{
    struct Pair
    {
        K key;
        V info;
    };
    struct Element
    {
        K key;
        V value;
        int index;
    };
    Pair *v;
    int size;
public:
    Map()
    {
        v = nullptr;
        size = 0;
    }
    ~Map()
    {
        delete[] v;
    }
    void Set(K key, V value)
    {
        for(int i=0;i<size;i++)
            if(v[i].key == key)
                {
                    v[i].info = value;
                    return;
                }
        insert(key,value);
    }
    bool Get(const K& key, V& value)
    {
        for(int i=0;i<size;i++)
            if(v[i].key==key)
        {
            value = v[i].info;
            return true;
        }
        return false;
    }
    int Count()
    {
        return size;
    }
    void Clear()
    {
        delete[] v;
        v = nullptr;
        size = 0;
    }
    bool Delete(const K& key)
    {
        int index = -1;
        for(int i=0;i<size;i++)
            if(v[i].key==key)
        {
            index = i;
            break;
        }
        if(index == -1)
            return false;

        Pair *temp = new Pair[size-1];

        for(int i=0;i<index;i++)
            temp[i] = v[i];

        for(int i=index+1;i<size;i++)
            temp[i-1] = v[i];

        delete[] v;
        v = temp;
        size--;
        return true;
    }
    bool Includes(const Map<K,V>& map)
    {
            for(int i=0;i<map.size;i++)
                if(!find(map.v[i].key))
                    return false;
        return true;
    }
    bool find(const K& key) const
    {
        for(int i=0; i<size; i++)
            if(v[i].key == key)
                return 1;
        return 0;
    }
    void insert(K key, V value)
    {

        if(find(key))
            return;
        Pair * temp = new Pair[size + 1];
        for(int i=0; i<size; i++)
            temp[i] = v[i];
        Pair q;
        q.key = key;
        q.info = value;

        temp[size] = q;

        delete[] v;
        v = temp;

        size++;
    }
    V& operator[](K key)
    {
        for(int i=0; i<size; i++)
            if(v[i].key==key)
                return v[i].info;

        insert(key, V());

        return v[size - 1].info;
    }

    class Iterator
    {
        Pair *ptr;
        int index;
    public:
        Iterator(Pair *p,int i)
        {
            ptr = p;
            index = i;
        }
        bool operator !=(const Iterator & a) const
        {
            return ptr != a.ptr;
        }
        void operator++()
        {
            ptr++;
            index++;
        }
        Element operator*() const
        {
            Element e;
            e.key = ptr->key;
            e.value = ptr->info;
            e.index = index;
            return e;
        }
    };
    Iterator begin()
    {
        return Iterator(v,0);
    }
    Iterator end()
    {
        return Iterator(v + size, size);
    }

};

