import java.util.*;
class NQueens{
  static int x[],c=0;
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    System.out.println("enter no of queens");
    int n=sc.nextInt();
    x=new int[n+1];
    NQueen(1,n);
    System.out.println("total no of solutios:"+c);
  }
  public static void NQueen(int k,int n){
    for(int i=1;i<=n;i++){
      if(place(k,i)){
        x[k]=i;
        if(k==n){
          c++;
          for(int j=1;j<=n;j++) System.out.print(x[j]+" "); //prints the positions of the queens in each row.
          System.out.println();
        }
        NQueen(k+1,n);
      }
    }
  }
  
  //to check if kth queen can be placed in the position pos
  public static boolean place(int k,int pos){
    for(int j=1;j<=k-1;j++){
      if( x[j]==pos || (Math.abs(k-j)==Math.abs(pos-x[j]))) return false;
    }
    return true;
  }
}
