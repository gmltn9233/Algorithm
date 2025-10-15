SELECT fp.product_id, fp.product_name, sum(fo.amount)*fp.price AS TOTAL_SALES FROM food_product AS fp
INNER JOIN food_order AS fo ON fp.product_id = fo.product_id
where fo.produce_date like '2022-05%'
group by product_id
order by TOTAL_SALES DESC, fp.product_id
;