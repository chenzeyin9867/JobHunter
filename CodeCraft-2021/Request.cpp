#include "Request.h"
//AddRequest::AddRequest() {
//
//}
//
//DelRequest::DelRequest() {
//
//}
Request::Request(string type, int id, VirtualMachine virtualMachine) :rtype(type), rid(id), virtualMachine(virtualMachine){
}

Request::Request(string type, int id) :rtype(type), rid(id){
}

int Request::get_id() {
    return rid;
}

string Request::get_rtype() {
    return rtype;
}

VirtualMachine Request::get_virtualMachine() {
    return virtualMachine;
}
