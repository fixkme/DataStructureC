#include<stdio.h>
#include <stdlib.h>
#include "SqList.h"
#include "SqStack.h"
#include "SqQueue.h"
#include "BTree.h"

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<sstream>

#include<thread>

using namespace std;

int v(int e){
	printf("%d\n", e);
	return OK;
}

__attribute((constructor)) void bf()
{
    puts(__FUNCTION__);
}
__attribute((destructor)) void af()
{
    puts(__FUNCTION__);
}
int main(int argc, char * argv[])
{
    puts(__FUNCTION__);
	return 0;
}

