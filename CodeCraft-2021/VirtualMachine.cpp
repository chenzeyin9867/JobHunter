#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(const string &type, int num_of_cpu, int size_of_mem, bool double_node)
    : _type(type), _num_of_cpu(num_of_cpu), _size_of_mem(size_of_mem), _is_double_node(double_node)
{

}

VirtualMachine::VirtualMachine(){

}

string VirtualMachine::get_type() {
    return _type;
}

int VirtualMachine::get_num_of_cpu() {
    return _num_of_cpu;
}

int VirtualMachine::get_size_of_mem(){
    return _size_of_mem;
}
bool VirtualMachine::get_double_node(){
    return _is_double_node;
}