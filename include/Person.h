#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <stdlib.h>

using namespace std;

class Person
{
    public:

        Person(string);
        virtual ~Person();
        string showPerson();

    protected:

    private:
        string names;

};

#endif // PERSON_H
