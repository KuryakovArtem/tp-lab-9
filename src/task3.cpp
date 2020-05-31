
#include <thread>
#include <iostream>
#include <queue>
#include <mutex>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
mutex mut;

void cleanQueue(queue<vector<int>>* customer) {
    while (!customer->empty())
        customer->pop();
}

void addToQueue(queue<vector<int>>* customer, int numbOfGoods) {
    vector<int> goods;
    for (int i = 0; i < numbOfGoods; i++) {
        int randomCost = 1 + rand() % 1000;
        goods.push_back(randomCost);
    }
    customer->push(goods);
}


void till(queue<vector<int>> customer) {
    lock_guard<mutex> lock(mut);
    cout << "till: " << this_thread::get_id() << " size = " << customer.size() << endl;
    while (!customer.empty()) {
        cout << "customer is consuming " << endl;
        for (int i = 0; i < customer.front().size(); i++) {
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        customer.pop();
    }
}


int main() {
    srand(time(NULL));

    int numbOfCustomers = 5 + rand() % 10;
    queue<vector<int>> customer;
    vector<thread*> threads;

    while (numbOfCustomers--) {
        int numbOfGoods = 1 + rand() % 10;

        addToQueue(&customer, numbOfGoods);

        if ((customer.size()) % 5 == 0) {
            threads.push_back(new thread(till, customer));
            cleanQueue(&customer);
        }
    }

    for (auto& tread : threads)
        tread->join();

    return 0;
}
