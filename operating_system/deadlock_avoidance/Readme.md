# Deadlock Avoidance

* The system dynamically considers every request and decides whether it is safe to grant it at this point.
* The system requires additional a priori information regarding the overall potential use of each resource for each process.
* Allows more concurrency.

## Banker's Algorithm

Bankers’s Algorithm is resource allocation and deadlock avoidance algorithm which test all the request made by processes for resources, it check for safe state, if after granting request system remains in the safe state it allows the request and if their is no safe state it don’t allow the request made by the process.  
  
### Inputs to Banker’s Algorithm
* Max need of resources by each process.
* Currently allocated resources by each process.
* Max free available resources in the system.

### Conditions for Granting Request
* If request made by process is less than equal to max need to that process.
* If request made by process is less than equal to freely available resource in the system.

### Example for Bankers
```
process id of the new request = 1
value of the new request      = 102

process |alloc  |max    |need   |available      |
p0      |010    |753    |743    |332            |
p1      |200    |322    |020    |               |
p2      |302    |902    |600    |               |
p3      |211    |222    |011    |               |
p4      |002    |433    |431    |               |

SAFE SEQUENCE :
1, 2, 3, 4, 0
```
