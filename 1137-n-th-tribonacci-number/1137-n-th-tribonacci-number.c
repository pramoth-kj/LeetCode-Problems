int tribonacci(int n){
  if (n<2)
  {
      return n;
  }
  int flag,count;
  int a=0;
  int b=1;
  int c=1;
  for(int i=3;i<n+1;i++)
  {
    flag=a;
    count=b;
    a=b;
    b=c;
    c=flag+count+c;
  }
  return c;
}