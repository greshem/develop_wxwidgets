// 
// #2011_04_02_13:36:06   ������   add by greshem
// 
// #ע��. ��ÿ���ͻ���Э��� �����  ����� ѡ�� �� tag һ�� ���� ����,  64 ���ֽ�
// 
//==========================================================================
// 1-402.
// 	�����ļ��� set get add 
// 		mark 
// 		size 
// 		main_func
// 		sub_func
#ifdef WINDOWSCODE
#define PACKED
#pragma pack(1)
#else
#define PACKED __attribute__((packed))
#endif

		typedef struct  _request_1_to_402 {
			char item[64];
		} PACKED request_1_to_402;

// sizeof = 64 = 64
// 	����ж����������ֵ ���� �����޸����ֵ�� ��size 
// 	size - ͷ�� Ϊ0   ��������. 
// 	size - ͷ�� > 0   ���� �����޸�����.  û���������������.
//	�����:
//		header| tagRequest|


//==========================================================================
//501.  
//	MAIN_USER_501_GET_STATION_LIST
//	��ȡnwconn �Ŀͻ��˵��б�. 
	typedef struct _request_501 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_501;
//sizeof = 4 + 32 + 16 =52
//	size - ͷ��== 0 , ��ȡ ȫ���� nwconn 
//	�����:
//		header|501_request|

//========================================================================
typedef struct _request_502 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_502;

//========================================================================
typedef struct _request_503 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_503;

//========================================================================
typedef struct _request_504 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_504;
//#==========================================================================
//505. 
//	MAIN_USER_505_KILL_NWCONN 
//	ɱ��ָ���Ľ��� 
	typedef struct _request_505 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_505;
//sizeof = 4 + 32 + 16 = 52
//	size - ͷ�� == 0 , ɱ��ȫ����nwconn
//	�����:
//		header|505_request|

//#==========================================================================
//506. 
//	MAIN_USER_506_CURRENT_ACCESS_FILE	
//	��ȡ˭ ռ����Щ�ļ�. 

	typedef struct _request_506 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_506 ;

//sizeof = 4 + 32 + 16 = 52
//	����  size - ͷ��==0,  �������е�nwconn ʵ�õ����е��ļ�, uniq һ��, ��ͳ��ÿ���ļ���ʵ�� Ƶ��.  	
//	�����:
//		header|506_request|

//==========================================================================
//507. 
//	MAIN_USER_507_START_NWSERV
//		���� nwserv �����Ѿ� ������ ���ǻ���Ҫ������, ���ش���. 
		typedef struct _request_507 {
		} PACKED request_507;
// sizeof = 1 = 1	
//		size - ͷ�� ==0  ����Ӧ�ò�Ҫʲô����. 
//		size - ͷ�� > 0 ����. 

//	�����:
//		header| 

//==========================================================================
//508. 
//	MAIN_USER_508_STOP_NWSERV
//		ֹͣ. 
		typedef struct _request_508 {
		} PACKED request_508 ;	
//sizeof = 1 = 1
// 		size - ͷ�� ==0  ����Ӧ�ò�Ҫʲô����. 
// 			size - ͷ�� > 0 ����. 
//	�����:
//		header| 

//#==========================================================================
//509.	
//	MAIN_USER_509_RESTART_NWSERV	 
//	����
	typedef struct _request_509 {
		} PACKED request_509;	
//sizeof = 1 = 1
//		size - ͷ�� ==0  ����Ӧ�ò�Ҫʲô����. 
//		size - ͷ�� > 0 ����. 

//	�����:
//		header| 
//#==========================================================================
// 510. MAIN_USER_510_REFRESH_ALL 
// 		ˢ��
	typedef struct _request_510 {
		} PACKED request_510;	
// sizeof = 1 = 1
		// size - ͷ�� ==0  ����Ӧ�ò�Ҫʲô����. 
		// size - ͷ�� > 0 ����. 
//	�����:
//		header| 

//#==========================================================================
//511. MAIN_USER_511_GET_LOG
//		��ȡ��־.
	typedef struct _request_511 {
		char 	filename[256]; 	//��Ӧ����־�ļ�. 
		int		start_time; //��ʼʱ��. 
		int  	end_time;	//����ʱ��. 	
		char 	pttern[32]; //��־�Ƿ�����������ַ���.
	} PACKED request_511;	
//sizeof = 256 + 4 + 4 + 32 = 296
//	size - ͷ�� == 0  ��ȡ /var/log/nwserv.log ��ȫ������־,   	
//  sizeof(size - ͷ��) == sizeof(501_request) ��ȷ��
// 	�����:
// 		header|511_request|
			
//#==========================================================================
// 512. 
// 	MAIN_USER_512_WHO_USE_THIS_FILE
// 	��ȡ ָ���ļ�˭��ռ��
	typedef struct _request_512 {
		char filename[256];
	} PACKED request_512;
// sizeof = 256 = 256
// ���� size - ͷ�� == 0 �Ǵ��������. 
// ����  filename[0]==NULL Ҳ�Ǵ���, 
// ���� filename �Ǿ���·��,  ����  filename ������ Ҳ�Ǵ���. 

//	�����:
//		header|512_request|
//#==========================================================================

//513. 
//	MAIN_USER_513_GEN_CORE_DUMP	
//	����ָ���Ľ��̵� core dump ת���ļ�. 
		typedef struct _request_513 {
			int pid;
			char mac_addr[32];
			char node_addr[16];
		} PACKED request_513;
//sizeof = 4 + 32 + 16 = 52
// 	���� size - ͷ�� == 0  ת�� ��ǰ���г��� �� core-dump
//	�����:
//		header|513_request|
