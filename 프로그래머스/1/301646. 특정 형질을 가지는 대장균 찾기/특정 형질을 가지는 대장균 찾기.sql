select count(*)as COUNT from ecoli_data
where ((GENOTYPE & 2 )= 0) and (GENOTYPE & 1 != 0 or GENOTYPE & 4 != 0)
;