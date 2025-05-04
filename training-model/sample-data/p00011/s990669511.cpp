 #include<iostream>
 #include<stdio.h>
 #include<string>
 #include<math.h>
 #include<iomanip>
 #include<algorithm>
 #include<string.h>
 #include<cctype>
 #include<map>
 #include<set>
 #include<vector>
 #include<sstream>
 
 using namespace std;
 
 int v[35];
 
 int main()
 {
   int w,n;
   cin>>w>>n;
   for(int i=1;i<=w;i++) v[i]=i;
   while(n--)
   {
     int l,r;
     char temp;
     cin>>l>>temp>>r;
     swap(v[l],v[r]);          
   } 
   for(int i=1;i<=w;i++)
   {
     cout<<v[i]<<endl;        
   }
   //while(1);      
   return 0;    
 }
 
 
 