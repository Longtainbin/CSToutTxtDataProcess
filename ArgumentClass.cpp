#include "ArgumentClass.h"
#include<string>
#include<iostream>
#include<regex>

using std::string;
using std::cin;
using std::cout;
using std::endl;

//���뺯����ģ��
template<typename T>
void  getParas(T & val,const unsigned int step,const string& str)
{
std::cout<<"���� "<<step<<":"<<str<<std::endl;
    while ((!(cin >> val)))
    {
        cin.clear();
        while (cin.get()!='\n')
            continue;
       std::cout<<"���� "<<step<<":"<<str<<std::endl;; 
    }
}

//���뺯��ģ���std::string���;��廯
template<>
void getParas<std::string>(std::string& val, const unsigned int step, const string& str)
{
std::cout<<"���� "<<step<<":"<<str<<std::endl;
getline(cin,val);
std::smatch sm;
std::regex pattern("[\\s]*(\\S+)[\\s]*"); //�ж��Ƿ��ǿհ��ַ���
bool rgeFlg=std::regex_search(val, sm, pattern);

while ((val.size()==0)||rgeFlg==false)
{
std::cout<<"���� "<<step<<":"<<str<<std::endl;
getline(cin,val);
rgeFlg=std::regex_search(val, sm, pattern);
}
val=sm[1].str();
}


//����������ļ���
void ArgumentClass::setFileName()
{
getParas(infileName,1,"�������������ļ���(���磺S11Theta.txt ע��:���ļ�Ӧ���α��������ͬһĿ¼��)");
}

//�������ļ��������ַ���
void ArgumentClass::setNewFileFlag()
{
getParas(newFileFlag,2,"�����봴�����ļ��ı�־���ַ���(���磺Frequency)");
}


//����ɨ�����
void ArgumentClass::setParaStr()
{
getParas(paraStr,3,"����ǲ���ɨ�������룺ɨ��Ĳ���(���磺theta); ������ǽ��в���ɨ��,������: mydata");

}
//����Ƶ��
void  ArgumentClass::setFreLow()
{
getParas<double>(lowLine,4,"�������ֹƵ������(����:6.5)");
}

void  ArgumentClass::setFreHig()
{
getParas<double>(heiLine,5,"�������ֹƵ������(����:9.5)");
}

void  ArgumentClass::setFreGap()
{
getParas<double>(gap,6,"������Ƶ�ʼ��(����:0.003)");

}

void ArgumentClass::setAllParas()
{
setFileName();
setNewFileFlag();
setParaStr();
setFreLow();
setFreHig();
while (lowLine > heiLine)
{
std::cout<<"\"��ֹƵ������\"Ӧ��С��\"��ֹƵ������\"�� �����������ֹƵ��"<<std::endl;
setFreLow();
setFreHig();
}
setFreGap();
while ((gap>heiLine-lowLine)||(gap<0))
{
std::cout<<"Ƶ�ʼ�� ������С! ���������� Ƶ�ʼ��"<<std::endl;
setFreGap();
}
}
