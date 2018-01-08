import java.util.*;
import java.io.*;

class Code{
    public static void main(String[] args) throws Exception{
        System.out.println("Yeahh..");
        Scanner sc = new Scanner(new File("inpl.in"));
        PrintWriter pw = new PrintWriter(new File("out.txt"));
        int T,r,c,i,j,k,p,q;
        char[][] arr =  new char[25][25];
        String temp;
        T = sc.nextInt();
        for(i=0;i<T;++i){
            r=sc.nextInt(); c=sc.nextInt();
            //System.out.println(String.format("r=%d c=%d",r,c));
            sc.nextLine();
            for(j=0;j<r;++j){
                temp = sc.nextLine();
                for(k=0;k<c;++k){
                    arr[j][k]=temp.charAt(k);
                    //System.out.print(arr[j][k]);
                }
                //System.out.println();
            }
            //row by row
            for(j=0;j<r;j++){
                for(k=0;k<c;){
                    p=k;
                    while(p<c && arr[j][p]=='?'){
                        ++p;
                    }
                    if(p!=c){
                        for(q=k;q<p;++q){
                            arr[j][q]=arr[j][p];
                        }
                    } else {
                        if(k-1>=0){
                            for(q=k;q<p;++q){
                                arr[j][q]=arr[j][k-1];
                            }    
                        }
                    }
                    if(k==p)
                    k=p+1;
                    else
                    k=p;
                }
            }
            //col by col
            for(j=0;j<c;j++){
                for(k=0;k<r;){
                    p=k;
                    while(p<r && arr[p][j]=='?'){
                        ++p;
                    }
                    if(p!=r){
                        for(q=k;q<p;++q){
                            arr[q][j]=arr[p][j];
                        }
                    } else {
                        if(k-1>=0){
                            for(q=k;q<p;++q){
                                arr[q][j]=arr[k-1][j];
                            }    
                        }
                    }
                    if(k==p)
                    k=p+1;
                    else
                    k=p;
                }
            }
            pw.println(String.format("Case #%d:",i+1));
            for(j=0;j<r;++j){
                for(k=0;k<c;++k){
                    pw.print(arr[j][k]);
                }
                pw.println();
            }
        }
        pw.close();
    }
}