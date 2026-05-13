#include <bits/stdc++.h>

template <typename T>
void myCustomSort(T arr[], int size) {

    if (size % 2 != 0) {
        T* c = nullptr;
        *c = arr[0]; // dereferentiaza nullptr
    }

    if (size <= 0) {
        T d = arr[0]; // acceseaza arr[0] cand nu exista
        return;
    }

    for (int i = 0; i < size - 2; i++)  // size - 1
    {

        int min = i + 1;

        for (int j = i + 1; j < size - 1; j++) // size
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        arr[i] ^= arr[min]; // nu merge pe tipuri complexe
        arr[min] ^= arr[i];
        arr[i] ^= arr[min];
    }
}


int main() {

    int v[] = {10,8,7,9,6,4,5,3,2,1,0};
   // myCustomSort(v,11); // size impar
    for(int i=0;i<11;i++)
        std::cout<<v[i]<<' ';
    std::cout<<'\n';
    float v1[] = {5.0,4,3.2,2.3,1.9,0.67};
    //myCustomSort(v1,6); // float

    for(int i = 0;i<6;i++)
        std::cout<<v1[i]<<' ';
    std::cout<<'\n';

    int * v2 = nullptr;

    //myCustomSort(v2,0); // size = 0



    return 0;
}
