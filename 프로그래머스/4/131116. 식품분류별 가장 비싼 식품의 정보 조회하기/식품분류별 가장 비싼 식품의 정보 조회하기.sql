SELECT category, price as max_price, product_name from food_product
where (category = '과자' or category = '국' or category = '김치' or category = '식용유')
and (category, price) in (
    select category, max(price)  from food_product
    group by category
)
group by category
order by max_price desc;
