# Process Scheduling Algorithms

A Process Scheduler schedules different processes to be assigned to the CPU based on particular scheduling algorithms. There are six popular process scheduling algorithms−  

* First-Come, First-Served (FCFS) Scheduling
* Shortest-Job-Next (SJN) Scheduling
* Priority Scheduling
* Shortest Remaining Time
* Round Robin(RR) Scheduling
* Multiple-Level Queues Scheduling


## First-Come, First-Served (FCFS) Scheduling

* Jobs are executed on first come, first serve basis.
* It is a non-preemptive, pre-emptive scheduling algorithm.
* Easy to understand and implement.
* Poor in performance as average wait time is high.

### Example for FCFS
```
+-----+--------------+------------+
| PID | Arrival Time | Burst Time |
+-----+--------------+------------+
|  A  |      2       |      3     |
+-----+--------------+------------+
|  B  |      1       |      2     |
+-----+--------------+------------+
|  C  |      0       |      2     |
+-----+--------------+------------+
|  D  |     10       |      5     |
+-----+--------------+------------+

the average waiting time = 3.75
```
