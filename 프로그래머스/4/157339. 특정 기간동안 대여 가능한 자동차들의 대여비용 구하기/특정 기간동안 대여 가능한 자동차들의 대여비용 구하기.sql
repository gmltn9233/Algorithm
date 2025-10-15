-- 코드를 입력하세요
SELECT car.car_id as CAR_ID, car.car_type as CAR_TYPE, ROUND((car.daily_fee*30*(100-plan.discount_rate)/100)) as FEE FROM CAR_RENTAL_COMPANY_CAR AS CAR
INNER JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN AS PLAN ON CAR.car_type = PLAN.car_type
where (car.car_type = 'SUV' or car.car_type = '세단') 
and plan.duration_type = '30일 이상'
and car.car_id not in (
    select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where START_DATE <= '2022-11-30' and END_DATE >= '2022-11.01'
)
AND (car.daily_fee*30*(100-plan.discount_rate)/100) >= 500000
AND (car.daily_fee*30*(100-plan.discount_rate)/100) < 2000000
order by FEE DESC, car_id
;