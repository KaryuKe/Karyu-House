#include<queue>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;

struct plane {//�ɻ��Ľṹ��
	int number;//�ɻ����
	bool status;//״̬��0Ϊ���䣬1Ϊ���
	int time;//��Ҫ�������ɵ�ʱ��
	int timein;//ʵ�ʽ��������в�����ʱ��
};
int timeCur = 0;//��ǰʱ��
bool flag;//�ж��Ƿ���Ҫ�����ʱ���ʱ��
int TimeRecord[10] = { 0 };//����Ҫ��ʱ�佨�������Է����Ⱥ��Ӧ
void Newplane(queue<plane>* req) {//��������ɻ�����
	srand(time(0));//���ʱ��
	plane a;//�����ɻ�
	
	for (int i = 1; i <= 10; i++)
	{
		a.number = i;//��Ŵ�1��ʼ
		a.status = rand() % 2;//״̬���
		a.time = TimeRecord[i-1]+rand()%50;//ʱ�����
		a.timein = a.time;//Ĭ������ȴ�
		TimeRecord[i] = a.time;//��¼ʱ��
		req->push(a);//Push��������
	}
}
string statusCheck(plane a)//���ɻ�״̬��Ϊ0return����
{
	if (a.status == 0)
		return "����";
	else
		return "���";
}
plane NumVisit(queue<plane> a, int b) {//����queue���±�Ϊb��Ԫ��
	if (a.size() >= (b + 1))
	{
		for (int i = 0; i < b; i++)//����b��
		{
			a.pop();
		}
		return a.front();
	}
	else
		cout << "Wrong";
}
int consume(plane a) {//���ض�Ӧ״̬����ʱ��
	if (a.status == 0)
		return 3;
	else
		return 5;
}
void CheckRunway(queue<plane> * Runway,int timeCur)//����ܵ�����״��
{
	if (!Runway->empty()) {//�ܵ��ǿ�ʱ
		int con;
		plane flying = Runway->front();
		con = consume(flying);//��������ʱ��
		if((flying.timein+con)>timeCur)//�ж��Ƿ��Ѿ����
		{
			if (flag)cout << "ʱ���ʱ:";
			else cout << "         ";//����flagѡ���Ƿ����
			cout << setw(5) << timeCur << " Y" << flying.number << "�ŷɻ�" << statusCheck(flying) << "�С���" << endl;
			for (int i = 1; i < Runway->size(); i++)//�����ܵ����к�����Ա
			{
				plane checking = NumVisit(*Runway, i);
				cout << "         " << setw(5) << timeCur << " Y" << checking.number << "�ŷɻ�" << "�ȴ��С���" << endl;
			}
		}
		else
		{
			Runway->pop();//�Ѿ�������/����
			CheckRunway(Runway,timeCur);//�ٴ�check��ǰ�Ƿ��в���
		}
	}
}
int main() {
	queue<plane> Request;//�ȴ�����
	srand(time(0));
	Newplane(&Request);//������
	int timeCur = 0;//��ǰʱ��Ϊ0
	cout << "ʱ���ʱ:" << setw(5) << timeCur << " ��������" << endl;//��������
	queue<plane> Runway;
		for(;!Request.empty()||!Runway.empty();timeCur++)//�������������ǰѭ����ʱ���������
		{
			if (!Request.empty())
			{
				plane current = Request.front();//��ǰ�ɻ�Ϊ���ȶ�����ǰ��
				if (timeCur == current.time)//ʱ��һ��ʱ
				{
					cout << "ʱ���ʱ:" << setw(5) << timeCur << " Y" << current.number << "�ŷɻ�����" << statusCheck(current) << endl;
					Runway.push(current);//push��Runway������
					Request.pop();//�ӵ��ȶ����е���
					while (!Request.empty())//Request���в���ʱ
					{
						plane toSee = Request.front();//��ֹ����ͬʱ��������ķɻ�
						if (toSee.time == current.time)
						{
							cout << "         " << setw(5) << timeCur << " Y" << toSee.number << "�ŷɻ�����" << statusCheck(toSee) << endl;
							toSee.timein = current.time + consume(current);
							Runway.push(toSee);
							Request.pop();
						}
						else
							break;
					}
					flag = 0;//�����ٴ����ʱ���ʱ
				}
				else
					flag = 1;//��Ҫ�ٴ����ʱ���ʱ
			}
			else
				flag = 1;//��Ҫ�ٴ����ʱ���ʱ
			
			CheckRunway(&Runway,timeCur);//���ܵ�����������
		}
		cout<<"ʱ���ʱ:"<< setw(5) <<--timeCur << " �����ر�" << endl;//���رջ���
		system("pause");
}