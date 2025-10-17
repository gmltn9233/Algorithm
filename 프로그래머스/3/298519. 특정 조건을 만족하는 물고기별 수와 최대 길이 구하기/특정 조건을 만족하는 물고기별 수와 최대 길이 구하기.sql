select count(*) as fish_count, max(length) as max_length,fish_type from fish_info
where fish_type in
(select fish_type from fish_info
group by fish_type
having avg(ifnull(length,10))>=33)
group by fish_type
order by fish_type;