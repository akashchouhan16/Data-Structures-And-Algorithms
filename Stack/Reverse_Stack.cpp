#include<iostream>
#include<stack>
using namespace std;

void  insertAtbottom(stack<int> &s, int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    //rec case
    int temp = s.top();
    s.pop();

    insertAtbottom(s,data);
    s.push(temp);
}

void reverse(stack<int> &s){
    if (s.empty()){
        return;
    }
    int t = s.top();
    s.pop();
    reverse(s);
    insertAtbottom(s,t);

}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    reverse(s);

    while (!s.empty())
    {
       cout<<s.top()<<endl;
       s.pop();
    }
return 0;
}
