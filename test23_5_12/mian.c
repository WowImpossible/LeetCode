#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//58、Length of Last Word
//Given a string s consisting of wordsand spaces, return the length of the last word in the string.
//A word is a maximal substring consisting of non - space characters only.

int lengthOfLastWord(char* s) {
	int count = 0;     //用于记录单词字母的个数
	while (*s != '\0') //字符串都是以\0结尾的
	{
		//当检测到一个空格时，是否要将count清零，取决于下一个字符是什么,如果是\0的话，count就不能清零
		if ((*s == ' ') && (*(s+1) != '\0'))
		{
			//有种情况就是，最后有好几个空格，moon    \0，有四个空格,这时候就要把空格全部吸收掉，指向下一个不是空格的字符 
			while (*(s + 1) == ' ')                  
				s++;
			if(*(s+1) != '\0')//同样要判断，下一个字符虽然不是空格，可能是\0，这样的话，count的值也不能清零
				count = 0;
		}
		else if(*s != ' ')//不是空格的话就开始记录单词数
			count++;
		s++;//这个要特别注意。如果++的话，会陷入死循环。
	}
	return count;
}



int main(void)
{
	char str[] = "   nihao a     ";
	int num;
	num = lengthOfLastWord(str);
	printf("%d\0", num);
	return 0;
}
