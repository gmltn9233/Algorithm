select item_id, item_name, rarity from item_info
where item_id in (
select tree.item_id from item_info as info
    join item_tree as tree on info.item_id = tree.parent_item_id
    where info.rarity = 'rare'
)
order by item_id desc
;