# Write your MySQL query statement below
SELECT MAX(Salary) AS SecondHighestSalary from Employee
WHERE Salary < (SELECT MAX(Salary) from Employee)