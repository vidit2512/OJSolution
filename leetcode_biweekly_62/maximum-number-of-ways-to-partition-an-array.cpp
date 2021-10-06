class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long int>pre(n);
        vector<long long int>suf(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+nums[i];
        }
        
        // for(auto it:pre)cout<<it<<" ";cout<<endl;
        //  for(auto it:suf)cout<<it<<" ";cout<<endl;
        map<long long int,long long int>mp1,mp2,mp3;
         for(int i=0;i<n-1;i++) mp2[(pre[i]-suf[i+1])]++;
        
      
     long long int ans=mp2[0];
     
        for(int i=0;i<n;i++)
        {
            long long int df=k-nums[i];
           long long int temp=0;
            if(mp1.count(df))temp+=mp1[df];
            if(mp2.count(-df))temp+=mp2[-df];
            ans=max(ans,temp);
            
            if(i<n-1)
            {
                mp1[pre[i]-suf[i+1]]++;
                mp2[pre[i]-suf[i+1]]--;
                
            }
            
            ////////////
            
            // mp2[-(pre[i]-suf[i+1])]++;
            // if(mp2.find(nums[i]-k)!=mp2.end())
            // frleft[i]=mp2[nums[i]-k];
            // else frleft[i]=0;
           
        }

            return ans;
        
    }
};