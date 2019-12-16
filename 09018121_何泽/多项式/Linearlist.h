//���Ա� ����
#pragma once
//LinearList.h
template<class PolyNode>
class LinearList {
public:
	LinearList() {}											//���캯��
	~LinearList() {}										//��������
	virtual int Size()const = 0;							//���������
	virtual int Length()const = 0;							//�����
	virtual int Search(PolyNode& x)const = 0;						//�ڱ�����������ֵx
	virtual int Locate(int i)const = 0;						//�ڱ��ж�λ��i��Ԫ��λ��
	virtual bool getData(int i, PolyNode& x)const = 0;				//ȡ��i�������ֵ
	virtual void setData(int i, PolyNode& x) = 0;					//�޸ĵ�i�������ֵΪx
	virtual bool Insert(int i, PolyNode& x) = 0;					//�ڵ�i����������x
	virtual bool Remove(int i, PolyNode& x) = 0;					//ɾ����i�����ͨ��x����
	virtual bool IsEmpty()const = 0;						//�б��
	virtual bool IsFull()const = 0;							//�б���
	virtual void Sort() = 0;								//����
	virtual void Input() = 0;								//����
	virtual void Output() = 0;								//���
}; 