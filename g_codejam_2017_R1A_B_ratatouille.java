import java.util.*;
import java.io.*;

/* https://code.google.com/codejam/contest/5304486/dashboard#s=p1&a=1 */
class Code{
    public static void main(String[] args) throws Exception{
        System.out.println("Yeahh..");
        Scanner sc = new Scanner(new File("inpl.in"));
        PrintWriter pw = new PrintWriter(new File("out.txt"));
        int i,j,k,T,n,p;
        int recp[] =new int[50];
        float low;
        int l,r,ans;
        PriorityQueue<Float> pq[] =new PriorityQueue[50];
        ArrayList<Float> tl = new ArrayList();
        T = sc.nextInt();
        for(i=1;i<=T;++i){
            n=sc.nextInt();
            p=sc.nextInt();
            tl.clear();
            ans=0;
            for(j=0;j<n;++j){
                recp[j]=sc.nextInt();
            }
            for(j=0;j<n;++j){
                pq[j] = new PriorityQueue(50,Collections.reverseOrder());
                for(k=0;k<p;++k){
                    pq[j].add((float)sc.nextInt()/recp[j]);
                }
                tl.add(pq[j].poll());
            }
            while(!tl.isEmpty()){
                /*System.out.print("..tl contains : ");
                for(j=0;j<n;++j){
                    System.out.print(tl.get(j)+" ");
                }
                System.out.println();*/
                low = tl.get(0);
                for(j=1;j<n;++j){
                    if(tl.get(j)<low)
                        low = tl.get(j);
                }
                r = (int)Math.floor(((float)10/9)*low);
                l = (int)Math.ceil(((float)10/11)*low);
                //System.out.println(String.format("low=%f l=%d r=%d",low,l,r));
                boolean possible=true;
                for(j=0;j<n;++j){
                    if((tl.get(j)<(float)(0.9*l)) || (tl.get(j)>(float)(1.1*r))){
                        //System.out.println("..failed for "+tl.get(j));
                        possible=false;
                        if(!pq[j].isEmpty()){
                            tl.remove(j);
                            tl.add(j,pq[j].poll());
                        } else{
                            tl.clear();
                            break;
                        }
                    }
                }
                if(possible){
                    ++ans;
                    tl.clear();
                    for(j=0;j<n;++j){
                        if(!pq[j].isEmpty())
                        tl.add(pq[j].poll());
                        else{
                            tl.clear();
                            break;
                        }                        
                    }
                }
            }
            pw.println(String.format("Case #%d: %d",i,ans));
        }
        pw.close();
    }
}