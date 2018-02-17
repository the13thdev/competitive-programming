/*
  Leetcode: Word Ladder II, https://leetcode.com/problems/word-ladder-ii/
  Find all min length shortest paths from src to dest vertex in graph.
*/

class Solution {
    HashMap<String, List<String> > graph;
    HashMap<String, Integer> distance;
    ArrayList< List<String> > result;
    ArrayList<String> temp;
    String dest_word;
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        result = new ArrayList();
        temp = new ArrayList();
        graph =  new HashMap<String, List<String> >();
        distance = new HashMap<String, Integer>();
        dest_word = endWord;
        Queue<String> queue = new LinkedList();
        int i,j;
        if(!wordList.contains(endWord))
            return result;
        if(!wordList.contains(beginWord))
            wordList.add(beginWord);
        for(i=0;i<wordList.size();++i){
            graph.put(wordList.get(i), new ArrayList());
        }
        distance.put(beginWord, 0);
        queue.add(beginWord);
        String orig_word;
        char word[], orig_char;
        int min_size=0;
        Boolean endFound = false;
        while(!queue.isEmpty()){
            orig_word = queue.poll();
            word = orig_word.toCharArray();
            for(i=0;i<word.length;++i){
                orig_char = word[i];
                for(j=(int)'a';j<=(int)'z';++j){
                    word[i]= (char)j;
                    if(!endFound && endWord.equals(String.valueOf(word))){
                        endFound=true;
                        min_size = distance.get(orig_word)+1;
                        distance.put(String.valueOf(word), distance.get(orig_word)+1);
                        //System.out.println("end: Updating "+String.valueOf(word)+" dist to "+ (distance.get(orig_word)+1)+", orig_word = "+orig_word);
                    }
                    //adding neighbor
                    if(graph.containsKey(String.valueOf(word)) && !orig_word.equals(String.valueOf(word))){
                        graph.get(orig_word).add(String.valueOf(word));
                    }
                    //updating dist and adding to queue
                    if(!endFound && graph.containsKey(String.valueOf(word)) && !distance.containsKey(String.valueOf(word))){
                        //System.out.println("Updating "+String.valueOf(word)+" dist to "+ (distance.get(orig_word)+1)+", orig_word = "+orig_word);
                        distance.put(String.valueOf(word), distance.get(orig_word)+1);
                        queue.add(String.valueOf(word));
                    }
                }
                word[i]=orig_char;
            }
        }
        //System.out.println("min len = "+min_size);
        dfs(beginWord, new HashMap<String, Boolean>());
        return result;
    }

    void dfs(String s_word, HashMap<String, Boolean> visited){
        //System.out.print("at: "+s_word);
        visited.put(s_word, true);
        List<String> neighbors = graph.get(s_word);
        int i;
        String word;
        temp.add(s_word);
        for(i=0;i<neighbors.size();++i){
            word = neighbors.get(i);
            if((!visited.containsKey(word) || !visited.get(word)) && distance.containsKey(word) && distance.get(word)==distance.get(s_word)+1){
                //System.out.println("  ..inner");
                if(word.equals(dest_word)){
                    temp.add(dest_word);
                    result.add(new ArrayList(temp));
                    temp.remove(dest_word);
                    //System.out.println("end found: "+dest_word);
                } else{
                    dfs(word, visited);
                }
            }
        }
        visited.put(s_word,false);
        temp.remove(s_word);
    }
}
