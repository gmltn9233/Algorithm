SELECT 
    ANIMAL_TYPE, 
    CASE 
        WHEN NAME IS NULL THEN 'No name' 
        ELSE NAME 
    END AS NAME, 
    SEX_UPON_INTAKE 
FROM 
    animal_ins
ORDER BY
    ANIMAL_ID
;
