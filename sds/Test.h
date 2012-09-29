#pragma once
class Base
{
       public:
          Base(){ cout<<"Constructor: Base"<<endl;}
          virtual ~Base(){ cout<<"Destructor : Base"<<endl;}
};
class Derived: public Base
{
     //Doing a lot of jobs by extending the functionality
       public:
           Derived(){ cout<<"Constructor: Derived"<<endl;}
            ~Derived(){ cout<<"Destructor : Derived"<<endl;}
};


class A{ 
public: 
A() {func(0);}; 
virtual void func(int data) {printf("A1 :%d\n",data);} 
virtual void func(int data) const {printf("A2 :%d\n",data);} 
void func(char *str) {printf("A3 %s)\n",str);} 
}; 
 
class B:public A{ 
public: 
void func() {printf("B1 :%s\n","");} 
void func(int data) {printf("B2 :%d\n",data);} 
void func(char *str) {printf("B3 %s)\n",str);} 
}; 
