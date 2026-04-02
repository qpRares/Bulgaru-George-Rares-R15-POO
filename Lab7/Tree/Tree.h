#pragma once

template<typename T>
class Tree
{
public:
    struct node
    {
        T info;
        int count;
        node ** next;
    };
    node *root;
    Tree()
    {
        root = nullptr;
    }
    void add_node(node *nod, T info)
    {
        node *q = new node;
        q->info = info;
        q->count = 0;
        q->next = nullptr;
        if(nod == nullptr)
        {
            this->root = q;
        }
        else
        {
            node ** temp = new node*[nod->count + 1];
            if(nod->count != 0)
                for(int i=0; i<nod->count; i++)
                    temp[i] = nod->next[i];
            temp[nod->count] = q;
            delete[] nod->next;
            nod->next = temp;
            nod->count ++;
        }
    }
    node* get_node(node *nod, int index)
    {
        if(nod == nullptr)
            return this->root;
        if(index < 0 || index >= nod->count)
            return nullptr;
        return nod->next[index];
    }
    void delete_node(node *nod)
    {
        if(nod == nullptr)
            return;

        for(int i=0; i<nod->count; i++)
            delete_node(nod->next[i]);

        delete[] nod->next;
        delete nod;
    }
    node* find(node *start,T value, bool (*compare)(T, T))
    {
        if(start == nullptr)
            return nullptr;
        if(compare(start->info,value)==1)
            return start;
        for(int i=0; i<start->count; i++)
        {
            node* result = find(start->next[i], value, compare);
            if (result != nullptr)
                return result;
        }
        return nullptr;
    }
    void insert(node *parent, int index,T info)
    {
        if (parent == nullptr)
            return;

        if (index < 0 || index > parent->count)
            return;

        node *q = new node;
        q->info = info;
        q->count = 0;
        q->next = nullptr;

        node ** temp = new node*[parent->count + 1];

        for (int i = 0; i < index; i++)
            temp[i] = parent->next[i];

        temp[index] = q;

        for (int i = index; i < parent->count; i++)
            temp[i + 1] = parent->next[i];

        delete[] parent->next;
        parent->next = temp;
        parent->count++;
    }
    void sort(node *nod, bool (*compare)(T , T))
    {
        if(compare==nullptr)
        {
            for(int i=0;i<nod->count;i++)
                for(int j=i;j<nod->count;j++)
                    if(nod->next[i]->info < nod->next[j]->info)
                    {
                        node * aux;
                        aux = nod->next[i];
                        nod->next[i] = nod->next[j];
                        nod->next[j] = aux;
                    }
        }
        else
        {
            for(int i=0;i<nod->count;i++)
                for(int j=i;j<nod->count;j++)
                    if(compare(nod->next[i]->info,nod->next[j]->info))
                    {
                        node * aux;
                        aux = nod->next[i];
                        nod->next[i] = nod->next[j];
                        nod->next[j] = aux;
                    }
        }
    }
    int count(node *nod)
    {
        if(nod == nullptr)
            nod = root;

        if(nod == nullptr)
            return 0;

        int result = 1;

        for(int i=0;i<nod->count;i++)
        {
            result += count(nod->next[i]);
        }

        return result;
    }
};
