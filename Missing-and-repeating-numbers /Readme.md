# Missing and repeating numbers
## Medium
<div _ngcontent-serverapp-c179="" class="problem-description-container"><div _ngcontent-serverapp-c179="" class="problem-statement-title-container"><div _ngcontent-serverapp-c179="" class="problem-statement-title">Problem Statement</div><div _ngcontent-serverapp-c179="" class="suggest-edit ng-star-inserted"> Suggest Edit </div><!----><!----><!----></div><div _ngcontent-serverapp-c179="" class="description ng-star-inserted"><h4 id="you-are-given-an-array-of-size-n-the-elements-of-the-array-are-in-the-range-from-1-to-n">You are given an array of size ‘N’. The elements of the array are in the range from 1 to ‘N’.</h4>

<h4 id="ideally-the-array-should-contain-elements-from-1-to-n-but-due-to-some-miscalculations-there-is-a-number-r-in-the-range-1-n-which-appears-in-the-array-twice-and-another-number-m-in-the-range-1-n-which-is-missing-from-the-array">Ideally, the array should contain elements from 1 to ‘N’. But due to some miscalculations, there is a number R in the range [1, N] which appears in the array twice and another number M in the range [1, N] which is missing from the array.</h4>

<h4 id="your-task-is-to-find-the-missing-number-m-and-the-repeating-number-r">Your task is to find the missing number (M) and the repeating number (R).</h4>

<h5 id="for-example">For example:</h5>

<pre><code>Consider an array of size six. The elements of the array are { 6, 4, 3, 5, 5, 1 }. 
The array should contain elements from one to six. Here, 2 is not present and 5 is occurring twice. Thus, 2 is the missing number (M) and 5 is the repeating number (R). 
</code></pre>

<h5 id="follow-up">Follow Up</h5>

<pre><code>Can you do this in linear time and constant additional space? 
</code></pre>

<h5 id="input-format">Input Format</h5>

<pre><code>The first line of input contains an integer T, the number of test cases.
The first line of every test case contains an integer ‘N’ denoting the size of the array.
The second line of every test case contains ‘N’ space-separated integers.
</code></pre>

<h5 id="output-format">Output Format:</h5>

<pre><code>For every test case, print the missing number (M) and the repeating number (R) separated by a single space. 
The output of each test case is printed in a separate line.
</code></pre>

<h5 id="note">Note</h5>

<pre><code>You don’t have to print anything, it has already been taken care of. Just implement the function. 
You have to return a pair whose first element is the missing number ‘M’ and the second element is the repeating number ‘R’. 
</code></pre>

<h5 id="constraints">Constraints:</h5>

<pre><code>1 &lt;= T &lt;= 10    
2 &lt;= N &lt;= 5 * 10^4
1 &lt;= data &lt;= N

Where ‘T’ is the number of test cases, ‘N’ is the size of the array and ‘data’ denotes the value of the elements of the array. 
</code></pre>
</div><div _ngcontent-serverapp-c179="" class="description ng-star-inserted"><h5>Sample Input 1:</h5>

<pre><code>1 
5
1 3 5 4 4
</code></pre>

<h5>Sample Output 1:</h5>

<pre><code>2 4
</code></pre>

<h5>Explanation of sample input 1:</h5>

<pre><code>As we can clearly see, among all the numbers from 1 to 5, 2 is not present and 4 is occurring twice. Thus, 2 and 4 are missing and repeating numbers respectively. 
</code></pre>

<h5>Sample Input 2:</h5>

<pre><code>2
10
4 5 2 9 8 1 1 7 10 3
7
7 5 3 2 1 6 6 
</code></pre>

<h5>Sample Output 2:</h5>

<pre><code>6 1 
4 6
</code></pre>
</div><!----><!----><!----></div>