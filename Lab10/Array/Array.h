#pragma once
#include <exception>
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

class exceptie3 : public std::exception
{
    virtual const char * what() const throw()
    {
        return "Index este out of range";
    }
};
template<class T>
class ArrayIterator
{
private:
    T** List;
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
    int Size;
public:
    ArrayIterator()
    {
        List = nullptr;
        Current = 0;
        Size = 0;
    }
    ArrayIterator(T** List, int Current, int Size)
    {
        this->List = List;
        this->Current = Current;
        this->Size = Size;
    }
    ArrayIterator& operator ++ ()
    {
        if(Current >= Size - 1)
            throw exceptie3();
        Current ++;
        return *this;
    }
    ArrayIterator& operator -- ()
    {
        if(Current == 0)
            throw exceptie3();
        Current --;
        return *this;
    }
    bool operator == (ArrayIterator<T> & a)
    {
        return this->Current == a.Current;
    }
    bool operator!=(ArrayIterator<T> & a)
    {
        return this->Current != a.Current;
    }
    T* GetElement()
    {
        if(!List || Current < 0 || Current >= Size)
            throw exceptie3();
        return List[Current];
    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() // Lista nu e alocata, Capacity si Size = 0
    {
        List = nullptr;
        Capacity = 0;
        Size = 0;
    }
    ~Array() // destructor
    {
        Capacity = 0;
        for(int i=0; i<Size; i++)
            delete List[i];
        Size = 0;
        delete[] List;
        List = nullptr;
    }
    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        this->Capacity = capacity;
        this->Size = 0;
        List = new T*[capacity];
    }
    Array(const Array<T> &otherArray) // constructor de copiere
    {
        this->Size = otherArray.Size;
        this->Capacity = otherArray.Capacity;
        List = new T*[Capacity];
        for(int i=0; i<Size; i++)
            List[i] = new T(*otherArray.List[i]);
    }

    T& operator[] (int index) // arunca exceptie daca index este out of range
    {
        if(index >= Size || index < 0)
            throw exceptie3();
        return *List[index];
    }

    const Array<T>& operator+=(const T &newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
    {
        T** temp = new T*[Size+1];

        for(int i=0; i<Size; i++)
            temp[i] = List[i];

        temp[Size] = new T(newElem);

        Size ++;
        Capacity = Size;

        delete[] List;
        List = temp;

        return *this;
    }
    const Array<T>& Insert(int index, const T &newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        exceptie3 index_out_of_range;
        if(index > Size || index < 0)
            throw index_out_of_range;

        T** temp = new T*[Size+1];

        for(int i=0; i<index; i++)
            temp[i] = List[i];

        temp[index] = new T(newElem);

        for(int i=index+1; i<Size + 1; i++)
            temp[i] = List[i-1];

        delete[] List;
        List = temp;
        Size ++;
        Capacity = Size;
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> & otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    {
        exceptie3 index_out_of_range;
            if(index > Size || index < 0)
                throw index_out_of_range;

            T** temp = new T*[Size+otherArray.Size];

            int j=0;
            for(int i=0; i<index; i++)
                temp[j++] = List[i];

            for(int i=0; i<otherArray.Size; i++)
            {
                temp[j++] = new T(*otherArray.List[i]);
            }

            for(int i=index; i<Size; i++)
                temp[j++] = List[i];
            delete[] List;
            List = temp;
            Size += otherArray.Size;
            Capacity = Size;
            return *this;
    }
    const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    {
        exceptie3 index_out_of_range;
            if(index >= Size || index < 0)
                throw index_out_of_range;

            T** temp = new T*[Size-1];

            for(int i=0; i<index; i++)
                temp[i] = List[i];

            for(int i=index+1; i<Size; i++)
                temp[i-1] = List[i];

            delete List[index];
            delete[] List;
            List = temp;
            Size --;
            return *this;
    }

    bool operator ==(const Array<T> &otherArray)
    {
        if(this->Size != otherArray.Size)
            return 0;
        for(int i=0; i<Size; i++)
            if(*List[i] != *otherArray.List[i])
                return 0;
        return 1;
    }

    void Sort() // sorteaza folosind comparatia intre elementele din T
    {
        for(int i=0; i<Size; i++)
            for(int j=i; j<Size; j++)
                if(*List[i] > *List[j])
                {
                    T* aux;
                    aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }
    void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
    {
        for(int i=0; i<Size; i++)
            for(int j=i; j<Size; j++)
                if(compare(*List[i],*List[j]))
                {
                    T* aux;
                    aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }
    void Sort(Compare *comparator) // sorteaza folosind un obiect de comparatie
    {
        for(int i=0; i<Size; i++)
            for(int j=i; j<Size; j++)
                if(comparator->CompareElements(List[i],List[j]) > 0)
                {
                    T* aux;
                    aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
    }


    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (*List[mid] == elem)
                return mid;

            if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind binary search si o functie de comparatie
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (compare(*List[mid],elem) == 0)
                return mid;

            if (compare(*List[mid],elem) < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
    int BinarySearch(const T& elem, Compare *comparator)//  cauta un element folosind binary search si un comparator
    {
        int left = 0;
        int right = Size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (comparator->CompareElements(List[mid], (void*)&elem) == 0)
                return mid;

            if (comparator->CompareElements(List[mid], (void*)&elem) < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

    int Find(const T& elem) // cauta un element in Array
    {
        for(int i=0; i<Size; i++)
            if(*List[i] == elem)
                return i;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&))//  cauta un element folosind o functie de comparatie
    {
        for(int i=0; i<Size; i++)
            if(compare(*List[i],elem) == 0)
                return i;
        return -1;
    }
    int Find(const T& elem, Compare *comparator)//  cauta un element folosind un comparator
    {
        for(int i=0; i<Size; i++)
            if(comparator->CompareElements(List[i],(void*)&elem) == 0)
                return i;
        return -1;
    }

    int GetSize()
    {
        return this->Size;
    }
    int GetCapacity()
    {
        return this->Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator(List,0,this->Size);
    }
    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator(List,this->Size,this->Size);
    }
};


