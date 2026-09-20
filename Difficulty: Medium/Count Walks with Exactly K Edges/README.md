<h2><a href="https://www.geeksforgeeks.org/problems/possible-paths3834/1">Count Walks with Exactly K Edges</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p class="PDq2pG_selectionAnchorContainer" data-start="582" data-end="729"><span style="font-size: 14pt;">Given the adjacency matrix <strong>adj[]</strong> of a directed graph and two vertices <strong>u </strong>and <strong>v</strong>, return the number of walks from<strong> </strong>u to v that use exactly <strong>k</strong> edges.</span></p>
<p data-start="731" data-end="867"><span style="font-size: 14pt;">A walk may visit the same vertex or traverse the same edge multiple times. Since the answer can be large, return it modulo 10^9 + 7.</span></p>
<p><span style="font-size: 14pt;"> </span></p>
<p data-start="869" data-end="949"><span style="font-size: 14pt;">Here, adj[i][j] =1 indicates a directed edge from vertex i to vertex j.</span></p>
<p><span style="font-size: 18px;"><strong>Note: </strong>There can be a cycle in the graph and an edge can be travelled multiple times.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>adj[][] =[[0,1,1,1], [0,0,0,1], [0,0,0,1], [0,0,0,0]], u = 0, v = 3, k = 2
<strong>Output: </strong>2
<strong>Explanation: </strong>The two walks are [0, 2, 3] and [0, 1, 3].<br></span><img style="cursor: zoom-in;" title="Click to enlarge" src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/graph1.png" alt="graph" width="321" height="215"></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>adj[][] =[[0,1,1], [0,0,1], [0,1,0]], u = 0, v = 1, k = 2
<strong>Output: 1</strong>
<strong>Explanation: </strong></span><span style="font-size: 14pt;">Let source ‘u’ be vertex 0, destination ‘v’ be 1 and k be 2. The output should be 1 as there is only one walk from 0 to 1 with exactly 2 edges. The walk is [0, 2, 1].</span></pre></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Divide and Conquer</code>&nbsp;<code>DFS</code>&nbsp;<code>Graph</code>&nbsp;