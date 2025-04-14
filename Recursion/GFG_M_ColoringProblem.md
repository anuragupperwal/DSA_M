You are given an undirected graph consisting of v vertices and a list of edges, along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

Note: The graph is indexed with 0-based indexing.

Examples:

Input: v = 4, edges[] = [(0,1),(1,2),(2,3),(3,0),(0,2)], m = 3
Output: true
Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:
Vertex 0: Color 3
Vertex 1: Color 2
Vertex 2: Color 1
Vertex 3: Color 2
Input: v = 3, edges[] = [(0,1),(1,2),(0,2)], m = 2
Output: false
Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
Expected Time Complexity: O(mV)
Expected Auxiliary Space: O(v2)

Constraints:
1 ≤ v ≤ 20
1 ≤ edges.size() ≤ (v*(v-1))/2
0 ≤ edges[i][j] ≤ n-1
1 ≤ m ≤ v

