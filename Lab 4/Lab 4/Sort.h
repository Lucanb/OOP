class Sort
{
private:
    void swap(int&, int&);
    void back();
    void qSort(int, int);
    int part(int st, int dr);
public:
    int *v, n;

    Sort(int, int, int);//constructor 1
    Sort(int* a, int b);//constructor 2
    Sort(int n,...);//constructor 3
    Sort(const char*);//constructor 4

    void InsertSort(bool dec = false);//functia cu val initializ.
    void QuickSort(bool dec = false);//functia cu val initializ.
    void BubbleSort(bool dec = false);//functia cu val initializ.

    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int i);
};

