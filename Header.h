#pragma once
#include <iostream>
#include <fstream>

class Kvartira {
private:
    double ploshad;
    char* fio;
    char* rayon;
    double stoimost;

    static int count;

    void setString(char*& dest, const char* src);

public:
    Kvartira();
    Kvartira(double pl, const char* f, const char* r, double st);
    Kvartira(const Kvartira& other);
    ~Kvartira();

    const Kvartira& operator=(const Kvartira& other);

    bool readFromFile(std::ifstream& fin);
    void print() const;
    bool isCentral() const;

    static int getCount() { return count; }
};
