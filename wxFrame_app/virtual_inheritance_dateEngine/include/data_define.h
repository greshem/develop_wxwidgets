#ifndef __DATA__DEFINED__HEADER
#define  __DATA__DEFINED__HEADER

#ifdef WINDOWSCODE
#define PACKED
#pragma pack(1)
#else
#define PACKED __attribute__((__packed__))
#endif

//wxwidgets �Ľ����struct ����Ϣ.  
//------------------------------------------------------------------------
//1. ��һ��ҳ�棬 ������Ϣ. 
//		�ӿ�: BaseDataEngine::GetBaseInfo( BaseInfo &out)
typedef struct _BaseInfo {
	char server_name[32]; 	// ����������
	char status;		  	// ģ��������״̬.
	char inner_network[32]; // �ڲ������. 
	char inner_node[32];	// �ڲ�node ��.	
	char ex_network[32];	// �ⲿnode��.
	char mac_addr[16];		// ������ַ.
	char frame_type[16];	// ֡����. 
	char 	reverse[7];
} PACKED BaseInfo ;
//sizeof = 32 + 1 + 32 + 32 +32 +16 +16  + 7 = 168 
//------------------------------------------------------------------------
//2.  �ڶ���ҳ��, �����ļ���Ŀ¼
//		�ӿ�: void BaseDataEngine::GetShareDir(vector<string> &share_dir)
//		notice: һ������Ŀ¼һ�� char path[256];
		
//------------------------------------------------------------------------
//3. ������ҳ��, ����վ����
//		�ӿ�: void GetAllWorkStation(vector<Workstation> &out);
typedef struct _Workstation {
	char mac_addr[16];		// ������ַ.
	char inner_network[32]; // �ڲ������. 
	char status;			//����״̬
	int	 connect_time;		//����ʱ��. 
	char cur_used_file[128];//��ǰ��ȡ�ļ�. 
	char 	reverse[3];
} PACKED Workstation ;
//sizeof = 16 + 32 + 1 + 4 + 128   + 3 = 184 

//------------------------------------------------------------------------
//4. ���ĸ�ҳ��, ���̹���
//		�ӿ�. void BaseDataEngine::GetAllProcess(vector<nw_process> &out);
typedef struct _nw_process {
	char mac_addr[16];		// ������ַ.
	char inner_network[32]; // �ڲ������. 
	char process_name [32]; // ��������. 
	char status;			// ����״̬. 
	char reverse[15];	
} PACKED nw_process   ;
//sizeof =  16 +32 + 32 + 1 + 15   = 96

//------------------------------------------------------------------------
//5. �����ҳ��, ��־���� 
//		�ӿ�: void BaseDataEngine::GetNwServLog(vector<string> &logStr)
//		notice: �м�����־, ����ֻʵ�� nwserv.log
//########################################################################

#endif
