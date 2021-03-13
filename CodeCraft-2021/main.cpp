#include "iostream"
#include <string>
#include <fstream>
#include <cassert>
#include <unordered_map>
#include <vector>
#include "Server.h"
#include "VirtualMachine.h"
#include "Request.h"

int main() {
    using namespace std;
    string testdataname = "/home/czy/MyWorkSpace/huawei/JobHunter/training-1.txt";
    ifstream infile(testdataname, ios::in);

    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行
    unordered_map<string, pair<int, int>> vms;
    unsigned long long cpu_req = 0, mem_req = 0;
    string s;
    int cnt = 0;
    int serverNum = 0;
    vector<Server> server_list;
    unordered_map<string, VirtualMachine> vmList;
    vector<vector<Request>> request_list;
    getline(infile, s);
    serverNum = stoi(s);
    for (int i = 0; i < serverNum; i++) {
        getline(infile, s);
        int id_h = 1; //"("
        int id_tail = s.find(',');
        string id = s.substr(id_h, id_tail - id_h); // id of the server
        int cpu_h = s.find(' ', id_tail);
        int cpu_tail = s.find(',', cpu_h);
        int cpu_num = stoi(s.substr(cpu_h + 1, cpu_tail - cpu_h - 1));
        int mem_h = s.find(' ', cpu_tail);
        int mem_t = s.find(',', mem_h);
        int mem_num = stoi(s.substr(mem_h + 1, mem_t - mem_h - 1));
        int hw_cost_h = s.find(' ', mem_t);
        int hw_cost_t = s.find(',', hw_cost_h);
        int hardware_cost = stoi(s.substr(hw_cost_h + 1, hw_cost_t - hw_cost_h - 1));
        int daily_cost_h = s.find(' ', hw_cost_t);
        int daily_cost_t = s.find(')', daily_cost_h);
        int daily_cost = stoi(s.substr(daily_cost_h + 1, daily_cost - daily_cost_h - 1));
        Server newServer = Server(id, cpu_num, mem_num, hardware_cost, daily_cost);
        server_list.push_back(newServer);
        cout << "id:" << id << "---- cpu_num:" << cpu_num << "--- mem:" << mem_num << " --- hardware_cost:" <<
             hardware_cost << " --- dailyCost:" << daily_cost << endl;
    }

    getline(infile, s);     // cin the number of the v

    int vm_num = stoi(s);
    for (int i = 0; i < vm_num; i++) {
        getline(infile, s);
        int id_h = 1; //"("
        int id_tail = s.find(',');
        string id = s.substr(id_h, id_tail - id_h); // id of the server
        int cpu_h = s.find(' ', id_tail);
        int cpu_tail = s.find(',', cpu_h);
        int cpu_num = stoi(s.substr(cpu_h + 1, cpu_tail - cpu_h - 1));
        int mem_h = s.find(' ', cpu_tail);
        int mem_t = s.find(',', mem_h);
        int mem_num = stoi(s.substr(mem_h + 1, mem_t - mem_h - 1));
        char cc = s[s.length() - 2];
        bool doubleNode = (cc == '1');
        VirtualMachine newVm = VirtualMachine(id, cpu_num, mem_num, doubleNode);
        vmList.insert(make_pair(id, newVm));
        cout << "id:" << id << "---- cpu_num:" << cpu_num << "--- mem:" << mem_num << "-- double" << cc << endl;
    }

    getline(infile, s); // get the num of days;
    int days = stoi(s);
    for (int i = 0; i < days; i++) {
        vector<Request> request_day;
        getline(infile, s); // get the num of requests of everyday
        int numRequest = stoi(s);
        cout << i << endl;
        for (int j = 0; j < numRequest; j++) {
            getline(infile, s); // get every request and parse it
            if (s.substr(0, 4) == "(add") { // add vm request
                int id_h = s.find(' ');
                int id_t = s.find(',', id_h);
                string id = s.substr(id_h + 1, id_t - id_h - 1);
                int index_h = s.find(' ', id_t);
                int index_t = s.find(')', index_h);
                int index = stoi(s.substr(index_h + 1, index_t - index_h - 1));
                VirtualMachine tmp = vmList.find(id)->second;
                VirtualMachine newVM = VirtualMachine(tmp.get_type(), tmp.get_num_of_cpu(), tmp.get_size_of_mem(), tmp.get_double_node());
                Request cur_request("add", index, newVM);
                request_day.push_back(cur_request);

            } else if (s.substr(0, 4) == "(del") {
                int id_h = s.find(' ');
                int id_t = s.find(',', id_h);
                int index = stoi(s.substr(id_h + 1, id_t - id_h - 1));
//                VirtualMachine tmp = vmList.find(id)->second;
//                VirtualMachine newVM = VirtualMachine(tmp.get_type(), tmp.get_num_of_cpu(), tmp.get_size_of_mem(), tmp.get_double_node());
                Request cur_request("del", index);
                request_day.push_back(cur_request);
            }
        }
        request_list.push_back(request_day);
    }
    // TODO:read standard input
    // TODO:process
    // TODO:write standard output
    // TODO:fflush(stdout);

    for (int i=0 ;i < request_list.size(); i++){
        for (int j = 0; j< request_list[i].size(); j++){
            cnt ++;
            Request r_cur = request_list[i][j];
            cout << cnt << "--type:" << r_cur.get_rtype() << "--id:" << r_cur.get_id() << endl;
//            if (r_cur.get_virtualMachine() != NULL){
//                cout <<" --vm_type-- "  << r_cur.get_virtualMachine().get_type() << endl;
//            }
        }
    }
    return 0;
}
