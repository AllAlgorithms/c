#include <stdio.h>
#include <stdlib.h>

struct process{
  int alloc;
  int max;
  int need;
}*p;

void read_proc(int n,int a,int pid,int req){
  printf("\nEnter initial process details : \n");

  for(int i=0;i<n;++i){
    printf("\nEnter details of process %d :\n",i);

    // enter allocation value
    printf("allocation\t= ");
    scanf("%d",&p[i].alloc);

    // enter max value
    printf("max\t\t= ");
    scanf("%d",&p[i].max);

    // calculate need
    p[i].need = p[i].max - p[i].alloc;

    // make negative need values as zero
    if(p[i].need<0){
      p[i].need = 0;
    }

  }

  // print process table
  printf("\n\t\tProcess Table:\nprocess\t|alloc\t|max\t|need\t|available\t|new id\t|new req\n");
  for(int i=0;i<n;++i){
    if(i==0){
      printf("p%d\t|%d\t|%d\t|%d\t|%d\t\t|%d\t|%d\n",i,p[i].alloc,p[i].max,p[i].need,a,pid,req);
    }
    else{
      printf("p%d\t|%d\t|%d\t|%d\t|  \t\t|  \t|  \n",i,p[i].alloc,p[i].max,p[i].need);
    }
  }
}

void disp(int safe[],int len){
  printf("\n\n**********SAFE NOW**********\n");
  printf("SAFE SEQUENCE\n");
  for(int i =0;i<len;++i){
    printf("%d, ",safe[i]);
  }
  printf("\n");
}

// Resource Allocation
int schedule(int pid,int req,int n_proc,int avail){
  int a,n,cnt=0,safe[20],s=0;

  // allocate the new request
  p[pid].alloc += req;
  p[pid].need  -= req;

  // find the safe sequence
  while(cnt != n_proc){
    printf("\nIN DEADLOCK");

    for(int pid=0;pid<n_proc;++pid){

      // store values to temporary variables
      a = p[pid].alloc;
      n = p[pid].need;

      // process safe if need less than available
      if ( n <= avail ){
        cnt += 1;
        avail += a;
        safe[s++] = pid;

        // if iterated over all processes then return
        if ( cnt == n_proc ){
          disp(safe,s);
          return 0;
        }
      }

    }
  }
  disp(safe,s);
  return 0;
}

int main(int argc, char const* argv[]){
  int n_proc,avail,pid,req;

  // total number of processes
  printf("Enter num of process : ");
  scanf("%d",&n_proc);

  // dynamically allocate the strucutre object
  p = (struct process*)malloc(n_proc*sizeof(struct process));

  // Enter the initial availability
  printf("\nEnter available\t= ");
  scanf("%d",&avail);

  // Enter process id for which resource needs to be allocated
  printf("new pid\t\t= ");
  scanf("%d",&pid);

  // Enter the value of the new resource request
  printf("new req\t\t= ");
  scanf("%d",&req);

  // read the details of each process
  read_proc(n_proc,avail,pid,req);

  // if the request is not available then exit
  if(req >= avail){
    printf("\nNo availability for new req\n");
    exit(0);
  }

  // schedule the processes along with the new request
  schedule(pid,req,n_proc,avail);

  return 0;
}
