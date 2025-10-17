with recursive hours as(
    select 0 as hour
    
    union all
    
    select hour+1 from hours
    where hour<23
)
SELECT h.hour, count(o.datetime) as count from hours h
left join animal_outs o on h.hour = hour(o.datetime)
group by h.hour
order by h.hour
;