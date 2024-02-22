SELECT CAR_ID,
CASE WHEN CAR_ID IN (SELECT CAR_ID FROM car_rental_company_rental_history WHERE "2022-10-16" BETWEEN START_DATE AND END_DATE) THEN "대여중"
ELSE "대여 가능"
END AVAILABILITY
from car_rental_company_rental_history h
GROUP BY CAR_ID
ORDER BY CAR_ID DESC
;
