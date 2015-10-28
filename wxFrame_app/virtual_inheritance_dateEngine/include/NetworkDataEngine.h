#include <sys/stat.h>
#include "DataEngine.h"
#include "../network/client/client_request.h"
#include "../network/client/Client_reponse_data_dump.h"

#ifndef NETWORK_DATAENGINE_HEADER
#define NETWORK_DATAENGINE_HEADER
//########################################################################
//通过网络获取数据， 最后的数据还是通过  服务器上的LocalDataEngine 对象 来获取的, 中间加了一层 网络协议, 
class NetworkDataEngine: public BaseDataEngine
{
private:
		Client m_client;
		Client_reponse_data_dump m_data_storage;
	
public:
	string GetName();
	int 	init();
public:
	NetworkDataEngine();
	~NetworkDataEngine();
	void GetBaseInfo( BaseInfo &out);
	void GetShareDir(vector<string> &share_dir);
	void GetAllProcess(vector<nw_process> &out);
	void GetNwServLog(vector<string> &logStr);

	//全局菜单
		int RestartNwserv();
		int StopNwserv();
		int StartNwserv();	

//第一个页面.
		string 	GetWorkStatus();   //工作状态.

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
		string  GetStationCount(); //得到客户端数量.
		string GetPasswd();			//密码.
		int		SetPasswd(string passwd);			//设置密码.
		
		string GetDialogNic();				//对话框关于服务器的网卡号

	//第2个页面.
		string  GetVolName();
		string  GetVolPath();

		void SetVolName(string name );
		void SetVolPath(string path );
	//第三个页面:
	void GetAllWorkStation(vector<Workstation> &out);
 	void GetAllWorkStation(vector<response_501> &out);
	int  kill_prog(int pid);
	void GetLsofFiles(int ,vector<string> &);
	bool CheckDirExists(string strServerPath);
	//第四个页面:
	string GetLog(string filename);	

};

#endif 
