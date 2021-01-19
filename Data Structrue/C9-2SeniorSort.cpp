#include "d:/WORK/VSC C/bits/stdcpp.h"
using namespace std;
#define N 999
#define NUM 800
template <class Item>
/* MergeSort's Performance is merely related to the array itself. O(nlogn) */
void merge(Item a[], int l, int m, int r) {
    int i, j, k = l;
    static Item aux[N];                //声明的是一个静态对象，降低空间复杂度
    for (i = l; i <= m; i++) aux[i] = a[i];
    for (j = m + 1; j <= r; j++) aux[r + m + 1 - j] = a[j];
    i = l; j = r;
    while (i <= j) {
        if (aux[i] < aux[j]) a[k++] = aux[i++];
        else a[k++] = aux[j--];
    }
}
template <class Item>
void MergeSort(Item a[], int l, int r) {
    if (r <= l)return;
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

/* QuickSort, based on InsertionSort, its unimproved version can be uneffiect in somecase. */
/* You can assume QuickSort is somewhat "reversed" MergeSort, For its Machinism.  */
template <class Item>
int partition(Item a[], int l, int r) {
    int i = l - 1, j = r;
    Item t = a[r];
    while (1) {
        while (a[++i] < t);
        while (t < a[--j]) if (j == l)break;
        if (i >= j)break;
        swap(a[i], a[j]);
    }
    swap(a[i], a[r]);  //why a[i] swap with a[r], rather than a[j] swap with a[r]? a question worth considering.
    return i;
}
template <class Item>
void QuickSort(Item a[], int l, int r) {
    if (r <= l) return;
    int m = partition(a, l, r);
    QuickSort(a, l, m - 1);
    QuickSort(a, m + 1, r);
}
/* 快排的三路优化 */
template <class Item>  void PQuickSort(Item a[], int left, int right) {
    int  k;    Item v = a[right];	       if (right <= left) return;
    int  i = left - 1, j = right, p = left - 1, q = right;
    for (;;) {
        while (a[++i] < v);             while (v < a[--j])  if (j == left)  break;
        if (i >= j) break; 	  swap(a[i], a[j]);
        if (a[i] == v) { p++;     swap(a[p], a[i]); }
        if (v == a[j]) { q--;       swap(a[q], a[j]); }
    }
    swap(a[i], a[right]);           j = i - 1;             i = i + 1;
    for (k = left; k <= p; k++, j--)  swap(a[k], a[j]);   //换到序列正中
    for (k = right - 1; k >= q; k--, i++)  swap(a[k], a[i]); //换到序列正中	
    PQuickSort(a, left, j);	PQuickSort(a, i, right);
}

/* HeapSort */
template <class Item>
void siftDown(Item a[], int k, int n) {
    int i = k, j = 2*i + 1; Item t;
    while ((j = 2*i + 1) < n) {
        if (j < n - 1 && a[j + 1] > a[j]) j++;
        if (a[j] > a[i]){
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        i = j;
    }
}
template <class Item>
void HeapSort(Item a[], int n) {
    int i; Item t;
    for (i = (n - 1)/2; i >= 0; i--) siftDown<int>(a, i, n);
    for (i = n - 1; i > 0; i--) {
        t = a[i];
        a[i] = a[0];
        a[0] = t;
        siftDown<int>(a, 0, i);
    }
}

/* ShellSort : For elems gap largely, make it transfer in large distance, in order to increase Algorithm's performance */
const int d[] = { 4, 3, 1 };
const int t = 3;
template <class Item>
void ShellSort(Item a[], int l, int r) {
    int h, m, i, j; Item v;
    for (m = 0; m < t; ++m)
        for (h = d[m], i = l + h; i <= r; i++, v = a[i]) {
            for (j = i, v = a[i]; j >= l + h && v < a[j - h]; j -= h)
                a[j] = a[j - h];
            a[j] = v;
        }
}
/* The method above all based on "compare-move", now we introduce new method based on "assignment". */
/* radix sort */
int maxbit(int data[], int n)
{
    int maxData = data[0];
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        maxData /= 10;
        ++d;
    }
    return d;
}
void RadixSortLSD(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    int* tmp = new int[n];
    int* count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) //进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for (j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] += count[j - 1]; //将tmp中的位置依次分配给每个桶
        for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete[]tmp;
    delete[]count;
}
void RadixSortMSD(int data[], int n) {
    int d = maxbit(data, n), i, j, k;
    int* tmp = new int[n];
    int* count = new int[10];
    int radix = 1;
    for (i = 0; i < d; ++i) {
        memset(count, 0, 10 * sizeof(int));
        for (int j = 0; j < n; ++j) {
            k = (data[j] / radix) % 10;
            count[k] ++;
        }
        for (int j = 1; j < 10; ++j) count[j] += count[j - 1];
        for (int j = n - 1; j >= 0; j--) {
            k = data[j] / radix % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for (j = 0; j < n; ++j) data[j] = tmp[j];
        radix *= 10;
    }
    delete[]tmp;
    delete[]count;
}

int main() {
    int * a = new int[NUM];
    for (int i = 0; i < NUM; ++i) a[i] = rand();
    //MergeSort<int> (a, 0, NUM-1);
    HeapSort<int>(a, NUM);
    for (int j = 0; j < NUM; ++j) cout << a[j] << '\t';
    delete []a;
    system("pause");
    return 0;
}