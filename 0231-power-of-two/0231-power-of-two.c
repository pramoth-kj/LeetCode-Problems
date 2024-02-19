bool isPowerOfTwo(int n){
 int i=n;
 if(i>0)
 {
     while(i%2==0)
     {
         i=i/2;
     }
 }
 if(i==1)
 {
     return true;
 }
 else
 {
     return false;
 }
}