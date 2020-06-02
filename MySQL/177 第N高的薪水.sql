/*
177. 第N高的薪水
编写一个 SQL 查询，获取 Employee 表中第 n 高的薪水（Salary）。

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
例如上述 Employee 表，n = 2 时，应返回第二高的薪水 200。如果不存在第 n 高的薪水，那么查询应返回 null。

+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
通过次数47,167提交次数104,367
在真实的面试中遇到过这道题？
*/

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
	SET N = N - 1;
	RETURN (
	 SELECT DISTINCT salary FROM employee ORDER BY salary DESC LIMIT N, 1
	);
END