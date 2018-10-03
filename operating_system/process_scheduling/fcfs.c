#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// holds the initial process details
struct proc {
  char name[5];
  int at;
  int bt;
  int tt;
  int wt;
} * p;

// holds the scheduled process details in order
struct done {
  char name[5];
  int ct;
} * d;

void read_proc(int n) {
  for (int i = 0; i < n; i++) {
    printf("\nEnter details of process %d :\n", i);

    // set process name
    printf("Enter process name\t: ");
    scanf("%s", p[i].name);

    // read arrival time
    printf("Enter arrival time\t: ");
    scanf("%d", &p[i].at);

    // read burst time
    printf("Enter burst time\t: ");
    scanf("%d", &p[i].bt);

    printf("\n");
  }
}

int sort(int n) {
  struct proc temp;

  // bubble sort in ascending order of arrival time
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (p[j].at > p[j+1].at) {
        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
      }
    }
  }

  return 0;
}

int fcfs(int n, int num) {
  int i = 0;
  int iterations = 0;
  int cur_time = 0;

  // iterate over n number of processes
  while (i != n) {

    /*
     * check if the current time is <= arrival time of process
     * if true then it's not idle time
     */
    if (cur_time >= p[i].at) {
      /*
       * schedule process and find
       * completion time,turnaround time
       * and waiting time
       */
      strcpy(d[num].name, p[i].name);
      cur_time = cur_time + p[i].bt;
      d[num].ct = cur_time;
      p[i].tt = d[num].ct - p[i].at;
      p[i].wt = p[i].tt - p[i].bt;
    } else {

      // in case of idle time we wait
      while (cur_time != p[i].at) {
        ++cur_time;
      }

      // idle time over
      d[num].ct = cur_time;

      /*
       * decrement the looping variable so as to
       * not miss one iteration spent on idle case
       */
      --i;

      // store idle case details
      strcpy(d[num].name, "idle");
    }

    // continue iteration processes + move to next process of done
    ++i;
    ++num;
  }
  return num;
}

// display gantt chart
void display_gantt(int num) {
  printf("\nGantt Chart:\n");
  for (int i = 0; i < num - 1; i++) {
    printf("--------------------");
  }
  printf("\n");
  for (int i = 0; i < num; i++) {
    printf("|\t%s\t|", d[i].name);
  }
  printf("\n");
  for (int i = 0; i < num - 1; i++) {
    printf("--------------------");
  }
  printf("\n%d\t\t", 0);
  for (int i = 0; i < num; i++) {
    printf("%d\t\t", d[i].ct);
  }
  printf("\n");
}

void display_table(int n) {
  float avg_tt = 0.0;
  float avg_wt = 0.0;
  printf("\nSorted Process Table After Scheduling:\n");
  puts("+-----+------------+-----------------+--------------+");
  puts("| PID | Burst Time | Turnaround Time | Waiting Time |");
  puts("+-----+------------+-----------------+--------------+");

  for (int i = 0; i < n; i++) {
    avg_tt = avg_tt + p[i].tt;
    avg_wt = avg_wt + p[i].wt;
    printf("| %2s  |     %2d     |        %2d       |      %2d      |\n",
           p[i].name, p[i].bt, p[i].tt, p[i].wt);
    puts("+-----+------------+--------------+-----------------+");
  }

  printf("\n");
  puts("+-------------------------+----------------------+");
  puts("| Average Turnaround Time | Average Waiting Time |");
  puts("+-------------------------+----------------------+");
  printf("|          %*.*f            |          %*.*f         |\n", 0, 1,
         avg_tt / n, 0, 1, avg_wt / n);
  puts("+-------------------------+----------------------+");
  printf("\n");
}

int main() {
  int n_proc;
  // number of items in done structure
  int num = 0;

  // read total number of processes
  printf("Enter no of processes : ");
  scanf("%d", &n_proc);

  // allocate memory for each process
  p = (struct proc *)malloc(n_proc * sizeof(struct proc));
  d = (struct done *)malloc((n_proc + 9) * sizeof(struct done));

  // read details of each process
  read_proc(n_proc);

  // sort the processes based on arrival time
  sort(n_proc);

  // perform fcfs
  num = fcfs(n_proc, num);

  // display the table
  display_table(n_proc);

  // display the gantt chart
  display_gantt(num);

  free(p);
  free(d);
  return 0;
}
