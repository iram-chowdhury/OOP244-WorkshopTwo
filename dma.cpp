/* Citation and Sources...
-----------------------------------------------------------
Workshop 2
Module: dma.cpp
Filename: dma.cpp
-----------------------------------------------------------
Author: Aryan Chowdhury
Student number: 138197181
Email: ichowdhury6@myseneca.ca
Subject: OOP244-NCC
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date      Reason
V1.0 2025/05/28
-----------------------------------------------------------
Done all the work by myself with help from AI modules such as Claude & ChatGPT, guiding me along the way whenever I got stuck. Helped me understand core concepts so I could finish this workshop. 
-----------------------------------------------------------  


*/

#include <iostream>
#include "dma.h"
#include "cstr.h"

using namespace std; 
using namespace seneca;

Samples* CreateSamples(const char* title) {
    Samples* sample = new Samples;

    int length = strlen(title) + 1; 
    sample->m_title = new char[length];

    strcpy(sample->m_title, title);

    sample->m_data = nullptr;
    sample->m_size = 0;

    return sample;
}

void add(Samples& S, const int data[], int size) {
    if (S.m_data == nullptr) {
        // Initial allocation
        S.m_data = new int[size];
        for (int i = 0; i < size; i++) {
            S.m_data[i] = data[i];
        }
        S.m_size = size;
        
    }
    else {
        int newSize = S.m_size + size;
        int* newData = new int[newSize];

        for (int i = 0; i < S.m_size; i++) {
            newData[i] = S.m_data[i];
        }

        for (int i = 0; i < size; i++) {
            newData[S.m_size + i] = data[i];
        }

        delete[] S.m_data;
        S.m_data = newData;
        S.m_size = newSize;
    }
}

void append(int*& data, int size, const int appendedData[], int dataSize) {
    int* newData = new int[size + dataSize];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    for (int i = 0; i < dataSize; i++) {
        newData[size + i] = appendedData[i];
    }

    delete[] data;
    data = newData;
}

void freemem(Samples*& s) {
    if (s) {
        delete[] s->m_title;
        delete[] s->m_data;
        delete s;
        s = nullptr;
    }
}
