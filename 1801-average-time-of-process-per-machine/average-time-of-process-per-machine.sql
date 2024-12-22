# Write your MySQL query statement below
-- select en.machine_id, st.process_id, en.timestamp as end, st.timestamp as start, en.timestamp-st.timestamp as time
select st.machine_id, round(avg(en.timestamp-st.timestamp),3) as processing_time
from activity en
join activity st 
on en.machine_id=st.machine_id and st.process_id=en.process_id and en.timestamp>st.timestamp
group by st.machine_id