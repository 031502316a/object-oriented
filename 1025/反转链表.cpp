#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

struct Node
{
  int before_address;
  int next_address;
  int number;
  Node *before;
  Node *next;
} dote[100010];

int main()
{
    Node *head,*head1,*p1,*p2,*temp;
  head=head1=p1=p2=temp=new Node;
  head1=NULL;
  
  int begin,n,much,i,real=0;
  cin>>begin>>n>>much;
  
  /* 构建双向链表 */
  for(i=0;i<n;i++)
  {
      int address1,address2,num;
    cin>>address1>>num>>address2;
    dote[address1].before_address = address1;
    dote[address1].next_address = address2;
    dote[address1].number = num;
    if(address2 != -1) 
    {
      dote[address1].next = &dote[address2];
      dote[address2].before = &dote[address1];
    }
    else
    {
      dote[address1].next=NULL;
    }
  }
  head1 = &dote[begin];
  p1 = head1;
  
   /* 看看真正的链表里面是有几个单位组成 */
  while(p1 != NULL)
  {
     real++;
     p1=p1->next;
  }
  n=real;
  p1 = head1;
  
  /* 新建反转链表 */
  int time=0;
  head = NULL;
  while(p1 != NULL && real >= much)
  {
    time++;
    if(time == much)
    {
      real=real-much;
      temp=p1;                       
            p1=p1->next;
      while(time != 0 )
      {
        if(head==NULL)
          head=temp;
        else
          p2->next=temp;
          p2->next_address=temp->before_address;
          
        
        p2=temp;
        temp=temp->before;
        time--;
      }
    }
    else
    {
      p1=p1->next;
    }
  }
    
    if(real != 0)
    {
      if(head==NULL)
    {
      head=p1;
    }
    else
    {
      p2->next=p1;
      p2->next_address=p1->before_address;
    }
  }
  else
  {
    p2->next=NULL;
  }

  /* 输出反转链表 */
  
  while(head != NULL)
  {
    if(head->next != NULL)
    {
      printf("%05d %d %05d\n",head->before_address,head->number,head->next_address);
    }
    else
    {
      head->next_address=-1;
      printf("%05d %d %d\n",head->before_address,head->number,head->next_address);
    }
    head=head->next;
  }  
  return 0;
}
