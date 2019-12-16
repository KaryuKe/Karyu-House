#include<queue>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;

struct plane {//飞机的结构体
	int number;//飞机序号
	bool status;//状态，0为降落，1为起飞
	int time;//想要降落或起飞的时间
	int timein;//实际进入轨道进行操作的时间
};
int timeCur = 0;//当前时间
bool flag;//判断是否需要输出“时间计时”
int TimeRecord[10] = { 0 };//对想要的时间建立数组以方便先后对应
void Newplane(queue<plane>* req) {//建立随机飞机队列
	srand(time(0));//随机时间
	plane a;//建立飞机
	
	for (int i = 1; i <= 10; i++)
	{
		a.number = i;//序号从1开始
		a.status = rand() % 2;//状态随机
		a.time = TimeRecord[i-1]+rand()%50;//时间随机
		a.timein = a.time;//默认无需等待
		TimeRecord[i] = a.time;//记录时间
		req->push(a);//Push到队列中
	}
}
string statusCheck(plane a)//检查飞机状态，为0return降落
{
	if (a.status == 0)
		return "降落";
	else
		return "起飞";
}
plane NumVisit(queue<plane> a, int b) {//访问queue中下标为b的元素
	if (a.size() >= (b + 1))
	{
		for (int i = 0; i < b; i++)//弹出b次
		{
			a.pop();
		}
		return a.front();
	}
	else
		cout << "Wrong";
}
int consume(plane a) {//返回对应状态所需时间
	if (a.status == 0)
		return 3;
	else
		return 5;
}
void CheckRunway(queue<plane> * Runway,int timeCur)//检查跑道队列状况
{
	if (!Runway->empty()) {//跑道非空时
		int con;
		plane flying = Runway->front();
		con = consume(flying);//计算消费时间
		if((flying.timein+con)>timeCur)//判断是否已经完成
		{
			if (flag)cout << "时间计时:";
			else cout << "         ";//根据flag选择是否输出
			cout << setw(5) << timeCur << " Y" << flying.number << "号飞机" << statusCheck(flying) << "中……" << endl;
			for (int i = 1; i < Runway->size(); i++)//遍历跑道队列后续成员
			{
				plane checking = NumVisit(*Runway, i);
				cout << "         " << setw(5) << timeCur << " Y" << checking.number << "号飞机" << "等待中……" << endl;
			}
		}
		else
		{
			Runway->pop();//已经完成起飞/降落
			CheckRunway(Runway,timeCur);//再次check当前是否有操作
		}
	}
}
int main() {
	queue<plane> Request;//等待队列
	srand(time(0));
	Newplane(&Request);//填充队列
	int timeCur = 0;//当前时间为0
	cout << "时间计时:" << setw(5) << timeCur << " 机场开启" << endl;//开启机场
	queue<plane> Runway;
		for(;!Request.empty()||!Runway.empty();timeCur++)//在两个队列清空前循环，时间依次向后
		{
			if (!Request.empty())
			{
				plane current = Request.front();//当前飞机为调度队列最前列
				if (timeCur == current.time)//时间一致时
				{
					cout << "时间计时:" << setw(5) << timeCur << " Y" << current.number << "号飞机请求" << statusCheck(current) << endl;
					Runway.push(current);//push到Runway队列中
					Request.pop();//从调度队列中弹出
					while (!Request.empty())//Request队列不空时
					{
						plane toSee = Request.front();//防止后方有同时发出请求的飞机
						if (toSee.time == current.time)
						{
							cout << "         " << setw(5) << timeCur << " Y" << toSee.number << "号飞机请求" << statusCheck(toSee) << endl;
							toSee.timein = current.time + consume(current);
							Runway.push(toSee);
							Request.pop();
						}
						else
							break;
					}
					flag = 0;//无需再次输出时间计时
				}
				else
					flag = 1;//需要再次输出时间计时
			}
			else
				flag = 1;//需要再次输出时间计时
			
			CheckRunway(&Runway,timeCur);//对跑道队列做操作
		}
		cout<<"时间计时:"<< setw(5) <<--timeCur << " 机场关闭" << endl;//最后关闭机场
		system("pause");
}