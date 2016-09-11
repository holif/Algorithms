/*
*如何编写一段小程序，让windows任务管理器cpu的占用率显示为50%？
*/
#include<windows.h>
void fun() {
	int busyTime = 10;
	int idleTime = busyTime * 1.0; 
	int ret = SetThreadAffinityMask(GetCurrentThread(),0x00000001);
	INT64 startTime = 0;
	while (1) {
		startTime = GetTickCount();
		while((GetTickCount() - startTime) <= busyTime);
		Sleep(idleTime);
	}
}
int main(){
	fun();
	return 0;
}
