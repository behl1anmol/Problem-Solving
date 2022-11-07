/* Write your T-SQL query statement below */
SELECT p.firstname, p.lastname, a.city, a.state from Person p LEFT OUTER JOIN Address a ON p.personId = a.personId; 