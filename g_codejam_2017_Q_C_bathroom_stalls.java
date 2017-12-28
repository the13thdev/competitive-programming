import java.util.*;
import java.io.*;

class Code{
    public static void main(String[] args) throws Exception{
        System.out.println("..yeah");
        Scanner sc = new Scanner(new File("inp3.in"));
        PrintWriter pw = new PrintWriter(new File("out.txt"));
        int T,i,j;
        long n,k,curr=0,l,r,min,max,p,c;
        PriorityQueue<Long> pq = new PriorityQueue(10, Collections.reverseOrder());
        HashMap<Long,Long> count = new HashMap<>(); 
        T = sc.nextInt();
        for(i=1;i<=T;++i){
            n = sc.nextLong();
            k =  sc.nextLong();      
            pq.clear();      
            count.clear();
            pq.add(n);
            count.put(n,(long)1);
            p=0;
            //System.out.println(pq.peek());
            while(p<k){
                curr = pq.poll();
                c = count.get(curr); 
                p+=c;
                //System.out.println(String.format("..curr=%d c=%d p=%d",curr,c,p));
                if(curr>1){
                    if(curr%2==0){
                        l = curr/2 - 1;                           
                    } else {
                        l = curr/2 ;
                    }
                    if(l>0){
                        if(count.get(l)==null){
                            pq.add(l);
                            count.put(l,c);
                        }
                        else
                        count.put(l,c+count.get(l));
                    }
                    r = curr - l - 1;    
                    if(r>0){
                        if(count.get(r)==null){
                            pq.add(r);
                            count.put(r,c);
                        }
                        else
                        count.put(r,c+count.get(r));
                    }
                }
            }
            if(curr%2==0){
                l = curr/2 - 1;                           
            } else {
                l = curr/2 ;
            }
            max = Math.max(l,curr - l - 1);
            min = Math.min(l,curr - l - 1);
            pw.println(String.format("Case #%d: %d %d",i,max,min));
        }
        pw.close();
    }
}