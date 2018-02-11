// https://leetcode.com/problems/word-ladder/description/
// Bidirectional bfs search
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashMap<String, Boolean> lvisited = new HashMap();
        Queue<String> lqueue = new LinkedList();
        HashMap<String, Boolean> rvisited = new HashMap();
        Queue<String> rqueue = new LinkedList();
        int i,j,k;
        if(!wordList.contains(beginWord))
        wordList.add(beginWord);
        if(!wordList.contains(endWord))
            return 0;
        for(i=0;i<wordList.size();++i){
            lvisited.put(wordList.get(i),false);
            rvisited.put(wordList.get(i),false);
        }
        lqueue.add(beginWord);
        lvisited.put(beginWord,true);
        rqueue.add(endWord);
        rvisited.put(endWord,true);
        int len,count=0;
        char[] word;
        char orignal_letter;
        while(!lqueue.isEmpty() && !rqueue.isEmpty()){
            //System.out.println("count = "+count);
            len= lqueue.size();
            for(i=0;i<len;++i){
                word = lqueue.poll().toCharArray();                
                //System.out.println("left word: "+String.valueOf(word));
                for(j=0;j<word.length;++j){
                    orignal_letter = word[j];
                    for(k=(int)'a';k<=(int)'z';++k){
                        word[j]=(char)k;
                        if(lvisited.containsKey(String.valueOf(word)) && !lvisited.get(String.valueOf(word))){         
                            //System.out.println("next visiting word: "+String.valueOf(word));
                            if(rvisited.get(String.valueOf(word)))
                                return (2*count+2);
                            lvisited.put(String.valueOf(word), true);
                            lqueue.add(String.valueOf(word));
                        }
                    }
                    word[j]=orignal_letter;
                }
            }
            len= rqueue.size();
            for(i=0;i<len;++i){
                word = rqueue.poll().toCharArray();    
                //System.out.println("right word: "+String.valueOf(word));            
                for(j=0;j<word.length;++j){
                    orignal_letter = word[j];
                    for(k=(int)'a';k<=(int)'z';++k){
                        word[j]=(char)k;
                        if(rvisited.containsKey(String.valueOf(word)) && !rvisited.get(String.valueOf(word))){
                            //System.out.println("next visiting word: "+String.valueOf(word));
                            if(lvisited.get(String.valueOf(word)))
                                return (2*count+3);
                            rvisited.put(String.valueOf(word), true);
                            rqueue.add(String.valueOf(word));
                        }
                    }                    
                    word[j]=orignal_letter;
                }
            }
            ++count;
        }
        return 0;
    }
}