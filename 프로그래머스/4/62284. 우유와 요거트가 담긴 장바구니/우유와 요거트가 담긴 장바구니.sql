select distinct c1.cart_id from cart_products c1
where c1.cart_id in(
select c2.cart_id from cart_products c2
where c2.name = 'Milk' or c2.name = 'Yogurt'
group by c2.cart_id
having count(distinct c2.name) =2
)
order by c1.cart_id
;