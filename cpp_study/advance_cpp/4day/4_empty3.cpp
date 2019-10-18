//73 page
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

/*
STL �ݺ���
// �Է� �ݺ��� :		=*p, ++   :�̱� �н�        (����°�����)
// ��� �ݺ���:			*p=, ++  : �̱� �н�

// �Ʒ��� ��Ƽ �н�

// ������ �ݺ���:	*p=, ++ => �̱۸���Ʈ
// ����� �ݺ���:	*p=, ++ , -- => ������Ʈ
// ���� ���� �ݺ���  *p=, ++ , -- , +, -, []
*/

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };


	// find �˰���
	// �ּ� �䱸 ���� : �Է�
	auto p = find(v.begin(), v.end(), 3);

	reverse(v.begin(), v.end());// �����

	sort(v.begin(), v.end());// �� ��Ʈ  ���� ���� : vector�� ����

	list<int>l = { 1,2,3,4 };
	sort(l.begin(), l.end()); // ����Ʈ�� quick sort (������ ������ �ϴµ� �Ұ�) �Ұ�

	// �׷��� list�� ���� sort �Լ� ����. 
	v.sort() // �̹� sort() ���� vector�� sort �� �� ����. ���� �Լ��� ���� �ʿ� ����.	
}
