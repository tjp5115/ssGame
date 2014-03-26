// ssGame.cpp : Defines the entry point for the console application.
//

#include "ssLoop.h"

int main(int argc, char* argv[])
{

	ssLoop *ss = new ssLoop(1200, 800);

	ss->loop();

	return 0;
}

