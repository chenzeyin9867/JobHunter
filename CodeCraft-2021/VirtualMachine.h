#ifndef _VIRTUAL_MACHINE_
#define _VIRTUAL_MACHINE_
#include <iostream>
#include <string>
using namespace std;

class VirtualMachine
{
public:
    VirtualMachine(const string &type, int num_of_cpu, int size_of_mem, bool double_node);
    VirtualMachine();
    int get_num_of_cpu();
    int get_size_of_mem();
    bool get_double_node();
    string get_type();
private:
    string _id;
    string _type;
    int _num_of_cpu;
    int _size_of_mem;
    bool _is_double_node;
};
#endif