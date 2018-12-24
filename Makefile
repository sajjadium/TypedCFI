all: sample.c
	gcc -Wl,-z,relro,-z,now -fplugin=./rap_plugin.so -fplugin-arg-rap_plugin-typecheck=call,ret  -fplugin-arg-rap_plugin-report=func,fptr,abs sample.c -m32 -fno-stack-protector -o sample
