class Solution {
    void sort_dec(vector<int>& citations)
    {
       int n = citations.size();
       bool swapped;

       for (int i = 0; i < n - 1; ++i) 
       {
          swapped = false;

          for (int j = 0; j < n - i - 1; ++j) 
          {
              if (citations[j] < citations[j + 1]) 
              {
                 swap(citations[j], citations[j + 1]);
                 swapped = true;
              }
          }

       }
    }

public:
    int hIndex(vector<int>& citations) {
        sort_dec(citations);
        int h_index = 0;
        while(h_index < citations.size() && citations[h_index] > h_index)
        {
            h_index++;
        }
        
        return h_index;
    }
};