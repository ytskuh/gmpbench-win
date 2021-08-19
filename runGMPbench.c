#include<stdio.h>
#include<string.h>
#include<io.h>
#include<windows.h>

#define MAX_PATH_LENGTH 1024

int main(int argc, char* argv[])
{
	int i;
	for(i=strlen(argv[0]);argv[0][i]!='\\';i--);

	char path[MAX_PATH_LENGTH],shpath[MAX_PATH_LENGTH],bashpath[MAX_PATH_LENGTH];
	strcpy(path,argv[0]);
	path[i]=0;
	strcpy(shpath,path);
	strcpy(bashpath,path);
	strcat(shpath,"\\msys64\\usr\\bin\\sh.exe");
	strcat(bashpath,"\\msys64\\usr\\bin\\bash.exe");
	if(access(bashpath,0))
		CopyFile(shpath,bashpath,0);
	system(bashpath);
	system("pause");
	return 0;
}

