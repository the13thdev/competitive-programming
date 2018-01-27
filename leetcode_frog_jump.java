//Froj Jump Leetcode problem, https://leetcode.com/submissions/detail/138048200/

class Solution {
    public boolean canCross(int[] stones) {
        HashMap<Integer, HashSet<Integer> > map = new HashMap();
        int i;
        for(i=0;i<stones.length;++i){
            map.put(stones[i], new HashSet<Integer>());
        }
        map.get(0).add(0);
        for(i=0;i<stones.length;++i){
            //System.out.println(String.format("stones[%d]=%d can be reached by:",i,stones[i]));
            for(Integer step: map.get(stones[i])){
                //System.out.println(step);
                //System.out.println(String.format("..checking %d %d %d",stones[i]+step-1,stones[i]+step,stones[i]+step+1));
                if((stones[i]+step-1)>stones[i] && map.containsKey(stones[i]+step-1)){
                    //System.out.println(String.format("..%d possible with step =%d",stones[i]+step-1,step-1));
                    map.get(stones[i]+step-1).add(step-1);
                }
                if((stones[i]+step)>stones[i] && map.containsKey(stones[i]+step)){
                    //System.out.println(String.format("..%d possible with step =%d",stones[i]+step,step));
                    map.get(stones[i]+step).add(step);
                }
                if((stones[i]+step+1)>stones[i] && map.containsKey(stones[i]+step+1)){
                    //System.out.println(String.format("..%d possible with step =%d",stones[i]+step+1,step+1));
                    map.get(stones[i]+step+1).add(step+1);
                }
            }
        }
        return (map.get(stones[stones.length-1]).size()>0);
    }
}
