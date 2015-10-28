#ifdef WINDOWSCODE
#define HZ 100
#else
#include <pwd.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/procfs.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <sys/user.h>
#include <asm/param.h> 
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>

 /* HZ */
using namespace std;
class sysinfo
{
	public:
		 int proc_run_time(int);
		 void get_meminfo(float *);
		 void get_cpuinfo(float *);
	private:
		char btime_char[10];
	//	int P_pid;
	//	char P_cmd[16];
		unsigned long P_start_time;
};

//得到程序的启动时间点
int sysinfo::proc_run_time(int pid)
{
    char buf[4096];
	int fd;
    snprintf(buf, 32, "/proc/%d/stat", pid);
    if ( (fd = open(buf, O_RDONLY, 0) ) == -1 ) 
	{
		return 0;
	}
    int num = read(fd, buf, sizeof buf - 1);
    close(fd);
    char *tmp = strrchr(buf, ')'); 
   // memset(P_cmd, 0, sizeof P_cmd);
   // sscanf(buf, "%d (%15c", &P_pid, P_cmd);
    num = sscanf(tmp + 2 + sizeof(char)+5*sizeof(int)+7*sizeof(unsigned long)+6*sizeof(long),
       "%lu", &P_start_time);
	
  int cnt = 0;
  unsigned long btime_int;
  string file="/proc/stat";
  FILE *fp=fopen(file.c_str(), "r");
  while(fgets(buf, sizeof(buf), fp))
  {
  	if(buf[0]=='b')
	{
		sscanf(buf,"%s%lu",btime_char,&btime_int);
		break;
	}
  }
  P_start_time /= HZ;
  int seconds_since_boot = time(NULL) -  btime_int;//当前时间减去系统启动时间
  int t=seconds_since_boot - P_start_time;
  
  int ss = t%60;
  t /= 60;
  int mm = t%60;
  t /= 60;
  int hh = t%24;
  t /= 24;
  if(t) cnt = snprintf(buf, sizeof buf, "%d-", (int)t);
  snprintf(buf, sizeof(buf), "%d天%02d:%02d:%02d",t, hh, mm, ss);
  fclose(fp);
  //printf("aaaaa==== %s\n",buf);
  return t*24*3600+hh*3600+mm*60+ss;
}

void sysinfo::get_meminfo(float meminfo[])
{
	char tmp[100];
	char buffer[4096]; /* about 40 fields, 64-bit decimal is about 20 chars */
    string file="/proc/meminfo";
    FILE *fp=fopen(file.c_str(), "r");
	for(int i=0; i<2; i++)
	{
    	fgets(buffer, sizeof(buffer), fp);
		sscanf(buffer,"%s%f",tmp,&meminfo[i]);
    }
    fclose(fp);
 }

void sysinfo::get_cpuinfo(float cpuinfo[])
{
	char tmp[5];
    char buffer[4096]; /* about 40 fields, 64-bit decimal is about 20 chars */
	string file="/proc/stat";
	FILE *fp=fopen(file.c_str(), "r");
    fgets(buffer, sizeof(buffer), fp);
	sscanf(buffer,"%s%f%f%f%f%f%f%f",tmp,&cpuinfo[0],&cpuinfo[1],&cpuinfo[2],&cpuinfo[3],&cpuinfo[4],&cpuinfo[5],&cpuinfo[6]);
	fclose(fp);
}

