#ifndef _REQUEST_
#define _REQUEST_
#include <string>
#include "VirtualMachine.h"
using namespace std;
class Request
{
private:
    /* data */
    string rtype; // 'add' or 'delete'
    int rid; // id of the request virtualMachine
    VirtualMachine virtualMachine;
public:
    Request(string type, int id, VirtualMachine virtualMachine);
    Request(string type, int id);
//    ~Request();

    int get_id();
    string get_rtype();
    VirtualMachine get_virtualMachine();
};
class AddRequest : public Request
{
    public:
    AddRequest();
};

class DelRequest : public Request
{
public:
    DelRequest();
};

#endif