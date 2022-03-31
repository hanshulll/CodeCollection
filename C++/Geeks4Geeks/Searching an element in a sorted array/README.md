# Searching an element in a sorted array
## Basic 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array&nbsp;<strong>arr[] </strong>sorted in ascending order of size <strong>N</strong> and an integer <strong>K</strong>. Check if K&nbsp;is present in the array or not.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5, K = 6
arr[] = {1,2,3,4,6}
<strong>Output: </strong>1<strong>
Exlpanation: </strong>Since, 6 is present in 
the array at index 4 (0-based indexing),
output is 1.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5, K = 2
arr[] = {1,3,4,5,6}
<strong>Output: </strong>-1<strong>
Exlpanation: </strong>Since, 2 is not present 
in the array, output is -1.</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Complete the function&nbsp;<strong>searchInSorted()</strong> which takes the sorted array arr[], its size N and the element K as input parameters&nbsp;and returns 1 if K&nbsp;is present in the array, else it returns -1.&nbsp;</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(Log N)<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>6</sup><br>
1 &lt;= K &lt;= 10<sup>6</sup><br>
1 &lt;= arr[i] &lt;= 10<sup>6</sup></span></p>

<p>&nbsp;</p>
 <p></p>
            </div>