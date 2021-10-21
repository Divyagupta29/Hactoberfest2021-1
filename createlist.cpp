#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertathead(node * &head,int val){        //add value starting of the linklist
       node* n=new node(val);
       n->next=head;
       head=n;
}
bool search(node* head,int key){               //search key is present in your linklist or not
     node *temp=head;
     while(temp!=NULL){
         if(temp->data==key){
             return true;          //your key present return 1
         }
         temp=temp->next;
     }
     return false;                    //not present return 0
}
void insertattail(node * &head,int val){           //add value  end of the linklist

    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node *temp=head;

    while(temp->next!=NULL){
       temp=temp->next;
    }
    temp->next=n;

}
void deleteathead(node* &head){               //delete the value in starting 
          node* todelete=head;  
          head=head->next;
          delete todelete;  
}
void deletion(node* &head,int val){                      //deletion at any given value
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteathead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
void display(node *head){             //show the element after condition
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverse(node* &head){                    //reverse the linklist
    node* pre=NULL;
    node*curre=head;
    node*nextptr;
    while(curre!=NULL){
        nextptr=curre->next;
        curre->next=pre;
        
        pre=curre;
        curre=nextptr;
    }
    return pre;
}
node *reversek(node* &head,int k){
     node* pre=NULL;
    node*curre=head;
    node*nextptr;
    int count=0;
     while(curre!=NULL&&count<k){
        nextptr=curre->next;
        curre->next=pre;
        pre=curre;
        curre=nextptr;
        count++;
     }
     if(nextptr!=NULL){
     head->next=reversek(nextptr,k);
     }
     return pre;
}
void insertatsortedlist(node* &head,int val){
    node* p=new node(val);
    node* q=NULL;
    p->data=val;
    p->next=NULL;
    if(head==NULL){
        head=p;
    }
    else{
        while(head && head->data<val){
            q=head;
            head=head->next;
        }
        if(head==NULL){
            p->next=head;
            head=p;
        }
        else{
            p->next=q->next;
            q->next=p;
        }
    }
}
int main(){
    node *head=NULL;
    insertattail(head,2);               //function calling
    insertattail(head,9);
    insertattail(head,7);
    insertattail(head,4);
    insertattail(head,10);
    display(head);
    insertathead(head,3);
    display(head);
 
 node* newhead=reverse(head);
 display(newhead);
 int k=2;
 node* newheade=reversek(head,k);
 display(newheade);
 insertatsortedlist(head,6);
 display(head);
    return 0;
}
