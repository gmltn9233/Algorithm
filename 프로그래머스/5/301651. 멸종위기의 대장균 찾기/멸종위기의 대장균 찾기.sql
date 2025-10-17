with recursive parent as(
    select id, parent_id, 0 depth
    from ecoli_data
    where parent_id is null
    
    union all
    
    select ed.id, ed.parent_id, p.depth+1 as depth from parent as p
    left join ecoli_data as ed on p.id = ed.parent_id
    where p.id is not null
)
select count(*) as count, depth as generation from parent
where id is null
group by depth
order by depth
;







# WITH RECURSIVE PARENT AS (
#     SELECT ID, PARENT_ID, 0 DEPTH
#       FROM ECOLI_DATA
#      WHERE PARENT_ID IS NULL

#     UNION ALL

#     SELECT ED.ID, ED.PARENT_ID, P.DEPTH + 1 DEPTH
#       FROM PARENT P
#       LEFT OUTER JOIN ECOLI_DATA ED
#         ON P.ID = ED.PARENT_ID
#      WHERE P.ID IS NOT NULL
# ) 

# SELECT 
#        COUNT(*) AS COUNT, DEPTH GENERATION
#   FROM PARENT
#  WHERE ID IS NULL
#  GROUP BY ID, DEPTH
#  ORDER BY DEPTH;