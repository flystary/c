#include<stdio.h>
#include<string.h>
#include<time.h>

/*
 * struct tm {
 *    int tm_sec;       # 秒，范围从 0 到 59               
 *  int tm_min;         # 分，范围从 0 到 59              
 *  int tm_hour;        # 小时，范围从 0 到 23              
 *  int tm_mday;        # 一月中的第几天，范围从 1 到 31                  
 *  int tm_mon;         # 月份，范围从 0 到 11
 *  int tm_year;        # 自 1900 起的年数
 *  int tm_wday;        # 一周中的第几天，范围从 0 到 6   
 *  int tm_yday;        # 一年中的第几天，范围从 0 到 365
 *  int tm_isdst;       # 夏令时                         
 * };
*/


int asc()
{
	struct tm t;
	t.tm_sec  =	10;
	t.tm_min  =	10;
	t.tm_hour =	6;
	t.tm_mday =	25;
	t.tm_mon  =	2;
	t.tm_year =	89;
	t.tm_wday =	6;

	printf("%s\n", asctime(&t));

	return(0);
}

int iclock()
{
	clock_t start_t, end_t;
	double total_t;
	int i;

	start_t = clock();
	printf("程序启动，start_t = %ld\n", start_t);
    
   	printf("开始一个大循环，start_t = %ld\n", start_t);
   	for(i=0; i< 10000000; i++)
   	{
   	}
   	end_t = clock();
   	printf("大循环结束，end_t = %ld\n", end_t);

   	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   	printf("CPU 占用的总时间：%f\n", total_t  );
   	printf("程序退出...\n");
 
   	return(0);
}

int start()
{
   clock_t start_t, end_t;
   double total_t;
   int i;
 
   start_t = clock();
   printf("程序启动，start_t = %ld\n", start_t);
    
   printf("开始一个大循环，start_t = %ld\n", start_t);
   for(i=0; i< 10000000; i++)
   {
   }
   end_t = clock();
   printf("大循环结束，end_t = %ld\n", end_t);
   
   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("CPU 占用的总时间：%f\n", total_t  );
   printf("程序退出...\n");
 
   return(0);
}

int c_time()
{
	time_t curtime;
	time(&curtime);
	
	printf("当前时间 = %s\n", ctime(&curtime));

	return(0);
}

int diff()
{
	time_t start_t, end_t;
	double diff_t;
    int i;

	printf("程序启动.....\n");
	time(&start_t);
	for(i=0;i<500000;i++){
		if(i % 9 == 0)
		{
			printf("%d ", i);
		}
	}

	printf("\n休眠 5 秒.....\n");
	sleep(5);

	time(&end_t);
	diff_t = difftime(end_t, start_t);

	printf("执行时间 = %f\n", diff_t);
	printf("程序退出....\n");

	return(0);
}

/*
 *  struct tm {
 *  int tm_sec;       #   秒，范围从 0 到 59               
 *  int tm_min;       #   分，范围从 0 到 59               
 *  int tm_hour;      #   小时，范围从 0 到 23               
 *  int tm_mday;      #   一月中的第几天，范围从 1 到 31        
 *  int tm_mon;       #   月份，范围从 0 到 11            
 *  int tm_year;      #   自 1900 起的年数               
 *  int tm_wday;      #   一周中的第几天，范围从 0 到 6             
 *  int tm_yday;      #   一年中的第几天，范围从 0 到 365 
 *  int tm_isdst;     #   夏令时     
 *};
*/


#define BST (+1)
#define CCT (+8)

int gm()
{
	time_t rawtime;
	struct tm *info;
	
	time(&rawtime);
	info = gmtime(&rawtime);

	printf("当前的世界时钟");


	printf("伦敦：%2d:%02d\n", (info->tm_hour+BST)%24, info->tm_min);
   	printf("中国：%2d:%02d\n", (info->tm_hour+CCT)%24, info->tm_min);
	
	return(0);
}


/*
 *
 * struct tm {
 *    int tm_sec;         # 秒，范围从 0 到 59
 *    int tm_min;         # 分，范围从 0 到 59
 *    int tm_hour;        # 小时，范围从 0 到 23
 *    int tm_mday;        # 一月中的第几天，范围从 1 到 31
 *    int tm_mon;         # 月份，范围从 0 到 11
 *    int tm_year;        # 自 1900 起的年数
 *    int tm_wday;        # 一周中的第几天，范围从 0 到 6
 *    int tm_yday;        # 一年中的第几天，范围从 0 到 365
 *    int tm_isdst;       # 夏令时
 * };
*/

int local()
{
	time_t rawtime;
	struct tm *info;
	char	buffer[80];

	time( &rawtime );
	info = localtime( &rawtime );
	
	printf("当前本地时间和日期 : %s\n", asctime(info));

	return(0);
}



/*
 *
 * struct tm {
 *    int tm_sec;         # 秒，范围从 0 到 59
 *    int tm_min;         # 分，范围从 0 到 59
 *    int tm_hour;        # 小时，范围从 0 到 23
 *    int tm_mday;        # 一月中的第几天，范围从 1 到 31
 *    int tm_mon;         # 月份，范围从 0 到 11
 *    int tm_year;        # 自 1900 起的年数
 *    int tm_wday;        # 一周中的第几天，范围从 0 到 6
 *    int tm_yday;        # 一年中的第几天，范围从 0 到 365
 *    int tm_isdst;       # 夏令时
 * };
*/


int mk()
{
	int ret;
    struct tm info;
    char buffer[80];

    info.tm_year = 2021 - 1900;
    info.tm_mon = 7 - 1;
    info.tm_mday = 4;
    info.tm_hour = 0;
    info.tm_min = 0;
    info.tm_sec = 1;
    info.tm_isdst = -1;

    ret = mktime(&info);
    if( ret == -1 ) {
        printf("Error: unable to make time using mktime\n");
    } else {
        strftime(buffer, sizeof(buffer), "%c", &info );
        printf(buffer);
    }

    return(0);
}

int whereis()
{
	time_t rawtime;
    struct tm * timeinfo;
    int year, month ,day;
    const char * weekday[] = { "周日", "周一","周二", "周三","周四", "周五", "周六"};
 
    /* 用户输入日期 */
    printf ("年: "); fflush(stdout); scanf ("%d",&year);
    printf ("月: "); fflush(stdout); scanf ("%d",&month);
    printf ("日: "); fflush(stdout); scanf ("%d",&day);
 
    /* 获取当前时间信息，并修改用户输入的输入信息 */
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;
 
    /* 调用 mktime: timeinfo->tm_wday  */
    mktime ( timeinfo );
 
    printf ("那一天是：%s\n", weekday[timeinfo->tm_wday]);
 
    return 0;
}


/*
 * 说明符	替换为	实例
 * %a	缩写的星期几名称	Sun
 * %A	完整的星期几名称	Sunday
 * %b	缩写的月份名称	Mar
 * %B	完整的月份名称	March
 * %c	日期和时间表示法	Sun Aug 19 02:56:02 2012
 * %d	一月中的第几天（01-31）	19
 * %H	24 小时格式的小时（00-23）	14
 * %I	12 小时格式的小时（01-12）	05
 * %j	一年中的第几天（001-366）	231
 * %m	十进制数表示的月份（01-12）	08
 * %M	分（00-59）	55
 * %p	AM 或 PM 名称	PM
 * %S	秒（00-61）	02
 * %U	一年中的第几周，以第一个星期日作为第一周的第一天（00-53）	33
 * %w	十进制数表示的星期几，星期日表示为 0（0-6）	4
 * %W	一年中的第几周，以第一个星期一作为第一周的第一天（00-53）	34
 * %x	日期表示法	08/19/12
 * %X	时间表示法	02:50:06
 * %y	年份，最后两个数字（00-99）	01
 * %Y	年份	2012
 * %Z	时区的名称或缩写	CDT
 * %%	一个 % 符号	%
 * timeptr -- 这是指向 tm 结构的指针，该结构包含了一个被分解为以下各部分的日历时间：
 * struct tm {  
* 	  int tm_min;         # 分，范围从 0 到 59
 *    int tm_hour;        # 小时，范围从 0 到 23
 *    int tm_mday;        # 一月中的第几天，范围从 1 到 31
 *    int tm_mon;         # 月份，范围从 0 到 11
 *    int tm_year;        # 自 1900 起的年数
 *    int tm_wday;        # 一周中的第几天，范围从 0 到 6
 *    int tm_yday;        # 一年中的第几天，范围从 0 到 365
 *    int tm_isdst;       # 夏令时
 * };
 *
 */

int formart()
{
	time_t rawtime;
	struct 	tm *info;
	char buffer[80];

	time( &rawtime );
	info = localtime( &rawtime );

	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);
	printf("格式化的日期 & 时间 : |%s|\n", buffer );

	return(0);
}


int second()
{
	time_t seconds;
	seconds = time(NULL);
	
	printf("自 1970-01-01 起的秒数 = %ld \n", seconds);
	printf("自 1970-01-01 起的小时数 = %ld \n", seconds/3600);
}
int main()
{
	// asc();
	// iclock();
    // start();
    // c_time();
	// diff();
	// gm();
	// local();
	// whereis();
	// mk();
	formart();
	second();
	return 0;
}
