using namespace std;
int main()
{
        int a, b, x, y, temp, hcf, lcm;
        cout<<"\n Enter Two Numbers : \n";
        cin>>x>>y;
        a=x;
        b=y;
        while(b!=0)
        {
                temp=b;
                b=a%b;
                a=temp;
        }
        hcf=a;
        lcm=(x*y)/hcf;
        cout<<"\n HCF : "<<hcf<<"\n";
        cout<<"\n LCM : "<<lcm<<"\n";
        return 0;
}
