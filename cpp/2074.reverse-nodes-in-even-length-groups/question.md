# [2074. Reverse Nodes in Even Length Groups][link] (Medium)

[link]: https://leetcode.com/problems/reverse-nodes-in-even-length-groups/

You are given the `head` of a linked list.

The nodes in the linked list are **sequentially** assigned to **non-empty** groups whose lengths form
the sequence of the natural numbers ( `1, 2, 3, 4, ...`). The **length** of a group is the number of
nodes assigned to it. In other words,

- The `1ˢᵗ` node is assigned to the first group.
- The `2ⁿᵈ` and the `3ʳᵈ` nodes are assigned to the second group.
- The `4ᵗʰ`, `5ᵗʰ`, and `6ᵗʰ` nodes are assigned to the third group, and so on.

Note that the length of the last group may be less than or equal to `1 + the length of the second to
last group`.

**Reverse** the nodes in each group with an **even** length, and return the `head`of the modified
linked list.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/10/25/eg1.png)

```
Input: head = [5,2,6,3,9,1,7,3,8,4]
Output: [5,6,2,3,9,1,4,8,3,7]
Explanation:
- The length of the first group is 1, which is odd, hence no reversal occurs.
- The length of the second group is 2, which is even, hence the nodes are reversed.
- The length of the third group is 3, which is odd, hence no reversal occurs.
- The length of the last group is 4, which is even, hence the nodes are reversed.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/10/25/eg2.png)

```
Input: head = [1,1,0,6]
Output: [1,0,1,6]
Explanation:
- The length of the first group is 1. No reversal occurs.
- The length of the second group is 2. The nodes are reversed.
- The length of the last group is 1. No reversal occurs.
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2021/11/17/ex3.png)

```
Input: head = [1,1,0,6,5]
Output: [1,0,1,5,6]
Explanation:
- The length of the first group is 1. No reversal occurs.
- The length of the second group is 2. The nodes are reversed.
- The length of the last group is 2. The nodes are reversed.
```

**Constraints:**

- The number of nodes in the list is in the range `[1, 10⁵]`.
- `0 <= Node.val <= 10⁵`
