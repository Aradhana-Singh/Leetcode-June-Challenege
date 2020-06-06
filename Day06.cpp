//Queue Reconstruction by Height

class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if(a[0] > b[0]) return true;
        if(a[0] == b[0]) return a[1]<b[1];
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        int n = people.size();
        vector<vector<int> >res(n, vector<int> (2,0));
        for(int i = 0; i<n; i++){
            int temp1 = res[people[i][1]][0];
            int temp2 = res[people[i][1]][1];
            res[people[i][1]][0] = people[i][0];
            res[people[i][1]][1] = people[i][1];
            for(int j = people[i][1]+1; j<i+1; j++){
                swap(temp1, res[j][0]);
                swap(temp2, res[j][1]);
            }
        }
        return res;
    }
};