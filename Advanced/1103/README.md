# Integer Factorization

使用了 dfs，从 bound to 1 进行 dfs，满足条件就判断，不满足，比如超过了 n 那就剪枝。每次 dfs 需要保留 path.

if 要考虑**所有情况**，小于、等于、大于都需要考虑，不能把等于和小于放在一起。