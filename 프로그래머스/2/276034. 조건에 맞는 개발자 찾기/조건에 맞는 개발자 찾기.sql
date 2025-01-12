SELECT
    DISTINCT id,
    email,
    first_name,
    last_name
FROM
    developers d
    JOIN skillcodes s
    ON s.name IN ('C#', 'Python')
    AND d.skill_code & s.code = s.code
ORDER BY
    1