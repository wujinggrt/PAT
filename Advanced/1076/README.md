# Forwards on Weibo

Graph，他们的关系为，有向图，方向为这个人（vertex）能够影响的方向。也就是被关注人指向关注者。

感觉是DFS， or BFS。

all his/her followers can view and forward his/her post, which can then be forwarded again by their followers.

题意：给出的每行是关注的list。我居然理解为被关注的。。。

一个坑：如果visited在pop之后才选择上色（or set flag），那么在遍历图的时候可能会被重复添加。

列可以知道关注了谁。行知道被谁关注。

BFS:如果访问过了，打个x:

            6                         2
            |                         |
            3                         1
          / | \                       |
         1  4  5                      4
        /   |   \_ 3x,7x            / | \
      4x  7,5x,6                   1x 5  6

       一共5个：3,1,4,5,7       一共4个:1,4,5,6