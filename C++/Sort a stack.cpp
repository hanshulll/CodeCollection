//Program for sort a stack 
void sortedInsert(stack<int>&s,int ele){
   
   if(s.empty() || ele > s.top()){
       s.push(ele);
   }
   else{
       int temp = s.top();
       s.pop();
       sortedInsert(s,ele);
       s.push(temp);
       return;
   }
   
}

void SortedStack :: sort()
{

   if(!s.empty()){
       int temp = s.top();
       s.pop();
       sort();
       sortedInsert(s,temp);
       return;
   }
}
