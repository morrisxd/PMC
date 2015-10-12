#include <stdio.h>
#include <string.h>
/*
this is a comment sample
*/

struct student_info {
    char name[128];
    int age;
    int score;
    struct student_info *p;
};

typedef struct student {
    int age;
    char name[16];
} student;

typedef int myint;

int main (int argc, char ** argv)
{
    struct clock;
    int ii = 0;
    const int iii;
    int kk;
    myint iiii;
    student sss;

	struct clock {
		int i;
        char c;
	}clock;
    int age = 0;

	printf ("Hello world\n");

	return 0;
}
