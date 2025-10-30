SELECT
    CASE
        WHEN 
            (d.skill_code & (SELECT SUM(code) FROM skillcodes WHERE category = 'Front End')) != 0
            AND (d.skill_code & (SELECT code FROM skillcodes WHERE name = 'Python')) != 0
        THEN 'A'

        WHEN 
            (d.skill_code & (SELECT code FROM skillcodes WHERE name = 'C#')) != 0
        THEN 'B'

        WHEN 
            (d.skill_code & (SELECT SUM(code) FROM skillcodes WHERE category = 'Front End')) != 0
            AND (d.skill_code & (SELECT SUM(code) FROM skillcodes WHERE name IN ('Python','C#'))) = 0
        THEN 'C'
    END AS GRADE,
    d.id,
    d.email
FROM developers d
HAVING GRADE IS NOT NULL
ORDER BY GRADE, d.id;