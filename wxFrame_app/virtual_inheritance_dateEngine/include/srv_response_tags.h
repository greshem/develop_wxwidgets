
//2011_04_02_14:13:40   ������   add by greshem
// ע��. 
// 	tagContent ��Ҫÿ�� Э���Լ�����.  
// 	tagResult
#ifndef __SRV_RESPONSE_TAGS_H__
#define __SRV_RESPONSE_TAGS_H__

#ifdef WINDOWSCODE
#define PACKED
#pragma pack(1)
#else
#define PACKED __attribute__((packed))
#endif

	typedef struct _tagResult {
	int frame_count; //һ���м�����Ƭ.
	int cur_frame;
	int result;
	}  PACKED tagResult;
	//sizeof = 4 + 4 + 4 = 12
	// ����ֵ: Э�����|û������|����|û�ж�Ӧ������| �����Ѿ�����|  
	// ͷ�� +  tagResult  + |tagContent|tagContent|tagContent|tagContent  
//==========================================================================
// 1-402.
// 	�����ļ���set get  add  
// 		mark 
// 		size 
// 		main_func
// 		sub_func
		
				
		typedef struct _response_1_to_402 {
		} PACKED response_1_to_402;
		//sizeof = 1 = 1
		// ����ж����������ֵ ���� �����޸����ֵ�� ��size 
		// size - ͷ�� Ϊ0   ��������, 
		// size - ͷ�� > 0   ���� �����޸�����, û���������������.

	// ���ذ�:
	// 	header|tagResult|
//==========================================================================
// 501. 
// 	MAIN_USER_501_GET_STATION_LIST
// 	��ȡnwconn �Ŀͻ��˵��б�. 
// 	tagContent=501_respense;
	typedef struct _response_501 {
		int   pid;			//pid	 ps -elf 4���ֶ�.
		int   ppid;			//������pid ps -elf 5���ֶ�.
		char  WCHAN[32];		//��ǰϵͳ���õ�״̬. ps -elf 11���ֶ�.
		int   elapsed_time;		//elapsed time from start up to now 
		char  cmdline[64];	//��������. ps -elf ��14 ���ֶ��Ժ�. 
	}  PACKED response_501;
//	���ذ�
//		tagHeader + tagResult |respense_501|respense_501|respense_501|respense_501|....
//		sizeof = 4 + 4  +32+4  +64 =108 
//========================================================================
	typedef struct _response_502 {
	}  PACKED response_502;
//	sizeof = 1 = 1

//========================================================================
typedef struct _response_503 {
	}  PACKED response_503;
//	sizeof = 1 = 1

//========================================================================
typedef struct _response_504 {
	}  PACKED response_504;
//	sizeof = 1 = 1

//#==========================================================================
//505. 	
// 	MAIN_USER_505_KILL_NWCONN 
// 	ɱ��ָ���Ľ��� 

//	tagContent{} û������. 
	typedef struct _response_505 {
	} PACKED  response_505;
//	sizeof = 1 = 1
//	���ذ�:
//		tagHeader + tagResult

//==========================================================================
//506. 
//lsof -p pid 
// 		MAIN_USER_506_CURRENT_ACCESS_FILE	
// 		��ȡ˭ ռ����Щ�ļ�. 
	//tagContent 
		typedef struct _response_506 {
		int 	pid;
		char	prog_name[32];
		char 	filename[256];
	} PACKED  response_506 ;
	
//���ذ�:	
//	tagHeader + tagResult + reponse_507|reponse_507| reponse_507|....
//	sizeof = 4+32+256 = 292


//==========================================================================
//507. 
//	MAIN_USER_507_START_NWSERV
//		���� nwserv �����Ѿ� ������ ���ǻ���Ҫ������, ���ش���. 
//		tagResult= ok|û���������| û���ļ�. 
	typedef struct _response_507 {
	}  PACKED response_507;
	
//	sizeof = 1 = 1
//���ذ�:	
//tagHeader + tagResult

//==========================================================================
//508. 
	// MAIN_USER_508_STOP_NWSERV
	// 	ֹͣ. 
	// tagResult= ok|û���������| û���ļ�. 
	typedef struct _response_508 {
	} PACKED  response_508;

//	sizeof = 1 = 1
//���ذ�:	
//tagHeader + tagResult

//==========================================================================
//509.	
// MAIN_USER_509_RESTART_NWSERV	 
// ����
// tagResult= ok|û���������| û���ļ�. 
	typedef struct _response_509 {
	}  PACKED response_509;

//sizeof = 1 = 1
//���ذ�:	
//tagHeader + tagResult


//==========================================================================
//510. 
//	MAIN_USER_510_REFRESH_ALL 
//		ˢ��

//	tagResult= ok
	typedef struct _response_510 {
	 } PACKED response_510;

//sizeof = 1 = 1
//���ذ�:	
//tagHeader + tagResult
//==========================================================================
//511. 
// 	MAIN_USER_511_GET_LOG
// 		��ȡ��־.
/*
	����511����Ӧ�ṹ��: 
	
	| REQUEST      |
	| tagResult    |
	| response_511 |
	| log_data     |
	................
	| response_511 |
	| log_data     |


*/
		 typedef struct _response_511 {
			char 		   filename[256];
			int            log_time;    //...
			int            log_length;	//��־�ĳ���
			#ifdef WINDOWSCODE
			#else
			char           log_data[0]; 
			#endif						/*����Ķ�����־��ƫ��log_length
										֮�󽫻�����һ��response_511�ṹ
										������־�������ɿͻ������������
										*/
		} PACKED response_511;
//	sizeof = 256 + 4 + 4 + 0 = 264
		//���������� tagContent ֻ��һƬ. 
//���ذ�:
	//header|tagResult|reponse_511 
	//sizeof(header|tagResult|reponse_511 )= header.size
//==========================================================================
//512. 
//	MAIN_USER_512_WHO_USE_THIS_FILE
//	��ȡ ָ���ļ�˭��ռ��
//����: fuser filename -v 	
//������: USER        PID ACCESS COMMAND
//	tagResult = �ļ�������| û�г��� |ok| 
	typedef struct  _response_512 {
		char	user[16];
		int 	pid;
		char	access[16];
		char	command[64]; 
		int 	null;
	} PACKED response_512 ;
//sizeof = 16 + 4 + 16+64 +4 = 104
	//repense_512 ���ؽṹ.  �� >=0  ��. 	
//���ذ�:
	//header|tagResult|reponse_512|reponse_512|reponse_512|...

//==========================================================================
//513. 
//	MAIN_USER_513_GEN_CORE_DUMP	
//	����ָ���Ľ��̵� core dump ת���ļ�. 
//	tagResult = �޷�����| gdb ������| Ȩ�޲���| 
//	tagConnect = response_513 
	typedef struct _response_513 {
		char core_dump_filename[64];
	}  PACKED response_513;
//sizeof = 64 = 64
//���ذ�:
//		header|tagResult|reponse_512|...

//==========================================================================
//514. 
//	main_514_NWSERV_IS_OK
//	tagResult = pid 
//	tagConnect = response_514
	typedef struct _response_514 {
	int pid;
	} PACKED  response_514;
//sizeof = 4 = 4
//���ذ�:
//		header|tagResult|reponse_514|...

//==========================================================================
//515. 
//	main_515_LOGIN_CHECK_PASSWD
//	tagResult = ret_code
//	tagContent = response_515
	typedef struct _response_515 {
	int ret_x;
	int ret_y;
	int ret_z;
	} PACKED  response_515;
//sizeof = 4+4+4 = 12
//���ذ�:
//		header|tagResult|response_515|...	

//==========================================================================
//516. 
//	main_516_GET_SYSTEM_INFO
//	tagResult = ret_code
//	tagContent = response_516
	typedef struct _response_516 {
	int CPUUsage;
	int MemUsage;
	int StationCount;
	int ServerStatus;
	char eths[64];
	} PACKED  response_516;
//sizeof = 4+4+4+4 +64 = 80
//���ذ�:
//		header|tagResult|response_516|...	

//==========================================================================
//517. 
//	main_517_FILE_EXISTS
//	tagResult = ret_code
//	tagContent = response_517
	typedef struct _response_517 {
	char filename[64];
	} PACKED  response_517;
//sizeof = 64  = 64
//���ذ�:
//		header|tagResult|response_517|...	

#endif
