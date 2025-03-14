SELECT 
    YEAR(DIFFERENTIATION_DATE) AS YEAR, 
    ABS(SIZE_OF_COLONY - (
        SELECT MAX(SIZE_OF_COLONY) 
        FROM ECOLI_DATA 
        WHERE YEAR(DIFFERENTIATION_DATE) = YEAR
    )) AS YEAR_DEV, 
    ID 
FROM ECOLI_DATA
order by YEAR, YEAR_DEV;