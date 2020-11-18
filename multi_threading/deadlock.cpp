#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

const int SIZE = 10;

mutex myMutex, myMutex1, myMutex2;


//Deadlock condition as if one thread has locked myMutex1 and want to lock myMutex2, 
// while at the same time another thread locked myMutex2 and wants to lock myMutex1
// As shared_count_thread_even and shared_cout_thread_odd method are doing
// To solve this deadlock
void shared_cout_thread_even(int i)
{
    lock(myMutex1,myMutex2);
    lock_guard<mutex> g1(myMutex1, adopt_lock);
    lock_guard<mutex> g2(myMutex2, adopt_lock);
    cout << " " << i << " ";
}

void shared_cout_thread_odd(int i)
{
    lock(myMutex1,myMutex2);
    lock_guard<mutex> g2(myMutex2, adopt_lock);
    lock_guard<mutex> g1(myMutex1, adopt_lock);
    cout << " " << i << " ";
}

void shared_cout_main(int i)
{
    lock_guard<mutex> g(myMutex);
    cout << " " << i << " ";
}

void f(int n)
{
    for(int i = SIZE*(n-1); i < SIZE*n ; i++) {
        if(n % 2 == 0)
            shared_cout_thread_even(i);
        else
            shared_cout_thread_odd(i);
    }
}

int main()
{
    thread t1(f, 1);  // 0-9
    thread t2(f, 2);  // 10-19
    thread t3(f, 3);  // 20-29
    thread t4(f, 4);  // 30-39
    thread t5(f, 5);  // 40-49


    for(int i = 0; i > -50; i--)
        shared_cout_main(i);  // (0, -49)

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}