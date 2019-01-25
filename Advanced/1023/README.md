# Have Fun with Numbers

存储用string，因为可能20 digits.

分解问题：乘以二， 再用map来判断是否存在original number.

由于只可能存在0~9，使用vector替代map.

注意num > 5*的时候，doubled_num就要多**一位**，需要多一位1。