#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std; 
struct student
{
	string num;
	string name;
	float score[4];
	float average; 
	float total;
}stud[50];
int n;
float a[6]={0};
float S[6];
void Menu()
{
	cout<<"	����ѡ�����¹���"<<endl;
    cout<<" *******************************"<<endl; 
	cout<<" 1�����ѧ���ɼ���"<<endl;
	cout<<" 2��������ѯĳͬѧ�ķ���"<<endl;
	cout<<" 3��ѧ�Ų�ѯĳͬѧ�ķ���"<<endl;
	cout<<" 4��ͳ�Ƽ�����"<<endl;
	cout<<" 5���������ļ�"<<endl;
	cout<<" 6����ʾ��ѧ�ɼ�"<<endl; 
	cout<<" 7����ʾӢ��ɼ�"<<endl; 
	cout<<" 8����ʾ������Ƴɼ�"<<endl; 
	cout<<" 9����ʾ����ɼ�"<<endl; 
	cout<<" 10���޸�ѧ���ɼ�"<<endl; 
	cout<<" 11���޸�ѧ��������Ϣ"<<endl;
	cout<<" 12����Ŀ����"<<endl;
	cout<<" 13��ȫ������"<<endl; 
	cout<<" 404���˳�  "<<endl;
	cout<<" *******************************"<<endl; 
	cout<<" ����������ѡ���Ӧ���ܣ�        ";
}

void Welcome()
{
	cout<<"	��ӭ����ѧ���ɼ�ϵͳ"<<endl;
	cout<<"**С���Ա�������� ������ �α���**"<<endl;
	cout<<"	�����������ϵͳ"<<endl;
	system("pause");
}

void Load(char s[20]) 
{
	int i,j;
	ifstream infile;
	infile.open(s);
	infile>>n;
	for(i=0; i<n; i++)      //  �ļ����ݶ��뵽�ṹ������ 
    { 
		infile>>stud[i].num;
		infile>>stud[i].name;
		infile>>stud[i].score[0];
		infile>>stud[i].score[1];
		infile>>stud[i].score[2];
		infile>>stud[i].score[3];  
	}
	infile.close();	
}

void Calculation()
{
	int i,j;
	float sum;
	for(i=0;i<n;i++)
	{
		stud[i].total=stud[i].score[0]+stud[i].score[1]+stud[i].score[2]+stud[i].score[3]; 
		stud[i].average=stud[i].total/4;
	}
	for(i=0;i<4;i++)
	{
		sum=0; 
		for(j=0;j<n;j++)
			sum+=stud[j].score[i];
		a[i]=sum/n;
	}	
	for(i=0;i<n;i++)
	{
		a[4]+=stud[i].average;
		a[5]+=stud[i].total;
	}
	a[4]/=n;
	a[5]/=n;
}

void Export()
{
  	ofstream  outfile;
  	outfile.open("cjb.txt"); 
    outfile<< setw(12) << "ѧ��" << setw(30) << "����"  << setw(27) << "��ѧ�ɼ�"<<setw(13)<<"Ӣ��ɼ�" << setw(17)<< "������Ƴɼ�"<<setw(15)<<"����ɼ�"<<setw(15)<<"ƽ���ɼ�"<<setw(12)<<"�ܷ�"<<endl;
  	for(int i=0; i<n; i++)     
    {  
    	outfile<<setw(12)<<stud[i].num<<'\t';
 		outfile<<setw(12)<<stud[i].name<<'\t';
 		outfile<<setw(10)<<fixed<<setprecision(1)<<stud[i].score[0]<<setw(15) <<stud[i].score[1]<<setw(19)<<stud[i].score[2]<<setw(20)<<stud[i].score[3]<<setw(18)<<fixed<<setprecision(1)<<stud[i].average<<setw(15)<<stud[i].total<<endl;
    }
    outfile<<setw(12)<<"ƽ����"<<setw(58)<<fixed<<setprecision(1)<<a[0]<<setw(15)<<a[1]<<setw(19)<<a[2]<<setw(20)<<a[3]<<setw(18)<<a[4]<<setw(15)<<a[5]<<endl;
    outfile.close();
 	cout<<"\n�ļ������ɹ�\n";    
}

void PrintScore()
{
	cout<<"		����1-��ʾѧ���ɼ���"<<endl;
	cout<< setw(12) << "ѧ��" << setw(15) << "����"  << setw(12) << "��ѧ�ɼ�"<<setw(12)<<"Ӣ��ɼ�" << setw(16)<< "������Ƴɼ�"<<setw(12)<<"����ɼ�"<<setw(12)<<"ƽ���ɼ�"<<setw(12)<<"�ܷ�"<<endl;
  	for(int i=0; i<n; i++)     
    {  
    	cout<<setw(12)<<stud[i].num<<setw(15)<<stud[i].name;
 		cout<<setw(12)<<fixed<<setprecision(1)<<stud[i].score[0]<<setw(12) <<stud[i].score[1]<<setw(16)<<stud[i].score[2]<<setw(12)<<stud[i].score[3]<<setw(12)<<fixed<<setprecision(1)<<stud[i].average<<setw(12)<<stud[i].total<<endl;
    }
    cout<<setw(12)<<"ƽ����"<<setw(27)<<fixed<<setprecision(1)<<a[0]<<setw(12)<<a[1]<<setw(16)<<a[2]<<setw(12)<<a[3]<<setw(12)<<a[4]<<setw(12)<<a[5]<<endl;	
}

void SearchName(string s)
{
	int count=0;
	cout<<"	����2-������ѯĳͬѧ�ķ���"<<endl; 
	for(int i;i<n;i++)
	{
		
		if(s==stud[i].name)
		{
			cout<<setw(12)<<"ѧ��"<<setw(15)<<"����"<<setw(5)<<"��ѧ"<<setw(5)<<"Ӣ��"<<setw(10)<<"�������"<<setw(5)<<"����"<<setw(12)<<"����ƽ����"<<setw(10)<<"�����ܷ�"<<endl; 
			cout<<setw(12) <<stud[i].num<<setw(15) <<stud[i].name;
			cout<<setw(5) <<stud[i].score[0]<<setw(5) <<stud[i].score[1];
			cout<<setw(10) <<stud[i].score[2]<<setw(5) <<stud[i].score[3]<<setw(12)<<stud[i].average<<setw(10)<<stud[i].total<<endl;
			count=1;
		}		
	}    
	if(count==0)   cout<<"	��Ǹ�����޴���";       
}

void SearchNum(string s)
{
	int count=0;	
	cout<<"	����3-ѧ�Ų�ѯĳͬѧ�ķ���"<<endl; 
	for(int i;i<n;i++)
	{
	
		if(s==stud[i].num)
		{
			cout<<setw(12)<<"ѧ��"<<setw(15)<<"����"<<setw(5)<<"��ѧ"<<setw(5)<<"Ӣ��"<<setw(10)<<"�������"<<setw(5)<<"����"<<setw(12)<<"����ƽ����"<<setw(10)<<"�����ܷ�"<<endl; 
			cout<<setw(12) <<stud[i].num<<setw(15) <<stud[i].name;
			cout<<setw(5) <<stud[i].score[0]<<setw(5) <<stud[i].score[1];
			cout<<setw(10) <<stud[i].score[2]<<setw(5) <<stud[i].score[3]<<setw(12)<<stud[i].average<<setw(10)<<stud[i].total<<endl;
			count=1;
		}	
	} 
	if(count==0)   cout<<"	��Ǹ�����޴���";         
}

void PassRate(student stud[])
{
    int h,y,i,r,a;
	int large(float, float);
	char c[20];
	cout<<"����4-ͳ�Ƽ�����"<<endl;            
	cout<<"�����뿼�Կ�Ŀ���ţ�0-��ѧ��1-Ӣ�2-������ƣ�3-�������Ծ�����:     "; 
	cin>>a>>h; 
	y=0;
    h=0.6*h;
	for (i=0; i<=n; i++)
	{
		if ((r=large(stud[i].score[a],h)==1)) 
			y++;
	}
	switch(a)
	{
		case 0: strcpy(c,"��ѧ"); break;
		case 1: strcpy(c,"Ӣ��"); break;
		case 2: strcpy(c,"�������"); break;
		case 3: strcpy(c,"����"); break;
	}
	cout<<"	 "<<c<<"������Ϊ��"<<fixed<<setprecision(2)<<1.0*y/n*100<<'%'<<endl; 	
}
int large(float x, float y)  //�˴��Զ�����һ������ �������� ����ϵͳ�е�ͳ�Ƽ����ʹ��� 
{
	int flag;
	if (x>=y)
	    flag=1;
	else 
	    flag=0;
	return(flag);
}

void Maths()
{
	int i;
	cout<<"	��ѧ�ɼ����£�"<<endl;	
	for(i=0;i<n;i++)
		cout<<setw(15)<<stud[i].name<<setw(10)<<stud[i].score[0]<<endl;
} 
void English()
{
	int i;
	cout<<"	Ӣ��ɼ����£�"<<endl; 
	for(i=0;i<n;i++)
		cout<<setw(15)<<stud[i].name<<setw(10)<<stud[i].score[1]<<endl;
} 
void Cplusplus()
{
	int i;
	cout<<"	������Ƴɼ����£�"<<endl; 
	for(i=0;i<n;i++)
		cout<<setw(15)<<stud[i].name<<setw(10)<<stud[i].score[2]<<endl;
} 
void Physics()
{
	int i;
	cout<<"	����ɼ����£�"<<endl; 
	for(i=0;i<n;i++)
		cout<<setw(15)<<stud[i].name<<setw(10)<<stud[i].score[3]<<endl;
} 

void ModifyScore(string s,int a)
{
	for(int i=0;i<n;i++)
		if(stud[i].num==s)
		{
			cout<<"����������³ɼ�:";
			cin>>stud[i].score[a];
		}			
	cout<<"�����޸ĳɹ�."<<endl;
	cout<<"ͬʱ������������¼������."<<endl; 	
}

void ModifyInformation(string s)
{
	for(int i=0;i<n;i++)
		if(stud[i].num==s)
			{
				cout<<"���������ѧ��ѧ�ź�������";
				cin>>stud[i].num>>stud[i].name;
			}			
	cout<<"��Ϣ�޸ĳɹ�."<<endl;
}

void SubjectSequence()
{
	int i,j,x;
	int p,t;
	int b[6]={0,1,2,3,4,5};
	char c[10];
	cout<<"�����뿼�Կ�Ŀ����(0-��ѧ��1-Ӣ�2-������ƣ�3-����): ";
	cin>>x;
	switch(x)
	{
		case 0: strcpy(c,"��ѧ"); break;
		case 1: strcpy(c,"Ӣ��"); break;
		case 2: strcpy(c,"�������"); break;
		case 3: strcpy(c,"����"); break;
	}
	for(i=0;i<n;i++)
		S[i]=stud[i].score[x];
	for(i=0;i<n-1;i++)
	{	
		p=i;
		for(j=i+1;j<n;j++)
			if(S[j]>S[p])
				p=j;		
		if(p!=i)
		{
			t=S[p]; S[p]=S[i]; S[i]=t;
			t=b[p]; b[p]=b[i]; b[i]=t;
		} 	
	}
	cout<<c<<"�������£�"<<endl; 
	cout<<"����"<<endl; 
	int k=1;
	for(i=0;i<n;i++)
		cout<<setw(4)<<k++<<setw(15)<<stud[b[i]].name<<setw(10)<<S[i]<<endl;

} 

void ClassSequence()
{
	int i,j,p,t;
	int b[6]={0,1,2,3,4,5};
	for(i=0;i<n;i++)
		S[i]=stud[i].total;     
	for(i=0;i<n-1;i++)            //����ɨ����� 
	{	
		p=i;
		for(j=i+1;j<n;j++)         //j�����±�仯 
			if(S[j]>S[p])     
				p=j;		//����ÿһ�����ֵ���ڵ�λ�� 
		if(p!=i)
		{
			t=S[p]; S[p]=S[i]; S[i]=t;
			t=b[p]; b[p]=b[i]; b[i]=t;
		} 	
	}
	int k=1;
	cout<<"ȫ���������£�"<<endl; 
	cout<<"����"<<endl; 
	for(i=0;i<n;i++)
		cout<<setw(3)<<k++<<setw(15)<<stud[b[i]].name<<setw(10)<<S[i]<<endl;                                                                                                                                            
}

