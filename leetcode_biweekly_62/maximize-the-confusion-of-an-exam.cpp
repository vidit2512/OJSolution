class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        
        //first for T;
        int n=s.size();
       
        int ans=0,temp=0;
        int kk=k;
        int ii=0,jj=0;k=kk;
        while(ii<n&&jj<n)
        {
           
            while(jj<n)
            {
                if(s[jj]=='T')
                jj++;
                else if(k>0){k--;jj++;}
                else if(k<=0)
                {
                    ans=max(ans,jj-ii);
                break;
                }
            }
            ans=max(ans,jj-ii);
            if(jj>=n)break;
            
            while(ii<n&&s[ii]!='F')ii++;
            if(ii>=n)break;
            if(s[ii]=='F')
            {
                ii++;
                ans=max(ans,jj-ii+1);
                jj++;
                
            }
          
        }
       // cout<<"Ans=="<<ans<<endl;
        ii=0,jj=0;k=kk;
        while(ii<n&&jj<n)
        {
           
            while(jj<n)
            {
                if(s[jj]=='F')
                jj++;
                else if(k>0){k--;jj++;}
                else if(k<=0)
                {
                    ans=max(ans,jj-ii);
                break;
                }
            }
            ans=max(ans,jj-ii);
          
            if(jj>=n)break;
            
            while(ii<n&&s[ii]!='T')ii++;
            if(ii>=n)break;
            if(s[ii]=='T')
            {
                ii++;
               
                ans=max(ans,jj-ii+1);
                 jj++;
                
            }
          
        }
    
        
        return ans;
       
    }
};