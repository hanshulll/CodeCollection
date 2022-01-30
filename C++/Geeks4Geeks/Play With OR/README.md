# Play With OR
## Basic 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">&nbsp;You are given an array <strong>arr[]</strong>, you have to re-construct an&nbsp;array <strong>arr[]</strong>.<br>
The values in <strong>arr[]</strong> are obtained by doing OR(<strong>bitwise or</strong>) of consecutive elements in the array.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>â€‹Input :</strong> arr[ ] = {10, 11, 1, 2, 3}
<strong>Output :</strong> 11 11 3 3 3
<strong>Explanation:</strong>
At index 0, arr[0] or arr[1] = 11
At index 1, arr[1] or arr[2] = 11
At index 2, arr[2] or arr[3] = 3
...
At index 4, No element is left So, it will 
remain as it is.
New Array will be {11, 11, 3, 3, 3}.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>â€‹Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[ ] = {5, 9, 2, 6} <strong>
Output :</strong>  13 11 6 6 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>game_with_number()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(n)</strong>, and return the array re-constructed array <strong>arr</strong>. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span></p>

<p><span style="font-size:18px">1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ arr[i] ≤ 10<sup>7</sup></span></p>
 <p></p>
            </div>