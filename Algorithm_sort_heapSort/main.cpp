#include <iostream>
using namespace std;
//������
int n, heap[10000001]; //heap ������ ��� �迭�� �׻� ù ���Ұ� heap[1]���� �����Ѵ�.

void heapify(int i)
{
	int cur = 2 * i;

	if (cur < n && heap[cur] < heap[cur + 1]) cur++; //������ ��尡 �� ũ�ٸ� ������ ��� ����

	if (heap[i] < heap[cur]) //���� ū �ڽ� ��尡 �θ� ��庸�� ũ�ٸ�
	{
		swap(heap[i], heap[cur]); //���� �ٲ۴�
		if (cur <= n / 2) heapify(cur); //�ڽ� ��忡�Ե� �� ���� �ڽ� ��尡 �ִٸ�, �� �κе� ����ؼ� �ٲ�
	}
}

void heapsort(int i)
{
	swap(heap[1], heap[i]); //�ִ밪�� heap ���� ������ ��带 �ٲ�

	int root = 1;
	int cur = 2;

	while (root / 2 < i) //heapify �˰���� ����ϰ� �ٽ� heap property ����
	{
		cur = 2 * root;
		if (cur < i - 1 && heap[cur] < heap[cur + 1]) cur++;
		if (cur < i && heap[root] < heap[cur])
			swap(heap[root], heap[cur]);

		root = cur;
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> heap[i];

	for (int i = n / 2; i > 0; i--) // ���� heap ����
		heapify(i);

	for (int i = n; i > 0; i--) // heap ����
		heapsort(i);

	for (int j = 1; j <= n; j++) // ���
		printf("%d ", heap[j]);
}