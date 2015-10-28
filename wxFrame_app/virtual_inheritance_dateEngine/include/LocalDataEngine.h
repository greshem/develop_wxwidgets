#include "DataEngine.h"
//########################################################################
//ͨ����������ȡ����. 
class LocalDataEngine: public BaseDataEngine
{
public:
	string GetName();
	int init();
public:
	void GetBaseInfo( BaseInfo &out);
	void GetShareDir(vector<string> &share_dir);
	void GetAllProcess(vector<nw_process> &out);
	void GetNwServLog(vector<string> &logStr);

		//ȫ�ֲ˵�
		int RestartNwserv();
		int StopNwserv();
		int StartNwserv();	

		//��һ��ҳ��.
		string 	GetServerName();   //��������.
		int 	SetServerName(string sername);

		string  GetInnerNetwork(); //�ڲ������.
		int 	SetInnerWork(string inner_work);

		string  GetNetwork();      //����.
		int		SetNetWork(	string network);

		string  GetNIC();          //����.
		int		SetNIC(	string nic);

		string  GetFrameType();    //frame֡����.
		int		SetFrameType( string frame_type);	

		string  GetServerStatus(); //������״̬.
		string  GetMemoryUsage(); //�ڴ�ռ����.
		string  GetCpuUsage(); 	  //Cpuռ����.
		string  GetStationCount(); //�ڴ�ռ����.
		string 	GetPasswd();			//����.
		int		SetPasswd(string passwd);			//��������.
		string GetDialogNic();				
		
		//set

		//------------------------------------------------------------------------
		//��2��ҳ��.
		string GetVolName();
		string GetVolPath();

		void SetVolName(string name );
		void SetVolPath(string path );
		
		bool CheckDirExists(string strServerPath);
	//������ҳ��.
	//virtual void GetStationList(	
	void GetAllWorkStation(vector<Workstation> &out);
 	void GetAllWorkStation(vector<response_501> &out);
	int kill_prog(int pid);
	void GetLsofFiles(int,vector<string>&);


	vector<string> Lsof(int i);
	//��4��ҳ��.
	string GetLog(string filename);
		
};

