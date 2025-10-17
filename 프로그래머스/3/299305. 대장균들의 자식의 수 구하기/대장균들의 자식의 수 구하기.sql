select ecoli_data.id, if(ecoli_data2.child_count is null,0,ecoli_data2.child_count) as child_count from ecoli_data
left join 
(select parent_id as id, count(*) as child_count from ecoli_data
where parent_id is not null
group by parent_id) as ecoli_data2
on ecoli_data.id = ecoli_data2.id
order by ecoli_data.id
;