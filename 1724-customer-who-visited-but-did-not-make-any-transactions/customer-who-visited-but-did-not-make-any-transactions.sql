select customer_id , count(*) as count_no_trans from

(SELECT v.customer_id 
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
where transaction_id is NULL ) as temp
group by customer_id ;