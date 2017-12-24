/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cp;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author vijit
 */
public class CP {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        
		// your code goes here
		//Scanner sc = new Scanner(System.in);
                Scanner sc = new Scanner(new File("inpl.in"));
                PrintWriter pw = new PrintWriter("out.txt");
		int T,a,n,p,i,j;
                long ans;
		String input, input_split[];
		T = sc.nextInt();
                sc.nextLine();
		for(j=1;j<=T;++j){
		    input = sc.nextLine();
                    //System.out.println(".."+input);
		    input_split = input.split(" ");
		    a = Integer.parseInt(input_split[0]);
		    n = Integer.parseInt(input_split[1]);
		    p = Integer.parseInt(input_split[2]);
		    //System.out.print(String.format("%d %d %d\n",a,n,p));
                    ans =  a%p;
                    for(i=2;i<=n;++i){
                        ans = powerMod(ans,i,p);
                    }
                    System.out.println(String.format("Case #%d: %d",j,ans));
                    pw.println(String.format("Case #%d: %d",j,ans));
		}
                pw.close();
    }
    
    static long powerMod(long a, long b,long p){
        //System.out.println(String.format("..at a=%d b=%d p=%d",a,b,p));
        if(b==0){
            return 1;
        } else{
            long temp = powerMod(a,b/2,p);
            if(b%2==0){
                return ((temp*temp)%p);
            }
            else{                
                return ((temp*temp*a)%p);
            }
        }
    }
    
}
