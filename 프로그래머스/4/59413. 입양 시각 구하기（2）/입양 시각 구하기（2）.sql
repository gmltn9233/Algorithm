with recursive hours as (
    select 0 as h
    union all
    select h+1 from hours
    where h<23
)
select hours.h as hour, count(ao.datetime) as count  from hours
left join animal_outs as ao on hours.h = hour(ao.datetime)
group by hour
;