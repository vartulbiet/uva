while(a!=b)
{
if(a>b)
a=a-b;
else
b=b-a;
}
hcf =a;



 while (b != 0) {
    t = b;
    b = a % b;
    a = t;
  }