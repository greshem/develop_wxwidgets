#ifndef __LmyUnitMThreadH__
#define __LmyUnitMThreadH__
#ifdef WINDOWSCODE
#include <windows.h> 
#else
	#include <pthread.h> 
	#include <dirent.h>
	#define     __stdcall  
 	#define     WSAGetLastError()   (errno)     
 	#define     GetLastError()      (errno)
	#include <errno.h>
	#include <unistd.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//========================================================================
#define		MAX_THREAD_REFRESHTIME				20000		//线程最大延迟时间
class MThread 
{
protected:
	static MThread			*	staticFirstThreadPtr;
protected:

#ifdef WINDOWSCODE
	HANDLE						m_ThreadHandle;
#else
	pthread_t					m_ThreadHandle;
#endif
	
	bool						m_ActiveThreadFlag;
	char						m_ThreadName[32];
	unsigned long				m_iTOCount;			
	MThread					*	m_NextThreadPtr;
	unsigned long				m_AddtionData;

public:
	MThread(void);
	virtual ~MThread();
public:
	int  StartThread(char * ThreadName,void * (__stdcall * ThreadFun)(void *),void * Param,bool PauseFlag = false);
	void StopThread(void);
public:
	int  PauseThread(void);
	int  ResumeThread(void);
public:
	bool IsEmpty(void);
	bool IsActive(void);
public:
	void RefreshThread(void);
public:
	unsigned long GetAddtionData(void);
	void SetAddtionData(unsigned long In);
public:
	static void Sleep(unsigned long Time);
	//static void CheckThreadRefreshTime(tagFunInterface_ThreadWriteReport * In);

	//DECLARE_LMYUNIT(MThread)
};
//========================================================================
#endif
//========================================================================

