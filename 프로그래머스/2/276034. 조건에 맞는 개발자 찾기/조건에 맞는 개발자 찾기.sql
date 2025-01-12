select distinct d.ID, d.EMAIL, d.FIRST_NAME, d.LAST_NAME from DEVELOPERS d 
inner join SKILLCODES s on 
s.NAME in ('C#' , 'Python') and d.SKILL_CODE & s.CODE = s.CODE
order by d.ID
;
