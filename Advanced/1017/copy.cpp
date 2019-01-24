#include<iostream>
#include<iomanip>
#include<queue>
#include<stdio.h>
 
using namespace std;
 
struct Person{
    int hour;
    int minute;
    int second;
    int last;
    int total;
 
    Person(int _h, int _m, int _s, int _l) : hour(_h), minute(_m), second(_s), last(_l * 60){
        total = _h * 3600 + _m *60 + _s;
    }
 
    bool operator < (const Person& p) const {
 
        if( total > p.total ){
            return true;
        }else{
            return false;
        }
 
    }
 
};
 
struct Window{
    int total;
 
    Window(int _t):total(_t){}
 
    bool operator < (const Window& w) const{
 
        if( total > w.total ){
            return true;
        }else{
            return false;
        }
 
    }
 
};
 
int main(){
 
    priority_queue<Person> persons;
    priority_queue<Window> windows;
 
    int N,K;
    cin >> N >> K;
 
    int clk_base = 28800;
    int clk_limit = 61201;
    int wait_total = 0;
 
    for(int i = 0; i < K; i++){
        windows.push(Window(clk_base));
    }
 
    int h,m,s,l;
    for(int i = 0; i < N; i++){
        scanf("%d:%d:%d%d",&h,&m,&s,&l);
        persons.push(Person(h,m,s,l));
    }
 
    int cnt = 0;
    Person p = Person(0,0,0,0);
    Window w = Window(0);
    while(!persons.empty()){
 
        p = persons.top();
        persons.pop();
        if(p.total >= clk_limit) break;
        cnt++;
        w = windows.top();
        windows.pop();
        if(p.total < w.total){
            wait_total += w.total - p.total;
            w.total += p.last;
        }else{
            w.total = p.total + p.last;
        }
        cout << p.total << " " << w.total <<  " " << wait_total << "\n";
        windows.push(w);
 
    }
 
    printf("%0.1f",wait_total / cnt / 60.0);
 
    return 0;
 
}