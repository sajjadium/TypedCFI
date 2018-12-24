#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*fptr) (void);
int new_proc=0;
char *p;

void foo1 (void){
	printf("Indirect call of foo1\n");
}
void foo2 (void){
	printf("Indirect call of foo2\n");
}
int shell_execute(char *proc){
	system(proc);
}
int initial_proc(void){
if (new_proc ==1)
	shell_execute(p);
}
void spawn_process(void){
	initial_proc();
}
void vulnfunc(char * input){
	fptr fIndirectCall;
	char buf[20];

	if (strcmp(input, "1") == 0)
		fIndirectCall = &foo1;
	else
		fIndirectCall = &foo2;
	printf(input);
	strcpy(buf, input);
	fIndirectCall();
}
int main(int argc, char *argv[])
{
 	if(argc <2)
 	{
    	printf("Syntax: %s <input string>\n", argv[0]);
	   	exit (0);
 	}
	vulnfunc(argv[1]);
	exit(0);
}
