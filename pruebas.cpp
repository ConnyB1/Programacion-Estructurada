#include <stdio.h>
#include <time.h>
int main()
{
    time_t seconds=time(NULL);
    struct tm* current_time=localtime(&seconds); 
    
    printf("Current year = %d\n",(current_time->tm_year + 1900));
    int op = current_time->tm_mday; 
    printf("%d", op);
    return 0;
}