# Graduate Admission

复杂排序：根据总分，ge来排序。如果两个相同，rank同。

在相同rank申请school，那么如果有一个被接受，另一个也会，就算超额也要给与他accept。

维护一个队列，每一次入队列，就减少这个学校的名额。然后rear就作为参考rank。

对于students的遍历prefer的学校中，先检查第一个，如果学校满了，检查队列尾部学生是否和自己同样的rank。if true，append。