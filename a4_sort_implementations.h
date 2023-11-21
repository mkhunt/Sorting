// a4_sort_implementations.h

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <Krish Mann>
// St.# : <301565069>
// Email: <kma133@sfu.ca>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#pragma once

#include "a4_base.h"
//
// Do NOT add any other #includes to this file!
//

using namespace std;

//
// Put the implementations of all the functions listed in a4_base.h here, as
// well as is_sorted and rand_vec. You can other helper functions if needed.
//
template<typename T>
bool  is_sorted(vector<T> &v)
{
    if(v.size() != 0)
    {
        for(int i = 1; i < v.size() ; i++)
        {
            if (v[i-1] > v[i])
            {
                return false;
            }
        }
    }
    return true;
}

vector<int> rand_vec(int n, int min, int max)
{
    srand(time(0)); 
    
    vector<int> ans;

    if(n >= 0 && min <= max)
    {
        for (int i = 0; i < n; i++)
        { 
            ans.push_back(rand() % (max - min + 1) + min);
        }
    }
    return ans;
}

// -------------------------------------BUBBLE SORT 
template <typename T>
Sort_stats bubble_sort(vector<T> &v)
{
    Sort_stats s;
    s.sort_name = "Bubble_Sort";
    s.vector_size = v.size();
    clock_t start = clock();
    s.num_comparisons = 0;

    // two loop to start from first to last element, and sorting from start
    if(v.size() >  1)
    {
        for( int i = 0 ; i < v.size() ; i++)
        {
            for( int j= 0; j < v.size() - 1 - i; j++) // check if you should -i
            {
                if(v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);
                }
                s.num_comparisons++;
            }
        }
    }
    clock_t end = clock();
    s.cpu_running_time_sec = (double) (end - start) / CLOCKS_PER_SEC;

    return s;
}

//---------------------------------------INSERTION SORT
// referred to CMPT130 labwork
template <typename T>
Sort_stats insertion_sort(vector<T> &v)
{
    Sort_stats s;
    s.sort_name = "Insertion_sort";
    s.vector_size = v.size();
    s.num_comparisons = 0;
    clock_t start = clock();
    if(v.size() > 1)
    {
        for( int i = 1; i < v.size() ; i++)
        {
            T temp = v[i]; // take the elmt,store it in 1 memory block
            int j = i - 1;
            while(j>=0 && v[j] > temp)
            {
                v[j + 1] = v[j];
                j--;
                s.num_comparisons++;
            }
            v[j + 1] = temp;
        }
    }

    clock_t end = clock();
    s.cpu_running_time_sec = (double) (end - start)/CLOCKS_PER_SEC;

    return s;
}

//-------------------------------------------SELECTION SORT
// referred to the notes and labwokr from CMPT 130.
// I had to make changes in order for this program to work correctly.
template <typename T>
Sort_stats selection_sort(vector<T> &v)
{
    Sort_stats s;
    s.sort_name = "Selection_sort";
    s.vector_size = v.size();
    s.num_comparisons = 0;
    clock_t start = clock();
    int min;
    if(v.size() > 1)
    {
        for(int i = 0; i < v.size() ; i++)
        {
            min = i;
            for(int j = i+1; j < v.size() ; j++)
            {
                if(v[j] < v[min])
                {
                    min = j;
                }
                s.num_comparisons++;
            }
            if(min != i)
            {
                swap(v[min], v[i]);
            }
        }
    }
    clock_t end = clock();
    s.cpu_running_time_sec = (double)(end-start)/CLOCKS_PER_SEC;

    return s;
}

//---------------------------------------------------------SHELL SORT
//refered to the books for CMPT225 and CMPT130
// Watched some youtube videos to understand the code better
template <typename T>
Sort_stats shell_sort(vector<T> &v)
{
    Sort_stats s;
    s.vector_size = v.size();
    s.sort_name = "Shell_sort";
    clock_t start = clock();
    s.num_comparisons = 0;

    if(v.size() > 1)
    {
        for( int i = v.size()/2 ; i >= 1; i = i/2)  //n/2, n/4, n/8, ..., 1.
        {
            for(int j = i; j < v.size() ; j = j + 1)
            {
                for(int k = j - i; k >= 0; k = k - i)
                {
                    if(v[i + k] > v[k])
                    {
                        break;
                    }
                    else
                    {
                        swap(v[ k + i], v[k]);
                    }
                    s.num_comparisons++;
                }
            }
        }
    }

    clock_t end = clock();
    s.cpu_running_time_sec = (double)(end - start) / CLOCKS_PER_SEC;

    return s;
}





////-----------------------------------------------------------MERGE SORT

// Implemented with the help of the code from CMPT135 lecture notes
// Referred to the tectbook for CMPT225


//--------------------------------------------------MERGE SORT--------------------------------------------------------------------------

template <typename T>
void merge(vector<T> &v, int low, int mid, int high){
    vector<T> temp;
    int left = low;
    int right = mid+1;
    while (left <= mid && right <= high)
    {
        merge_comp++; // <--- num_comps is incremented here
        if(v[left] <= v[right]){
            temp.push_back(v[left]);
            left++;
        } else{
            temp.push_back(v[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(v[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(v[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        v[i]=temp[i-low];
    }
    
}

template <typename T>
void merge_sort_helper(vector<T> &v, int low, int high){
    if(low >= high){
        return;
    }
    int mid = (low+high)/2;
    merge_sort_helper(v,low,mid);
    merge_sort_helper(v,mid+1,high);
    merge(v,low,mid,high);
}

template <typename T>
Sort_stats merge_sort(vector<T> &v){
    clock_t start = clock(); 
    merge_sort_helper(v,0,v.size()-1);
    clock_t end = clock();
    double elapsed_cpu_time_sec = double(end - start) / CLOCKS_PER_SEC;

    return SortStats{"Merge sort",v.size(),merge_comp,elapsed_cpu_time_sec};
}





//-------------------------------------------------QUICK SORT--------------------------------------------------------------------------

template<typename T>
int partition(vector<T> &v, int start, int end, ulong & quick_comps)
{
   
    T pivot = v[end];
    int pivotindex = start;
    for (int j = start; j < end; j++)
    {
        quick_comps++;
        if(v[j] <= pivot){
            swap(v[pivotindex],v[j]);
            ++pivotindex;
        }
    }
    swap(v[pivotindex],v[end]);
    return pivotindex;
}

template <typename T>
void quick_sort_helper(vector<T> &v, int start, int end, ulong& quick_comps){
    while(start >= end){
        return;
    }
    int pivot = partition(v, start, end, quick_comps);
    quick_sort_helper(v, start, pivot-1,quick_comps);
    quick_sort_helper(v, pivot+1, end, quick_comps);
}

template <typename T>
Sort_stats quick_sort(vector<T> &v)
{
    Sort_stats s;
    s.sort_name = "quick Sort";
    s.vector_size = v.size();
    clock_t start = clock(); 

    if(v.size() <= 1)
    {
        
        s.num_comparisons = 0;
        clock_t end = clock();
        s.cpu_running_time_sec = (double) (end - start)/CLOCKS_PER_SEC;
        return s;
    }

    ulong quick_comps=0;
    quick_sort_helper(v,0,v.size()-1, quick_comps);

    s.num_comparisons = quick_comps;
    clock_t end = clock();
    s.cpu_running_time_sec = double(end - start) / CLOCKS_PER_SEC;

    return s;
} 

template <typename T>
void iquick_sort(vector <T> &v, int start, int end, ulong &iquick_comps)
{
    iquick_comps++;
    if(start >= end)
    {
        return;
    }
    if(v.size() <= 5)
    {
        insertion_sort(v);
    }
    else
    {
        int pivotIndex = partition(v,start,end,iquick_comps);
        iquick_sort(v,start,pivotIndex-1,iquick_comps);
        iquick_sort(v, pivotIndex+1, end, iquick_comps);
    }
}
template<typename T>
Sort_stats iquick_sort(vector<T> &v)
{
    Sort_stats s;
    s.sort_name = "iquick sort";
    s.vector_size = v.size();
    clock_t start = clock();

    iquick_sort(v, 0, v.size()-1,s.num_comparisons);

    clock_t end = clock();

    s.cpu_running_time_sec = (double)(end - start)/ CLOCKS_PER_SEC;
    return s;
}

vector<int> rand_vec(int n, int min, int max)
{
    //create vector
    vector<int> v;
    //loop through n times
    for (int i = 0; i < n; i++){
        //add random number to vector
        v.push_back(rand() % (max - min + 1) + min);
    }
    //return vector
    return v;
}