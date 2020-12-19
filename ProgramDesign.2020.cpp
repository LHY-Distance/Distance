#include <iostream>
#include "ProgramDesign2020.h"
using namespace std;
int main()
{
	Welcome(); 
	int i,x,k;
	string s,password;
	cout<<"	请输入登录密码:    ";
	for(i=1;i<=3;i++)
	{
        cin>>password;
		if(password=="123")
		
		    break; 
		else if(i==3)
		{ 
			cout<<"	密码错误3次 爬 "<<endl;
			system("pause");
			return 0;
	    }
	    else
	        cout<<"	密码错误 重新输入： "; 	    
    }
	cout<<"	成功登入"<<endl;
	cout<<"	现导入学生成绩数据"<<endl; 
	cout<<"	请输入需导入的数据文件名及后缀:";
	char Filename[20];
	cin>>Filename;
	Load(Filename);
	Calculation();       
	while(1)
	{	
		Menu();
		cin>>x;
		switch(x)
		{
			case 1: PrintScore(); 			break;
			case 2:	cout<<"	请输入查找人姓名:";
					cin>>s;
					SearchName(s); 			break; 
			case 3: cout<<"	请输入查找人学号:";
					cin>>s;
					SearchNum(s); 			break;
			case 4:	PassRate(stud); 		break;
			case 5:	Export(); 				break;
			case 6:	Maths(); 				break; 
			case 7: English(); 				break;
			case 8: Cplusplus(); 			break;
			case 9: Physics(); 				break; 	
			case 10: cout<<" 请输入学生学号及需要更改的考试科目代号（0-数学；1-英语；2-程序设计；3-物理）：";
					 cin>>s>>k;
					 ModifyScore(s,k); 
					 Calculation();  		break;     //修改成绩后要重新调用Calculation()函数来计算平均分和总分 
			case 11: cout<<" 请输入学生学号:";
					 cin>>s;
					 ModifyInformation(s); 	break;	
			case 12: SubjectSequence(); 	break;
			case 13: ClassSequence(); 		break;
			case 404: return 0;
		} 
		system("pause");
	    system("cls");
	}
	system("pause");
    return 0;
}
