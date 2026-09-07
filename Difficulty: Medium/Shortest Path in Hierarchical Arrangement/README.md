<h2><a href="https://www.geeksforgeeks.org/problems/shortest-path-between-cities/1">Shortest Path in Hierarchical Arrangement</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18.6667px;">In a special city, houses are arranged in a hierarchical manner. Starting from house <strong>1</strong>, every house is connected to <strong>two</strong> new houses. For example:</span></p>
<ul>
<li><span style="font-size: 18.6667px;">1 is connected to 2 and 3</span></li>
<li><span style="font-size: 18.6667px;">2 is connected to 4 and 5</span></li>
<li><span style="font-size: 18.6667px;">3 is connected to 6 and 7</span></li>
<li><span style="font-size: 18.6667px;">and so on.</span></li>
</ul>
<p><span style="font-size: 18.6667px;">Given two house numbers <strong>x</strong> and <strong>y</strong>, determine the length of the shortest path between them.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input: </strong><span style="font-size: 14pt;">x = 2, y = 6
</span><strong style="font-size: 14pt;">Output:</strong><span style="font-size: 14pt;"> 3
</span><strong style="font-size: 14pt;">Explanation: </strong><span style="font-size: 18.6667px;">The shortest path between 2 and 6 is: 2 -&gt; 1 -&gt; 3 -&gt; 6. Since this path consists of 3 edges, the answer is 3.</span><strong style="font-size: 14pt;"><br></strong><span style="font-size: 14pt;"><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/930053/Web/Other/blobid1_1782122537.png" width="341" height="251"></span><br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>x = 8, y = 10
<strong>Output: </strong>4
<strong>Explanation: </strong>The shortest path between 8 and 10 is: 8 -&gt; 4 -&gt; 2 -&gt; 5 -&gt; 10. Since this path consists of 4 edges, the answer is 4.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:&nbsp;</strong><br>1 ≤ x, y ≤ 10<sup>9</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>PlaySimple</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematics</code>&nbsp;<code>Tree</code>&nbsp;<code>Heap</code>&nbsp;