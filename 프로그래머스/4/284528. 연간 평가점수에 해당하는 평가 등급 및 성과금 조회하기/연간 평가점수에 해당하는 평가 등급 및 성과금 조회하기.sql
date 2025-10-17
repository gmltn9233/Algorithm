select e.emp_no, e.emp_name,
case
when avg(g.score)>=96 then 'S'
when avg(g.score)>=90 then 'A'
when avg(g.score)>=80 then 'B'
else 'C'
end as grade,
case
when avg(g.score)>=96 then e.sal*20/100
when avg(g.score)>=90 then e.sal*15/100
when avg(g.score)>=80 then e.sal*10/100
else 0
end as bonus
from hr_employees as e
join hr_grade as g on e.emp_no = g.emp_no
group by emp_no
order by emp_no
;