#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <math.h>

using namespace std;
mutex mtx;
unsigned long long res = 2;

void PrimesToN(unsigned long long begin, unsigned long long end){
    for (unsigned long long i = begin; i <= end; i++){
        for (unsigned long long j = 2; j < i; j++){
            if (i % j == 0){
                break;
            }
            else if(j + 1 == i){
                mtx.lock();
                res = res + i;
                mtx.unlock();
            }
        }
    }
}

void PrimesMultipleThreads(unsigned long long begin, unsigned long long end, unsigned long long N){
    clock_t startTimer, stopTimer;
    startTimer = clock();
    vector<thread> arr;
    unsigned long long each = end/N;
    unsigned long long start = begin;
    unsigned long long finish = start + each - 1;
    for (unsigned long long i = 0; i < N; i++){
        arr.emplace_back(PrimesToN, start, finish);
        start += each;
        finish += each;
    }
    for (auto& thread : arr){
        thread.join();
    }
    stopTimer = clock();
    cout << "The time that takes is: " << (double)(stopTimer - startTimer) / CLOCKS_PER_SEC << endl;
    cout << "Result: " << res << endl;
}


int main(){
    PrimesMultipleThreads(1, 5000000, 15);
    return 0;
}