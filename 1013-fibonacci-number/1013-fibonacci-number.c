int fib(int n){
   int a=0;
        int c, b=1,sum=0;
        if(n<=0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        else{
        while(n>1){
            c=a+b;
            a=b;
            b=c;
            n=n-1;
        }
       return c; }
    
}