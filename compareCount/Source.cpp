/*���Ի�����VS2019*/

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
		cout << "�޷����ļ�data.txt!" << endl;
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
	//����
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




/**������********************************************/
/**
�ѵľֲ���������
*/
void sift(int R[], int low, int high) {      //�ؼ����趨�±��0��ʼ
	int i = low, j = 2 * i + 1;                 //R[j]��R[i]�����ӽڵ�
	int temp = R[i];
	while (j <= high) {
		if (Compare(j, high) < 0 && Compare(R[j], R[j + 1])< 0) { //   ԭ��j < high && R[j] < R[j + 1]      //���Һ��ӽϴ���jָ���Һ���
			j++;                           //j��Ϊ2*i+2
		}
		if (Compare(temp, R[j] < 0)) { //  ԭ��
			R[i] = R[j];                  //��R[j]������˫�׽ڵ��λ��
			i = j;                        //�޸�i��j��ֵ���������µ���
			j = 2 * i + 1;
		}
		else {
			break;                       //��������
		}
	}
	R[i] = temp;                         //�������ڵ��������λ��
}


/**
�������㷨������
*/
void heapSort(int R[] = a, int n = N) {
	int i;
	int temp;
	for (i = n / 2 - 1; i >= 0; i--) {      //������ʼ��
		sift(R, i, n - 1);
	}
	for (i = n - 1; i > 0; i--) {        //����n-1��ѭ������ɶ�����
	/*  temp = R[0];             //һ��3�任�����ڵ�Ĺؼ��֣������������λ��
		R[0] = R[i];
		R[i] = temp;  �˶�ע����Ϊԭ����д��*/
		Swap(R[0], R[i]);
		sift(R, 0, i - 1);           //�ڼ�����һ���ؼ��ֵ����������е���
	}
}

/**********************************************/






int main()
{
	CreatData();
	cout << "�����㷨		" << "�Ƚϴ���		" << "��������" << endl;

	ReadDate();
	bubbleSort();
	cout << "ð������		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	selectSort();
	cout << "ѡ������		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	insertSort();
	cout << "��������		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	shellSort();
	cout << "ϣ������		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	mergeSort();
	cout << "�鲢����		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	quickSort();
	cout << "��������		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	ReadDate();
	heapSort();
	cout << "�������		" << setw(8) << count_Com << setw(24) << count_Exc << endl;

	//system("pause");
}
