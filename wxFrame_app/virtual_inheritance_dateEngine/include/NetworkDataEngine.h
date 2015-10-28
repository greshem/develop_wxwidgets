#include <sys/stat.h>
#include "DataEngine.h"
#include "../network/client/client_request.h"
#include "../network/client/Client_reponse_data_dump.h"

#ifndef NETWORK_DATAENGINE_HEADER
#define NETWORK_DATAENGINE_HEADER
//########################################################################
//ͨ�������ȡ���ݣ� �������ݻ���ͨ��  �������ϵ�LocalDataEngine ���� ����ȡ��, �м����һ�� ����Э��, 
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

	//ȫ�ֲ˵�
		int RestartNwserv();
		int StopNwserv();
		int StartNwserv();	

//��һ��ҳ��.
		string 	GetWorkStatus();   //����״̬.

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
		string  GetStationCount(); //�õ��ͻ�������.
		string GetPasswd();			//����.
		int		SetPasswd(string passwd);			//��������.
		
		string GetDialogNic();				//�Ի�����ڷ�������������

	//��2��ҳ��.
		string  GetVolName();
		string  GetVolPath();

		void SetVolName(string name );
		void SetVolPath(string path );
	//������ҳ��:
	void GetAllWorkStation(vector<Workstation> &out);
 	void GetAllWorkStation(vector<response_501> &out);
	int  kill_prog(int pid);
	void GetLsofFiles(int ,vector<string> &);
	bool CheckDirExists(string strServerPath);
	//���ĸ�ҳ��:
	string GetLog(string filename);	

};

#endif 
