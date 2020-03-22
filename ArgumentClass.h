//���� ���ڹ��� ����������

#ifndef ARGUMENTCLASS_H_
#define ARGUMENTCLASS_H_
#pragma once

#include<string>
//#include<iostream>

using std::string;
//using std::cin;
//using std::cout;

class ArgumentClass
{
private:
	double lowLine;
	double heiLine;
	double gap;
	string infileName;
	string paraStr;
	string newFileFlag;

//ͨ�� ���� setAllParas()��������private����
void setNewFileFlag();
void setFileName();
void setParaStr();
void  setFreLow();
void  setFreHig();
void  setFreGap();
public:
	string reNewFileFlag(){return newFileFlag;}
	string reInfileName(){return infileName;}
	string reParaStr(){return paraStr;}
	double reLowLine(){return lowLine;}
	double reHeiLine(){return heiLine;}
	double reGap(){return gap;}

//���캯��
	ArgumentClass():newFileFlag("Frequency"),infileName("NoName.txt"),
		paraStr("theta"),lowLine(6.5),heiLine(9.5),gap(0.003)
		{}
   
    ArgumentClass(const string & minfileName,const string & mparaStr,
		const double& mlowLine,const double& mheiLine,const double& mgap,const string& mnewFileFlag="Frequency" )
	:newFileFlag(mnewFileFlag),infileName(minfileName),
		paraStr(mparaStr),lowLine(mlowLine),heiLine(mheiLine),gap(mgap)
		{}

void setAllParas();
	
};
#endif // !ARGUMENTCLASS_H_



