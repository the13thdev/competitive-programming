package cp;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

/*Cards Game*/

class Union {

    int arr[];

    public Union(int n) {
        arr = new int[n];
        int i;
        for (i = 0; i < n; ++i) {
            arr[i] = -1;
        }
    }

    public int find(int id) {
        while (arr[id]  >=0) {
            id = arr[id];
        }
        return id;
    }

    public void union(int a, int b) {
        int root_a = find(a), root_b = find(b);
        if (root_a != root_b) {
            if (-arr[root_a] > -arr[root_b]) {
                arr[root_a] += arr[root_b];
                arr[root_b] = root_a;
            } else {
                arr[root_a] += arr[root_b];
                arr[root_b] = root_a;
            }
        }
    }
}

class Edge {

    public int weight, from, to;

    public Edge(int w, int f, int t) {
        weight = w;
        from = f;
        to = t;
    }
}

class EdgeCompare implements Comparator<Edge>{
    
    public int compare(Edge a, Edge b){
        return a.weight-b.weight;
    }
}

public class CP {

    public static void main(String[] args) throws Exception {

        //Scanner sc = new Scanner(System.in);
        Scanner sc = new Scanner(new File("inpl.in"));
        PrintWriter pw = new PrintWriter("out.txt");
        ArrayList<Edge> list = new ArrayList();
        int T, n, i, j, k;
        long ans = 0;
        int[] r_arr, b_arr;
        T = sc.nextInt();
        for (i = 1; i <= T; ++i) {
            n = sc.nextInt();
            r_arr = new int[n];
            b_arr = new int[n];
            list.clear();
            ans = 0;
            for (j = 0; j < n; ++j) {
                r_arr[j] = sc.nextInt();
            }
            for (j = 0; j < n; ++j) {
                b_arr[j] = sc.nextInt();
            }
            for (j = 0; j < n; ++j) {
                for (k = j+1; k < n; ++k) {
                    list.add(new Edge(Math.min(r_arr[j] ^ b_arr[k],r_arr[k] ^ b_arr[j]), j, k));
                }
            }
            Collections.sort(list,new EdgeCompare());
            Union uf = new Union(n);
            int z=0;
            for(j=0;j<list.size();++j){
                Edge temp = list.get(j);
                if(uf.find(temp.from)!=uf.find(temp.to)){
                    ans+=temp.weight;
                    uf.union(temp.from, temp.to);
                    ++z;
                    if(z==n-1)
                        break;
                }
                
            }
            System.out.println(String.format("Case #%d: %d", i, ans));
            pw.println(String.format("Case #%d: %d", i, ans));
        }
        pw.close();
    }

    //Recursive solution for brute force
    static long rsolve(LinkedList<int[]> list) {
        if (list.size() < 2) {
            return 0;
        }
        long ans;
        ans = (long) Math.pow(10, 17);
        int[] a, b;
        LinkedList<int[]> sublist;
        ListIterator<int[]> itr1;
        ListIterator<int[]> itr2;
        /*itr1 = list.listIterator();
        System.out.print(String.format("..current list: "));
        while(itr1.hasNext()){
            a=itr1.next();
            System.out.print(String.format(" (r:%d b:%d)",a[0],a[1]));
        }
        System.out.println();*/
        itr1 = list.listIterator();
        while (itr1.hasNext()) {
            a = itr1.next();
            itr2 = list.listIterator(itr1.nextIndex());
            while (itr2.hasNext()) {
                b = itr2.next();
                //System.out.println(String.format("a: r=%d b=%d, b: r=%d b=%d",a[0],a[1],b[0],b[1]));
                sublist = new LinkedList(list);
                sublist.remove(itr1.previousIndex());
                ans = Math.min(ans, Math.min(a[0] ^ b[1], a[1] ^ b[0]) + rsolve(sublist));
                sublist = new LinkedList(list);
                sublist.remove(itr2.previousIndex());
                ans = Math.min(ans, Math.min(a[0] ^ b[1], a[1] ^ b[0]) + rsolve(sublist));
                //System.out.println(String.format("..updated ans=%d, min val a^b=%d ",ans, Math.min(a[0]^b[1], a[1]^b[0])));
            }
        }
        return ans;
    }

}
