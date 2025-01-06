select CONCAT(quarter(DIFFERENTIATION_DATE),'Q')as QUARTER, count(*) as ECOLI_COUNT
from ECOLI_DATA
group by quarter
order by quarter
;