#include<iostream>
#include<memory>                                      // Header file having declaration of the unique pointer
using namespace std;

class foo
{
    int x;


    public:

   explicit foo(int x):x(x)
    {}

    int getx()
    {
        return x;
    }

    ~foo()
    {
        cout<<"Foo Dest"<<endl;
    }
};

int main()
{
   // foo *f=new foo(10);             // the problem is that we forgot to destroy the DMA block, hence it leads to memory leak.  
   // cout<<f->getx()<<endl;          // Using delete will be necessary in this but as we can't always remember to do so. SO WE USE UNIQUE POINTER.
                                       //  delete f;

    unique_ptr<foo> p (new foo(40));   // NO EXCEPTION SAFETY         
   // unique_ptr<foo> p1 = make_unique<foo>(40);   (should use make_unique(exception safe))          
                                    
    cout<<p->getx()<<endl;              // The advantages of unique pointer is that it will destroy the memory block it is pointing to when it

    return 0;                           // itself will be destroyed, and obviously when object is gonna destroyed, the destructor will be called.    
                                        // We can't copy that address to any pointer to which unique pointer is pointing. Only unique pointer 
                                        // has ownership for that DMA block, but we can make a pointer to pointer to that to access that memory block.
    
     // IMP -----  We can move the ownership of the unique_ptr to another one(unique_ptr) by using move() 
       /* unique_ptr<foo> p1 = move(p);  Here the ownership has been moved from "p" to "p1", now p points to that object(having the ownership) and p points null now.
         
    // IMP ------ We can release the ownership of the unique_ptr and can make it point by a normal (class)pointer by using release().
       foo *p2 = p1.release() 
    
    // IMP ------ We can swap the managed objects of the unique_ptr(s) by using swap() function.
        unique_ptr<foo> p3 = swap(p1);

    // IMP ------ We can reset the unique_ptr by using reset() function.  
        p4.reset(p2)   HERE 'p2' SHOULD BE A NORMAL (CLASS) POINTER.       (Considering that 'p4' is pointing to a managed object(having ownership)) 
                      Hence, Now the p4 will point to what p2 is pointing, and that previous managed object which was pointed by p4 will get deleted.      
  
   */
       
}



