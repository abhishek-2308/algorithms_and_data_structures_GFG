<h2><a href="https://www.geeksforgeeks.org/problems/maximum-gcd-of-siblings-of-a-binary-tree/1">Max GCD of Siblings</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a 2D list that represents the nodes of a <a href="https://www.geeksforgeeks.org/binary-tree-data-structure/">Binary tree</a> with <strong>n</strong> nodes, find the maximum <a href="https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/">GCD</a> of the siblings of this tree without actually constructing it.&nbsp;</span></p>
<p><span style="font-size: 18px;"><strong>Note: </strong>If there are <strong>no pairs</strong> of siblings in the given tree, print <strong>0</strong>. Also, if given that there's an edge between a and b in the form of <strong>[a, b]</strong> in the list, then <strong>a</strong> is the <strong>parent </strong>node.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr = [[4, 5], [4, 2], [2, 3], [2, 1], [3, 6], [3, 12]]
<strong>Output: </strong>6
<strong>Explanation:</strong>
</span><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/929018/Web/Other/blobid0_1779965479.webp" width="203" height="226"> <br><span style="font-size: 18px;">For the above tree, the maximum GCD for the sibilings is 6, formed for the nodes 6 and 12 for the children of node 3.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [[1, 2], [1, 4]] 
<strong>Output : </strong>2</span>
<span style="font-size: 18px;"><strong>Explanation:</strong>
</span><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/929018/Web/Other/blobid1_1779965502.webp" width="166" height="109"> <br><span style="font-size: 18px;">For the above tree, the maximum GCD for the sibilings is 2, formed for the nodes 2 and 4 for the children of node 1.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>5 </sup>There might be edges with similar values</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Samsung</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Tree</code>&nbsp;