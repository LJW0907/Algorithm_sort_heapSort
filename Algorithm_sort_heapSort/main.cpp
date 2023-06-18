#include <iostream>
using namespace std;
//힙정렬
int n, heap[10000001]; //heap 정보가 담긴 배열은 항상 첫 원소가 heap[1]에서 시작한다.

void heapify(int i)
{
	int cur = 2 * i;

	if (cur < n && heap[cur] < heap[cur + 1]) cur++; //오른쪽 노드가 더 크다면 오른쪽 노드 선택

	if (heap[i] < heap[cur]) //가장 큰 자식 노드가 부모 노드보다 크다면
	{
		swap(heap[i], heap[cur]); //서로 바꾼다
		if (cur <= n / 2) heapify(cur); //자식 노드에게도 두 개의 자식 노드가 있다면, 그 부분도 고려해서 바꿈
	}
}

void heapsort(int i)
{
	swap(heap[1], heap[i]); //최대값과 heap 가장 마지막 노드를 바꿈

	int root = 1;
	int cur = 2;

	while (root / 2 < i) //heapify 알고리즘과 비슷하게 다시 heap property 복원
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

	for (int i = n / 2; i > 0; i--) // 최초 heap 생성
		heapify(i);

	for (int i = n; i > 0; i--) // heap 정렬
		heapsort(i);

	for (int j = 1; j <= n; j++) // 출력
		printf("%d ", heap[j]);
}