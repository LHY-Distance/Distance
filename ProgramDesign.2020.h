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
	cout<<"	现请选择以下功能"<<endl;
    cout<<" *******************************"<<endl; 
	cout<<" 1、输出学生成绩表"<<endl;
	cout<<" 2、姓名查询某同学的分数"<<endl;
	cout<<" 3、学号查询某同学的分数"<<endl;
	cout<<" 4、统计及格率"<<endl;
	cout<<" 5、导出到文件"<<endl;
	cout<<" 6、显示数学成绩"<<endl; 
	cout<<" 7、显示英语成绩"<<endl; 
	cout<<" 8、显示程序设计成绩"<<endl; 
	cout<<" 9、显示物理成绩"<<endl; 
	cout<<" 10、修改学生成绩"<<endl; 
	cout<<" 11、修改学生个人信息"<<endl;
	cout<<" 12、科目排名"<<endl;
	cout<<" 13、全班排名"<<endl; 
	cout<<" 404、退出  "<<endl;
	cout<<" *******************************"<<endl; 
	cout<<" 请输入数字选择对应功能：        ";
}

void Welcome()
{
	cout<<"	欢迎进入学生成绩系统"<<endl;
	cout<<"**小组成员：梁惠怡 刘柳宏 何秉熹**"<<endl;
	cout<<"	按任意键进入系统"<<endl;
	system("pause");
}

void Load(char s[20]) 
{
	int i,j;
	ifstream infile;
	infile.open(s);
	infile>>n;
	for(i=0; i<n; i++)      //  文件数据读入到结构体数组 
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
    outfile<< setw(12) << "学号" << setw(30) << "姓名"  << setw(27) << "数学成绩"<<setw(13)<<"英语成绩" << setw(17)<< "程序设计成绩"<<setw(15)<<"物理成绩"<<setw(15)<<"平均成绩"<<setw(12)<<"总分"<<endl;
  	for(int i=0; i<n; i++)     
    {  
    	outfile<<setw(12)<<stud[i].num<<'\t';
 		outfile<<setw(12)<<stud[i].name<<'\t';
 		outfile<<setw(10)<<fixed<<setprecision(1)<<stud[i].score[0]<<setw(15) <<stud[i].score[1]<<setw(19)<<stud[i].score[2]<<setw(20)<<stud[i].score[3]<<setw(18)<<fixed<<setprecision(1)<<stud[i].average<<setw(15)<<stud[i].total<<endl;
    }
    outfile<<setw(12)<<"平均分"<<setw(58)<<fixed<<setprecision(1)<<a[0]<<setw(15)<<a[1]<<setw(19)<<a[2]<<setw(20)<<a[3]<<setw(18)<<a[4]<<setw(15)<<a[5]<<endl;
    outfile.close();
 	cout<<"\n文件导出成功\n";    
}

void PrintScore()
{
	cout<<"		功能1-显示学生成绩表"<<endl;
	cout<< setw(12) << "学号" << setw(15) << "姓名"  << setw(12) << "数学成绩"<<setw(12)<<"英语成绩" << setw(16)<< "程序设计成绩"<<setw(12)<<"物理成绩"<<setw(12)<<"平均成绩"<<setw(12)<<"总分"<<endl;
  	for(int i=0; i<n; i++)     
    {  
    	cout<<setw(12)<<stud[i].num<<setw(15)<<stud[i].name;
 		cout<<setw(12)<<fixed<<setprecision(1)<<stud[i].score[0]<<setw(12) <<stud[i].score[1]<<setw(16)<<stud[i].score[2]<<setw(12)<<stud[i].score[3]<<setw(12)<<fixed<<setprecision(1)<<stud[i].average<<setw(12)<<stud[i].total<<endl;
    }
    cout<<setw(12)<<"平均分"<<setw(27)<<fixed<<setprecision(1)<<a[0]<<setw(12)<<a[1]<<setw(16)<<a[2]<<setw(12)<<a[3]<<setw(12)<<a[4]<<setw(12)<<a[5]<<endl;	
}

void SearchName(string s)
{
	int count=0;
	cout<<"	功能2-姓名查询某同学的分数"<<endl; 
	for(int i;i<n;i++)
	{
		
		if(s==stud[i].name)
		{
			cout<<setw(12)<<"学号"<<setw(15)<<"姓名"<<setw(5)<<"数学"<<setw(5)<<"英语"<<setw(10)<<"程序设计"<<setw(5)<<"物理"<<setw(12)<<"个人平均分"<<setw(10)<<"个人总分"<<endl; 
			cout<<setw(12) <<stud[i].num<<setw(15) <<stud[i].name;
			cout<<setw(5) <<stud[i].score[0]<<setw(5) <<stud[i].score[1];
			cout<<setw(10) <<stud[i].score[2]<<setw(5) <<stud[i].score[3]<<setw(12)<<stud[i].average<<setw(10)<<stud[i].total<<endl;
			count=1;
		}		
	}    
	if(count==0)   cout<<"	抱歉，查无此人";       
}

void SearchNum(string s)
{
	int count=0;	
	cout<<"	功能3-学号查询某同学的分数"<<endl; 
	for(int i;i<n;i++)
	{
	
		if(s==stud[i].num)
		{
			cout<<setw(12)<<"学号"<<setw(15)<<"姓名"<<setw(5)<<"数学"<<setw(5)<<"英语"<<setw(10)<<"程序设计"<<setw(5)<<"物理"<<setw(12)<<"个人平均分"<<setw(10)<<"个人总分"<<endl; 
			cout<<setw(12) <<stud[i].num<<setw(15) <<stud[i].name;
			cout<<setw(5) <<stud[i].score[0]<<setw(5) <<stud[i].score[1];
			cout<<setw(10) <<stud[i].score[2]<<setw(5) <<stud[i].score[3]<<setw(12)<<stud[i].average<<setw(10)<<stud[i].total<<endl;
			count=1;
		}	
	} 
	if(count==0)   cout<<"	抱歉，查无此人";         
}

void PassRate(student stud[])      
{
    int h,y,i,r,a;
	int large(float, float);
	char c[20];
	cout<<"功能4-统计及格率"<<endl;            
	cout<<"请输入考试科目代号（0-数学；1-英语；2-程序设计；3-物理）及试卷满分:     "; 
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
		case 0: strcpy(c,"数学"); break;
		case 1: strcpy(c,"英语"); break;
		case 2: strcpy(c,"程序设计"); break;
		case 3: strcpy(c,"物理"); break;
	}
	cout<<"	 "<<c<<"及格率为："<<fixed<<setprecision(2)<<1.0*y/n*100<<'%'<<endl; 	
}
int large(float x, float y)  //此处自定义了一个函数 作用如下 用于系统中的统计及格率功能
{
	int flag;
	if (x>=y)     //x即为stud[i].score[a] 
	    flag=1;
	else 
	    flag=0;
	return(flag);
}

void Maths()
{
	int i;
	cout<<"	数学成绩如下："<<endl;	
	for(i=0;i<n;i++)
		cout<<setw(15)<<stud[i].name<<setw(10)<<stud[i].score[0]<<endl;
} 
void English()
{
	int i;
	cout<<"	英语成绩如下："<<endl; 
	for(i=0;i<n;i++)
		cout<<setw(15)<<stud[i].name<<setw(10)<<stud[i].score[1]<<endl;
} 
void Cplusplus()
{
	int i;
	cout<<"	程序设计成绩如下："<<endl; 
	for(i=0;i<n;i++)
		cout<<setw(15)<<stud[i].name<<setw(10)<<stud[i].score[2]<<endl;
} 
void Physics()
{
	int i;
	cout<<"	物理成绩如下："<<endl; 
	for(i=0;i<n;i++)
		cout<<setw(15)<<stud[i].name<<setw(10)<<stud[i].score[3]<<endl;
} 

void ModifyScore(string s,int a)
{
	for(int i=0;i<n;i++)
		if(stud[i].num==s)
		{
			cout<<"输入更正的新成绩:";
			cin>>stud[i].score[a];
		}			
	cout<<"数据修改成功."<<endl;
	cout<<"同时相关数据已重新计算完成."<<endl; 	
}

void ModifyInformation(string s)
{
	for(int i=0;i<n;i++)
		if(stud[i].num==s)
			{
				cout<<"输入更正的学生学号和姓名：";
				cin>>stud[i].num>>stud[i].name;
			}			
	cout<<"信息修改成功."<<endl;
}

void SubjectSequence()
{
	int i,j,x;
	int p,t;
	int b[6]={0,1,2,3,4,5};
	char c[10];
	cout<<"请输入考试科目代号(0-数学；1-英语；2-程序设计；3-物理): ";
	cin>>x;
	switch(x)
	{
		case 0: strcpy(c,"数学"); break;      //用strcpy()函数实现字符数组的赋值 
		case 1: strcpy(c,"英语"); break;
		case 2: strcpy(c,"程序设计"); break;
		case 3: strcpy(c,"物理"); break;
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
	cout<<c<<"排名如下："<<endl; 
	cout<<"名次"<<endl; 
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
	for(i=0;i<n-1;i++)            //控制扫描次数 
	{	
		p=i;
		for(j=i+1;j<n;j++)         //j控制下标变化 
			if(S[j]>S[p])     
				p=j;		//记下每一趟最大值所在的位置 
		if(p!=i)
		{
			t=S[p]; S[p]=S[i]; S[i]=t;
			t=b[p]; b[p]=b[i]; b[i]=t;
		} 	
	}
	int k=1;
	cout<<"全班排名如下："<<endl; 
	cout<<"名次"<<endl; 
	for(i=0;i<n;i++)
		cout<<setw(3)<<k++<<setw(15)<<stud[b[i]].name<<setw(10)<<S[i]<<endl;                                                                                                                                            
}
