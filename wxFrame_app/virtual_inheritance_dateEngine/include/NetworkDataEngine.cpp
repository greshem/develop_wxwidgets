#ifdef WINDOWSCODE
#else
#include <glob.h>
#endif
#include "IniFile.hpp"
#include "NetworkDataEngine.h"
#include "LocalDataEngine.h"
#include "Cmd_str_to_struct.h"
#ifndef NETWORK_DATAENGINE_HEADER
#define NETWORK_DATAENGINE_HEADER
#endif 
//########################################################################
string NetworkDataEngine::GetName()
{
	return "������������";
}

NetworkDataEngine::NetworkDataEngine()
{
}
int NetworkDataEngine::init()
{
	if(m_client.init( )< 0)
	{
		log::Instance()->logger("���� ��ʼ��ʧ��\n");
		return -1;
	}
	IniFile<char>  inifile("config.ini");
	int tmp=inifile.get<int>("BASE", "u_sec");
	log::Instance()->logger("timeout ֵ u_sec �� %d \n", tmp);
	m_client.set_time_out(0,tmp);
	return 1;
}
NetworkDataEngine::~NetworkDataEngine()
{
	m_client.release();
}
void NetworkDataEngine::GetBaseInfo( BaseInfo &out)
{
};
void NetworkDataEngine::GetShareDir(vector<string> &share_dir)
{
};
void NetworkDataEngine::GetAllProcess(vector<nw_process> &out)
{
}
void NetworkDataEngine::GetNwServLog(vector<string> &logStr)
{
	//������ͨ������֮�� ͨ�������ȡ logStr ֮�� �Ϳ����滻��������. 
	LocalDataEngine *db= new LocalDataEngine();
	db->GetNwServLog(logStr);
}

//���˵�.
//========================================================================
// 10 ��timetout, ��ʼ. 
int NetworkDataEngine::StartNwserv()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	tagResult result;
	m_client.request_main_507_START_NWSERV(NULL, 0);

	m_client.set_time_out(1,10000);
	if(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			memcpy(&result, (char *)((char*)&frame + sizeof(REQUEST)), sizeof(result));
			cout<<"start: �����"<<result.result<<endl;
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	m_client.set_time_out(0,1000);
	
	return result.result;
}

//========================================================================
// 10 ��timetout, ֹͣ.
int NetworkDataEngine::StopNwserv()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	tagResult result;
	m_client.request_main_508_STOP_NWSERV(NULL, 0);
	
	m_client.set_time_out(10,10000000);
	if(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			memcpy(&result, (char *)((char*)&frame + sizeof(REQUEST)), sizeof(result));
			cout<<"start: �����"<<result.result<<endl;
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	m_client.set_time_out(0,1000);
	
	return result.result;
}

//========================================================================
// 10 ��timetout, ����������.
int NetworkDataEngine::RestartNwserv()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	tagResult result;
	m_client.request_main_509_RESTART_NWSERV(NULL, 0);

	m_client.set_time_out(10,10000000);
	if(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			memcpy(&result, (char *)((char*)&frame + sizeof(REQUEST)), sizeof(result));
			cout<<"start: �����"<<result.result<< endl;
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	m_client.set_time_out(0,1000);
	
	return result.result;
}


//��һ��ҳ��.
//========================================================================
string  NetworkDataEngine::GetWorkStatus()
{
	static int i=0;
	if(i%2)
	{
		return "running";	
	}
	return "stop";

}

string NetworkDataEngine::GetServerName()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	char item[64]={0};
	m_client.request_template(2, 0, item);

	m_client.set_time_out(0,1000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			cout<<"����������: ��ȡ������"<<string(item)<<endl;
			//conf.add_item(main_function, sub_function, item);
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	
	return string(item);
}

int 	NetworkDataEngine::SetServerName(string sername)
{
	// nw_conf_parser conf;
	// conf.parse_file("/etc/nwserv.conf");
	// int ret = conf.set_item(2,0, sername);	
	// cout<<"SetServerName "<<sername<<endl;
	// return ret;

	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}

	FRAME frame;
	tagResult result;
	char item[64]={0};
	strncpy(item, sername.c_str(), sizeof(item));
	m_client.request_template(2, 0, item);

	m_client.set_time_out(0,1000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			//conf.add_item(main_function, sub_function, item);
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
			memcpy(&result, frame.data, sizeof(result));
		}   
	}   
	return result.result;
}


//========================================================================
string NetworkDataEngine::GetInnerNetwork()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	char item[64]={0};
	m_client.request_template(3, 0, item);

	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			cout<<"�ڲ������: ��ȡ������"<<string(item)<<endl;
			//conf.add_item(main_function, sub_function, item);
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	return string(item);	
}

int 	NetworkDataEngine::SetInnerWork(string inner_work)
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	tagResult result;
	char item[64]={0};
	strncpy(item , inner_work.c_str(), sizeof(item));
	m_client.request_template(3, 0, item);

	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			//conf.add_item(main_function, sub_function, item);
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
			memcpy(&result,  inner_work.c_str(), sizeof(result));
		}   
	}   
	return result.result;	
}


//========================================================================
string NetworkDataEngine::GetNetwork()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	char item[64]={0};
	m_client.request_template(4, 0, item);

	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			cout<<"�ڲ������: ��ȡ������"<<string(item)<<endl;
			//conf.add_item(main_function, sub_function, item);
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	return string(item);
}

int		NetworkDataEngine::SetNetWork(	string network)
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}

	FRAME frame;
	tagResult result;

	char item[64]={0};
	strncpy(item, network.c_str(), sizeof(item));

	m_client.request_template(4, 0, item);

	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			//cout<<"�ڲ������: ��ȡ������"<<string(item)<<endl;
			//conf.add_item(main_function, sub_function, item);
			memcpy(&result, frame.data, sizeof(tagResult));
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	return result.result;
}


//========================================================================
string NetworkDataEngine::GetNIC()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	memset(&frame, '\0', sizeof(frame));
	char item[64]={0};

	m_client.request_template(4, 1, item);
	m_client.set_time_out(0,1000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			cout<<"Nic ��ȡ������"<<string(item)<<endl;
			//conf.add_item(main_function, sub_function, item);
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	return string(item);
}

int NetworkDataEngine::SetNIC(string nic)
{

	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	REQUEST header;
	tagResult result;
	memset(&frame, '\0', sizeof(frame));
	char item[64]={0};
	strncpy(item, nic.c_str(), sizeof(item));

	m_client.request_template(4, 1, item);
	m_client.set_time_out(0,1000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
			memcpy(&result, &frame.data, sizeof(tagResult));
		}   
	}   
	return result.result;
}


//========================================================================
string NetworkDataEngine::GetFrameType()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	char item[64]={0};
	m_client.request_template(4, 2, item);

	m_client.set_time_out(0,1000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			//printf("main_fun %ld sub_fun %ld %s\n ", main_function, sub_function, item);        
			cout<<"frameType ��ȡ������"<<string(item)<<endl;
			//conf.add_item(main_function, sub_function, item);
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	return string(item);
}

int NetworkDataEngine::SetFrameType(string frame_type)
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}

	FRAME frame;
	tagResult result;
	char item[64]={0};
	strncpy(item , frame_type.c_str(), sizeof(item));

	m_client.request_template(4, 2, item);

	//m_client.set_time_out(10,10000);
	//
	m_client.set_time_out(0,1000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			//printf("main_fun %ld sub_fun %ld %s\n ", main_function, sub_function, item);        
			//cout<<"����frameType ��ȡ������"<<string(item)<<endl;
			//conf.add_item(main_function, sub_function, item);
			memcpy(&result, frame.data, sizeof(tagResult));
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	return result.result;
}


//########################################################################
string NetworkDataEngine::GetServerStatus() //������״̬.
{
	if(m_client.is_ok() == 0)
    {   
        log::Instance()->logger(" �����ʼ��ʧ��\n");
    }   
    FRAME frame;
    char item[64]={0};
    response_516 resp_516;
	memset(&resp_516,'\0',sizeof(resp_516));
    m_client.request_template(516, 0, item);

	m_client.set_time_out(0,1000);
    if(m_client.is_readable())
    {   
        m_client.recv();
        memset(&frame, '\0', sizeof(frame));
        while(m_client.have_one_frame()==1)
        {   
			int ret=m_client.get_one_frame(frame);
            char *data = (char*)&frame;
			//int count =int ((int *)(data+sizeof(REQUEST)+sizeof(tagResult)));
            //strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			memcpy((char *) &resp_516,   data+sizeof(REQUEST)+sizeof(tagResult), sizeof(response_516));
            cout<<"struct 516 ��ȡ������ Count"<<endl;
			//snprintf(item ,sizeof(item),"%d", resp_516.ServerStatus);
            m_data_storage.dispatch_to_dump((char*)&frame, ret );

		}
    }
	else
	{
		log::Instance()->logger("panic:  GetServerStatus() ��ʱ \n");
	}

	if(0 == resp_516.ServerStatus)
	{
		return string("running");
	}
	else
	{
		return string("stop");
	}
}

string NetworkDataEngine::GetMemoryUsage() //�ڴ�ռ����.
{
	if(m_client.is_ok() == 0)
    {
        log::Instance()->logger(" �����ʼ��ʧ��\n");
    }
    FRAME frame;
    char item[64]={0};
	response_516 resp_516;
	memset(&resp_516,'\0',sizeof(resp_516));
    m_client.request_template(516, 0, item);

	m_client.set_time_out(0,1000);
    if(m_client.is_readable())
    {
        m_client.recv();
        memset(&frame, '\0', sizeof(frame));
        while(m_client.have_one_frame()==1)
        {
			int ret=m_client.get_one_frame(frame);
            char *data = (char*)&frame;
			//int count =int ((int *)(data+sizeof(REQUEST)+sizeof(tagResult)));
            //strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			memcpy((char *) &resp_516,   data+sizeof(REQUEST)+sizeof(tagResult), sizeof(response_516));
            cout<<"struct 516 ��ȡ������ Count"<<endl;
			//snprintf(item ,sizeof(item),"%d", resp_516.MemUsage);
            m_data_storage.dispatch_to_dump((char*)&frame, ret );

        }
    }
	else
	{
		log::Instance()->logger("panic:  GetMemoryUsage() ��ʱ \n");
	}

	char   buf[32];
#ifdef WINDOWSCODE
    _snprintf(buf,sizeof(buf),"%d ",resp_516.MemUsage);
#else
    snprintf(buf,sizeof(buf),"%d ",resp_516.MemUsage);
#endif
    string s = buf;
    return s;
}

string NetworkDataEngine::GetCpuUsage() //CPUռ����.
{
    if(m_client.is_ok() == 0)
    {   
        log::Instance()->logger(" �����ʼ��ʧ��\n");
    }   
    FRAME frame;
    char item[64]={0};
	response_516 resp_516;
	memset(&resp_516,'\0',sizeof(resp_516));
    m_client.request_template(516, 0, item);

	m_client.set_time_out(0,1000);
    if(m_client.is_readable())
    {   
        m_client.recv();
        memset(&frame, '\0', sizeof(frame));
        while(m_client.have_one_frame()==1)
        {   
			int ret=m_client.get_one_frame(frame);
            char *data = (char*)&frame;
			memcpy((char *) &resp_516,   data+sizeof(REQUEST)+sizeof(tagResult), sizeof(response_516));
            cout<<"struct 516 ��ȡ������ Count"<<endl;
            m_data_storage.dispatch_to_dump((char*)&frame, ret );

        }   
    }   
	else
	{
		log::Instance()->logger("panic:  GetCPUUsage() ��ʱ \n");
	}

	char   buf[32];
#ifdef WINDOWSCODE
    _snprintf(buf,sizeof(buf),"%d ",resp_516.CPUUsage);
#else
    snprintf(buf,sizeof(buf),"%d ",resp_516.CPUUsage);
#endif
    string s = buf;
    return s;
}


string NetworkDataEngine::GetStationCount() //�ͻ�������
{
	if(m_client.is_ok() == 0)
    {
        log::Instance()->logger(" �����ʼ��ʧ��\n");
    }
    FRAME frame;
    char item[64]={0};
	response_516 resp_516;
	memset(&resp_516,'\0',sizeof(resp_516));
    m_client.request_template(516, 0, item);

	m_client.set_time_out(0,1000);
    if(  m_client.is_readable())
    {
        m_client.recv();
        memset(&frame, '\0', sizeof(frame));
        while(m_client.have_one_frame()==1)
        {
            int ret=m_client.get_one_frame(frame);
            char *data = (char*)&frame;
			//int count =int ((int *)(data+sizeof(REQUEST)+sizeof(tagResult)));
            //strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			memcpy((char *) &resp_516,   data+sizeof(REQUEST)+sizeof(tagResult), sizeof(response_516));
            cout<<"struct 516 ��ȡ������ Count"<<endl;
			//snprintf(item ,sizeof(item),"%d", resp_516.StationCount);
            m_data_storage.dispatch_to_dump((char*)&frame, ret );
        }
    }
	else
	{
		log::Instance()->logger("Pannic:  GetStationCount() ��ʱ \n");
	}
	
	char   buf[32];
#ifdef WINDOWSCODE
    _snprintf(buf,sizeof(buf),"%d ",resp_516.StationCount);
#else
    snprintf(buf,sizeof(buf),"%d ",resp_516.StationCount);
#endif
    string s = buf;
    return s;
}

//========================================================================

string NetworkDataEngine::GetDialogNic() //����������
{
	if(m_client.is_ok() == 0)
    {
        log::Instance()->logger(" �����ʼ��ʧ��\n");
    }
    FRAME frame;
    char item[64]={0};
	response_516 resp_516;
	memset(&resp_516,'\0',sizeof(resp_516));
    m_client.request_template(516, 0, item);

	m_client.set_time_out(0,100000);
    if(  m_client.is_readable())
    {
        m_client.recv();
        memset(&frame, '\0', sizeof(frame));
        while(m_client.have_one_frame()==1)
        {
            int ret=m_client.get_one_frame(frame);
            char *data = (char*)&frame;
			memcpy((char *) &resp_516,   data+sizeof(REQUEST)+sizeof(tagResult), sizeof(response_516));
            cout<<"struct 516 ��ȡ������ Count"<<endl;
            m_data_storage.dispatch_to_dump((char*)&frame, ret );
        }
    }
	else
	{
		log::Instance()->logger("Pannic:  GetStationCount() ��ʱ \n");
	}
	
	string s = resp_516.eths ;
    return s;
}

//========================================================================
string NetworkDataEngine::GetPasswd()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	char item[64]={0};
	m_client.request_template(12, 2, item);

	m_client.set_time_out(0,30000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			cout<<"passwd ��ȡ������"<<string(item)<<endl;
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
			//conf.add_item(main_function, sub_function, item);
		}   
	}   
	return string(item);
}

//========================================================================
int NetworkDataEngine::SetPasswd(string passwd)
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	REQUEST header;
	tagResult result;
	char item[64]={0};
	strncpy(item, passwd.c_str(), sizeof(item));
	m_client.request_template(12, 2, item);

	m_client.set_time_out(0,100);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			cout<<"passwd ��ȡ������"<<string(item)<<endl;
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
			//conf.add_item(main_function, sub_function, item);
			memcpy(&result, frame.data, sizeof(tagResult));
		}   
	}   
	return result.result;
}

//========================================================================
//������ҳ��.
bool NetworkDataEngine::CheckDirExists(string strServerPath)
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	tagResult result;
	request_517 req_517={0};;
	m_client.set_time_out(0, 1000);
	
	strncpy(req_517.filename, strServerPath.c_str(), sizeof(req_517.filename));
	int ret= m_client.request_main_517_FILE_EXISTS (req_517.filename, sizeof(req_517.filename) );
	if(ret>0)
	{
		log::Instance()->logger("������ %d, �ɹ� ret=%d \n", 517, ret);
	}

	while(m_client.is_readable())
	{	
		m_client.recv();
		while(m_client.have_one_frame()==1)
		{
			ret=m_client.get_one_frame(frame);
			cout<<"������"<<ret<<endl;
			m_data_storage.dispatch_to_dump((char*)&frame, ret );	
			memcpy(&result, frame.data, sizeof(tagResult));
		}
	}
	if(result.result == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//------------------------------------------------------------------------
string NetworkDataEngine::GetVolName()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	char item[64]={0};
	m_client.request_template(1, 0, item);

	m_client.set_time_out(0,1000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			cout<<"passwd ��ȡ������"<<string(item)<<endl;
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
			//conf.add_item(main_function, sub_function, item);
		}   
	}   
	return item;
}
//------------------------------------------------------------------------
string NetworkDataEngine::GetVolPath()
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	char item[64]={0};
	m_client.request_template(1, 1, item);

	m_client.set_time_out(0,1000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			char *data = (char*)&frame;
			strncpy(item,data+sizeof(REQUEST)+sizeof(tagResult),sizeof(item));
			cout<<"passwd ��ȡ������"<<string(item)<<endl;
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
			//conf.add_item(main_function, sub_function, item);
		}   
	}   
	return item;
}
//------------------------------------------------------------------------
void NetworkDataEngine::SetVolName(string name)
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	char item[64]={0};
	strncpy(item, name.c_str(), sizeof(item));
	m_client.request_template(1, 0, item);


	m_client.set_time_out(0,1000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			m_client.get_one_frame(frame);
			char *data = (char*)&frame;
		}   
	}   


}

//------------------------------------------------------------------------
void NetworkDataEngine::SetVolPath(string path)
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;
	char item[64]={0};
	strncpy(item, path.c_str(), sizeof(item));
	m_client.request_template(1, 1, item);

	m_client.set_time_out(0,1000);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret= m_client.get_one_frame(frame);
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
			char *data = (char*)&frame;

		}   
	}   
}
//========================================================================
//������ҳ��
void NetworkDataEngine::GetAllWorkStation(vector<Workstation> &out)
{
}

void NetworkDataEngine::GetAllWorkStation(vector<response_501> &out)
{
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;

	m_client.request_main_501_GET_STATION_LIST(NULL, 0);

	m_client.set_time_out(1,0);
	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret= m_client.get_one_frame(frame);
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	m_client.set_time_out(0,1000);

	char *data=NULL;
	int len=0;
	data = m_data_storage.get_501_data(len);
	if(len%sizeof(response_501)!=0)
	{
		log::Instance()->logger("��Ϣ: NetworkDataEngine 501 Э���ȡ�����ݳ��Ȳ�Ϊresponse_501���ȵ�������\n");
	}
	if(data==NULL)
	{
		log::Instance()->logger("����: NetworkDataEngine 501 Э��û�л�ȡ����������, PANIC\n");
	}
	else
	{
		log::Instance()->logger("��Ϣ: NetworkDataEngine 501 Э���ȡ������Ϊ%d\n", len );
	}
	Cmd_str_to_struct::net_buf_to_vec(data, len, out );
}

int  NetworkDataEngine::kill_prog(int pid)
{

	//########################################################################
	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}

	request_505 req_505={0};
	req_505.pid=pid;
	FRAME frame;
	tagResult result;
	char item[64]={0};


	m_client.request_main_505_KILL_NWCONN((char *)&req_505, sizeof(request_505));
	m_client.set_time_out(0,100000);

	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret=m_client.get_one_frame(frame);
			cout<<"kill_prog"<<string(item)<<endl;
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
			memcpy(&result, frame.data, sizeof(tagResult));
		}   
	}   

	m_client.set_time_out(0,1000);

	return result.result;
}

void NetworkDataEngine::GetLsofFiles(int pid,vector<string> &lines)
{
 	if(m_client.is_ok() == 0)
    {
        log::Instance()->logger(" �����ʼ��ʧ��\n");
    }

    request_506 req_506={0};
    req_506.pid=pid;
    FRAME frame;
    m_client.request_main_506_CURRENT_ACCESS_FILE((char *)&req_506, sizeof(request_506));
    m_client.set_time_out(0,300000);
    
    while(m_client.is_readable())
    {
        m_client.recv();
        memset(&frame, '\0', sizeof(frame));
        while(m_client.have_one_frame()==1)
        {
            int ret= m_client.get_one_frame(frame);
            m_data_storage.dispatch_to_dump((char*)&frame, ret );
        }
    }
    //m_client.set_time_out(0,100000);

    char *data = NULL;
    int len = 0;
    data = m_data_storage.get_506_data(len);
    if(len%sizeof(response_506)!=0)
    {
        log::Instance()->logger("��Ϣ: NetworkDataEngine 506 Э���ȡ�����ݳ��Ȳ�Ϊresponse_506���ȵ�������\n");
    }
    if(data==NULL)
    {
        log::Instance()->logger("����: NetworkDataEngine 506 Э��û�л�ȡ����������, PANIC\n");
    }
    else
    {
        log::Instance()->logger("��Ϣ: NetworkDataEngine 506 Э���ȡ������Ϊ%d\n", len );
    }
	
	vector<response_506> out;
	Cmd_str_to_struct::net_buf_to_vec(data, len, out );	
	vector<response_506>::iterator it;
	for(it=out.begin();it!=out.end();it++)
	{
		lines.push_back((*it).filename);
	}
}

//========================================================================
//���ĸ�ҳ�� ��־
//�������� ���������ļ���ȡ ��Ϊ���ڵ���־��ֻ��, 
string   NetworkDataEngine::GetLog(string filename)
{
	//return "this is netlog";
	//����������־�ڱ���.
	if(strstr(filename.c_str(), "nwservUI"))
	{
#ifdef WINDOWSCODE
		FILE *fp;
    	char *buffer;

	  	struct stat st; 
    	if(stat(filename.c_str(), &st)< 0)
    	{   
			log::Instance()->logger("��ȡ�ļ�stat����ʧ��\n");
       		return string(""); 
    	}   
		
		buffer = (char*)malloc(st.st_size);
		memset(buffer,'\0',st.st_size);		//��Ҫд��sizeof(buffer),sizeof(buffer) = 4
		fp=fopen(filename.c_str(), "r");
		if(NULL == fp)
		{
			log::Instance()->logger("�ļ���ʧ��\n");
		}
		if(0==fread(buffer,1,st.st_size,fp))
		{
			log::Instance()->logger("�ļ���ȡʧ��\n");
		}
		log::Instance()->logger("��ȡ������־��\n %s\n",  buffer);
		
		string str(buffer);
		fclose(fp);
		free(buffer);
		buffer = NULL;

		return str;
#else
		string cmd("cat ");
		cmd+=filename;
		cmd+=" |iconv -c -f gb2312 -t utf8 ";
		log::Instance()->logger("��־��ȡ���� %s\n",  cmd.c_str());
		string output;
		int ret=shell_exec<char>(cmd, output);   
		return output;
#endif
	}

	if(m_client.is_ok() == 0)
	{
		log::Instance()->logger(" �����ʼ��ʧ��\n");
	}
	FRAME frame;

	m_client.request_main_511_GET_LOG((char *)filename.c_str(), filename.size());
	m_client.set_time_out(1,0);

	while(m_client.is_readable())
	{   
		m_client.recv();
		memset(&frame, '\0', sizeof(frame));
		while(m_client.have_one_frame()==1)
		{   
			int ret= m_client.get_one_frame(frame);
			m_data_storage.dispatch_to_dump((char*)&frame, ret );
		}   
	}   
	m_client.set_time_out(0,1000);

	char *data=NULL;
	int len=0;
	data = m_data_storage.get_511_data(len);
	if(data==NULL)
	{
		log::Instance()->logger("����: NetworkDataEngine 511 Э��û�л�ȡ����������, PANIC\n");
		return "null log file\n";
	}
	else
	{
		log::Instance()->logger("��Ϣ: NetworkDataEngine 511 Э���ȡ������Ϊ%d\n", len );
		//return "ok log file\n";
		data[len]='\0';	
		return string(data);
	}
}
