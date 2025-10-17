with recursive parent as(
    select id, parent_id, 0 as depth from ecoli_data
    where parent_id is null
    
    union all
    
    select ed.id, ed.parent_id, p.depth+1 depth from parent as p
    left join ecoli_data as ed on p.id = ed.parent_id
    where p.id is not null
)
select count(*) as count, depth as generation from parent
where id is null
group by depth
order by depth
;