#include "data_define.h"
#ifndef __DATAENGER__HEADER
#define __DATAENGER__HEADER

//#�ӿ�����.  
//1. ��һ��ҳ��. 
#ifdef WINDOWSCODE
#else
#include <dirent.h>
#endif

#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "protocol.h"
#include "client_request.h"
//#include "tools.h"
using namespace std;



class BaseDataEngine
{
public:
		virtual string GetName();
		virtual int init();
public:
	virtual   	void GetBaseInfo( BaseInfo &out);
	virtual 	void GetShareDir(vector<string> &share_dir);
	
	virtual		void GetAllProcess(vector<nw_process> &out);
	virtual 	void GetNwServLog(vector<string> &logStr);

	//ȫ�ֲ˵�
	virtual		int RestartNwserv();
	virtual 	int StopNwserv();
	virtual		int StartNwserv();	


	//��һ��ҳ��. 
	virtual 		string	 	GetWorkStatus();   //����״̬.
	virtual 		string  	GetServerName();   //��������.
	virtual 		string  	GetInnerNetwork(); //�ڲ������.
	virtual 		string  	GetNetwork();      //����.
	virtual 		string  	GetNIC();          //����.
	virtual 		string  	GetFrameType();    //frame֡����.
	virtual 		string 		GetServerStatus(); //������״̬.
	virtual 		string 		GetMemoryUsage(); //�ڴ�ռ����.
	virtual			string		GetCpuUsage();		//Cpuռ����
	virtual 		string 		GetStationCount(); //�ڴ�ռ����.
	virtual			string  	GetPasswd();			//����.
	virtual 		int		SetPasswd(string passwd);			//��������.

	virtual			string 		GetDialogNic();
	//set
	virtual 	int 	SetServerName(string sername);
	virtual 	int 	SetInnerWork(string inner_work);
	virtual 	int		SetNetWork(	string network);
	virtual 	int		SetNIC(	string nic);
	virtual 	int		SetFrameType( string frame_type);	
	//�ڶ���ҳ��.
	//
	virtual string GetVolName();
	virtual string GetVolPath();

	virtual void SetVolName(string name );
	virtual void SetVolPath(string path );

	virtual bool CheckDirExists(string strServerPath);

	//������ҳ��.
	//virtual void GetStationList(	
	virtual		void GetAllWorkStation(vector<Workstation> &out);
 	virtual		void GetAllWorkStation(vector<response_501> &out);
	virtual		int kill_prog(int pid);
	virtual     void GetLsofFiles(int,vector<string>&);
	//��4��ҳ��.
	virtual string GetLog(string filename );

};



#endif  //__DATAENGER__HEADER

