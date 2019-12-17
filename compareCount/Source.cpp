/*测试环境：VS2019*/

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

const int N = 500;
int a[N], temp[N];
unsigned int count_Exc, count_Com;

inline void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
	count_Exc++;
}

inline void CopyData()
{
	for (int i = 0; i < N; i++)
		temp[N] = a[N];
}

inline int Compare(int a, int b)
{
	count_Com++;
	return a - b;
}

inline void ReadDate()
{
	count_Exc = 0;
	count_Com = 0;
	ifstream datafile("data.txt");
	int i = 0;
	if (!datafile.is_open())
		cout << "无法打开文件data.txt!" << endl;
	else
		while (!datafile.eof() && i < N)
			datafile >> a[i++];
	datafile.close();
}

void CreatData()
{
	ofstream datafile("data.txt");
	for (int i = 0; i < N; i++)
	{
		datafile << rand() << "	";
		if ((i + 1) % 10 == 0)
			datafile << endl;
	}
	datafile.close();
}

void Print()
{
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << "	";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << "******************************************************************************" << endl;
}


void bubbleSort()
{
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (Compare(a[j], a[j + 1]) > 0)
				Swap(a[j], a[j + 1]);
		}
}

void selectSort()
{
	int index;
	for (int i = 0; i < N - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < N; j++)
		{
			if (Compare(a[j], a[index]) < 0)
				index = j;
		}
		Swap(a[i], a[index]);
	}
}

void insertSort()
{
	int preindex, current;
	for (int i = 1; i < N; i++)
	{
		preindex = i - 1;
		current = a[i];
		while (preindex > -1 && Compare(a[preindex], current) > 0)
		{
			a[preindex + 1] = a[preindex];
			count_Exc++;//
			preindex--;
		}
		a[preindex + 1] = current;
		count_Exc++;//
	}
}

void shellSort()
{
	int	temp, gap = 1;
	while (gap < N / 3)
		gap = gap * 3 + 1;
	for (gap; gap > 0; gap = floor(gap / 3))
		for (int i = gap, j; i < N; i++)
		{
			temp = a[i];
			for (j = i - gap; j >= 0 && Compare(a[j], temp) > 0; j -= gap)
			{
				a[j + gap] = a[j];
				count_Exc++;
			}
			a[j + gap] = temp;
			//count_Exc++;
		}
}

void mergeSort(int arry[] = a, int b[] = temp, int left = 0, int right = N - 1)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	mergeSort(arry, temp, left, mid);
	mergeSort(arry, temp, mid + 1, right);

	for (int i = left; i <= right; i++)
		temp[i] = arry[i];

	int i1 = left;
	int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++)
	{
		if (Compare(i1, mid + 1) == 0)
		{
			arry[curr] = temp[i2++];
			count_Exc++;
		}
		else if (Compare(i2, right) > 0)
		{
			arry[curr] = temp[i1++];
			count_Exc++;
		}
		else if (Compare(temp[i1], temp[i2]) < 0)
		{
			arry[curr] = temp[i1++];
			count_Exc++;
		}
		else
		{
			arry[curr] = temp[i2++];
			count_Exc++;
		}
	}
}

void quickSort(int arry[] = a, int left = 0, int right = N - 1)
{
	if (right <= left)
		return;
	int pivotindex = (left + right) / 2;
	Swap(arry[pivotindex], arry[right]);
	//划分
	int L = left - 1, R = right;
	do
	{
		while (Compare(arry[++L], arry[right]) < 0);
		while (L < R && Compare(arry[right], arry[--R]) < 0);
		Swap(arry[L], arry[R]);
	} while (L < R);

	Swap(arry[L], arry[right]);
	quickSort(arry, left, L - 1);
	quickSort(arry, L + 1, right);
}




/**堆排序********************************************/
/**
堆的局部调整方法
*/
void sift(int R[], int low, int high) {      //关键字设定下表从0开始
	int i = low, j = 2 * i + 1;                 //R[j]是R[i]的左孩子节点
	int temp = R[i];
	while (j <= high) {
		if (Compare(j, high) < 0 && Compare(R[j], R[j + 1])< 0) { //   原：j < high && R[j] < R[j + 1]      //若右孩子较大，则j指向右孩子
			j++;                           //j变为2*i+2
		}
		if (Compare(temp, R[j] < 0)) { //  原：
			R[i] = R[j];                  //将R[j]调整到双亲节点的位置
			i = j;                        //修改i和j的值，继续向下调整
			j = 2 * i + 1;
		}
		else {
			break;                       //调整结束
		}
	}
	R[i] = temp;                         //被调整节点放入最终位置
}


/**
堆排序算法主方法
*/
void heapSort(int R[] = a, int n = N) {
	int i;
	int temp;
	for (i = n / 2 - 1; i >= 0; i--) {      //建立初始堆
		sift(R, i, n - 1);
	}
	for (i = n - 1; i > 0; i--) {        //进行n-1次循环，完成堆排序
	/*  temp = R[0];             //一下3句换出根节点的关键字，将其放入最终位置
		R[0] = R[i];
		R[i] = temp;  此段注释内为原来的写法*/
		Swap(R[0], R[i]);
		sift(R, 0, i - 1);           //在减少了一个关键字的无序序列中调整
	}
}

/**********************************************/






int main()
{
	CreatData();
	cout << "排序算法		" << "比较次数		" << "交换次数" << endl;

	ReadDate();
	bubbleSort();
	cout << "冒泡排序		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	selectSort();
	cout << "选择排序		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	insertSort();
	cout << "插入排序		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	shellSort();
	cout << "希尔排序		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	mergeSort();
	cout << "归并排序		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	quickSort();
	cout << "快速排序		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	heapSort();
	cout << "大堆排序		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	//system("pause");
}
