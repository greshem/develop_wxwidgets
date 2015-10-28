#include "DataEngine.h"
//########################################################################
//通过本地来获取数据. 
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

		//全局菜单
		int RestartNwserv();
		int StopNwserv();
		int StartNwserv();	

		//第一个页面.
		string 	GetServerName();   //服务器名.
		int 	SetServerName(string sername);

		string  GetInnerNetwork(); //内部网络号.
		int 	SetInnerWork(string inner_work);

		string  GetNetwork();      //网络.
		int		SetNetWork(	string network);

		string  GetNIC();          //网卡.
		int		SetNIC(	string nic);

		string  GetFrameType();    //frame帧类型.
		int		SetFrameType( string frame_type);	

		string  GetServerStatus(); //服务器状态.
		string  GetMemoryUsage(); //内存占用率.
		string  GetCpuUsage(); 	  //Cpu占用率.
		string  GetStationCount(); //内存占用率.
		string 	GetPasswd();			//密码.
		int		SetPasswd(string passwd);			//设置密码.
		string GetDialogNic();				
		
		//set

		//------------------------------------------------------------------------
		//第2个页面.
		string GetVolName();
		string GetVolPath();

		void SetVolName(string name );
		void SetVolPath(string path );
		
		bool CheckDirExists(string strServerPath);
	//第三个页面.
	//virtual void GetStationList(	
	void GetAllWorkStation(vector<Workstation> &out);
 	void GetAllWorkStation(vector<response_501> &out);
	int kill_prog(int pid);
	void GetLsofFiles(int,vector<string>&);


	vector<string> Lsof(int i);
	//第4个页面.
	string GetLog(string filename);
		
};

