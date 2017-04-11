#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool test_sort(vector<int>& array) {
    for(int i = 1;i < (int)array.size();i++)
        if(array[i] < array[i - 1])
            return false;
    return true;
}

pair<int,ll> partition(vector<int>& array, int pivot, int lo, int hi) {
    int value = array[pivot];
    swap(array[pivot], array[hi]);
    int store = lo;
    ll comparisons = 0;
    for(int i = lo;i < hi;i++) {
        comparisons++;
        if(array[i] <= value) {
            swap(array[i], array[store]);
            store++;
        }
    }
    swap(array[store], array[hi]);
    return {store, comparisons};
}

ll quick_sort_random(vector<int>& array, int lo, int hi) {
    ll total_comparisons = 0;
    if(lo < hi) {
        minstd_rand generator;
		uniform_int_distribution<> dist(lo, hi);
		pair<int,int> p = partition(array, dist(generator), lo, hi);
        int new_pivot = p.first;
        total_comparisons += p.second;
		total_comparisons += quick_sort_random(array, lo, new_pivot - 1);
		total_comparisons += quick_sort_random(array, new_pivot + 1, hi);
    }
    return total_comparisons;
}

ll quick_sort_random_algo(vector<int>& array) {
    return quick_sort_random(array, 0, (int)array.size() - 1);
}

void shuffle_array(vector<int>& a) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle (a.begin(), a.end(), default_random_engine(seed));
}

void generate_random_array(vector<int>& a, int n=1000) {
    a.clear();
    for(int i = n;i >= 1;i--)
        a.emplace_back(i);
    shuffle_array(a);
}

void part1() {
    freopen("output1.txt", "w", stdout);
    vector<int> a;
    generate_random_array(a);
    int n = (int)(a.size());
    double nlgn = n*log2(n);
    for(int i = 1;i <= 100000;i++) {
        shuffle_array(a);
        if(i%50 != 0)
            continue;
        ll b = quick_sort_random_algo(a);
        printf("%d %lld %lf\n", i, b, nlgn);
    }
}

void generate_random_array1(vector<int>& a, int n=1000) {
    a.clear();
    while(n--) {
        srand(time(NULL));
        a.emplace_back(rand()%10000);
    }
    for(int i = 100;i >= 0;i--)
        shuffle_array(a);
}

void part2() {
    freopen("output2.txt", "w", stdout);
    int n = 1000;
    double nlgn = n*log2(n);
    for(int i = 1;i <= 2000;i++) {
        vector<int> a;
        generate_random_array(a);
        ll b = quick_sort_random_algo(a);
        printf("%d %lld %lf\n", i, b, nlgn);
    }

}

int main() {
    //part1();
    //part2();
    return 0;
}
