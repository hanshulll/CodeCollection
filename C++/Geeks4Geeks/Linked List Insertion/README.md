# Linked List Insertion
## Basic 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Create a link list of size N according to the given input literals. Each integer input is accompanied by an indicator which can either be 0 or 1. If it is 0, insert the integer in the beginning of the link list.&nbsp;If it is 1, insert the integer at the end of the link list.&nbsp;</span><br>
<span style="font-size:18px"><strong>Hint: </strong>When inserting at the end, make sure that you handle NULL explicitly. </span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>LinkedList: 9-&gt;0-&gt;5-&gt;1-&gt;6-&gt;1-&gt;2-&gt;0-&gt;5-&gt;0
<strong>Output: </strong>5 2 9 5 6<strong>
Explanation:
</strong>Length of Link List = N = 5
9 0&nbsp;indicated that 9 should be
inserted in the beginning. Modified
Link List = 9.
5 1&nbsp;indicated that 5&nbsp;should be
inserted in the end.&nbsp;Modified Link
List = 9,5.
6 1 indicated that 6&nbsp;should be
inserted in the end.&nbsp;Modified Link
List = 9,5,6.
2 0&nbsp;indicated that 2&nbsp;should be
inserted in the beginning.&nbsp;Modified
Link List = 2,9,5,6.
5 0&nbsp;indicated that 5&nbsp;should be
inserted in the beginning.&nbsp;Modified
Link List = 5,2,9,5,6.&nbsp;
Final linked list =&nbsp;5, 2, 9, 5, 6.<strong>
</strong></span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>LinkedList: 5-&gt;1-&gt;6-&gt;1-&gt;9-&gt;1
<strong>Output: </strong>5 6 9<strong>
</strong></span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You only need to complete the <strong>functions insertAtBeginning()&nbsp;</strong>and </span><span style="font-size:18px"><strong>insertAtEnd()</strong></span><span style="font-size:18px">&nbsp;that takes the head of link list and integer value of the data to be inserted as inputs and returns the head of the modified link list.&nbsp;</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(1) for&nbsp;<strong>insertAtBeginning()&nbsp;</strong>and O(N) for&nbsp;<strong>insertAtEnd()</strong>.<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1) for both.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>4</sup></span></p>
 <p></p>
            </div>