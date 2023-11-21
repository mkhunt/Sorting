// cpu_timer_example.cpp

//
// Example of how to measure CPU time using clock().
//

#include <iostream>
#include <ctime>
#include"a4_sort_implementations.h"
#include<fstream>

using namespace std;

int main() {
    //
    // Simple way to measure CPU time used.
    //
    // clock_t start = clock();
    
    // string result;
    // string s = "this is a test, this is only a test";
    // for(int i = 0; i < 10000000; i++) {
    //     result += s + s;
    // }
    
    // clock_t end = clock();
    // double elapsed_cpu_time_sec = double(end - start) / CLOCKS_PER_SEC;

    // cout << "Elapsed CPU time: " << elapsed_cpu_time_sec << " seconds" << endl;

    vector<int> v;
    //ofstream out("output.csv", ios::app);
    for( int i= 2000; i<= 50000; i+=2000)
    {
        v = rand_vec(i,1,i);
        SortStats q = iquick_sort(v);
        cout<< q.to_csv()<<endl;
    }

    // 
    // int n = 10;
    // vector <int> x = rand_vec(n, 1, n);
    // vector <int> y = x;

    // out << insertion_sort(x).to_csv() << endl;
    // out << quick_sort(y).to_csv() << endl; 

    // out.close();


}
