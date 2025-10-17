select info.item_id, info.item_name, info.rarity from item_info as info
left join item_tree as tree on tree.parent_item_id = info.item_id
where tree.item_id is null
order by info.item_id desc
;