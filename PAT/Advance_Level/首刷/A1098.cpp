 /*===================================================================================
A1098 Insertion or Heap Sort (25)（25 分）
=====================================================================================
According to Wikipedia:
Insertion sort iterates, consuming one input element each repetition, and growing
a sorted output list. At each iteration, insertion sort removes one element from
the input data, finds the location it belongs within the sorted list, and inserts
it there. It repeats until no input elements remain.
Heap sort divides its input into a sorted and an unsorted region, and it iteratively
shrinks the unsorted region by extracting the largest element and moving that to
the sorted region. it involves the use of a heap data structure rather than a linear-time
search to find the maximum.
Now given the initial sequence of integers, together with a sequence which is a
result of several iterations of some sorting method, can you tell which sorting
method we are using?
-------------------------------------------------------------------------------------
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive
integer N (<=100). Then in the next line, N integers are given as the initial sequence.
The last line contains the partially sorted sequence of the N numbers. It is assumed
that the target sequence is always ascending. All the numbers in a line are separated
by a space.
-------------------------------------------------------------------------------------
Output Specification:
For each test case, print in the first line either "Insertion Sort" or "Heap Sort"
to indicate the method used to obtain the partial result. Then run this method for
one more iteration and output in the second line the resuling sequence. It is guaranteed
that the answer is unique for each test case. All the numbers in a line must be
separated by a space, and there must be no extra space at the end of the line.
-------------------------------------------------------------------------------------
Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
------------------
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9

Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
===================================================================================*/

#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 110;
int seq[maxn], heap[maxn], insertion[maxn];
int n;

bool isEqual(int a[], int b[]){
    for(int i = 1; i <= n; ++i)
        if(a[i] != b[i])
            return false;
    return true;
}

bool insertionSort(){
    int i, index;
    bool flag = false;
    for(i = 2; i <= n; ++i){
        int temp = insertion[i], j = i;
        while(j > 1 && insertion[j - 1] > temp){
            insertion[j] = insertion[j - 1];
            j--;
        }
        insertion[j] = temp;
        if(flag) return true;
        if(isEqual(seq, insertion))
            flag = true;
    }
    return false;
}

void downAdjust(int low, int high){
    int i = low, j = i * 2;
    while(j <= high){
        if(j + 1 <= high && heap[j + 1] > heap[j])
            j = j + 1;
        if(heap[j] > heap[i]){
            swap(heap[i], heap[j]);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
}

void creatHeap(){
    for(int i = n/2; i >= 1; --i)
        downAdjust(i, n);
}

void heapSort(){
    creatHeap();
    bool flag = false;
    for(int i = n; i >= 1; --i){
        swap(heap[i], heap[1]);
        downAdjust(1, i - 1);
        if(flag)    return;
        if(isEqual(heap, seq))
            flag = true;
    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int temp;
        cin >>temp;
        heap[i] = insertion[i] = temp;
    }
    for(int i = 1; i <= n; ++i)
        cin >> seq[i];
    if(insertionSort()){
        cout << "Insertion Sort" << endl;
        bool flag = false;
        for(int i = 1; i <= n; ++i){
            if(flag)    cout << " ";
            flag = true;
            cout << insertion[i];
        }
    }
    else{
        heapSort();
        cout << "Heap Sort" << endl;
        bool flag = false;
        for(int i = 1; i <= n; ++i){
            if(flag)    cout << " ";
            flag = true;
            cout << heap[i];
        }
    }
    return 0;
}
