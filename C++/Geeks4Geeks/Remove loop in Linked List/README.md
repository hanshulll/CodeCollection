# Remove loop in Linked List
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a linked list of <strong>N</strong> nodes such that it may contain a loop. </span></p>

<blockquote>
<p><span style="font-size:18px">A loop here means that the last node of the link list is connected to the node at position X. If the link list does not have any loop, X=0.</span></p>
</blockquote>

<p><span style="font-size:18px">Remove the loop from the linked list, if it is present. </span>&nbsp;</p>

<p><br>
<strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 3
value[] = {1,3,4}
X = 2
<strong>Output: </strong>1<strong>
Explanation: </strong>The link list looks like<strong>
</strong>1 -&gt; 3 -&gt; 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. </span>
</pre>

<p><br>
<strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 4
value[] = {1,8,3,4}
X = 0
<strong>Output: </strong>1<strong>
Explanation: </strong>The&nbsp;Linked list does not 
contains any loop. </span></pre>

<p><br>
<strong><span style="font-size:18px">Example 3:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 4
value[] = {1,2,3,4}
X = 1
<strong>Output: </strong>1<strong>
Explanation: </strong>The link list looks like<strong> 
</strong>1 -&gt; 2 -&gt; 3 -&gt; 4
|______________|
A loop is present. 
If you remove it successfully, 
the answer will be 1. </span></pre>

<p><br>
<span style="font-size:18px"><strong>Your&nbsp;Task:</strong><br>
You don't need to read input or print anything.&nbsp;Your task is to&nbsp;complete the function <strong>removeLoop</strong>() which takes the&nbsp;head of the linked list as the input parameter. Simply remove the loop in the list (if present) without disconnecting any nodes from the list.<br>
<strong>Note: </strong>The generated output&nbsp;will be&nbsp;<strong>1&nbsp;</strong>if your submitted code is correct.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected time complexity:</strong> O(N)</span><br>
<span style="font-size:18px"><strong>Expected auxiliary space:&nbsp;</strong>O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>4</sup></span></p>
 <p></p>
            </div>