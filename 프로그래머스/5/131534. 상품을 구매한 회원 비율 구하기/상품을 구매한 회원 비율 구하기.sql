SELECT YEAR(os.sales_date) as YEAR, 
MONTH(os.sales_date) as MONTH, 
count(distinct os.user_id) as purchased_users,
round(count(distinct os.user_id) / (SELECT count(*) 
FROM user_info as ui
where year(joined) = 2021),1)as PUCHASED_RATIO
FROM online_sale as os
INNER JOIN user_info as ui on os.user_id = ui.user_id
where year(ui.joined) = 2021
GROUP BY YEAR, MONTH
order by year, month
;





