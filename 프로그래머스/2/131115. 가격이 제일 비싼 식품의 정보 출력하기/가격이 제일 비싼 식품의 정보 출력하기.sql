-- 코드를 입력하세요
SELECT f.PRODUCT_ID,
       f.PRODUCT_NAME,
       f.PRODUCT_CD,
       f.CATEGORY,
       f.PRICE
from FOOD_PRODUCT as f
WHERE F.PRICE = (SELECT MAX(PRICE) FROM FOOD_PRODUCT)
;