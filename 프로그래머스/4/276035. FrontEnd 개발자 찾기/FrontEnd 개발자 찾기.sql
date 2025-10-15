SELECT distinct d.id, d.email,  d.first_name, d.last_name FROM developers as d
inner join skillcodes as s on (d.skill_code & s.code) = s.code
where s.category = 'Front End'
order by d.id;

