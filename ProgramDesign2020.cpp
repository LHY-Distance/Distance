#include <iostream>
#include "ProgramDesign2020.h"
using namespace std;
int main()
{
	Welcome(); 
	int i,x,k;
	string s,password;
	cout<<"	�������¼����:    ";
	for(i=1;i<=3;i++)
	{
        cin>>password;
		if(password=="123")
		
		    break; 
		else if(i==3)
		{ 
			cout<<"	�������3�� �� "<<endl;
			system("pause");
			return 0;
	    }
	    else
	        cout<<"	������� �������룺 "; 	    
    }
	cout<<"	�ɹ�����"<<endl;
	cout<<"	�ֵ���ѧ���ɼ�����"<<endl; 
	cout<<"	�������赼��������ļ�������׺:";
	char Filename[20];
	cin>>Filename;
	Load(Filename);
	Calculation();       //�Ѽ���ƽ���ֺ��ֵܷĺ�������ѭ������ 
	while(1)
	{	
		Menu();
		cin>>x;
		switch(x)
		{
			case 1: PrintScore(); 			break;
			case 2:	cout<<"	���������������:";
					cin>>s;
					SearchName(s); 			break; 
			case 3: cout<<"	�����������ѧ��:";
					cin>>s;
					SearchNum(s); 			break;
			case 4:	PassRate(stud); 		break;
			case 5:	Export(); 				break;
			case 6:	Maths(); 				break; 
			case 7: English(); 				break;
			case 8: Cplusplus(); 			break;
			case 9: Physics(); 				break; 	
			case 10: cout<<" ������ѧ��ѧ�ż���Ҫ���ĵĿ��Կ�Ŀ���ţ�0-��ѧ��1-Ӣ�2-������ƣ�3-������";
					 cin>>s>>k;
					 ModifyScore(s,k); 
					 Calculation();  		break;
			case 11: cout<<" ������ѧ��ѧ��:";
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

