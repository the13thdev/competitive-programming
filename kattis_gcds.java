import java.util.*;
import java.io.*;


public class Code {

    public static void main(String[] args) throws Exception {
//        Scanner sc = new Scanner(new File("inp.txt"));
        Scanner sc = new Scanner(System.in);

        int n,i,j;
        n = sc.nextInt();
        int[] arr = new int[100000];
        boolean[][] dp = new boolean[100000][101];
        HashSet<Integer> set = new HashSet<>();
        for(i=0; i<n; ++i) {
            arr[i] = sc.nextInt();
        }
        dp[0][arr[0]]= true;
        set.add(arr[0]);
        for(i=1;i<n;++i){
            dp[i][arr[i]]=true;
            set.add(arr[i]);
            for(j=1;j<=100;++j){
                if(dp[i-1][j]){
                    int new_gcd = gcd(j,arr[i]);
                    dp[i][new_gcd] = true;
                    set.add(new_gcd);
                }
            }
        }
        System.out.println(set.size());
    }

    static int gcd(int a, int b){
//    System.out.println(String.format("at gcd %d %d",a,b));
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }
}
