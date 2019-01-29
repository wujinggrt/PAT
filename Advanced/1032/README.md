# Sharing

根据题意，很显然是关于map的使用。

首先使用unordered_map来存储former_visited, c, next这三个数据。

第一次，从第一个start address开始遍历，然后把遍历的node设置former_visited为true。随后，从latter start address开始遍历。如果遍历途中遇到former_visited为true，那么就是访问过了，从这儿break，便可输出。如果没找到这样的点，自然为"-1"s。

注意，第一个字符的former_visited，和最后一个“-1”的address，也需要设置为former_visited为true。

然后在latter_address开始遍历的时候，从第一个字符开始，便需要考虑到是否遇到former_visited为true。