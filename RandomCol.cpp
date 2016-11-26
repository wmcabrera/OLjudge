// Randomized Collection
// First Try

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    /*
    
    [1]
    
    */
    private:
      vector<int> col;
    private: const int SIZE= 100; 
    private: int numElem;
      
    public:RandomizedCollection() {
        vector<int> v;
        for ( int i=0; i<SIZE; i++){
            col.push_back(0);
        }
        numElem=0;
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public:
    bool insert(int val) {
       col[SIZE/2 + val]+=1;
       numElem++;
       if (col[SIZE/2 + val]==1) {
          return true; 
       }  else return false;    
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
        public:
    bool remove(int val) {
        if (col[SIZE/2 + val]>0) {
            col[SIZE/2 + val]--;
            numElem--;
            return true;
        } else
            return false;
        
        
    }
    
    /** Get a random element from the collection.
    5  3/6
    6 2/6
    9 1/6
    */
     public:
    int getRandom() {
    int r= rand()%numElem;
    int i =0;
    if (r < numElem+1) {
       int ac=0;
       for ( i =0; i<SIZE; i++ ) {
           
           if (ac <= r < ac+col[i]) break;
           ac+= col[i];
           
       }
       return i -SIZE/2;
    } else {
        int ac=numElem;
       for ( i =SIZE-1; i>=0; i++ ) {
          
           if (ac-col[i] <r<=ac) break;
            ac-= col[i];
           
       }
       return i - SIZE/2;
    } 
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
