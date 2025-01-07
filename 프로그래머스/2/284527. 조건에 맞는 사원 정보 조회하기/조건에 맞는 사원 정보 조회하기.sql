select sum(GR.score)as SCORE, EM.EMP_NO, EM.EMP_NAME, EM.POSITION, EM.EMAIL from  HR_EMPLOYEES as EM
inner join HR_GRADE as GR on EM.EMP_NO = GR.EMP_NO
inner join HR_DEPARTMENT as DE on DE.DEPT_ID = EM.DEPT_ID
group by EM.EMP_NO
order by SCORE DESC
limit 1
;