#include "JZOff.h"

/*��Ŀ�������붨��һ�����в�ʵ�ֺ��� max_value �õ�����������ֵ��Ҫ����max_value��push_back �� pop_front 
�ľ�̯ʱ�临�Ӷȶ���O(1)��
������Ϊ�գ�pop_front �� max_value ��Ҫ���� -1*/

/*������
ʹ���������У�һ����ͨ���� �� һ��˫�˶���
��ͨ����������ӡ�����
˫�˶����ڲ���ʱ���ִӶ��׵���βΪ�ݼ��� �������ӵ�Ԫ�ش���˫�˶��еĶ�β�����β���� ֱ����� ���ӵĲ��ù���*/



class MaxQueue {
public:
	MaxQueue() {

	}

	int max_value() {
		if (m_max_queue.empty())
		{
			return -1;
		}
		return m_max_queue.front();
	}

	void push_back(int value) {
		m_queue.push(value);

		//˫�˶������
		while (!m_max_queue.empty() && value > m_max_queue.back())
		{
			m_max_queue.pop_back();
		}
		m_max_queue.push_back(value);
	}

	int pop_front() {
		if (m_queue.empty())
		{
			return -1;
		}

		int front = m_queue.front();
		m_queue.pop();

		//˫�˶��г���
		if (!m_max_queue.empty() && m_max_queue.front() == front)
		{
			m_max_queue.pop_front();
		}

		return front;
	}

private:
	queue<int> m_queue;
	list<int> m_max_queue;  //˫�˶���
};