<h2><a href="https://www.geeksforgeeks.org/problems/ticket-sellers3241/1">Max Amount by Selling K Tickets</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given an integer array <strong>arr[]</strong>, where <strong>arr[i]</strong> denotes the number of tickets available with the i-th ticket seller.</span></p>
<ul>
<li><span style="font-size: 14pt;">The price of each ticket is equal to the number of tickets remaining with that seller at the time of sale.</span></li>
<li><span style="font-size: 14pt;">A seller can sell at most one ticket at a time, and after each sale, the price of the next ticket from that seller decreases by 1.</span></li>
<li><span style="font-size: 14pt;">At most<strong> k</strong> tickets can be sold in total.</span></li>
</ul>
<p><span style="font-size: 14pt;">Find the maximum amount that can be earned by selling at most k tickets. Return the answer modulo 10? + 7.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [4, 3, 6, 2, 4], k = 3
<strong>Output:</strong> 15
<strong>Explanation:</strong> Sell two tickets from the seller with 6 tickets, priced at 6 and 5 respectively, and one ticket from a seller with 4 tickets, priced at 4. The maximum earning is 15.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> arr[] = [5, 3, 5, 2, 4, 4], k = 2
<strong>Output:</strong> 10
<strong>Explanation:</strong> Sell one ticket from each of the two sellers with 5 tickets. Both tickets are priced at 5, giving a maximum earning of 10.</span></pre></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>BankBazaar</code>&nbsp;<code>Linkedin</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Heap</code>&nbsp;<code>Sorting</code>&nbsp;<code>Priority Queue</code>&nbsp;