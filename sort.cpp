#include<bits/stdc++.h>
using namespace std;

template <typename T, typename Container=vector<T>>
bool test_sort(Container& array) {
    for(int i = 1;i < (int)array.size();i++)
        if(array[i] < array[i - 1])
            return false;
    return true;
}

template <typename T, typename Container=vector<T>>
int merge(Container& array, int lo, int mid, int hi) {
    vector<T> temp;
    int i = lo, j = mid + 1, comparisons = 0;
    while(i <= mid and j <= hi) {
        if(array[i] <= array[j]) {
            temp.emplace_back(array[i]);
            i++;
        }
        else {
            temp.emplace_back(array[j]);
            j++;
        }
        comparisons++;
    }
    while(i <= mid)
        temp.emplace_back(array[i++]);
    while(j <= hi)
        temp.emplace_back(array[j++]);
    i = lo;
    for(auto element: temp)
        array[i++] = element;
    return comparisons;
}

template <typename T, typename Container=vector<T>>
pair<int,int> partition(Container& array, int pivot, int lo, int hi) {
    T value = array[pivot];
    swap(array[pivot], array[hi]);
    int store = lo, comparisons = 0;
    for(int i = lo;i < hi;i++)
        if(array[i] <= value) {
            swap(array[i], array[store]);
            store++;
            comparisons++;
        }
    swap(array[store], array[hi]);
    return {store, comparisons};
}

template <typename T, typename Container=vector<T>>
int merge_sort(Container& array, int lo, int hi) {
    int total_comparisons = 0;
    if(lo < hi) {
        int mid = (lo + hi)>>1;
        total_comparisons += merge_sort<T>(array, lo, mid);
        total_comparisons += merge_sort<T>(array, mid + 1, hi);
        total_comparisons += merge<T>(array, lo, mid, hi);
    }
    return total_comparisons;
}

template <typename T, typename Container=vector<T>>
int quick_sort_random(Container& array, int lo, int hi) {
    int total_comparisons = 0;
    if(lo < hi) {
        minstd_rand generator;
		uniform_int_distribution<> dist(lo, hi);
		pair<int,int> p = partition<T>(array, dist(generator), lo, hi);
        int new_pivot = p.first;
        total_comparisons += p.second;
		total_comparisons += quick_sort_random<T>(array, lo, new_pivot - 1);
		total_comparisons += quick_sort_random<T>(array, new_pivot + 1, hi);
    }
    return total_comparisons;
}

template <typename T, typename Container=vector<T>>
int quick_sort(Container& array, int lo, int hi) {
    int total_comparisons = 0;
    if(lo < hi) {
        int pivot, mid, new_pivot;
        mid = (lo + hi)>>1;
        if((array[lo] <= array[mid] and array[mid] <= array[hi]) or (array[hi] <= array[mid] and array[mid] <= array[lo]))
            pivot = mid;
        else if((array[mid] <= array[lo] and array[lo] <= array[hi]) or (array[hi] <= array[lo] and array[lo] <= array[mid]))
            pivot = lo;
        else
            pivot = hi;
		pair<int,int> p = partition<T>(array, pivot, lo, hi);
        new_pivot = p.first;
        total_comparisons += p.second;
		total_comparisons += quick_sort<T>(array, lo, new_pivot - 1);
		total_comparisons += quick_sort<T>(array, new_pivot + 1, hi);
    }
    return total_comparisons;
}

template <typename T, typename Container=vector<T>>
int merge_sort_algo(Container& array) {
    return merge_sort<T>(array, 0, (int)array.size() - 1);
}

template <typename T, typename Container=vector<T>>
int quick_sort_random_algo(Container& array) {
    return quick_sort_random<T>(array, 0, (int)array.size() - 1);
}

template <typename T, typename Container=vector<T>>
int quick_sort_algo(Container& array) {
    return quick_sort<T>(array, 0, (int)array.size() - 1);
}

int main() {
    vector<int> v = {'z', 'r', 't', 'y', 'q', 'i', 'p', 'f', 's', 'd'};
    int total = merge_sort_algo<int>(v);
    printf("%d\n", total);
    cout<<test_sort<int>(v)<<endl;
    for(auto &it: v)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}
