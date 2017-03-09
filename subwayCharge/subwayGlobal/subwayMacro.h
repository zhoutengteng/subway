#ifndef __SUBWAY_MACRO_H__
#define __SUBWAY_MACRO_H__

//���ʱ���ʽ�Ƿ���ȷ
#define CHECK_TIME(timeTmp) (((timeTmp)->hour < 24) && ((timeTmp)->minutes < 60))

//����ʱ���
#define DIFF_TIME(time1, time2, diffMinutes) \
    (diffMinutes) = ((time1)->hour - (time2)->hour) * 60;\
    (diffMinutes) += ((time1)->minutes - (time2)->minutes);

//���ò����жϺ���ڴ��ͷź�
#define IF_INVALID_BREAK(condition) if(!(condition)) {break;}
#define IF_INVALID_RETURN(condition, returnValue) if(!(condition)) {return (returnValue);}
#define IF_INVALID_RETURN_NOVALUE(condition) if(!(condition)) {return ;}
#define IF_INVALID_SET_RETURN_VALUE(condition, returnValue, returenPara) if(!(condition)) {(returenPara) = (returnValue);}
#define FREE_PTR(ptr) if((ptr)) {free((ptr)); (ptr) = NULL;}

//�������С
#define SIZE(arr) (sizeof((arr))/sizeof((arr)[0]))

//�����ֵ
static inline int MaxValue(int x, int y)
{
    return (x > y) ? x : y;
}

//����Сֵ
static inline int MinValue(int x, int y)
{
    return (x < y) ? x : y;
}

#endif