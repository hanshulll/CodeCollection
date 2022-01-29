package LeetCode;

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;

/*
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively.
 All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue).
 Return the number of students that are unable to eat.
 */
public class NumberofStudentsUnabletoEatLunch {
    public static void main(String[] args) {
        int[] student = {1,1,1,0,0,1};
        int[] sandWitch ={1,0,0,0,1,1};

        int ans = countStudents(student , sandWitch);
        System.out.println(ans);
    }
    public static int countStudents(int[] students, int[] sandwiches) {

        Stack<Integer> st = new Stack<>();
        Queue<Integer> Q = new ArrayDeque<>();

        for (int i = sandwiches.length-1; i >=0 ; i--) {
            st.push(sandwiches[i]);
        }

        for (int i = 0; i <students.length; i++) {
                Q.add(students[i]);
        }



        int count= 0;
        while(Q.size() !=0){
            if(count == Q.size()) return  count;
            if(Q.element() == st.peek()){
                Q.poll();
                st.pop();
                count = 0;

            }else{
                int val = Q.poll();
                Q.offer(val);
                count += 1;

            }
        }
        return count;

    }
}
