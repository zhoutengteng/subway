/******************************************************************************

��Ȩ���� (C), 2016-2036,��Ϊ�������޹�˾

******************************************************************************
�� �� ��   : list.h
�� �� ��   : ����
��    ��   : 
��������   : 
����޸�   :
��������   : ����ľ���ʵ��
�����б�   :
�޸���ʷ   :
1.��    ��   : 
��    ��   : 
�޸�����   : ����

******************************************************************************/

#ifndef _COMM_LIST_H
#define _COMM_LIST_H

/*����ĳ���ṹ��*/
typedef struct ListHead {
    struct ListHead *next;
    struct ListHead *prev;
}TListHead;


/*������̬�Ķ�ĳ������ڵ�����ʼ������*/
#define InitListHead(ptr) do { \
    TListHead* list_head_ptr = (TListHead*)ptr; \
    list_head_ptr->next = list_head_ptr; \
    list_head_ptr->prev = list_head_ptr; \
} while (0)


/*��ȡ����ڵ����������ַ*/
#define OFF_SET_OF(type,member) ((char*)&(((type *)0)->member))
#define CONTAINER_OF(ptr, type, member) ((type *)((char *)ptr - OFF_SET_OF(type,member)))
#define ListEntryGet(ptr, type, member)   CONTAINER_OF(ptr, type, member)

/*��û��ɾ��������ʱ��,��һ���ǰ�ȫ��,�����Ҫʹ��safe���Ǹ�*/
#define ListForEach(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define  ListForEachSafe(pos, n, head) \
    for(pos = (head)->next,n = pos->next; pos != (head);pos = n, n = pos->next)


/*****************************************************************************
�� �� ��  : __list_add
��������  : ˫���������ĳ���
�������  : struct list_head *new
struct list_head *prev
struct list_head *next
�������  : ��
�� �� ֵ  : ��

�޸���ʷ      :
1.��    ��   : 
��    ��   : 
�޸�����   : �����ɺ���
˵��:��Ϊ����˫������Ĳ�����˵,��������ͷ,�Լ�ͷ��ǰһ�����ߺ�һ��,�Լ�
�½ڵ����Ĺ�ϵ;ʵ����ֻҪ���������ڵ�֮��Ĺ�ϵ�����ü���,
���Գ������һ���ܵ�list add����;
*****************************************************************************/
static inline void ListAdd(TListHead *ptNew,
                       TListHead *ptPrev,
                       TListHead *ptNext)
{
    ptNext->prev = ptNew;
    ptNew->next = ptNext;
    ptNew->prev = ptPrev;
    ptPrev->next = ptNew;
}
/*****************************************************************************
�� �� ��  : list_add
��������  : ������ͷ��ʼ���
�������  : TListHead *new
TListHead *head
�������  : ��
�� �� ֵ  : ��
���ú���  : ��
��������  : ��

�޸���ʷ      :
1.��    ��   : 
��    ��   : 
�޸�����   : �����ɺ���

*****************************************************************************/
 static inline void ListAddHead(TListHead *ptNew, TListHead *ptHead)
{
    ListAdd(ptNew, ptHead, ptHead->next);
}
/*****************************************************************************
�� �� ��  : list_add_tail
��������  : ������β��ʼ���
�������  : TListHead *new
TListHead *head
�������  : ��
�� �� ֵ  : ��
���ú���  : ��
��������  : ��

�޸���ʷ      :
1.��    ��   : 
��    ��   :
�޸�����   : �����ɺ���

*****************************************************************************/
static inline void ListAddTail(TListHead *ptNew, TListHead *ptHead)
{
    ListAdd(ptNew, ptHead->prev, ptHead);
}


/*****************************************************************************
�� �� ��  : list_empty
��������  : �жϵ�ǰ�����Ƿ�Ϊ��
�������  : const TListHead *head
�������  : ��
�� �� ֵ  : ��
���ú���  : ��
��������  : ��

�޸���ʷ      :
1.��    ��   :
��    ��   : 
�޸�����   : �����ɺ���

*****************************************************************************/
static inline unsigned int ListEmpty(const TListHead *ptHead)
{
    return ptHead->next == ptHead;
}
/*****************************************************************************
 �� �� ��  : list_is_last
 ��������  : �ж��Ƿ�ڵ������һ���ڵ�
 �������  : const TListHead *ptList
             const TListHead *ptHead
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  : ��
 ��������  : ��

 �޸���ʷ      :
  1.��    ��   : 
    ��    ��   : 
    �޸�����   : �����ɺ���

*****************************************************************************/
static inline unsigned int ListIsLast(const TListHead *ptList,const TListHead *ptHead)
{
    return ptList->next == ptHead;
}

/*****************************************************************************
�� �� ��  : __list_del
��������  : ɾ������
�������  : TListHead * prev
TListHead * next
�������  : ��
�� �� ֵ  : ��
���ú���  : ��
��������  : ��

�޸���ʷ      :
1.��    ��   : 
��    ��   : 
�޸�����   : �����ɺ���

*****************************************************************************/
static inline void _ListDel(TListHead * ptPrev, TListHead * ptNext)
{
    ptNext->prev = ptPrev;
    ptPrev->next = ptNext;
}
/*****************************************************************************
�� �� ��  : list_del
��������  : ɾ������������
�������  : TListHead *entry
�������  : ��
�� �� ֵ  : ��
���ú���  : ��
��������  : ��

�޸���ʷ      :
1.��    ��   : 
��    ��   : 
�޸�����   : �����ɺ���

*****************************************************************************/
static inline void ListDel(TListHead *ptEntry)

{
    _ListDel(ptEntry->prev, ptEntry->next);
    ptEntry->next = (TListHead*)0;
    ptEntry->prev = (TListHead*)0;
}
/*****************************************************************************
 �� �� ��  : list_move_tail
 ��������  : ��һ���ڵ�ӵ�ǰ�ƶ�������β��
 �������  : TListHead *ptList
             TListHead *ptHead
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  : ��
 ��������  : ��

 �޸���ʷ      :
  1.��    ��   : 
    ��    ��   : 
    �޸�����   : �����ɺ���

*****************************************************************************/
static inline void ListMoveTail(TListHead *ptList, TListHead *ptHead)
 {
     _ListDel(ptList->prev, ptList->next);
     ListAddTail(ptList, ptHead);
 }

static inline void __ListSplice(const TListHead *list,
				 TListHead *prev,
				 TListHead *next)
{
	TListHead *first = list->next;
	TListHead *last = list->prev;

	first->prev = prev;
	prev->next = first;

	last->next = next;
	next->prev = last;
}
/*****************************************************************************
 �� �� ��  : ListSpliceTail
 ��������  : ��һ������ҵ�head�����ͷ
 �������  : TListHead *list
             				TListHead *head
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  : ��
 ��������  : ��

 �޸���ʷ      :
  1.��    ��   : 
    ��    ��   : 
    �޸�����   : �����ɺ���
    ˵��:head��ԭ����list����������list�ҽӵ�head    ��ͷ

ע��:����û���ͷ����Ƕ�̬����ģ���Ҫ�û����������
�ֹ��ͷ�����ͷ
*****************************************************************************/

static inline void ListSplice(const TListHead *list,
				TListHead *head)
{
	if (!ListEmpty(list))
		__ListSplice(list, head, head->next);
}
/*****************************************************************************
 �� �� ��  : ListSpliceTail
 ��������  : ��һ������ҵ�head�����β��
 �������  : TListHead *list
             				TListHead *head
 �������  : ��
 �� �� ֵ  : ��
 ���ú���  : ��
 ��������  : ��

 �޸���ʷ      :
  1.��    ��   : 
    ��    ��   : 
    �޸�����   : �����ɺ���
    ˵��:head��ԭ����list����������list�ҽӵ�head
    ע��:����û���ͷ����Ƕ�̬����ģ���Ҫ�û����������
    �ֹ��ͷ�����ͷ
*****************************************************************************/
static inline void ListSpliceTail(TListHead *list,
				TListHead *head)
{
	if (!ListEmpty(list))
		__ListSplice(list, head->prev, head);
}


#endif
