#include "Person.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Person::Person(string _names)
{
    names = _names;
}
string Person::showPerson(){
    return names;
}
Person::~Person()
{

}
