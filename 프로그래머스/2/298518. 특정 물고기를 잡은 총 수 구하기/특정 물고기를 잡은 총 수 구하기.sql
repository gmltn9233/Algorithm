select count(*)as FISH_COUNT from FISH_INFO as FI
inner join FISH_NAME_INFO as FNI on FI.FISH_TYPE = FNI.FISH_TYPE
where FNI.FISH_NAME = 'BASS' or FNI.FISH_NAME = 'SNAPPER'
;