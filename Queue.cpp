#pragma hdrstop

#include "Queue.h"

Queue :: ~Queue()
{
	while(Head)
	{
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}

void Queue :: Show(TListBox *ListBox1)
{
	Node *temp;
	temp = Head;
	while (temp != NULL)
	{
		ListBox1->Items->Add(temp->x);   //����� � ListBox1
		temp = temp->Next;
    }
}

void Queue :: Add(int x)
{
	Node *temp = new Node;
	temp->Next = NULL;
	temp->x = x;
	if (Head != NULL)         //���� ������ �� ������
	{
		temp->Prev = Tail;
		Tail->Next = temp;
		Tail = temp;
	}
	else                      //���� ������ ������
	{
		temp->Prev = NULL;    //����� ������� ������
		Head = Tail = temp;   //(������������ ������ � ����� �������)
    }
}

void Queue :: Delete(TEdit *Edit1)
{
	if (Head == NULL)        //���� ������ ������
	{
		Application->Title = "��������";
		ShowMessage("������� �����");
	}
	else                     //���� ������ �� ������
	{
		Node *temp;
		temp = Head->Next;
		delete Head;         //������� ������ �������
		Head = temp;         //������� ��������� �� ����� ������ �������
        Edit1->Text = IntToStr(StrToInt(Edit1->Text) - 1);
    }
}

void Queue :: IsEmpty(TEdit *Edit1)
{
	Application->Title = "Is empty?";
	if (Head != NULL)
	{
		ShowMessage("� ������� ���������: " + (Edit1->Text));
	}
	else
		ShowMessage("������� �����");
}

#pragma package(smart_init)
