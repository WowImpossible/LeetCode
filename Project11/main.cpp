#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//bool isValid(char* s) {
//    int count = 0;
//    int flag = 0;
//    char* pc = s;
//    // int flag2 = 0;
//    // int flag3 = 0;
//    if ((*s == ')') || (*s == ']') || (*s == '}'))
//        return false;
//    while (*pc != '\0')
//    {
//        count++;
//        pc++;
//    }
//    if (count % 2 == 0)
//    {
//        // if((0 == flag1) && (0 == flag2) && (0 == flag3))
//        //     return true;
//        // else
//        //     return false;
//        for (int i = 0; i < count / 2;)
//        {
//            //if (((*(s + i) == '(') && (*(s + count - i - 1) == ')')) || ((*(s + i) == '[') && (*(s + count - i - 1) == ']')) || ((*(s + i) == '{') && (*(s + count - i - 1) == '}')))
//            //    flag = 1;
//            //else
//            //    return false;
//            if ((*(s + i) == '(') && (*(s + count - i - 1) == ')'))
//                i++;
//            else if ((*(s + i) == '[') && (*(s + count - i - 1) == ']'))
//                i++;
//            else if ((*(s + i) == '{') && (*(s + count - i - 1) == '}'))
//                i++;
//            else if(*(s + i) == '('))
//                return false;
//        }
//        return true;
//    }
//    else
//        return false;
//}

//bool isValid(char* s) {
//    int count = 0;
//    while (*s != '\0')
//    {
//        if (*s == ')')
//        {
//            if (*(s - 1 - count*2) != '(')
//                return false;
//            else
//                *s = *(s - 1 - count * 2) = ' ', count++;
//        }
//        else if (*s == ']')
//        {
//            if (*(s - 1 - count * 2) != '[')
//                return false;
//            else
//                *s = *(s - 1 - count * 2) = ' ', count++;
//        }
//        else if (*s == '}')
//        {
//            if (*(s - 1 - count * 2) != '{')
//                return false;
//            else
//                *s = *(s - 1 - count * 2) = ' ', count++;
//        }
//        s++;
//    }
//    return true;
//}

bool isValid(char* s) {
    int count = 1;
    int i = 0;
    int j = 0;
    char* pc = s;
    int flag = 0;
    int flag1 = 0;
    if ((*s == ')') || (*s == ']') || (*s == '}'))
        return false;
    s++;
    while (*s != '\0')
    {
        if (*s == ')')
        {
            if (s == pc + 1)
            {
                if (*(s - 1) != '(')
                    return false;
                else
                    *(s - 1) = ' ', * s = ' ';

            }
            else
            {
                for (i = 1; (*(s - i) == ' ') && (i < count); i++);
                if (*(s - i) != '(')
                    return false;
                else
                    *s = *(s - i) = ' ';
            }
            flag = 1;
        }
        else if (*s == ']')
        {
            if (s == pc + 1)
            {
                if (*(s - 1) != '[')
                    return false;
                else
                    *(s - 1) = ' ', * s = ' ';
            }
            else
            {
                for (i = 1; (*(s - i) == ' ') && (i < count); i++);
                if (*(s - i) != '[')
                    return false;
                else
                    *s = *(s - i) = ' ';
            }
            flag = 1;
        }
        else if (*s == '}')
        {
            if (s == pc + 1)
            {
                if (*(s - 1) != '{')
                    return false;
                else
                    *(s - 1) = ' ', * s = ' ';
            }
            else
            {
                for (i = 1; (*(s - i) == ' ') && (i < count); i++);
                if (*(s - i) != '{')
                    return false;
                else
                    *s = *(s - i) = ' ';
            }
            flag = 1;
        }
        s++;
        count++;
    }
    for (j = 0; j < count; j++)
    {
        if (*(pc + j) != ' ')
        {
            flag1 = 1;
            break;
        }
    }
    if ((count % 2 == 0) && (1 == flag) && (0 == flag1))
        return true;
    else
        return false;
}

int main(void)
{
    char str[] = "(()(";
    printf("%d",isValid(str));
    return 0;
}

